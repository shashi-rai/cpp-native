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

#include "signal.h"

namespace shp {

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
    bool operator<(const Temporal& peer) const;
    bool operator>(const Temporal& peer) const;
    bool operator<=(const Temporal& peer) const;
    bool operator>=(const Temporal& peer) const;
    Temporal operator+(const Temporal& peer) const;
    Temporal operator-(const Temporal& peer) const;
    Temporal operator*(const Temporal& peer) const;
    Temporal operator/(const Temporal& peer) const;
    Temporal operator%(const Temporal& peer) const;

    // Getters
protected:
    Signal getModulation() const { return modulation; }

    // Setters
protected:
    void setModulation(const Signal& shift) { this->modulation = shift; }

    // Additional methods
public:
    Temporal getCarrierScalar(const float coefficient) const;
    Temporal getOverlayScalar(const float coefficient) const;
    Temporal getCarrierRotation(const short int degree) const;
    Temporal getOverlayRotation(const short int degree) const;
    Temporal getDotProduct(const Temporal& peer) const;
    Temporal getCarrierDotProduct(const Temporal& peer) const;
    Temporal getOverlayDotProduct(const Temporal& peer) const;
    Temporal getCrossProduct(const Temporal& peer) const;
    Temporal getCarrierCrossProduct(const Temporal& peer) const;
    Temporal getOverlayCrossProduct(const Temporal& peer) const;
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const Unit& unit);
    float getIntensity() const;
    float getIntensityDrift() const;
    void setIntensityDrift(const float shift);
    void setIntensityDrift(const Azimuth& shift);
    float getSpatialDrift() const;
    void setSpatialDrift(const Signal& motion);
    void setSpatialDrift(const Azimuth& rate);
    void setSpatialDrift(const float distance, const Azimuth& rate);
    void setSpatialDrift(const float distance, const short int scale, const Azimuth& rate);
    void setSpatialDrift(const float distance, const short int scale, const std::string unit, const Azimuth& rate);
    void setSpatialDrift(const float distance, const short int scale, const Unit& unit, const Azimuth& rate);
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
    virtual shp::Quantity getPhaseScaling() const;
    virtual shp::Quantity getPeriodScaling() const;
    virtual Signal getPhaseSpace() const;
    virtual Signal getLinearSpace() const;
    virtual Signal getCurvedSpace() const;
    Signal getFrequency() const;
    Signal getTotal() const;
    virtual Signal copy() const;
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Temporal > TemporalArray;

} // namespace shp

#endif //SHP_TEMPORAL_H