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

#ifndef SHP_BOUND_H
#define SHP_BOUND_H

#include <cmath>
#include <complex>

namespace shp {

class Bound {
    float magnitude;
    short int scaling;
public:
    // Constructors
    Bound();
    Bound(const float magnitude);
    Bound(const float magnitude, const short int scaling);

    // Destructors
    ~Bound();

    // Operator overloading
    bool operator==(const Bound& peer) const;
    bool operator<(const Bound& peer) const;
    bool operator>(const Bound& peer) const;
    bool operator<=(const Bound& peer) const;
    bool operator>=(const Bound& peer) const;
    Bound operator+(const Bound& peer) const;
    Bound operator-(const Bound& peer) const;
    Bound operator*(const Bound& peer) const;
    Bound operator/(const Bound& peer) const;
    Bound operator%(const Bound& peer) const;

    // Getters
    float getMagnitude() const { return magnitude; }
    short int getScaling() const { return scaling; }

    // Setters
    void setMagnitude(const float amount) { this->magnitude = amount; }
    void setScaling(const short int factor) { this->scaling = factor; }

    // Additional methods
    void setMagnitude(const float value, const short int scale);
    double getZeroScale() const;
    Bound getAbsolute() const;
    Bound getNegative() const;
    Bound getInverse() const;
    Bound getSquare() const;
    Bound getSquareRoot() const;
    Bound getCube() const;
    Bound getCubeRoot() const;
    Bound getMultiple(const float coefficient) const;
    Bound getFraction(const float coefficient) const;
    Bound getDivision(const float coefficient) const;
    Bound getRemainder(const float coefficient) const;
    Bound getLeftOver(const float coefficient) const;
    bool isConvergent() const;
    bool isDivergent() const;
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    void adjustNumeric();
    void adjustScaling();
    Bound copy() const;
    void clear();
    std::string print() const;
    float getCosComponent(const float phase) const;
    float getSinComponent(const float phase) const;
    float getCosHyperbola(const float phase) const;
    float getSinHyperbola(const float phase) const;
protected:
    static const std::complex<float> getComplex(const float value, const float direction);
public:
    static const float DEFAULT_VALUE;
    static const float DECIMAL_SCALE;
    static const short int DEFAULT_SCALE;
};

typedef std::vector<Bound > BoundArray;

} // namespace shp

#endif //SHP_BOUND_H