#pragma once
#include <vector>
#include "Sprite.h"
using namespace std;

class Tile : public Sprite {

    bool _isFlagged;
    bool _isMine;
    bool _isRevealed;
    bool _isBlank;
    vector<Tile*> _adjacentTiles;

public:
    Tile(unsigned int xPos, unsigned int yPos, bool isBomb = false);

    void Flag();
    void PlantMine();
    void AddAdjacentTile(Tile* adjacentTile);

    bool IsFlagged();
    bool IsMine();
    bool IsRevealed();
    bool IsBlank();
    unsigned int NumAdjacentFlags();
    unsigned int NumAdjacentMines();

    bool Reveal();
    void RevealAdjacentTiles();
};

