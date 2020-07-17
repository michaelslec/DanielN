//
// Created by Michael on 7/17/2020.
//

#ifndef MAIN_MAIN_H
#define MAIN_MAIN_H
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


#endif // MAIN_MAIN_H
