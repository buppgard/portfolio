#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;



class Tile {

    const static int _tileWidth = 32;
    const static int _tileHeight = 32;

    unsigned int _xPos;
    unsigned int _yPos;
    bool _isFlagged;
    bool _isBomb;
    bool _isRevealed;
    sf::Sprite _tileSprite;
    vector<Tile*> _adjacentTiles;
    bool _isBlank;
    unsigned int _adjacentMines;


public:
    Tile(unsigned int xPos, unsigned int yPos, bool isBomb = false);
    sf::Sprite& GetSprite();
    bool Contains(int x, int y);
    bool Reveal();
    bool IsRevealed();
    bool IsBlank();
    void DrawTile(sf::RenderWindow& window);
    bool IsMine();
    void AddAdjacentTile(Tile* adjacentTile);
    void PrintCoordinates();
    void Flag();
    bool IsFlagged();
    void PlantMine();



};

