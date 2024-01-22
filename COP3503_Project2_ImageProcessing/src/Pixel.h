#pragma once

#include <fstream>

using namespace std;

class Pixel {
    unsigned char _colorValues[3];

    // Pixel Math
    float multiplyValue(float a, float b) const;
    float invertValue(float a) const;
    float screenValue(float a, float b) const;
    float overlayValue(float a, float b) const;
    unsigned int colorCharToInt(unsigned char color);

public:

    // Constructor
    Pixel();

    // Operators
    bool operator==(const Pixel& rhs) const;
    Pixel& operator-=(const Pixel& rhs);
    Pixel& operator*=(const Pixel& rhs);


    // File Operations
    void LoadPixelData(ifstream& inData);
    void WritePixelData(ofstream& outData);

    // Pixel Manipulations
    void Screen(const Pixel& topPixel);
    void Screen(const Pixel& topPixel, unsigned char color);
    void Overlay(const Pixel& topPixel);
    void Overlay(const Pixel& topPixel, unsigned char color);
    void Multiply(const Pixel& topPixel, unsigned char color);
    void Add(unsigned char amount, unsigned char color);
    void Subtract(const Pixel& topPixel);
    void Subtract(const Pixel& topPixel, unsigned char color);
    void Scale(unsigned int scaleFactor, char color);
    void SingleChannel(char color);
    void Combine(const Pixel& topPixel, char color);

    // Testing Functions
    void Print() const;
};






