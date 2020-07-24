#include "TGA_File.h"

using namespace std;

namespace tga_prog
{
TGA::TGA(const std::string &fg, const std::string &bg)
{
  open_files(fg, bg);
  read_write_headerInfo();
}

void TGA::open_files(const std::string &fg, const std::string &bg)
{
  //must used open() if previously declared
  input1_.open(fg.c_str(), ios::binary | ios::in);
  input2_.open(bg.c_str(), ios::binary | ios::in);
  output_temp_.open(output_temp_filename_, ios::binary | ios::out);

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
  else if (!output_temp_)
  {
    message += output_temp_filename_;
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

  output_temp_.write(&header1_.idLength, sizeof(header1_.idLength));
  output_temp_.write(&header1_.colorMapType, sizeof(header1_.colorMapType));
  output_temp_.write(&header1_.dataTypeCode, sizeof(header1_.dataTypeCode));
  output_temp_.write((char *)&header1_.colorMapOrigin, sizeof(header1_.colorMapOrigin));
  output_temp_.write((char *)&header1_.colorMapLength, sizeof(header1_.colorMapLength));
  output_temp_.write(&header1_.colorMapDepth, sizeof(header1_.colorMapDepth));
  output_temp_.write((char *)&header1_.xOrigin, sizeof(header1_.xOrigin));
  output_temp_.write((char *)&header1_.yOrigin, sizeof(header1_.yOrigin));
  output_temp_.write((char *)&header1_.width, sizeof(header1_.width));
  output_temp_.write((char *)&header1_.height, sizeof(header1_.height));
  output_temp_.write(&header1_.bitsPerPixel, sizeof(header1_.bitsPerPixel));
  output_temp_.write(&header1_.imageDescriptor, sizeof(header1_.imageDescriptor));
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

    output_temp_.write((char *)&new_pixel.red, sizeof(new_pixel.red));
    output_temp_.write((char *)&new_pixel.green, sizeof(new_pixel.green));
    output_temp_.write((char *)&new_pixel.blue, sizeof(new_pixel.blue));
  }
}

void TGA::applyMultiplyBlending()
{
  applyBlending(_multiplyAlgorithm);
}

void TGA::applySubtractionBlending()
{
  applyBlending(_subtractAlgorithm);
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

  int red   = bg.red   - fg.red;
  int green = bg.green - fg.green;
  int blue  = bg.blue  - fg.blue;

  new_pixel.red   = red   < 0 ? 0 : red;
  new_pixel.green = green < 0 ? 0 : green;
  new_pixel.blue  = blue  < 0 ? 0 : blue;

  return new_pixel;
}
void TGA::save(const string &out_file_name)
{
  string err_msg = "Could not open ";
  ofstream out_file(out_file_name.c_str(), ios::binary | ios::out);
  if (!out_file)
    throw std::invalid_argument(err_msg + out_file_name);

  rename(output_temp_filename_.c_str(), out_file_name.c_str());
}

} // namespace tga_prog