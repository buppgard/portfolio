#pragma once
#include "Pixel.h"

using namespace std;

class TGA {

    struct Header {
        char _idLength;
        char _colorMapType;
        char _dataTypeCode;
        short _colorMapOrigin;
        short _colorMapLength;
        char _colorMapDepth;
        short _xOrigin;
        short _yOrigin;
        short _width;
        short _height;
        char _bitsPerPixel;
        char _imageDescriptor;
    };

    Header _header;
    unsigned int _numPixels;
    Pixel* _imageData = nullptr;


public:

    // Construction, Destruction
    TGA();
    TGA(string filepath);
    TGA(const TGA& sourceTGA);
    ~TGA();

    // Operators
    TGA& operator=(const TGA& sourceTGA);
    TGA operator*(const TGA& rhs) const;
    TGA& operator*=(const TGA& rhs);
    TGA operator-(const TGA& rhs) const;
    TGA& operator-=(const TGA& rhs);

    // File Operations
    bool LoadTGA(string filepath);
    void WriteTGA(string filepath);

    // Image Processing
    void Multiply(const TGA& topLayer);
    void Subtract(const TGA& topLayer);
    void Screen(const TGA& topLayer);
    void Overlay(const TGA& topLayer);
    void AddColor(char color, unsigned char amount);
    void ScaleColor(char color, unsigned int scaleFactor);
    void SingleChannel(char color);
    void Combine(char color, const TGA& topLayer);
    void Rotate180();
    void Collage(const TGA& lowerLeft, const TGA& lowerRight, const TGA& upperLeft, const TGA& upperRight);

    // Test Functions
    void PrintFirstPixels();
    void PrintDifference(TGA& image2);

};
