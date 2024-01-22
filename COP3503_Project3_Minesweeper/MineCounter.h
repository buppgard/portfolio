#pragma once
#include "GUI.h"
#include "Sprite.h"

class MineCounter {
    Sprite _onesDigit;
    Sprite _tensDigit;
    Sprite _hundredsDigit;
    const unsigned int _digitWidth = 21;

public:
    MineCounter();
    void SetPosition(unsigned int xPosition, unsigned int yPosition);
    void Update(unsigned int mineCount);
    void Draw(GUI& gui, unsigned int mineCount);
};


