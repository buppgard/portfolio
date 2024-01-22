#include "MineCounter.h"
using namespace std;

MineCounter::MineCounter() {
    _hundredsDigit.SetTexture("digits");
    _tensDigit.SetTexture("digits");
    _onesDigit.SetTexture("digits");
}

void MineCounter::SetPosition(unsigned int xPosition, unsigned int yPosition) {
    _hundredsDigit.SetPosition(xPosition + _digitWidth, yPosition);
    _tensDigit.SetPosition(_hundredsDigit.GetXPos() + _digitWidth, yPosition);
    _onesDigit.SetPosition(_tensDigit.GetXPos() + _digitWidth, yPosition);
}

void MineCounter::Update(unsigned int mineCount) {
    bool negative = false;
    if (mineCount < 0) {
        negative = true;
        mineCount *= -1;
    }
        int ones = mineCount % 10;
        mineCount /= 10;
        int tens = mineCount % 10;
        mineCount /= 10;
        int hundreds = mineCount % 10;

        if (negative) {
            _hundredsDigit.MaskTexture(_digitWidth * 10, 0, _digitWidth, _hundredsDigit.GetHeight());
        } else {
            _hundredsDigit.MaskTexture(hundreds * _digitWidth, 0, _digitWidth, _hundredsDigit.GetHeight());
        }
        _tensDigit.MaskTexture(tens * _digitWidth, 0, _digitWidth, _hundredsDigit.GetHeight());
        _onesDigit.MaskTexture(ones * _digitWidth, 0, _digitWidth, _hundredsDigit.GetHeight());
}


void MineCounter::Draw(GUI& gui, unsigned int mineCount) {
    Update(mineCount);
    gui.Draw(_hundredsDigit);
    gui.Draw(_tensDigit);
    gui.Draw(_onesDigit);
}



