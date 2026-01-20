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

#ifndef SHP_QUANTITY_H
#define SHP_QUANTITY_H

#include <cmath>
#include <complex>
#include "unit.h"

namespace shp {

class Quantity {
    float magnitude;
    short int scaling;
    Unit unit;
public:
    // Constructors
    Quantity();
    Quantity(const float magnitude);
    Quantity(const short int scaling);
    Quantity(const std::string unit);
    Quantity(const Unit& unit);
    Quantity(const short int scaling, const std::string unit);
    Quantity(const short int scaling, const Unit& unit);
    Quantity(const float magnitude, const std::string unit);
    Quantity(const float magnitude, const Unit& unit);
    Quantity(const float magnitude, const short int scaling);
    Quantity(const float magnitude, const short int scaling, const std::string unit);
    Quantity(const float magnitude, const short int scaling, const Unit& unit);

    // Destructors
    ~Quantity();

    // Operator overloading
    bool operator==(const Quantity& peer) const;
    Quantity operator+(const Quantity& peer) const;
    Quantity operator-(const Quantity& peer) const;
    Quantity operator*(const Quantity& peer) const;
    Quantity operator/(const Quantity& peer) const;
    Quantity operator%(const Quantity& peer) const;

    // Getters
    float getMagnitude() const { return magnitude; }
    short int getScaling() const { return scaling; }
    Unit getUnit() const { return unit; }

    // Setters
    void setMagnitude(const float amount) { this->magnitude = amount; }
    void setScaling(const short int factor) { this->scaling = factor; }
    void setUnit(const Unit& object) { this->unit = object; }

    // Additional methods
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const Unit& unit);
    void setUnit(const std::string name);
    double getZeroScale() const;            // convert value assuming scaling is zero
    Quantity getAbsolute() const;
    Quantity getNegative() const;
    Quantity getInverse() const;
    Quantity getPercent() const;
    Quantity getSquare() const;
    Quantity getSquareRoot() const;
    Quantity getCube() const;
    Quantity getCubeRoot() const;
    Quantity getMultiple(const float coefficient) const;
    Quantity getFraction(const float coefficient) const;
    Quantity getDivision(const float coefficient) const;
    Quantity getRemainder(const float coefficient) const;
    Quantity getLeftOver(const float coefficient) const;
    bool isConvergent() const;
    bool isDivergent() const;
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    void adjustNumeric();
    void adjustScaling();
    Quantity copy() const;
    void clear();
    std::string print() const;
    std::string printSuffixed() const;
    std::string printPrefixed() const;
    float getCosComponent(const float phase) const;
    float getSinComponent(const float phase) const;
protected:
    static const std::complex<float> getComplex(const float value, const float direction);
public:
    static const std::string DEFAULT_TEXT;
    static const float DEFAULT_VALUE;
    static const float DECIMAL_SCALE;
    static const short int DEFAULT_SCALE;
};

typedef std::vector<Quantity > QuantityArray;

} // namespace shp

#endif //SHP_QUANTITY_H