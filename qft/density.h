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

#include <string>
#include <vector>
#include "../shp/volume.h"

namespace qft {

class Density {
    std::string name;
    shp::Signal parameter;
    shp::Volume volume;
public:
    // Constructors
    Density();
    Density(std::string name);
    Density(const float parameter);
    Density(const float parameter, const std::string unit);
    Density(const float parameter, const short int scaling, const std::string unit);
    Density(const float parameter, const float volume);
    Density(const float parameter, const short int scaling, const float volume);
    Density(const float parameter, const std::string unit, const float volume);
    Density(const float parameter, const short int scaling, const std::string unit, const float volume);
    Density(const float parameter, const short int scaling, const std::string unit, const shp::Volume& volume);
    Density(const float parameter, const short int scaling, const shp::Unit& unit, const shp::Volume& volume);
    Density(const shp::Signal& parameter, const shp::Volume& volume);
    Density(const std::string name, const shp::Unit& unit);
    Density(const std::string name, const short int scaling, const shp::Unit& unit);
    Density(const std::string name, const float parameter);
    Density(const std::string name, const float parameter, const std::string unit);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit);
    Density(const std::string name, const float parameter, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const float volume);
    Density(const std::string name, const float parameter, const std::string unit, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const std::string unit, const float volume);
    Density(const std::string name, const float parameter, const short int scaling, const shp::Unit& unit, const shp::Volume& volume);
    Density(const std::string name, const shp::Signal& parameter);
    Density(const std::string name, const shp::Signal& parameter, const shp::Volume& volume);

    // Destructors
    ~Density();

    // Operator overloading
    bool operator==(const Density& peer) const;
    Density operator+(const Density& peer) const;
    Density operator-(const Density& peer) const;
    Density operator*(const Density& peer) const;
    Density operator/(const Density& peer) const;
    Density operator%(const Density& peer) const;

    // Getters
    std::string getName() const { return name; }
    shp::Signal getParameter() const { return parameter; }
    shp::Volume getVolume() const { return volume; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setParameter(const shp::Signal& temporal) { this->parameter = temporal; }
    void setVolume(const shp::Volume& spatial) { this->volume = spatial; }

    // Additional methods
    float getMagnitude() const;
    void setMagnitude(const float value);
    void setMagnitude(const float value, const short int scale);
    void setMagnitude(const float value, const short int scale, const std::string unit);
    short int getScaling() const;
    void setScaling(const short int scale);
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& unit);
    void setVolume(const float value);
    shp::Signal getTotal() const;
    virtual Density copy();
    virtual void clear();
    virtual std::string print();
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Density > DensityArray;

} // namespace qft

#endif //QFT_DENSITY_H