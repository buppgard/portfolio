#include "Tile.h"
#include <string>
using namespace std;

Tile::Tile(unsigned int xPos, unsigned int yPos, bool isBomb) {
    SetTexture("tile_hidden");
    SetPosition(xPos * GetWidth(), yPos * GetHeight());
    _isRevealed = false;
    _isFlagged = false;
    _isBlank = false;
    _isMine = isBomb;
}

void Tile::Flag() {
    _isFlagged = !_isFlagged;
}

void Tile::PlantMine() {
    _isMine = true;
}

void Tile::AddAdjacentTile(Tile* adjacentTile) {
    _adjacentTiles.push_back(adjacentTile);
}

bool Tile::IsFlagged() {
    return _isFlagged;
}

bool Tile::IsMine() {
    return _isMine;
}

bool Tile::IsRevealed() {
    return _isRevealed;
}

bool Tile::IsBlank() {
    return _isBlank;
}

unsigned int Tile::NumAdjacentFlags() {
    unsigned int adjacentFlagCount = 0;
    for (unsigned int i = 0; i < _adjacentTiles.size(); i++) {
        if (_adjacentTiles[i]->_isFlagged)
            adjacentFlagCount++;
    }
    return adjacentFlagCount;
}

unsigned int Tile::NumAdjacentMines() {
    unsigned int adjacentMineCount = 0;
    for (unsigned int i = 0; i < _adjacentTiles.size(); i++) {
        if (_adjacentTiles[i]->_isMine)
            adjacentMineCount++;
    }
    return adjacentMineCount;
}

bool Tile::Reveal() {
    _isRevealed = true;
    if (_isMine) {
        _isBlank = true;
        return true;
    }
    else {
        unsigned int adjMines = NumAdjacentMines();
        if (adjMines > 0) {
            string fileName = "number_";
            fileName.append(to_string(adjMines));
            SetTexture(fileName);
        }
        else {
            _isBlank = true;
            for (unsigned int i = 0; i < _adjacentTiles.size(); i++) {
                if(!_adjacentTiles[i]->_isRevealed && !_adjacentTiles[i]->_isFlagged)
                    _adjacentTiles[i]->Reveal();
            }
        }
    }
    return false;
}

void Tile::RevealAdjacentTiles() {
    for (unsigned int i = 0; i < _adjacentTiles.size(); i++) {
        if (!_adjacentTiles[i]->IsFlagged())
            _adjacentTiles[i]->Reveal();
    }
}








