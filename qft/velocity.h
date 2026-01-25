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

#ifndef QFT_VELOCITY_H
#define QFT_VELOCITY_H

#include "time.h"
#include "../shp/distance.h"

namespace qft {

class Velocity : protected shp::Distance {
    std::string name;
public:
    // Constructors
    Velocity();
    Velocity(const std::string name);
    Velocity(const shp::Unit& unit);
    Velocity(const shp::Azimuth& direction);
    Velocity(const float displacement);
    Velocity(const float displacement, const std::string unit);
    Velocity(const float displacement, const shp::Unit& unit);
    Velocity(const float displacement, const float direction);
    Velocity(const float displacement, const shp::Azimuth& direction);
    Velocity(const float displacement, const std::string unit, const float direction);
    Velocity(const float displacement, const std::string unit, const shp::Azimuth& direction);
    Velocity(const float displacement, const shp::Unit& unit, const shp::Azimuth& direction);
    Velocity(const float displacement, const short int scaling, const std::string unit);
    Velocity(const float displacement, const short int scaling, const shp::Unit& unit);
    Velocity(const float displacement, const short int scaling, const float direction);
    Velocity(const float displacement, const short int scaling, const shp::Azimuth& direction);
    Velocity(const float displacement, const short int scaling, const std::string unit, const float direction);
    Velocity(const float displacement, const short int scaling, const std::string unit, const shp::Azimuth& direction);
    Velocity(const std::string name, const std::string unit);
    Velocity(const std::string name, const shp::Unit& unit);
    Velocity(const std::string name, const shp::Azimuth& direction);
    Velocity(const std::string name, const float displacement);
    Velocity(const std::string name, const float displacement, const std::string unit);
    Velocity(const std::string name, const float displacement, const shp::Unit& unit);
    Velocity(const std::string name, const float displacement, const float direction);
    Velocity(const std::string name, const float displacement, const shp::Azimuth& direction);
    Velocity(const std::string name, const float displacement, const std::string unit, const float direction);
    Velocity(const std::string name, const float displacement, const shp::Unit& unit, const float direction);
    Velocity(const std::string name, const float displacement, const shp::Unit& unit, const shp::Azimuth& direction);
    Velocity(const std::string name, const float displacement, const short int scaling, const float direction);
    Velocity(const std::string name, const float displacement, const short int scaling, const shp::Azimuth& direction);
    Velocity(const std::string name, const float displacement, const short int scaling, const std::string unit, const float direction);
    Velocity(const std::string name, const float displacement, const short int scaling, const shp::Unit& unit, const float direction);
    Velocity(const std::string name, const float displacement, const short int scaling, const shp::Unit& unit, const shp::Azimuth& direction);

    // Destructors
    ~Velocity();

    // Operator overloading
    bool operator==(const Velocity& peer) const;
    bool operator<(const Velocity& peer) const;
    bool operator>(const Velocity& peer) const;
    bool operator<=(const Velocity& peer) const;
    bool operator>=(const Velocity& peer) const;
    Velocity operator+(const Velocity& peer) const;
    Velocity operator-(const Velocity& peer) const;
    Velocity operator*(const Velocity& peer) const;
    Velocity operator/(const Velocity& peer) const;
    Velocity operator%(const Velocity& peer) const;

    // Getters
    std::string getName() const { return name; }

    // Setters
    void setName(const std::string& name) { this->name = name; }

    // Additional methods
    shp::Unit getUnit() const;
    void setUnit(const shp::Unit& unit);
    shp::Distance getDisplacement() const;
    void setDisplacement(const shp::Distance& distance);
    shp::Azimuth getDirection() const;
    void setDirection(const shp::Azimuth& direction);
    void setChangeMagnitude(const float motion);
    void setChangeDirection(const float degree);
    shp::Signal getTotal() const;
    virtual shp::Signal getLinear(const Time& slice);
    virtual shp::Signal getAngular(const Time& theta);
    void adjustScaling();
    bool checkNonZero() const;
    virtual shp::Distance copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Signal getCosComponent(const float phase) const;
    shp::Signal getSinComponent(const float phase) const;
protected:
    std::complex<float> toComplex(const float coefficient, const float change);

public:
    static const std::string UNIT;
};

typedef std::vector<Velocity > VelocityArray;

} // namespace qft

#endif //QFT_VELOCITY_H