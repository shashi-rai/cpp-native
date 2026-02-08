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

Coordinate Coordinate::operator+(const float scalar) const {
    return Coordinate((x + scalar), (y + scalar), (z + scalar));
}

Coordinate Coordinate::operator-(const float scalar) const {
    return Coordinate((x - scalar), (y - scalar), (z - scalar));
}

Coordinate Coordinate::operator*(const float scalar) const {
    return Coordinate((x * scalar), (y * scalar), (z * scalar));
}

Coordinate Coordinate::operator/(const float scalar) const {
    return Coordinate((x / scalar), (y / scalar), (z / scalar));
}

Coordinate Coordinate::operator%(const float scalar) const {
    return Coordinate((x % scalar), (y % scalar), (z % scalar));
}

Coordinate Coordinate::operator+(const Quantity& scalar) const {
    return Coordinate((x + scalar), (y + scalar), (z + scalar));
}

Coordinate Coordinate::operator-(const Quantity& scalar) const {
    return Coordinate((x - scalar), (y - scalar), (z - scalar));
}

Coordinate Coordinate::operator*(const Quantity& scalar) const {
    return Coordinate((x * scalar), (y * scalar), (z * scalar));
}

Coordinate Coordinate::operator/(const Quantity& scalar) const {
    return Coordinate((x / scalar), (y / scalar), (z / scalar));
}

Coordinate Coordinate::operator%(const Quantity& scalar) const {
    return Coordinate((x % scalar), (y % scalar), (z % scalar));
}

Coordinate Coordinate::operator+(const Distance& scalar) const {
    return Coordinate((x + scalar), (y + scalar), (z + scalar));
}

Coordinate Coordinate::operator-(const Distance& scalar) const {
    return Coordinate((x - scalar), (y - scalar), (z - scalar));
}

Coordinate Coordinate::operator*(const Distance& scalar) const {
    return Coordinate((x * scalar), (y * scalar), (z * scalar));
}

Coordinate Coordinate::operator/(const Distance& scalar) const {
    return Coordinate((x / scalar), (y / scalar), (z / scalar));
}

Coordinate Coordinate::operator%(const Distance& scalar) const {
    return Coordinate((x % scalar), (y % scalar), (z % scalar));
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
    return x.getIntrinsic();
}

void Coordinate::setStressFactorX(const float orientation) {
    x.setIntrinsic(orientation);
}

void Coordinate::setStressFactorX(const Azimuth& orientation) {
    x.setIntrinsic(orientation);
}

Polar Coordinate::getDopplerShiftX() const {
    return x.getVertical();
}

void Coordinate::setDopplerShiftX(const float relativity) {
    x.setVertical(relativity);
}

void Coordinate::setDopplerShiftX(const Polar& relativity) {
    x.setVertical(relativity);
}

void Coordinate::setChangeXMagnitude(const float motion) {
    x.setChangeMagnitude(motion);
}

void Coordinate::setChangeXDirection(const float degree) {
    x.setChangeIntrinsic(degree);
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
    return y.getIntrinsic();
}

void Coordinate::setStressFactorY(const float orientation) {
    y.setIntrinsic(orientation);
}

void Coordinate::setStressFactorY(const Azimuth& orientation) {
    y.setIntrinsic(orientation);
}

Polar Coordinate::getDopplerShiftY() const {
    return y.getVertical();
}

void Coordinate::setDopplerShiftY(const float relativity) {
    y.setVertical(relativity);
}

void Coordinate::setDopplerShiftY(const Polar& relativity) {
    y.setVertical(relativity);
}

void Coordinate::setChangeYMagnitude(const float motion) {
    y.setChangeMagnitude(motion);
}

void Coordinate::setChangeYDirection(const float degree) {
    y.setChangeIntrinsic(degree);
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
    return z.getIntrinsic();
}

void Coordinate::setStressFactorZ(const float orientation) {
    z.setIntrinsic(orientation);
}

void Coordinate::setStressFactorZ(const Azimuth& orientation) {
    z.setIntrinsic(orientation);
}

Polar Coordinate::getDopplerShiftZ() const {
    return z.getVertical();
}

void Coordinate::setDopplerShiftZ(const float relativity) {
    z.setVertical(relativity);
}

void Coordinate::setDopplerShiftZ(const Polar& relativity) {
    z.setVertical(relativity);
}

void Coordinate::setChangeZMagnitude(const float motion) {
    z.setChangeMagnitude(motion);
}

void Coordinate::setChangeZDirection(const float degree) {
    z.setChangeIntrinsic(degree);
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

Distance Coordinate::getDotProduct(const Coordinate& peer) const {
    Distance result = (x * peer.x) + (y * peer.y) + (z * peer.z);
    return result;
}

Coordinate Coordinate::getCrossProduct(const Coordinate& peer) const {
    Coordinate result;
    result = Coordinate((y * peer.z - z * peer.y), (z * peer.x - x * peer.z), (x * peer.y - y * peer.x));
    return result;
}

Coordinate Coordinate::getRotation(const Coordinate& v, const Coordinate& axis, const float angle) const {
    Coordinate result;
    float cos_theta = std::cos(angle), sin_theta = std::sin(angle);
    float one_minus_cos = (1.0f - cos_theta);
    result.x = v.x * ((axis.x * axis.x * one_minus_cos) + cos_theta)
                + v.y * ((axis.x * axis.y * one_minus_cos) - (axis.z * sin_theta))
                + v.z * ((axis.x * axis.z * one_minus_cos) + (axis.y * sin_theta));
    result.y = v.x * ((axis.y * axis.x * one_minus_cos) + (axis.z * sin_theta))
                + v.y * ((axis.y * axis.y * one_minus_cos) + cos_theta)
                + v.z * ((axis.y * axis.z * one_minus_cos) - (axis.x * sin_theta));
    result.z = v.x * ((axis.z * axis.x * one_minus_cos) - (axis.y * sin_theta))
                + v.y * ((axis.z * axis.y * one_minus_cos) + (axis.x * sin_theta))
                + v.z * ((axis.z * axis.z * one_minus_cos) + cos_theta);
    return result;
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