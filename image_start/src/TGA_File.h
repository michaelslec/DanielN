#include <iostream>
#include <string>
#include <fstream>
#include <functional>

namespace tga_prog
{
struct Header
{
  char idLength = 0; // 1 byte
  char colorMapType = 0;
  char dataTypeCode = 0;
  short colorMapOrigin = 0; // 2 bytes
  short colorMapLength = 0;
  char colorMapDepth = 0;
  short xOrigin = 0;
  short yOrigin = 0;
  short width = 0;
  short height = 0;
  char bitsPerPixel = 0;
  char imageDescriptor = 0;
}; // 18 bytes total

struct Pixel
{
  uint8_t red = 0;
  uint8_t green = 0;
  uint8_t blue = 0;
};

class TGA
{
public:
  TGA(const std::string &in1, const std::string &in2);
  ~TGA() {
    input1_.close();
    input2_.close();
    output_temp_.close();
    remove(output_temp_filename_.c_str());
  };

  void applyMultiplyBlending();
  void applySubtractionBlending();
  void save(const std::string& out_file_name);

private:
  void open_files(const std::string &fg, const std::string &bg);
  void read_write_headerInfo();
  void applyBlending(std::function<Pixel(const Pixel&, const Pixel&)> algorithm);

  static Pixel _multiplyAlgorithm(const Pixel &, const Pixel &);
  static Pixel _subtractAlgorithm(const Pixel &, const Pixel &);

private:
  Header header1_; //!< header information of the file
  const std::string output_temp_filename_ = "output/__temp.tga";

  std::ifstream input1_;
  std::ifstream input2_;
  std::ofstream output_temp_;
};
} // namespace tga_prog