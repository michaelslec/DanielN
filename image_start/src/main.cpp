#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "TGA_File.h"

using namespace std;
using namespace tga_prog;

int main()
{

  TGA test;

  try {
    test.setup("input/layer1.tga", "input/pattern2.tga", "output/temp.tga");
  } catch (const std::invalid_argument& e) {
    cerr << e.what() << endl;
  }

  test.applyMultiplyBlending();
  TGA task3("input/text.tga", "output/temp.tga", "output/task3.tga");
  task3.applyScreenBlending();

  // test.read_write_pixelInfo();
}
