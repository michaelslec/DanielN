#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

struct GameSaveHeader {
    char game_mode;
    int x_coord;
    int y_coord;
};

struct GameSaveBlock {
    int x_coord; // 4 bytes
    int y_coord; // 4 bytes
    char width; // 1 byte
    char height; // 1 bute
};

void generateRandomGameSaveData(char game_mode, int x, int y) {
    ofstream gameSave("testing.sav", ios::binary | ios::out);
    if (!gameSave) {
        cerr << "Could not open testin.sav";
        exit(1); // abnormal return
    }

    GameSaveHeader new_game = {game_mode, x, y};
    gameSave.write(&new_game.game_mode, sizeof(new_game.game_mode));
    gameSave.write((char*)&new_game.x_coord, sizeof(new_game.x_coord));
    gameSave.write((char*)&new_game.y_coord, sizeof(new_game.y_coord));

    srand(time(NULL));
    for (size_t i = 0; i < 1000; ++i) {
        GameSaveBlock temp = {rand() % 1000, rand() % 1000, rand() % 127, 
            rand() % 127};

        gameSave.write((char*)&temp.x_coord, sizeof(temp.x_coord));
        gameSave.write((char*)&temp.y_coord, sizeof(temp.y_coord));
        gameSave.write(&temp.width, sizeof(temp.width));
        gameSave.write(&temp.height, sizeof(temp.height));
    }
}

void printBlock(const GameSaveBlock& block) {
    cout << "---BLOCK---" << endl;
    cout << "X: " << block.x_coord << ", Y: " << block.y_coord << endl;
    cout << "Width: " << (int)block.width << ", Height: " 
        << (int)block.height << endl;
    cout << endl;
}

int main() 
{
    generateRandomGameSaveData(0, 113141, 11123);

    ifstream inFile("testing.sav", ios::binary | ios::in);
    if (!inFile) {
        cerr << "Could not open file testing.sav" << endl;
        return 1;
    }

    GameSaveHeader header;
    inFile.read(&header.game_mode,      sizeof(header.game_mode));
    inFile.read((char*)&header.x_coord, sizeof(header.x_coord));
    inFile.read((char*)&header.y_coord, sizeof(header.y_coord));

    if ((int)header.game_mode == 1) {
        cout << "Game mode: CREATIVE!" << endl;
    } else {
        cout << "Game mode: SURVIVAL!" << endl;
    }

    cout << "Player Coords: " << header.x_coord << ", " << header.y_coord << endl;
    cout << endl;

    bool end_file = false;
    while (!end_file) {
        GameSaveBlock temp;
        inFile.read((char*)&temp.x_coord, sizeof(temp.x_coord));
        inFile.read((char*)&temp.y_coord, sizeof(temp.y_coord));
        inFile.read(&temp.width, sizeof(temp.width));
        inFile.read(&temp.height, sizeof(temp.height));
        printBlock(temp);

        if (!inFile) end_file = true;
    }

    return 0;
}
