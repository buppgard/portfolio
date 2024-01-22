#include "Board.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Random.h"

Board::Board() {
    _debug = false;
    Reset();

    GenerateRandomBoard();

    unsigned int tileHeight = _tiles[0][0].GetHeight();
    unsigned int tileWidth = _tiles[0][0].GetWidth();

    _faceButton.SetPosition(_numCols * tileWidth / 2 - _faceButton.GetWidth() / 2, _numRows * tileHeight);
    _test3Button.SetTexture("test_3");
    _test3Button.SetPosition(_numCols * tileWidth - _test3Button.GetWidth(), _faceButton.GetYPos());
    _test2Button.SetTexture("test_2");
    _test2Button.SetPosition(_test3Button.GetXPos() - _test2Button.GetWidth(), _faceButton.GetYPos());
    _test1Button.SetTexture("test_1");
    _test1Button.SetPosition(_test2Button.GetXPos() - _test1Button.GetWidth(), _faceButton.GetYPos());
    _debugButton.SetTexture("debug");
    _debugButton.SetPosition(_test1Button.GetXPos() - _debugButton.GetWidth(), _faceButton.GetYPos());

    _mineCounter.SetPosition(0, _faceButton.GetYPos());

    _tileBase.SetTexture("tile_revealed");
    _mine.SetTexture("mine");
    _flag.SetTexture("flag");
}

void Board::Draw(GUI& gui) {

    for (unsigned int i = 0; i < _numRows; i++)
        for (unsigned int j = 0; j < _numCols; j++) {
            _tileBase.SetPosition(j * _tileBase.GetWidth(), i * _tileBase.GetHeight());
            gui.Draw(_tileBase);
        }
    for (unsigned int i = 0; i < _numRows; i++)
        for (unsigned int j = 0; j < _numCols; j++) {
            if (!_tiles[i][j].IsBlank())
                gui.Draw(_tiles[i][j]);
        }

    gui.Draw(_faceButton);
    gui.Draw(_debugButton);
    gui.Draw(_test1Button);
    gui.Draw(_test2Button);
    gui.Draw(_test3Button);

    _mineCounter.Draw(gui, _numMines - _numFlags);

    for (unsigned int i = 0; i < _numRows; i++) {
        for (unsigned int j = 0; j < _numCols; j++) {
            if (_tiles[i][j].IsFlagged()) {
                _flag.SetPosition(j * 32, i * 32);
                gui.Draw(_flag);
                if (_tiles[i][j].IsRevealed() && _tiles[i][j].IsMine()) {
                    _mine.SetPosition(j * 32, i * 32);
                    gui.Draw(_mine);
                }
            }
            if (_debug) {
                if (_tiles[i][j].IsMine()) {
                    _mine.SetPosition(j * 32, i * 32);
                    gui.Draw(_mine);
                }
            }
            if (_end) {
                if (_tiles[i][j].IsMine() && _tiles[i][j].IsRevealed()) {
                    _mine.SetPosition(j * 32, i * 32);
                    gui.Draw(_mine);
                }
            }
        }
    }
}

void Board::MouseClick(GUI& gui) {

    unsigned int mousePosX = gui.GetMousePosX();
    unsigned int mousePosY = gui.GetMousePosY();

    if (gui.LeftClick()) {
        if (_faceButton.Contains(mousePosX, mousePosY)) {
            Reset();
            GenerateRandomBoard();
        }
        else if (_debugButton.Contains(mousePosX, mousePosY)) {
            if (!_end)
                _debug = !_debug;
        }
        else if (_test1Button.Contains(mousePosX, mousePosY))
            LoadBoard("testboard1");
        else if (_test2Button.Contains(mousePosX, mousePosY))
            LoadBoard("testboard2");
        else if (_test3Button.Contains(mousePosX, mousePosY))
            LoadBoard("testboard3");
        else if (!_end) {
            for (unsigned int i = 0; i < _numRows; i++) {
                for (unsigned int j = 0; j < _numCols; j++) {
                    if (_tiles[i][j].Contains(mousePosX, mousePosY)) {
                        if (!_tiles[i][j].IsFlagged()) {
                            if (_tiles[i][j].Reveal()) {
                                Loss();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    else if (gui.RightClick()) {
        if (!_end) {
            for (unsigned int i = 0; i < _numRows; i++) {
                for (unsigned int j = 0; j < _numCols; j++) {
                    if (_tiles[i][j].Contains(mousePosX, mousePosY)) {
                        if (!_tiles[i][j].IsRevealed()) {
                            if (_tiles[i][j].IsFlagged())
                                _numFlags--;
                            else
                                _numFlags++;
                            _tiles[i][j].Flag();
                        }

                        else {
                            unsigned int adjacentFlags = _tiles[i][j].NumAdjacentFlags();
                            unsigned int adjacentMines = _tiles[i][j].NumAdjacentMines();
                            if (adjacentFlags == adjacentMines)
                                _tiles[i][j].RevealAdjacentTiles();
                        }
                    }
                }
            }
        }
    }

    if (_numCols * _numRows - NumRevealedTiles() == _numMines)
        Win();
}

unsigned int Board::GetOverallHeight() {
    return _numRows * _tiles[0][0].GetHeight() + _faceButton.GetHeight();
}

unsigned int Board::GetOverallWidth() {
    return _numCols * _tiles[0][0].GetWidth();
}

void Board::LoadConfigFile() {
    ifstream configFile("boards/config.cfg");
    if (configFile.is_open()) {
        string numColumns;
        getline(configFile, numColumns);
        _numCols = stoi(numColumns);

        string numRows;
        getline(configFile, numRows);
        _numRows = stoi(numRows);

        string numMines;
        getline(configFile, numMines);
        _numMines = stoi(numMines);
    }
    configFile.close();
}

void Board::LoadBoard(string filename) {
    Reset();
    filename = "boards/" + filename + ".brd";
    ifstream boardFile(filename);
    string fileLine;
    _numRows = 16; // All Test boards have 16 rows
    _tiles.resize(_numRows);
    for (unsigned int i = 0; i < _numRows; i++) {
        getline(boardFile, fileLine);
        for (unsigned int j = 0; j < _numCols; j++) {
            char temp = fileLine[j];
            bool mineFlag;
            if (temp == '1') {
                mineFlag = true;
                _numMines++;
            }
            else
                mineFlag = false;
            _tiles[i].emplace_back(j, i, mineFlag);
        }
    }
    LoadAdjacentTilesArray();
}

void Board::LoadAdjacentTilesArray() {
    for (int i = 0; i < _numRows; i++)
        for (int j = 0; j < _numCols; j++)
            if(!_tiles[i][j].IsMine())
                for (int k = i - 1; k <= i +1; k++)
                    if (k >= 0 && k < _numRows)
                        for (int m = j - 1; m <= j + 1; m++)
                            if (m >= 0 && m < _numCols)
                                    if (!(k == i && m == j))
                                        _tiles[i][j].AddAdjacentTile(&_tiles.at(k).at(m));
}

void Board::Reset() {
    _end = false;
    _numMines = 0;
    _numFlags = 0;
    _tiles.clear();
    _faceButton.SetTexture("face_happy");
}

void Board::GenerateRandomBoard() {
    LoadConfigFile();
    _tiles.resize(_numRows);
    for (unsigned int i = 0; i < _numRows; i++)
        for (unsigned int j = 0; j < _numCols; j++)
            _tiles[i].emplace_back(j, i, false);

    int minesPlanted = 0;
    while (minesPlanted < _numMines) {
        unsigned int randX = Random::Int(0, static_cast<int>(_numCols) - 1);
        unsigned int randY = Random::Int(0, static_cast<int>(_numRows) - 1);
        if (!_tiles[randY][randX].IsMine()) {
            _tiles[randY][randX].PlantMine();
            minesPlanted++;
        }
    }
    LoadAdjacentTilesArray();
}

void Board::Loss() {
    _faceButton.SetTexture("face_lose");
    for (int i = 0; i < _numRows; i++) {
        for (int j = 0; j < _numCols; j++) {
            if (_tiles[i][j].IsMine()) {
                _tiles[i][j].Reveal();
            }
        }
    }
    _end = true;
}

void Board::Win() {
    _faceButton.SetTexture("face_win");
    for (int i = 0; i < _numRows; i++) {
        for (int j = 0; j < _numCols; j++) {
            if (_tiles[i][j].IsMine() && !_tiles[i][j].IsFlagged()) {
                _tiles[i][j].Flag();
                _numFlags++;
            }
        }
    }
    _end = true;
}

unsigned int Board::NumRevealedTiles() {
    unsigned int RevealedTileCount = 0;
    for (unsigned int i = 0; i < _numRows; i++) {
        for (unsigned int j = 0; j < _numCols; j++) {
            if (_tiles[i][j].IsRevealed())
                RevealedTileCount++;
        }
    }
    return RevealedTileCount;
}




