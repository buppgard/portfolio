#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "Sprite.h"
using namespace std;

class GUI {
    sf::RenderWindow _window;
    sf::Event _event;
    unsigned int _mousePosX;
    unsigned int _mousePosY;
    bool _mouseButtonLeft;
    bool _mouseButtonRight;

public:

    GUI(unsigned int width, unsigned int height, string name);

    bool IsOpen();
    bool Event();
    bool EventCloseWindow();
    bool EventMouseClick();

    bool LeftClick();
    bool RightClick();
    unsigned int GetMousePosX();
    unsigned int GetMousePosY();

    void Draw(Sprite& sprite);
    void Clear();
    void Display();
    void Close();
};


