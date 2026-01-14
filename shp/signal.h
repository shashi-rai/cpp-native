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

#ifndef SHP_SIGNAL_H
#define SHP_SIGNAL_H

#include <sstream>
#include <string>
#include <vector>
#include "azimuth.h"
#include "quantity.h"

namespace shp {

// To enable compiler resolve forward declarations
class Frequency;

class Signal : private Quantity {
    float orientation;
public:
    // Constructors
    Signal();
    Signal(const std::string unit);
    Signal(const shp::Unit& unit);
    Signal(const float quantity);
    Signal(const float quantity, const std::string unit);
    Signal(const float quantity, const shp::Unit& unit);
    Signal(const float quantity, const short int scaling);
    Signal(const float quantity, const short int scaling,
        const std::string unit);
    Signal(const float quantity, const short int scaling,
        const shp::Unit& unit);
    Signal(const Quantity& quantity);
    Signal(const Azimuth& orientation);
    Signal(const Azimuth& orientation, const Quantity& quantity);
    Signal(const float orientation, const float quantity);
    Signal(const float orientation, const float quantity,
        const std::string unit);
    Signal(const float orientation, const float quantity,
        const shp::Unit& unit);
    Signal(const Azimuth& orientation, const float quantity);
    Signal(const Azimuth& orientation, const float quantity,
        const std::string unit);
    Signal(const Azimuth& orientation, const float quantity,
        const Unit& unit);
    Signal(const float orientation, const float quantity,
        const short int scaling);
    Signal(const Azimuth& orientation, const float quantity,
        const short int scaling);
    Signal(const float orientation, const float quantity,
        const short int scaling, const std::string unit);
    Signal(const Azimuth& orientation, const float quantity,
        const short int scaling, const std::string unit);
    Signal(const float orientation, const float quantity,
        const short int scaling, const Unit& unit);
    Signal(const Azimuth& orientation, const float quantity,
        const short int scaling, const Unit& unit);

    // Destructors
    ~Signal();

    // Operator overloading
    bool operator==(const Signal& peer) const;
    Signal operator+(const Signal& peer) const;
    Signal operator-(const Signal& peer) const;
    Signal operator*(const Signal& peer) const;
    Signal operator/(const Signal& peer) const;
    Signal operator%(const Signal& peer) const;

    // Multiple operator
    Signal operator()(const float scaleup) const;

    // Getters
    float getOrientation() const { return orientation; }

    // Setters
    void setOrientation(const float direction) { this->orientation = direction; }

    // Additional methods
    Signal getRotation(const short int degree) const;
    Signal getDotProduct(const Signal& peer) const;
    Signal getCrossProduct(const Signal& peer) const;
    Frequency getFrequency() const;
    float getCyclingRate() const;
    float getTimePerCycle() const;
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    float getAmplitude() const;
    Direction getPhase() const;
    void setPhase(const Direction& direction);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    Signal getScalarAbsolute() const;
    Signal getVectorAbsolute() const;
    Signal getScalarInverse() const;
    Signal getVectorInverse() const;
    Signal getScalarPercent() const;
    Signal getVectorPercent() const;
    Signal getDotProductSquare() const;
    Signal getCrossProductSquare() const;
    Signal getDotProductSquareRoot() const;
    Signal getDotProductCube() const;
    Signal getCrossProductCube() const;
    Signal getDotProductCubeRoot() const;
    bool isConvergent() const;
    bool isDivergent() const;
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    void adjustNumeric();
    void adjustScaling();
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Signal > SignalArray;

} // namespace shp

#endif //SHP_SIGNAL_H