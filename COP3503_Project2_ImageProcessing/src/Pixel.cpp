#include <iostream>
#include <cmath>
#include "Pixel.h"

using namespace std;

// Pixel Math
float Pixel::multiplyValue(float a, float b) const {
    return a * b / 255;
}

float Pixel::invertValue(float a) const {
    return 255 - a;
}

float Pixel::screenValue(float a, float b) const {
    a = invertValue(a);
    b = invertValue(b);
    a = multiplyValue(a, b);
    a = invertValue(a);
    return a;
}

float Pixel::overlayValue(float a, float b) const {
    if (a < 128) {
        a = 2 * multiplyValue(a, b);
    }
    else {
        a = invertValue(a);
        b = invertValue(b);
        a = 2 * multiplyValue(a, b);
        a = invertValue(a);
    }
    return a;
}

unsigned int Pixel::colorCharToInt(unsigned char color) {
    if (color < 3)
        return color;
    else if (color == 'R')
        return 2;
    else if (color == 'G')
        return 1;
    else if (color == 'B')
        return 0;
    else
        throw runtime_error(R"(Invalid color char. 'R' or 2 for red. 'G' or 1 for green.'B' or 0 for Blue.)");
}


// Constructor
Pixel::Pixel() {
    for (unsigned int i = 0; i <3; i++)
        _colorValues[i] = 0;
}


// Operators
bool Pixel::operator==(const Pixel &rhs) const {
    for (unsigned int i = 0; i < 3; i++) {
        if (_colorValues[i] != rhs._colorValues[i])
            return false;
    }
    return true;
}

Pixel& Pixel::operator-=(const Pixel &rhs) {
    Subtract(rhs);
    return *this;
}

Pixel& Pixel::operator*=(const Pixel &rhs) {
    for (unsigned int i = 0; i <3; i++)
        Multiply(rhs, i);
    return *this;
}


// File Operations
void Pixel::LoadPixelData(ifstream& inData) {
    for (unsigned int i = 0; i < 3; i++)
        _colorValues[i] = inData.get();
}

void Pixel::WritePixelData(ofstream& outData) {
    for (unsigned int i = 0; i < 3; i++)
        outData.put(_colorValues[i]);
}

// Pixel Manipulations
void Pixel::Screen(const Pixel &topPixel) {
    for (unsigned int i = 0; i < 3; i++)
        Screen(topPixel, i);
}

void Pixel::Screen(const Pixel& topPixel, unsigned char color) {
    unsigned int i = colorCharToInt(color);
    float temp = screenValue(_colorValues[i], topPixel._colorValues[i]);
    _colorValues[i] = static_cast<unsigned char>(round(temp));
}

void Pixel::Overlay(const Pixel &topPixel) {
    for (unsigned int i = 0; i < 3; i++)
        Overlay(topPixel, i);
}

void Pixel::Overlay(const Pixel& topPixel, unsigned char color) {
    unsigned int i = colorCharToInt(color);
    float temp = overlayValue(_colorValues[i], topPixel._colorValues[i]);
    _colorValues[i] = static_cast<unsigned char>(round(temp));
}

void Pixel::Multiply(const Pixel& topPixel, unsigned char color) {
    unsigned int i = colorCharToInt(color);
    float temp = multiplyValue(_colorValues[i], topPixel._colorValues[i]);
    _colorValues[i] = static_cast<char>(round(temp));
}

void Pixel::Add(unsigned char amount, unsigned char color) {
    unsigned int i = colorCharToInt(color);
    if (amount > 255 - _colorValues[i])
        _colorValues[i] = 255;
    else
        _colorValues[i] += amount;
}

void Pixel::Subtract(const Pixel &topPixel) {
    for (unsigned int i = 0; i < 3; i++)
        Subtract(topPixel, i);
}

void Pixel::Subtract(const Pixel &topPixel, unsigned char color) {
    unsigned int i = colorCharToInt(color);
    if (topPixel._colorValues[i] >= _colorValues[i])
        _colorValues[i] = 0;
    else
        _colorValues[i] -= topPixel._colorValues[i];
}

void Pixel::Scale(unsigned int scaleFactor, char color) {
    unsigned int i = colorCharToInt(color);
    unsigned int temp = _colorValues[i];
    temp *= scaleFactor;
    if (temp > 255) {
        temp = 255;
    }
    _colorValues[i] = static_cast<unsigned char>(temp);
}

void Pixel::SingleChannel(char color) {
    unsigned int colorChannel = colorCharToInt(color);
    unsigned char channelVal = _colorValues[colorChannel];
    for (unsigned int i = 0; i <3; i++) {
        _colorValues[i] = channelVal;
    }
}

void Pixel::Combine(const Pixel& topPixel, char color) {
    unsigned int i = colorCharToInt(color);
    _colorValues[i] = topPixel._colorValues[i];
}


// Test Functions
void Pixel::Print() const {
    cout << "(" << static_cast<int>(_colorValues[2]) << ", " << static_cast<int>(_colorValues[1]) << ", " << static_cast<int>(_colorValues[0]) << ")";
}



