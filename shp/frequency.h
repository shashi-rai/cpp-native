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

#ifndef SHP_FREQUENCY_H
#define SHP_FREQUENCY_H

#include <sstream>
#include <string>
#include <vector>
#include "azimuth.h"
#include "polar.h"
#include "signal.h"

namespace shp {

class Frequency : private Signal {
    Direction modulation;
public:
    // Constructors
    Frequency();
    Frequency(const std::string unit);
    Frequency(const shp::Unit& unit);
    Frequency(const float magnitude);
    Frequency(const float magnitude, const std::string unit);
    Frequency(const float magnitude, const shp::Unit& unit);
    Frequency(const float magnitude, const short int scaling);
    Frequency(const float magnitude, const short int scaling, const std::string unit);
    Frequency(const float magnitude, const short int scaling, const shp::Unit& unit);
    Frequency(const Polar& modulation);
    Frequency(const Polar& modulation, const shp::Quantity& magnitude);
    Frequency(const Polar& modulation, const Azimuth& phase, const shp::Quantity& magnitude);
    Frequency(const float modulation, const float magnitude);
    Frequency(const float modulation, const float phase, const float magnitude);
    Frequency(const float modulation, const float magnitude, const std::string unit);
    Frequency(const float modulation, const float phase, const float magnitude, const std::string unit);
    Frequency(const float modulation, const float magnitude, const shp::Unit& unit);
    Frequency(const float modulation, const float phase, const float magnitude, const shp::Unit& unit);
    Frequency(const Polar& modulation, const float magnitude);
    Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude);
    Frequency(const float modulation, const float magnitude, short int scaling);
    Frequency(const float modulation, const float phase, const float magnitude, short int scaling);
    Frequency(const Polar& modulation, const float magnitude, short int scaling);
    Frequency(const Polar& modulation, const float phase, const float magnitude, short int scaling);
    Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude, short int scaling);
    Frequency(const float modulation, const float magnitude, short int scaling, std::string unit);
    Frequency(const float modulation, const float phase, const float magnitude, short int scaling, std::string unit);
    Frequency(const Polar& modulation, const float magnitude, short int scaling, std::string unit);
    Frequency(const Polar& modulation, const float phase, const float magnitude, short int scaling, std::string unit);
    Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude, short int scaling, std::string unit);
    Frequency(const float modulation, const float magnitude, short int scaling, const Unit& unit);
    Frequency(const float modulation, const float phase, const float magnitude, short int scaling, const Unit& unit);
    Frequency(const Polar& modulation, const float magnitude, short int scaling, const Unit& unit);
    Frequency(const Polar& modulation, const float phase, const float magnitude, short int scaling, const Unit& unit);
    Frequency(const Polar& modulation, const Azimuth& phase, const float magnitude, short int scaling, const Unit& unit);

    // Destructors
    ~Frequency();

    // Operator overloading
    bool operator==(const Frequency& peer) const;
    Frequency operator+(const Frequency& peer) const;
    Frequency operator-(const Frequency& peer) const;
    Frequency operator*(const Frequency& peer) const;
    Frequency operator/(const Frequency& peer) const;
    Frequency operator%(const Frequency& peer) const;

    // Getters
    Direction getModulation() const { return modulation; }

    // Setters
    void setModulation(const Direction& shift) { this->modulation = shift; }

    // Additional methods
    float getMagnitude() const;
    void setMagnitude(const float value);
    float getPhase() const;
    void setPhase(const float value);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    virtual shp::Quantity getPhaseShift() const;
    virtual shp::Quantity getWavelength() const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Frequency > FrequencyArray;

} // namespace shp

#endif //SHP_FREQUENCY_H