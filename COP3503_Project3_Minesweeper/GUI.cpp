#include "GUI.h"
#include <string>
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

using namespace std;

GUI::GUI(unsigned int width, unsigned int height, std::string name) {
    _window.create(sf::VideoMode(width, height), name);
}

bool GUI::IsOpen() {
    if (_window.isOpen())
        return true;
    return false;
}

bool GUI::Event() {
    return _window.pollEvent(_event);
}

bool GUI::EventCloseWindow() {
    if (_event.type == sf::Event::Closed)
        return true;
    return false;
}

bool GUI::EventMouseClick() {
    if (_event.type == sf::Event::MouseButtonPressed) {
        auto clickLocation = sf::Mouse::getPosition(_window);
        _mousePosX = clickLocation.x;
        _mousePosY = clickLocation.y;
        _mouseButtonLeft = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        _mouseButtonRight = sf::Mouse::isButtonPressed(sf::Mouse::Right);
        return true;
    }
    return false;
}

bool GUI::LeftClick() {
    if (_mouseButtonLeft)
        return true;
    return false;
}

bool GUI::RightClick() {
    if (_mouseButtonRight)
        return true;
    return false;
}

unsigned int GUI::GetMousePosX() {
    return _mousePosX;
}

unsigned int GUI::GetMousePosY() {
    return _mousePosY;
}

void GUI::Draw(Sprite& sprite) {
    _window.draw(sprite.GetSFSprite());
}

void GUI::Clear() {
    _window.clear();
}

void GUI::Display() {
    _window.display();
}

void GUI::Close() {
    _window.close();
    TextureManager::Clear();
}