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
#include "signal.h"

namespace shp {

class Frequency : private Signal {
    Signal modulation;
public:
    // Constructors
    Frequency();
    Frequency(const std::string unit);
    Frequency(const shp::Unit& unit);
    Frequency(const float magnitude);
    Frequency(const float magnitude, const std::string unit);
    Frequency(const float magnitude, const shp::Unit& unit);
    Frequency(const float magnitude, const short int scaling);
    Frequency(const float magnitude, const short int scaling,
        const std::string unit);
    Frequency(const float magnitude, const short int scaling,
        const shp::Unit& unit);
    Frequency(const Azimuth& phase);
    Frequency(const Azimuth& phase, const std::string unit);
    Frequency(const Azimuth& phase, const shp::Unit& unit);
    Frequency(const Azimuth& phase, const float magnitude);
    Frequency(const Azimuth& phase, const float magnitude,
        const std::string unit);
    Frequency(const Azimuth& phase, const float magnitude,
        const shp::Unit& unit);
    Frequency(const Azimuth& phase, const float magnitude,
        const short int scaling);
    Frequency(const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const Azimuth& phase, const float magnitude,
        const short int scaling, const shp::Unit& unit);
    Frequency(const Signal& modulation);
    Frequency(const Signal& modulation, const shp::Quantity& magnitude);
    Frequency(const Signal& modulation, const Azimuth& phase);
    Frequency(const Signal& modulation, const Azimuth& phase,
        const shp::Quantity& magnitude);
    Frequency(const float modulation, const float magnitude);
    Frequency(const float modulation, const float phase, const float magnitude);
    Frequency(const float modulation, const float magnitude,
        const std::string unit);
    Frequency(const float modulation, const float phase, const float magnitude,
        const std::string unit);
    Frequency(const float modulation, const float magnitude,
        const shp::Unit& unit);
    Frequency(const float modulation, const float phase, const float magnitude,
        const shp::Unit& unit);
    Frequency(const Signal& modulation, const float magnitude);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const std::string unit);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const Unit& unit);
    Frequency(const float modulation, const float magnitude,
        const short int scaling);
    Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling);
    Frequency(const Signal& modulation, const float magnitude,
        const short int scaling);
    Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling);
    Frequency(const float modulation, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const Signal& modulation, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const std::string unit);
    Frequency(const float modulation, const float magnitude,
        const short int scaling, const Unit& unit);
    Frequency(const float modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit);
    Frequency(const Signal& modulation, const float magnitude,
        const short int scaling, const Unit& unit);
    Frequency(const Signal& modulation, const float phase, const float magnitude,
        const short int scaling, const Unit& unit);
    Frequency(const Signal& modulation, const Azimuth& phase, const float magnitude,
        const short int scaling, const Unit& unit);

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
    Signal getModulation() const { return modulation; }

    // Setters
    void setModulation(const Signal& shift) { this->modulation = shift; }

    // Additional methods
    Frequency getCarrierScalar(const float coefficient) const;
    Frequency getOverlayScalar(const float coefficient) const;
    Frequency getCarrierRotation(const short int degree) const;
    Frequency getOverlayRotation(const short int degree) const;
    Frequency getDotProduct(const Frequency& peer) const;
    Frequency getCarrierDotProduct(const Frequency& peer) const;
    Frequency getOverlayDotProduct(const Frequency& peer) const;
    Frequency getCrossProduct(const Frequency& peer) const;
    Frequency getCarrierCrossProduct(const Frequency& peer) const;
    Frequency getOverlayCrossProduct(const Frequency& peer) const;
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
    virtual shp::Quantity getTraversal() const;
    virtual shp::Quantity getLifespan() const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Frequency > FrequencyArray;

} // namespace shp

#endif //SHP_FREQUENCY_H