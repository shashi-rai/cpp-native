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

#ifndef SHP_TEMPORAL_H
#define SHP_TEMPORAL_H

#include <sstream>
#include <string>
#include <vector>
#include "signal.h"

namespace shp {

// To enable compiler resolve forward declarations
class Frequency;

class Temporal : private Signal {
    Signal modulation;
public:
    // Constructors
    Temporal();
    Temporal(const std::string unit);
    Temporal(const shp::Unit& unit);
    Temporal(const float magnitude);
    Temporal(const float magnitude, const std::string unit);
    Temporal(const float magnitude, const shp::Unit& unit);
    Temporal(const float magnitude, const short int scaling);
    Temporal(const float magnitude, const short int scaling,
        const std::string unit);
    Temporal(const float magnitude, const short int scaling,
        const shp::Unit& unit);
    Temporal(const Azimuth& phase);
    Temporal(const Azimuth& phase, const std::string unit);
    Temporal(const Azimuth& phase, const shp::Unit& unit);
    Temporal(const Azimuth& phase, const float magnitude);
    Temporal(const Azimuth& phase, const float magnitude, 
        const std::string unit);
    Temporal(const Azimuth& phase, const float magnitude,
        const Unit& unit);
    Temporal(const Azimuth& phase, const float magnitude,
        const short int scaling);
    Temporal(const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const Azimuth& phase, const float magnitude,
        const short int scaling, const Unit& unit);
    Temporal(const Signal& modulation);
    Temporal(const Signal& modulation, const shp::Quantity& magnitude);
    Temporal(const Signal& modulation, const Azimuth& phase);
    Temporal(const Signal& modulation, const Azimuth& phase, const shp::Quantity& magnitude);
    Temporal(const float modulation, const float magnitude);
    Temporal(const float modulation, const float phase, const float magnitude);
    Temporal(const float modulation, const float magnitude,
        const std::string unit);
    Temporal(const float modulation, const float phase, const float magnitude,
        const std::string unit);
    Temporal(const float modulation, const float magnitude,
        const shp::Unit& unit);
    Temporal(const float modulation, const float phase, const float magnitude,
        const shp::Unit& unit);
    Temporal(const Signal& modulation, const float magnitude);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const std::string unit);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const Unit& unit);
    Temporal(const float modulation, const float magnitude,
        const short int scaling);
    Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling);
    Temporal(const Signal& modulation, const float magnitude,
        const short int scaling);
    Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling);
    Temporal(const float modulation, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const Signal& modulation, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit);
    Temporal(const float modulation, const float magnitude,
        const short int scaling, const Unit& unit);
    Temporal(const float modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit);
    Temporal(const Signal& modulation, const float magnitude,
        const short int scaling, const Unit& unit);
    Temporal(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit);
    Temporal(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const Unit& unit);

    // Destructors
    ~Temporal();

    // Operator overloading
    bool operator==(const Temporal& peer) const;
    Temporal operator+(const Temporal& peer) const;
    Temporal operator-(const Temporal& peer) const;
    Temporal operator*(const Temporal& peer) const;
    Temporal operator/(const Temporal& peer) const;
    Temporal operator%(const Temporal& peer) const;

    // Getters
    Signal getModulation() const { return modulation; }

    // Setters
    void setModulation(const Signal& shift) { this->modulation = shift; }

    // Additional methods
    float getMagnitude() const;
    void setMagnitude(const float value);
    float getAmplitude() const;
    float getPhase() const;
    void setPhase(const float value);
    short int getScaling() const;
    void setScaling(const short int factor);
    Unit getUnit() const;
    void setUnit(const Unit& object);
    void adjustNumeric();
    void adjustScaling();
    bool checkNonZero() const;
    bool checkInfinity() const;
    short int checkScaling(const float amount) const;
    virtual shp::Quantity getPhaseShift() const;
    virtual shp::Quantity getPerpetuity() const;
    virtual shp::Frequency getFrequency() const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Temporal > TemporalArray;

} // namespace shp

#endif //SHP_TEMPORAL_H