#include <iostream>
#include <string>
#include <fstream>
#include <stack>
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
    TGA(){};
    TGA(const std::string &in1, const std::string &in2, const std::string &out);
    ~TGA() { close(); };

    void setup(const std::string &fg, const std::string &bg, const std::string out_file);
    void applyMultiplyBlending();
    void applySubtractBlending();

  private:
    Pixel _multiplyAlgorithm(const Pixel &, const Pixel &);
    Pixel _subtractAlgorithm(const Pixel &, const Pixel &);
    //open input files
    void open_files(const std::string &fg, const std::string &bg, const std::string out_file);
    // read header
    void read_write_headerInfo();
    // close files
    void close();

  private:
    Header header1_; //!< header information of the file

    std::ifstream input1_;
    std::ifstream input2_;
    std::ofstream output_;
  };
} // namespace tga_prog