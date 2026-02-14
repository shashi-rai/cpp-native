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

#ifndef QFT_DENSITY_H
#define QFT_DENSITY_H

#include "../shp/medium.h"
#include "../shp/volume.h"

namespace qft {

class Density : protected shp::Medium {
    shp::Volume volume;
public:
    // Constructors
    Density();
    Density(const float parameter);
    Density(const float parameter, const shp::Signal& modulation);
    Density(const float parameter, const std::string unit);
    Density(const float parameter, const shp::Unit& unit);
    Density(const float parameter, const std::string unit, const shp::Signal& modulation);
    Density(const float parameter, const shp::Unit& unit, const shp::Signal& modulation);
    Density(const float parameter, const short int scaling, const std::string unit);
    Density(const float parameter, const short int scaling, const shp::Unit& unit);
    Density(const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation);
    Density(const float parameter, const float volume);
    Density(const float parameter, const shp::Volume& volume);
    Density(const float parameter, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const float volume);
    Density(const float parameter, const short int scaling, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const short int scaling, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const std::string unit, const float volume);
    Density(const float parameter, const shp::Unit& unit, const float volume);
    Density(const float parameter, const std::string unit, const shp::Volume& volume);
    Density(const float parameter, const shp::Unit& unit, const shp::Volume& volume);
    Density(const float parameter, const std::string unit, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const shp::Unit& unit, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const std::string unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const shp::Unit& unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const std::string unit, const float volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const float volume);
    Density(const float parameter, const short int scaling, const std::string unit, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const float volume);
    Density(const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const shp::Signal& volume);
    Density(const shp::Signal& modulation);
    Density(const shp::Signal& modulation, const float volume);
    Density(const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name);
    Density(const std::string name, const std::string unit);
    Density(const std::string name, const shp::Unit& unit);
    Density(const std::string name, const short int scaling, const std::string unit);
    Density(const std::string name, const short int scaling, const shp::Unit& unit);
    Density(const std::string name, const float parameter);
    Density(const std::string name, const float parameter, const shp::Signal& modulation);
    Density(const std::string name, const float parameter, const std::string unit);
    Density(const std::string name, const float parameter, const shp::Unit& unit);
    Density(const std::string name, const float parameter, const std::string unit, const shp::Signal& modulation);
    Density(const std::string name, const float parameter, const shp::Unit& unit, const shp::Signal& modulation);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation);
    Density(const std::string name, const float parameter, const float volume);
    Density(const std::string name, const float parameter, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const std::string unit, const float volume);
    Density(const std::string name, const float parameter, const shp::Unit& unit, const float volume);
    Density(const std::string name, const float parameter, const std::string unit, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const shp::Unit& unit, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const std::string unit, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const shp::Unit& unit, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const std::string unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const shp::Unit& unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const shp::Volume& volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Signal& modulation, const shp::Signal& volume);
    Density(const std::string name, const shp::Signal& modulation);
    Density(const std::string name, const shp::Signal& modulation, const float volume);
    Density(const std::string name, const shp::Signal& modulation, const shp::Volume& volume);

    // Destructors
    ~Density();

    // Operator overloading
    bool operator==(const Density& peer) const;
    bool operator<(const Density& peer) const;
    bool operator>(const Density& peer) const;
    bool operator<=(const Density& peer) const;
    bool operator>=(const Density& peer) const;
    Density operator+(const Density& peer) const;
    Density operator-(const Density& peer) const;
    Density operator*(const Density& peer) const;
    Density operator/(const Density& peer) const;
    Density operator%(const Density& peer) const;

    // Getters
    shp::Volume getVolume() const { return volume; }

    // Setters
    void setVolume(const shp::Volume& spatial) { this->volume = spatial; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string name);
    shp::Area getArea() const;
    void setArea(const shp::Area& planar);
    void setArea(const shp::Distance& length, const shp::Distance& breadth);
    void setArea(const float length, const float breadth);
    void setArea(const float length, const float breadth, const short int scale);
    void setArea(const float length, const float breadth, const short int scale, const std::string unit);
    void setArea(const float length, const float breadth, const short int scale, const shp::Unit& unit);
    shp::Distance getHeight() const;
    void setHeight(const shp::Distance& height);
    void setHeight(const float height);
    void setHeight(const float height, const short int scale);
    void setHeight(const float height, const short int scale, const std::string unit);
    void setHeight(const float height, const short int scale, const shp::Unit& unit);
    shp::Direction getParameterDiffusion() const;
    void setParameterDiffusion(const float factor);
    void setParameterDiffusion(const shp::Intrinsic& rate);
    shp::Direction getParameterThreshold() const;
    void setParameterThreshold(const float factor);
    void setParameterThreshold(const shp::Polar& factor);
    shp::Signal getThermalFactor() const;
    void setThermalFactor(const shp::Signal& temperature);
    shp::Signal getScalarThermalDrift();
    shp::Signal getScalarThermalTotal();
    shp::Signal getThermalFieldDrift();
    shp::Signal getThermalFieldTotal();
    float getAmplitude() const;
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    void setMagnitude(const float value, const short int scale, const shp::Unit& unit);
    short int getScaling() const;
    void setScaling(const short int scale);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& unit);
    void setVolume(const float value);
    void setVolume(const float value, const short int scale);
    void setVolume(const shp::Signal& signal);
    void setChangeLength(const float value);
    void setChangeLength(const float value, const short int scale);
    void setChangeLength(const float value, const short int scale, const std::string unit);
    void setChangeLength(const float value, const short int scale, const shp::Unit& unit);
    void setChangeLengthPhase(const float direction);
    void setChangeLengthPhase(const shp::Intrinsic& orientation);
    void setChangeBreadth(const float value);
    void setChangeBreadth(const float value, const short int scale);
    void setChangeBreadth(const float value, const short int scale, const std::string unit);
    void setChangeBreadth(const float value, const short int scale, const shp::Unit& unit);
    void setChangeBreadthPhase(const float direction);
    void setChangeBreadthPhase(const shp::Intrinsic& orientation);
    void setChangeHeight(const float value);
    void setChangeHeight(const float value, const short int scale);
    void setChangeHeight(const float value, const short int scale, const std::string unit);
    void setChangeHeight(const float value, const short int scale, const shp::Unit& unit);
    void setChangeHeightPhase(const float direction);
    void setChangeHeightPhase(const shp::Intrinsic& orientation);
    shp::Signal getScalarFlux() const;
    shp::Signal getVectorFlux() const;
    Density copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const std::string UNIT;
    static const float DEFAULT_VOLUME;
};

typedef std::vector<Density > DensityArray;

} // namespace qft

#endif //QFT_DENSITY_H