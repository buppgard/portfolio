#pragma once
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;

class Sprite {

    sf::Sprite _sprite;
    unsigned int _xPos;
    unsigned int _yPos;
    unsigned int _width;
    unsigned int _height;

public:

    Sprite();

    void SetTexture(string textureName);
    void SetPosition(unsigned int xPos, unsigned int yPos);

    unsigned int GetWidth();
    unsigned int GetHeight();
    unsigned int GetXPos();
    unsigned int GetYPos();
    sf::Sprite& GetSFSprite();

    bool Contains(unsigned int xPos, unsigned int yPos);

    void MaskTexture(unsigned int xPos, unsigned int yPos, unsigned int maskWidth, unsigned int maskHeight);

};



