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

#include "time.h"

namespace qft {

const std::string Time::UNIT = "s";                 // System International
const short int Time::ATOMIC_SCALE = -17;           // 10^-17 s
const float Time::ATOMIC_UNIT = 2.4188843265864f;   // 2.41 x 10^-17 s
const long Time::RADIATION_PERIODS = 9192631770;    // 9,192,631,770 fluctuations

Time::Time()
        : shp::Quantity(ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(std::string name)
        : shp::Quantity(ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(const shp::Unit& unit)
        : shp::Quantity(ATOMIC_SCALE, unit), name() {

}

Time::Time(const float time)
        : shp::Quantity(time, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(const float time, const shp::Unit& unit)
        : shp::Quantity(time, ATOMIC_SCALE, unit), name() {

}

Time::Time(const float time, const short int scaling)
        : shp::Quantity(time, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(const float time, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(time, scaling, unit), name() {

}

Time::Time(std::string name, const shp::Unit& unit)
        : shp::Quantity(ATOMIC_SCALE, unit), name(name) {

}

Time::Time(std::string name, const float time)
        : shp::Quantity(time, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(std::string name, const float time, const shp::Unit& unit)
        : shp::Quantity(time, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(std::string name, const float time, const short int scaling)
        : shp::Quantity(time, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(std::string name, const float time, const short int scaling, const shp::Unit& unit)
        : shp::Quantity(time, scaling, unit), name(name) {

}

Time::Time(std::string name, const shp::Quantity& quantity)
    : shp::Quantity(quantity), name(name) {

}

Time::~Time() {

}

bool Time::operator==(const Time& peer) const {
    return (static_cast<const shp::Quantity&>(*this) == static_cast<const shp::Quantity&>(peer))
        && (name == peer.name);
}

Time Time::operator+(const Time& peer) const {
    Quantity self = *this, other = peer;
    Quantity duration = (self + other);
    return Time("+", duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator-(const Time& peer) const {
    Quantity self = *this, other = peer;
    Quantity duration = (self - other);
    return Time("-", duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator*(const Time& peer) const {
    Quantity self = *this, other = peer;
    Quantity duration = (self * other);
    return Time("*", duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator/(const Time& peer) const {
    Quantity self = *this, other = peer;
    Quantity duration = (self / other);
    return Time("/", duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator%(const Time& peer) const {
    Quantity self = *this, other = peer;
    Quantity duration = (self % other);
    return Time("%", duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

shp::Quantity Time::getTotal() const {
    shp::Quantity result(getMagnitude(), getScaling(), getUnit());
    return result;
}

long Time::getSeconds() const {
    std::chrono::duration<float> period(getMagnitude());
    std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(period);
    long result = seconds.count();
    return result;
}

long Time::getMilliseconds() const {
    std::chrono::duration<float> period(getMagnitude());
    std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(period);
    long result = milliseconds.count();
    return result;
}

long long Time::getNanoseconds() const {
    std::chrono::duration<float> period(getMagnitude());
    std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(period);
    long long result = nanoseconds.count();
    return result;
}

Time Time::copy() {
    Time fresh(name, getMagnitude(), getScaling(), getUnit());
    return fresh;
}

void Time::clear() {
    shp::Quantity::clear();
    name.clear();
    return;
}

std::string Time::print() {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TIME) << ":";
    result << shp::Quantity::print();
	return result.str();
}

} // namespace qft