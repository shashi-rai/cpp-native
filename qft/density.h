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
#include "../shp/quantity.h"
#include "../shp/volume.h"

namespace qft {

class Density {
    std::string name;
    shp::Unit unit;
    shp::Quantity magnitude;
    shp::Volume volume;
public:
    // Constructors
    Density();
    Density(std::string name);
    Density(const float magnitude);
    Density(const float magnitude, const std::string unit);
    Density(const float magnitude, const short int scaling, const std::string unit);
    Density(const float magnitude, const float volume);
    Density(const float magnitude, const float volume, const std::string unit);
    Density(const float magnitude, const float volume, const short int scaling, const std::string unit);
    Density(const shp::Quantity& magnitude, const shp::Volume& volume);
    Density(const shp::Quantity& magnitude, const shp::Volume& volume, const shp::Unit& unit);
    Density(std::string name, const shp::Unit& unit);
    Density(std::string name, const short int scaling, const shp::Unit& unit);
    Density(std::string name, const float magnitude);
    Density(std::string name, const float magnitude, const std::string unit);
    Density(std::string name, const float magnitude, const short int scaling, const std::string unit);
    Density(std::string name, const float magnitude, const float volume);
    Density(std::string name, const float magnitude, const float volume, const std::string unit);
    Density(std::string name, const float magnitude, const float volume, const short int scaling, const std::string unit);
    Density(std::string name, const shp::Quantity& magnitude);
    Density(std::string name, const shp::Quantity& magnitude, const shp::Unit& unit);
    Density(std::string name, const shp::Quantity& magnitude, const shp::Volume& volume);
    Density(std::string name, const shp::Quantity& magnitude, const shp::Volume& volume, const shp::Unit& unit);

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
    shp::Unit getUnit() const { return unit; }
    shp::Quantity getMagnitude() const { return magnitude; }
    shp::Volume getVolume() const { return volume; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setUnit(const shp::Unit& value) { this->unit = value; }
    void setMagnitude(const shp::Quantity& magnitude) { this->magnitude = magnitude; }
    void setVolume(const shp::Volume& space) { this->volume = space; }

    // Additional methods
    shp::Quantity getTotal() const;
    virtual Density copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Density > DensityArray;

} // namespace qft

#endif //QFT_DENSITY_H