#include <iostream>
#include "TGA_File.h"

using namespace std;
using namespace tga_prog;

int main()
{

  try {
    TGA task2("input/layer2.tga", "input/car.tga");
    task2.applySubtractionBlending();
    task2.save("output/task2.tga");
  } catch (const std::invalid_argument& e) {
    cerr << e.what() << endl;
  }

  try {
    TGA task4_sub("input/layer2.tga", "input/circles.tga");
    task4_sub.applyMultiplyBlending();
    task4_sub.save("output/task4_sub.tga");
    TGA task4("input/pattern2.tga", "output/task4_sub.tga");
    task4.applySubtractionBlending();
    task4.save("output/task4.tga");
  } catch (const std::invalid_argument& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
