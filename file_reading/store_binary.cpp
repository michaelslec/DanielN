#include <iostream>
#include <fstream>

using namespace std;

struct RGBTriple {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

int main()
{
    // first byte - game mode
    // x coords
    // y coord
    // 4 byte chunk
    //  - width height
    RGBTriple pixel = {22, 82, 43};

    ofstream outFile("storage", ios::binary | ios::out);
    if (!outFile) {
        cerr << "Could not open storage" << endl;
        return 1;
    }

    outFile.write(reinterpret_cast<char*>(&pixel.red), 1);
    outFile.write(reinterpret_cast<char*>(&pixel.green), 1);
    outFile.write(reinterpret_cast<char*>(&pixel.blue), 1);

    outFile.close();

    fstream inFile("storage", ios::binary | ios::in);
    if (!inFile) {
        cerr << "Could not open storage" << endl;
        return 1;
    }

    RGBTriple new_pixel;
    inFile.read(reinterpret_cast<char*>(&new_pixel.red), 1);
    inFile.read(reinterpret_cast<char*>(&new_pixel.green), 1);
    inFile.read(reinterpret_cast<char*>(&new_pixel.blue), 1);

    cout << (int)new_pixel.red << endl;

    inFile.close();

    return 0;
}
