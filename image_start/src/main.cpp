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
  int red;
  int green;
  int blue;
};

int main(int argc, char* argv[]) {
  
  //if there are more than 3 command line arguments
  if (argc > 3 || argc < 3)
    cerr << "Usage: program file_1 file_2" << endl;
  
  //get the name of the file we want to copy data from
  string file1 = argv[1];
  //get the name of the file we want to copy data to
  string file2 = argv[2];
  
  // ios::binary - open in binary mode
  // ios::in - open for input operations
  ifstream inFile(file1.c_str(), ios::binary | ios::in);
  
  if (!inFile)
    cerr << "Could not open file " << "\"" << file1 << "\"" << endl;
  
  // for storing the read-in information
  Header tgaHeader;
  
  inFile.read(&tgaHeader.idLength, sizeof(tgaHeader.idLength));
  inFile.read(&tgaHeader.colorMapType, sizeof(tgaHeader.colorMapType));
  inFile.read(&tgaHeader.dataTypeCode, sizeof(tgaHeader.dataTypeCode));
  inFile.read((char*)&tgaHeader.colorMapOrigin, sizeof(tgaHeader.colorMapOrigin));
  inFile.read((char*)&tgaHeader.colorMapLength, sizeof(tgaHeader.colorMapLength));
  inFile.read(&tgaHeader.colorMapDepth, sizeof(tgaHeader.colorMapDepth));
  inFile.read((char*)&tgaHeader.xOrigin, sizeof(tgaHeader.xOrigin));
  inFile.read((char*)&tgaHeader.yOrigin, sizeof(tgaHeader.yOrigin));
  inFile.read((char*)&tgaHeader.width, sizeof(tgaHeader.width));
  inFile.read((char*)&tgaHeader.height, sizeof(tgaHeader.height));
  inFile.read(&tgaHeader.bitsPerPixel, sizeof(tgaHeader.bitsPerPixel));
  inFile.read(&tgaHeader.imageDescriptor, sizeof(tgaHeader.imageDescriptor));
  
  // create an array of pixels with the length = number of pixels in image
  unsigned long size = tgaHeader.width * tgaHeader.height;
  Pixel* pixelData = new Pixel[size];
  
  // read in the data for each pixel in the image
  
  for (unsigned long i = 0; i < size; i++)
  {
    inFile.read((char*)&pixelData[i].red, sizeof(pixelData[i].red));
    inFile.read((char*)&pixelData[i].green, sizeof(pixelData[i].green));
    inFile.read((char*)&pixelData[i].blue, sizeof(pixelData[i].blue));
  }
  
  inFile.close(); // close file1
  
  //==========================================================================
  
  // ios::binary - open in binary mode
  // ios::in - open for output operations
  ofstream outFile(file2.c_str(), ios::binary | ios::out);
  
  // if the file could not be opened
  if(!outFile)
    cerr << "Could not open file " << "\"" << file2 << "\"" <<  endl;
  
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
  
  // write the data for each pixel in the image to file2
  for (unsigned long i = 0; i < size; i++)
  {
    outFile.write((char*)&pixelData[i].red, sizeof(pixelData[i].red));
    outFile.write((char*)&pixelData[i].green, sizeof(pixelData[i].green));
    outFile.write((char*)&pixelData[i].blue, sizeof(pixelData[i].blue));
  }
  
  outFile.close(); // close file2
  
  delete [] pixelData;
}
