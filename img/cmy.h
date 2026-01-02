// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef IMG_CMY_H
#define IMG_CMY_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace img {

class RGB;

class CMY {         // subtractive colour model
    float cyan;
    float magenta;
    float yellow;
    float key;      // % - black colour channel
public:
    // Constructors
    CMY();
    CMY(const float cyan);
    CMY(const float cyan, const float magenta);
    CMY(const float cyan, const float magenta, const float yellow);
    CMY(const float cyan, const float magenta, const float yellow, const float key);

    // Destructors
    ~CMY();

    // Operator overloading
    bool operator==(const CMY& peer) const;
    CMY operator+(const CMY& peer) const;
    CMY operator-(const CMY& peer) const;
    CMY operator*(const CMY& peer) const;
    CMY operator/(const CMY& peer) const;
    CMY operator%(const CMY& peer) const;

    // Getters
    float getCyan() const { return cyan; }
    float getMagenta() const { return magenta; }
    float getYellow() const { return yellow; }
    float getKey() const { return key; }

    // Setters
    void setCyan(const float value) { this->cyan = getIndexed(value); }
    void setMagenta(const float value) { this->magenta = getIndexed(value); }
    void setYellow(const float value) { this->yellow = getIndexed(value); }
    void setKey(const float value) { this->key = getIndexed(value); }

    // Additional methods
    CMY getBlackColour() const;
    CMY getWhiteColour() const;
    virtual CMY copy();
    virtual void clear();
    virtual std::string toByte();
    virtual std::string toDecimal();
    virtual std::string toHex();
    virtual std::string print();
public:
    static const RGB getModel(const CMY& colour);
private:
    static const float getWhiteness(const CMY& colour);
    static const float getBlackness(const CMY& colour);
    static const short int getByteIndex(const short int value);
    static const float getIndexed(const float value);
    static const float getByteCode(const float value);
public:
    static const char BYTE_FILL;
    static const short int BYTE_WIDTH;
    static const short int BYTE_MIN;
    static const short int BYTE_MAX;
    static const float BYTE_FLT_MAX;
    static const float CODE_FLT_MAX;
    static const float COLOUR_MIN;
    static const float COLOUR_MAX;
};

typedef std::vector<CMY > CMYArray;

} // namespace img

#endif //IMG_CMY_H