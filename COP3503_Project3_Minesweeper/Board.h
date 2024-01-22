#pragma once
#include <vector>
#include "Tile.h"
#include "MineCounter.h"
#include "Sprite.h"
#include "GUI.h"
using namespace std;

class Board {
    unsigned int _numCols;
    unsigned int _numRows;
    int _numMines;
    int _numFlags;
    vector<vector<Tile>> _tiles;
    Sprite _faceButton;
    Sprite _debugButton;
    Sprite _test1Button;
    Sprite _test2Button;
    Sprite _test3Button;
    Sprite _mine;
    Sprite _flag;
    Sprite _tileBase;
    MineCounter _mineCounter;
    bool _debug;
    bool _end;

public:

    Board();
    void Draw(GUI& gui);
    void MouseClick(GUI& gui);
    unsigned int GetOverallHeight();
    unsigned int GetOverallWidth();


private:

    void LoadConfigFile();
    void LoadBoard(string fileName);
    void LoadAdjacentTilesArray();
    void Reset();
    void GenerateRandomBoard();
    void Loss();
    void Win();
    unsigned int NumRevealedTiles();

};


