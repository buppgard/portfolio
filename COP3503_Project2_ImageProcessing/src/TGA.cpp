#include <iostream>
#include <fstream>
#include <stdexcept>
#include "TGA.h"

using namespace std;

// Construction, Destruction
TGA::TGA() {
    _header._idLength = 0;
    _header._colorMapType = 0;
    _header._dataTypeCode = 0;
    _header._colorMapOrigin = 0;
    _header._colorMapLength = 0;
    _header._colorMapDepth = 0;
    _header._xOrigin = 0;
    _header._yOrigin = 0;
    _header._width = 0;
    _header._height = 0;
    _header._bitsPerPixel = 0;
    _header._imageDescriptor = 0;
    _numPixels = 0;
}

TGA::TGA(string filepath) {
    try {
        if (!LoadTGA(filepath)) {
            throw runtime_error("TGA instantiation failed.");
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

TGA::TGA(const TGA& sourceTGA) {
    _header = sourceTGA._header;
    _numPixels = sourceTGA._numPixels;
    _imageData = new Pixel[_numPixels];
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i] = sourceTGA._imageData[i];
    }
}

TGA::~TGA() {
    delete[] _imageData;
}


// Operators
TGA& TGA::operator=(const TGA& sourceTGA) {
    if (this == &sourceTGA)
        return *this;
    delete[] _imageData;
    _header = sourceTGA._header;
    _numPixels = sourceTGA._numPixels;
    _imageData = new Pixel[_numPixels];
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i] = sourceTGA._imageData[i];
    }
    return *this;
}

TGA TGA::operator*(const TGA& rhs) const {
    TGA output = *this;
    output.Multiply(rhs);
    return output;
}

TGA& TGA::operator*=(const TGA &rhs) {
    Multiply(rhs);
    return *this;
}

TGA TGA::operator-(const TGA &rhs) const {
    TGA output = *this;
    output.Subtract(rhs);
    return output;
}

TGA& TGA::operator-=(const TGA &rhs) {
    Subtract(rhs);
    return *this;
}


// File Operations
bool TGA::LoadTGA(string filepath) {

    if (_imageData != nullptr)
        delete[] _imageData;

    ifstream inData(filepath, ios_base::binary);

    if (inData.is_open()) {

        inData.read(&_header._idLength, sizeof(_header._idLength));
        inData.read(&_header._colorMapType, sizeof(_header._colorMapType));
        inData.read(&_header._dataTypeCode, sizeof(_header._dataTypeCode));
        inData.read(reinterpret_cast<char *>(&_header._colorMapOrigin), sizeof(_header._colorMapOrigin));
        inData.read(reinterpret_cast<char *>(&_header._colorMapLength), sizeof(_header._colorMapLength));
        inData.read(&_header._colorMapDepth, sizeof(_header._colorMapDepth));
        inData.read(reinterpret_cast<char *>(&_header._xOrigin), sizeof(_header._xOrigin));
        inData.read(reinterpret_cast<char *>(&_header._yOrigin), sizeof(_header._yOrigin));
        inData.read(reinterpret_cast<char *>(&_header._width), sizeof(_header._width));
        inData.read(reinterpret_cast<char *>(&_header._height), sizeof(_header._height));
        inData.read(&_header._bitsPerPixel, sizeof(_header._bitsPerPixel));
        inData.read(&_header._imageDescriptor, sizeof(_header._imageDescriptor));

        _numPixels = _header._width * _header._height;
        _imageData = new Pixel[_numPixels];
        for (unsigned int i = 0; i < _numPixels; i++) {
            _imageData[i].LoadPixelData(inData);
        }
        return true;
    }
    else {
        cout << "Could not load image data. Failed to open file." << endl;
        return false;
    }
}

void TGA::WriteTGA(string filepath) {

    ofstream outputFile(filepath);
    outputFile.write(&_header._idLength, sizeof(_header._idLength));
    outputFile.write(&_header._colorMapType, sizeof(_header._colorMapType));
    outputFile.write(&_header._dataTypeCode, sizeof(_header._dataTypeCode));
    outputFile.write(reinterpret_cast<char*>(&_header._colorMapOrigin), sizeof(_header._colorMapOrigin));
    outputFile.write(reinterpret_cast<char*>(&_header._colorMapLength), sizeof(_header._colorMapLength));
    outputFile.write(&_header._colorMapDepth, sizeof(_header._colorMapDepth));
    outputFile.write(reinterpret_cast<char*>(&_header._xOrigin), sizeof(_header._xOrigin));
    outputFile.write(reinterpret_cast<char*>(&_header._yOrigin), sizeof(_header._yOrigin));
    outputFile.write(reinterpret_cast<char*>(&_header._width), sizeof(_header._width));
    outputFile.write(reinterpret_cast<char*>(&_header._height), sizeof(_header._height));
    outputFile.write(&_header._bitsPerPixel, sizeof(_header._bitsPerPixel));
    outputFile.write(&_header._imageDescriptor, sizeof(_header._imageDescriptor));

    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i].WritePixelData(outputFile);
    }
    outputFile.close();
}


// Image Processing
void TGA::Multiply(const TGA &topLayer) {
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i] *= topLayer._imageData[i];
    }
}

void TGA::Subtract(const TGA &topLayer) {
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i] -= topLayer._imageData[i];
    }
}

void TGA::Screen(const TGA &topLayer) {
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i].Screen(topLayer._imageData[i]);
    }
}

void TGA::Overlay(const TGA& topLayer) {
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i].Overlay(topLayer._imageData[i]);
    }
}

void TGA::AddColor(char color, unsigned char amount) {
    try {
        for (unsigned int i = 0; i < _numPixels; i++) {
            _imageData[i].Add(amount, color);
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

void TGA::ScaleColor(char color, unsigned int scaleFactor) {
    try {
        for (unsigned int i = 0; i < _numPixels; i++) {
            _imageData[i].Scale(scaleFactor, color);
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

void TGA::SingleChannel(char color) {
    try {
        for (unsigned int i = 0; i < _numPixels; i++) {
            _imageData[i].SingleChannel(color);
        }
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

void TGA::Combine(char color, const TGA& topLayer) {
    for (unsigned int i = 0; i < _numPixels; i++) {
        _imageData[i].Combine(topLayer._imageData[i], color);
    }
}

void TGA::Rotate180() {
    Pixel* outputImage = new Pixel[_numPixels];
    for (unsigned int i = 0; i < _numPixels; i++) {
        outputImage[i] = _imageData[(_numPixels - 1) - i];
    }
    delete[] _imageData;
    _imageData = outputImage;
}

void TGA::Collage(const TGA& lowerLeft, const TGA &lowerRight, const TGA &upperLeft, const TGA &upperRight) {
    if (upperLeft._header._width != upperRight._header._width ||
            upperLeft._header._width != lowerLeft._header._width ||
            upperLeft._header._width != lowerRight._header._width) {
        if (upperLeft._header._height != upperRight._header._height||
            upperLeft._header._height != lowerLeft._header._height||
            upperLeft._header._height != lowerRight._header._height) {
            cout << "All images are not the same size. Could not create collage." << endl;
            return;
        }
    }

    int width = upperLeft._header._width;
    int height = upperLeft._header._height;

    _header = upperLeft._header;
    _header._width = static_cast<short>(width * 2);
    _header._height = static_cast<short>(height * 2);
    _numPixels = _header._width * _header._height;

    if (_imageData != nullptr)
        delete[] _imageData;

    _imageData = new Pixel[_numPixels];

    for (unsigned int i = 0; i < height; i++) {
        int sourceRowStart = i * width;
        int outputBottomRowStart = sourceRowStart * 2;
        int outputTopRowStart = outputBottomRowStart + width * height * 2;
        for (unsigned int j = 0; j < width; j++) {
            _imageData[j % width + outputBottomRowStart] = lowerLeft._imageData[j + sourceRowStart];
        }
        for (unsigned int j = 0; j < width; j++) {
            _imageData[j % width + width + outputBottomRowStart] = lowerRight._imageData[j + sourceRowStart];
        }
        for (unsigned int j = 0; j < width; j++) {
            _imageData[j % width + outputTopRowStart] = upperLeft._imageData[j + sourceRowStart];
        }
        for (unsigned int j = 0; j < width; j++) {
            _imageData[j % width + width + outputTopRowStart] = upperRight._imageData[j + sourceRowStart];
        }
    }
}


// Test Functions
void TGA::PrintFirstPixels() {
    for (unsigned int i = 0; i < 10; i++) {
        _imageData[i].Print();
        cout << " ";
    }
    cout << endl;
}

void TGA::PrintDifference(TGA& compareImage) {
    for (unsigned int i = 0; i < _header._width * _header._height; i++) {
        if (not(_imageData[i] == compareImage._imageData[i])) {
            cout << "The pixels do not match :-( " << endl;
            cout << "Image one: ";
            _imageData[i].Print();
            cout << endl;
            cout << "Image two: ";
            compareImage._imageData[i].Print();
            cout << endl;
        }
    }
}
