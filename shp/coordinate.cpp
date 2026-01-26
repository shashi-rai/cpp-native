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

#include "coordinate.h"

namespace shp {

const float Coordinate::ORIGIN = Quantity::DEFAULT_VALUE;
const float Coordinate::UNIT_MAGNITUDE = 1e-9;

Coordinate::Coordinate()
        : x(Coordinate::ORIGIN), y(Coordinate::ORIGIN), z(Coordinate::ORIGIN) {

}

Coordinate::Coordinate(const float x)
        : x(x), y(Coordinate::ORIGIN), z(Coordinate::ORIGIN) {

}

Coordinate::Coordinate(const Distance& x)
        : x(x), y(Coordinate::ORIGIN), z(Coordinate::ORIGIN) {

}

Coordinate::Coordinate(const float x, const float y)
        : x(x), y(y), z(Coordinate::ORIGIN) {

}

Coordinate::Coordinate(const Distance& x, const Distance& y)
        : x(x), y(y), z(Coordinate::ORIGIN) {

}

Coordinate::Coordinate(const float x, const float y, const float z)
        : x(x), y(y), z(z) {

}

Coordinate::Coordinate(const Distance& x, const Distance& y, const Distance& z)
        : x(x), y(y), z(z) {

}

Coordinate::~Coordinate() {

}

bool Coordinate::operator==(const Coordinate& peer) const {
    return (x == peer.x) && (y == peer.y) && (z == peer.z);
}

bool Coordinate::operator<(const Coordinate& peer) const {
    bool result = false;
    if (x < peer.x) {
        result = true;
    }
    if (y < peer.y) {
        result = true;
    }
    if (z < peer.z) {
        result = true;
    }
    return result;
}

bool Coordinate::operator>(const Coordinate& peer) const {
    bool result = false;
    if (x > peer.x) {
        result = true;
    }
    if (y > peer.y) {
        result = true;
    }
    if (z > peer.z) {
        result = true;
    }
    return result;
}

bool Coordinate::operator<=(const Coordinate& peer) const {
    Coordinate self = *this;
    return (self < peer) || (self == peer);
}

bool Coordinate::operator>=(const Coordinate& peer) const {
    Coordinate self = *this;
    return (self > peer) || (self == peer);
}

Coordinate Coordinate::operator+(const Coordinate& peer) const {
    return Coordinate((x + peer.x), (y + peer.y), (z + peer.z));
}

Coordinate Coordinate::operator-(const Coordinate& peer) const {
    return Coordinate((x - peer.x), (y - peer.y), (z - peer.z));
}

Coordinate Coordinate::operator*(const Coordinate& peer) const {
    return Coordinate((x * peer.x), (y * peer.y), (z * peer.z));
}

Coordinate Coordinate::operator/(const Coordinate& peer) const {
    return Coordinate((x / peer.x), (y / peer.y), (z / peer.z));
}

Coordinate Coordinate::operator%(const Coordinate& peer) const {
    return Coordinate((x % peer.x), (y % peer.y), (z % peer.z));
}


void Coordinate::setX(const float length) {
    x.setMagnitude(length);
}

void Coordinate::setX(const float length, const short int scale) {
    x.setMagnitude(length, scale);
}

void Coordinate::setX(const float length, const short int scale, const std::string unit) {
    x.setMagnitude(length, scale, unit);
}

void Coordinate::setX(const float length, const short int scale, const Unit& unit) {
    x.setMagnitude(length, scale, unit);
}

short int Coordinate::getScalingX() const {
    return x.getScaling();
}

void Coordinate::setScalingX(const short int factor) {
    x.setScaling(factor);
}

Unit Coordinate::getUnitX() const {
    return x.getUnit();
}

void Coordinate::setUnitX(const Unit& object) {
    x.setUnit(object);
}

Azimuth Coordinate::getStressFactorX() const {
    return x.getAzimuth();
}

void Coordinate::setStressFactorX(const float orientation) {
    x.setAzimuth(orientation);
}

void Coordinate::setStressFactorX(const Azimuth& orientation) {
    x.setAzimuth(orientation);
}

Polar Coordinate::getDopplerShiftX() const {
    return x.getModulation();
}

void Coordinate::setDopplerShiftX(const float relativity) {
    x.setModulation(relativity);
}

void Coordinate::setDopplerShiftX(const Polar& relativity) {
    x.setModulation(relativity);
}

void Coordinate::setChangeXMagnitude(const float motion) {
    x.setChangeMagnitude(motion);
}

void Coordinate::setChangeXDirection(const float degree) {
    x.setChangeDirection(degree);
}

void Coordinate::setY(const float length) {
    y.setMagnitude(length);
}

void Coordinate::setY(const float length, const short int scale) {
    y.setMagnitude(length, scale);
}

void Coordinate::setY(const float length, const short int scale, const std::string unit) {
    y.setMagnitude(length, scale, unit);
}

void Coordinate::setY(const float length, const short int scale, const Unit& unit) {
    y.setMagnitude(length, scale, unit);
}

short int Coordinate::getScalingY() const {
    return y.getScaling();
}

void Coordinate::setScalingY(const short int factor) {
    y.setScaling(factor);
}

Unit Coordinate::getUnitY() const {
    return y.getUnit();
}

void Coordinate::setUnitY(const Unit& object) {
    y.setUnit(object);
}

Azimuth Coordinate::getStressFactorY() const {
    return y.getAzimuth();
}

void Coordinate::setStressFactorY(const float orientation) {
    y.setAzimuth(orientation);
}

void Coordinate::setStressFactorY(const Azimuth& orientation) {
    y.setAzimuth(orientation);
}

Polar Coordinate::getDopplerShiftY() const {
    return y.getModulation();
}

void Coordinate::setDopplerShiftY(const float relativity) {
    y.setModulation(relativity);
}

void Coordinate::setDopplerShiftY(const Polar& relativity) {
    y.setModulation(relativity);
}

void Coordinate::setChangeYMagnitude(const float motion) {
    y.setChangeMagnitude(motion);
}

void Coordinate::setChangeYDirection(const float degree) {
    y.setChangeDirection(degree);
}

void Coordinate::setZ(const float length) {
    z.setMagnitude(length);
}

void Coordinate::setZ(const float length, const short int scale) {
    z.setMagnitude(length, scale);
}

void Coordinate::setZ(const float length, const short int scale, const std::string unit) {
    z.setMagnitude(length, scale, unit);
}

void Coordinate::setZ(const float length, const short int scale, const Unit& unit) {
    z.setMagnitude(length, scale, unit);
}

short int Coordinate::getScalingZ() const {
    return z.getScaling();
}

void Coordinate::setScalingZ(const short int factor) {
    z.setScaling(factor);
}

Unit Coordinate::getUnitZ() const {
    return z.getUnit();
}

void Coordinate::setUnitZ(const Unit& object) {
    z.setUnit(object);
}

Azimuth Coordinate::getStressFactorZ() const {
    return z.getAzimuth();
}

void Coordinate::setStressFactorZ(const float orientation) {
    z.setAzimuth(orientation);
}

void Coordinate::setStressFactorZ(const Azimuth& orientation) {
    z.setAzimuth(orientation);
}

Polar Coordinate::getDopplerShiftZ() const {
    return z.getModulation();
}

void Coordinate::setDopplerShiftZ(const float relativity) {
    z.setModulation(relativity);
}

void Coordinate::setDopplerShiftZ(const Polar& relativity) {
    z.setModulation(relativity);
}

void Coordinate::setChangeZMagnitude(const float motion) {
    z.setChangeMagnitude(motion);
}

void Coordinate::setChangeZDirection(const float degree) {
    z.setChangeDirection(degree);
}

Signal Coordinate::getDiagonal() const {
    Signal xx = x.getScalarSquare();
    Signal yy = y.getScalarSquare();
    Signal zz = z.getScalarSquare();
    return (xx + yy + zz).getDotProductSquareRoot();
}

Coordinate Coordinate::getNormalize() const {
    Signal magnitude = this->getDiagonal();
    if (magnitude < Coordinate::UNIT_MAGNITUDE) {
        return Coordinate((x / magnitude), (y / magnitude), (z / magnitude));
    }
    return Coordinate(Coordinate::ORIGIN, Coordinate::ORIGIN, Coordinate::ORIGIN);;
}

Coordinate Coordinate::getField(const float intensity, const float conservable,
        const Coordinate& origin, const Coordinate& point) const {
    Coordinate radial_vector = (origin - point);
    Signal distance = radial_vector.getDiagonal();
    if (distance < Coordinate::UNIT_MAGNITUDE) {
        return Coordinate(Coordinate::ORIGIN, Coordinate::ORIGIN, Coordinate::ORIGIN);
    }
    Signal field_magnitude = distance.getDotFractionSquare(std::abs(conservable)).getDotProduct(intensity);
    Coordinate unit_vector = radial_vector.getNormalize();
    if (conservable < Quantity::DEFAULT_VALUE) {
        field_magnitude = field_magnitude.getScalarNegative();  // sign reversal
    }
    Coordinate result = Coordinate((unit_vector.x * field_magnitude),
        (unit_vector.y * field_magnitude), (unit_vector.z * field_magnitude));
    return result;
}

Coordinate Coordinate::shiftX(const float step) const {
    return Coordinate((x + step), y, z);
}

Coordinate Coordinate::shiftY(const float step) const {
    return Coordinate(x, (y + step), z);
}

Coordinate Coordinate::shiftZ(const float step) const {
    return Coordinate(x, y, (z + step));
}

Coordinate Coordinate::copy() {
    Coordinate fresh(x, y, z);
    return fresh;
}

void Coordinate::clear() {
    x.clear();
    y.clear();
    z.clear();
    return;
}

std::string Coordinate::print() const {
    std::stringstream result;
    result << "(";
    result << x.print() << ",";
    result << y.print() << ",";
    result << z.print() << ")";
	return result.str();
}

std::string Coordinate::printRadians() const {
    std::stringstream result;
    result << "(";
    result << x.printRadians() << ",";
    result << y.printRadians() << ",";
    result << z.printRadians() << ")";
	return result.str();
}

} // namespace shp