#include "Tile.h"
#include "TextureManager.h"
#include <string>
#include <iostream>
using namespace std;



Tile::Tile(unsigned int xPos, unsigned int yPos, bool isBomb) {
    _xPos = xPos * _tileWidth;
    _yPos = yPos * _tileHeight;
    _isRevealed = false;
    _isFlagged = false;
    _isBomb = isBomb;
    _tileSprite.setTexture(TextureManager::GetTexture("tile_hidden"));
    _tileSprite.setPosition(_xPos, _yPos);
}



sf::Sprite& Tile::GetSprite() {
    return _tileSprite;
}


bool Tile::Contains(int x, int y) {
    if (_tileSprite.getGlobalBounds().contains(x, y))
        return true;
    return false;
}

bool Tile::Reveal() {
    _isRevealed = true;
    if (_isBomb) {
        _tileSprite.setTexture(TextureManager::GetTexture("mine"));
        return true;
    }

    else {
        int adjMines = 0;
        for (unsigned int i = 0; i < _adjacentTiles.size(); i ++) {
            if (_adjacentTiles[i]->_isBomb) {
                adjMines++;
            }
        }
        if (adjMines > 0) {
            string fileName = "number_";
            fileName.append(to_string(adjMines));
            _tileSprite.setTexture(TextureManager::GetTexture(fileName));
        }
        else {
            _isBlank = true;
            for (unsigned int i = 0; i < _adjacentTiles.size(); i++) {
                if(!_adjacentTiles[i]->_isRevealed)
                    _adjacentTiles[i]->Reveal();
            }
        }
    }
    return false;
}

bool Tile::IsRevealed() {
    if (_isRevealed)
        return true;
    return false;
}

bool Tile::IsMine() {
    return _isBomb;
}

void Tile::AddAdjacentTile(Tile* adjacentTile) {
    _adjacentTiles.push_back(adjacentTile);
}

void Tile::PrintCoordinates() {
    cout << "(" << _xPos/32 << ", " << _yPos/32 << ")" << endl;
}

bool Tile::IsBlank() {
    return _isBlank;
}

void Tile::Flag() {
    _isFlagged = !_isFlagged;
}

bool Tile::IsFlagged() {
    return _isFlagged;
}

void Tile::PlantMine() {
    _isBomb = true;
}





