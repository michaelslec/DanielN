#include "TGA_File.h"

using namespace std;

namespace tga_prog
{
TGA::TGA(const std::string &fg, const std::string &bg, const std::string &out_file)
{
  open_files(fg, bg, out_file);
  read_write_headerInfo();
}

void TGA::open_files(const std::string &fg, const std::string &bg, const std::string out_file)
{
  //must used open() if previously declared
  input1_.open(fg.c_str(), ios::binary | ios::in);
  input2_.open(bg.c_str(), ios::binary | ios::in);
  output_.open(out_file.c_str(), ios::binary | ios::out);

  std::string message = "Could not open file: ";
  if (!input1_)
  {
    message += fg;
    throw std::invalid_argument(message);
  }
  else if (!input2_)
  {
    message += bg;
    throw std::invalid_argument(message);
  }
  else if (!output_)
  {
    message += out_file;
    throw std::invalid_argument(message);
  }
}

void TGA::read_write_headerInfo()
{
  input1_.read(&header1_.idLength, sizeof(header1_.idLength));
  input1_.read(&header1_.colorMapType, sizeof(header1_.colorMapType));
  input1_.read(&header1_.dataTypeCode, sizeof(header1_.dataTypeCode));
  input1_.read((char *)&header1_.colorMapOrigin, sizeof(header1_.colorMapOrigin));
  input1_.read((char *)&header1_.colorMapLength, sizeof(header1_.colorMapLength));
  input1_.read(&header1_.colorMapDepth, sizeof(header1_.colorMapDepth));
  input1_.read((char *)&header1_.xOrigin, sizeof(header1_.xOrigin));
  input1_.read((char *)&header1_.yOrigin, sizeof(header1_.yOrigin));
  input1_.read((char *)&header1_.width, sizeof(header1_.width));
  input1_.read((char *)&header1_.height, sizeof(header1_.height));
  input1_.read(&header1_.bitsPerPixel, sizeof(header1_.bitsPerPixel));
  input1_.read(&header1_.imageDescriptor, sizeof(header1_.imageDescriptor));

  input2_.seekg(18);

  output_.write(&header1_.idLength, sizeof(header1_.idLength));
  output_.write(&header1_.colorMapType, sizeof(header1_.colorMapType));
  output_.write(&header1_.dataTypeCode, sizeof(header1_.dataTypeCode));
  output_.write((char *)&header1_.colorMapOrigin, sizeof(header1_.colorMapOrigin));
  output_.write((char *)&header1_.colorMapLength, sizeof(header1_.colorMapLength));
  output_.write(&header1_.colorMapDepth, sizeof(header1_.colorMapDepth));
  output_.write((char *)&header1_.xOrigin, sizeof(header1_.xOrigin));
  output_.write((char *)&header1_.yOrigin, sizeof(header1_.yOrigin));
  output_.write((char *)&header1_.width, sizeof(header1_.width));
  output_.write((char *)&header1_.height, sizeof(header1_.height));
  output_.write(&header1_.bitsPerPixel, sizeof(header1_.bitsPerPixel));
  output_.write(&header1_.imageDescriptor, sizeof(header1_.imageDescriptor));
}



void TGA::applyBlending(std::function<Pixel(const Pixel&, const Pixel&)> algorithm)
{
  for (int i = 0; i < (header1_.width * header1_.height); i++)
  {
    Pixel pixel1_, pixel2_;
    input1_.read((char *)&pixel1_.red, sizeof(pixel1_.red));
    input1_.read((char *)&pixel1_.green, sizeof(pixel1_.green));
    input1_.read((char *)&pixel1_.blue, sizeof(pixel1_.blue));

    input2_.read((char *)&pixel2_.red, sizeof(pixel2_.red));
    input2_.read((char *)&pixel2_.green, sizeof(pixel2_.green));
    input2_.read((char *)&pixel2_.blue, sizeof(pixel2_.blue));

    Pixel new_pixel = algorithm(pixel1_, pixel2_);

    output_.write((char *)&new_pixel.red, sizeof(new_pixel.red));
    output_.write((char *)&new_pixel.green, sizeof(new_pixel.green));
    output_.write((char *)&new_pixel.blue, sizeof(new_pixel.blue));
  }
}

void TGA::applyMultiplyBlending()
{
  applyBlending(_multiplyAlgorithm);
}


Pixel TGA::_multiplyAlgorithm(const Pixel &fg, const Pixel &bg)
{
  Pixel new_pixel;

  new_pixel.red = (fg.red * bg.red) / 255.0f + 0.5f;
  new_pixel.green = (fg.green * bg.green) / 255.0f + 0.5f;
  new_pixel.blue = (fg.blue * bg.blue) / 255.0f + 0.5f;

  return new_pixel;
}

Pixel TGA::_subtractAlgorithm(const Pixel &fg, const Pixel &bg)
{
  Pixel new_pixel;

  new_pixel.red = (fg.red * bg.red) / 255.0f + 0.5f;
  new_pixel.green = (fg.green * bg.green) / 255.0f + 0.5f;
  new_pixel.blue = (fg.blue * bg.blue) / 255.0f + 0.5f;

  return new_pixel;
}

//Pixel (TGA::* )(const Pixel&, const Pixel&)
//passing function pointer (which will be multiplyAlgorithm)

void TGA::close()
{
}
} // namespace tga_prog