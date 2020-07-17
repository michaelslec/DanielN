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

struct Pixel
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

int main() {
  ifstream layer_file("input/layer1.tga", ios::binary | ios::in);
  ifstream pattern_file("input/pattern1.tga", ios::binary | ios::in);
  ofstream outFile("output/test.tga", ios::binary | ios::out);

  if (!layer_file)
    cerr << "Could not open file layer1.tga" << endl;

  if (!pattern_file)
    cerr << "Could not open file layer1.tga" << endl;

  // if the file could not be opened
  if(!outFile)
    cerr << "Could not open file test.tga" <<  endl;
  // for storing the read-in information
  Header tgaHeader;
  
  layer_file.read(&tgaHeader.idLength, sizeof(tgaHeader.idLength));
  layer_file.read(&tgaHeader.colorMapType, sizeof(tgaHeader.colorMapType));
  layer_file.read(&tgaHeader.dataTypeCode, sizeof(tgaHeader.dataTypeCode));
  layer_file.read((char*)&tgaHeader.colorMapOrigin, sizeof(tgaHeader.colorMapOrigin));
  layer_file.read((char*)&tgaHeader.colorMapLength, sizeof(tgaHeader.colorMapLength));
  layer_file.read(&tgaHeader.colorMapDepth, sizeof(tgaHeader.colorMapDepth));
  layer_file.read((char*)&tgaHeader.xOrigin, sizeof(tgaHeader.xOrigin));
  layer_file.read((char*)&tgaHeader.yOrigin, sizeof(tgaHeader.yOrigin));
  layer_file.read((char*)&tgaHeader.width, sizeof(tgaHeader.width));
  layer_file.read((char*)&tgaHeader.height, sizeof(tgaHeader.height));
  layer_file.read(&tgaHeader.bitsPerPixel, sizeof(tgaHeader.bitsPerPixel));
  layer_file.read(&tgaHeader.imageDescriptor, sizeof(tgaHeader.imageDescriptor));

  outFile.write(&tgaHeader.idLength, sizeof(tgaHeader.idLength));
  outFile.write(&tgaHeader.colorMapType, sizeof(tgaHeader.colorMapType));
  outFile.write(&tgaHeader.dataTypeCode, sizeof(tgaHeader.dataTypeCode));
  outFile.write((char*)&tgaHeader.colorMapOrigin, sizeof(tgaHeader.colorMapOrigin));
  outFile.write((char*)&tgaHeader.colorMapLength, sizeof(tgaHeader.colorMapLength));
  outFile.write(&tgaHeader.colorMapDepth, sizeof(tgaHeader.colorMapDepth));
  outFile.write((char*)&tgaHeader.xOrigin, sizeof(tgaHeader.xOrigin));
  outFile.write((char*)&tgaHeader.yOrigin, sizeof(tgaHeader.yOrigin));
  outFile.write((char*)&tgaHeader.width, sizeof(tgaHeader.width));
  outFile.write((char*)&tgaHeader.height, sizeof(tgaHeader.height));
  outFile.write(&tgaHeader.bitsPerPixel, sizeof(tgaHeader.bitsPerPixel));
  outFile.write(&tgaHeader.imageDescriptor, sizeof(tgaHeader.imageDescriptor));


  for (unsigned long i = 0; i < tgaHeader.width * tgaHeader.height; i++)
  {
    Pixel new_pixel;

    layer_file.read((char*)&new_pixel.red, sizeof(new_pixel.red));
    layer_file.read((char*)&new_pixel.green, sizeof(new_pixel.green));
    layer_file.read((char*)&new_pixel.blue, sizeof(new_pixel.blue));

    outFile.write((char*)&new_pixel.red, sizeof(new_pixel.red));
    outFile.write((char*)&new_pixel.green, sizeof(new_pixel.green));
    outFile.write((char*)&new_pixel.blue, sizeof(new_pixel.blue));
  }

  layer_file.close(); // close file1
  pattern_file.close();
  outFile.close(); // close file2
}
