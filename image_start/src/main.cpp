#include <iostream>
#include "TGA_File.h"

using namespace std;
using namespace tga_prog;

int main()
{

  try {
    TGA test("input/layer1.tga", "input/pattern1.tga", "output/new.tga");
    test.applyMultiplyBlending();
  } catch (const std::invalid_argument& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
