#include <iostream>
#include <string>
#include <fstream>
#include <stack>

struct Header {
  char idLength; // 1 byte
  char colorMapType;
  char dataTypeCode;
  short colorMapOrigin; // 2 bytes
  short colorMapLength;
  char colorMapDepth;
  short xOrigin;
  short yOrigin;
  short width;
  short height;
  char bitsPerPixel;
  char imageDescriptor;
}; // 18 bytes total

using namespace std;

int main(int argc, char* argv[]) {

  return 0;
}
