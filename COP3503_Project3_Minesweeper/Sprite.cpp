#include "Sprite.h"
#include "TextureManager.h"
using namespace std;

Sprite::Sprite() {
    _xPos = 0;
    _yPos = 0;
    _width = 0;
    _height = 0;
}

void Sprite::SetTexture(string textureName) {
    _sprite.setTexture(TextureManager::GetTexture(textureName));
    _width = _sprite.getLocalBounds().getSize().x;
    _height = _sprite.getLocalBounds().getSize().y;
}

void Sprite::SetPosition(unsigned int xPos, unsigned int yPos) {
    _xPos = xPos;
    _yPos = yPos;
    _sprite.setPosition(_xPos, _yPos);
}

unsigned int Sprite::GetWidth() {
    return _width;
}

unsigned int Sprite::GetHeight() {
    return _height;
}

sf::Sprite& Sprite::GetSFSprite() {
    return _sprite;
}

unsigned int Sprite::GetXPos() {
    return _xPos;
}

unsigned int Sprite::GetYPos() {
    return _yPos;
}

bool Sprite::Contains(unsigned int xPos, unsigned int yPos) {
    if (_sprite.getGlobalBounds().contains(xPos, yPos))
        return true;
    return false;
}

void Sprite::MaskTexture(unsigned int xPos, unsigned int yPos, unsigned int maskWidth, unsigned int maskHeight) {
    _sprite.setTextureRect(sf::IntRect(xPos, yPos, maskWidth, maskHeight));
}