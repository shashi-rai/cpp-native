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
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
        name() {

}

Time::Time(std::string name)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
        name(name) {

}

Time::Time(const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit), name() {

}

Time::Time(std::string name, const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(const float duration)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(const float duration, const std::string unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, unit), name() {

}

Time::Time(const float duration, const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, unit), name() {

}

Time::Time(const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, scaling, unit), name() {

}

Time::Time(const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, scaling, unit), name() {

}

Time::Time(const float change, const float duration)
        : shp::Temporal(change,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(const float change, const float duration, const short int scaling)
        : shp::Temporal(change,
            duration, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name() {

}

Time::Time(const float change, const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(change,
            duration, scaling, unit), name() {

}

Time::Time(const float change, const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(change,
            duration, scaling, unit), name() {

}

Time::Time(const shp::Direction& change, const float duration, const short int scaling,
        const std::string unit)
        : shp::Temporal(change, duration, scaling, unit), name() {

}

Time::Time(const shp::Direction& change, const float duration, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(change, duration, scaling, unit), name() {

}

Time::Time(std::string name, const float duration)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(std::string name, const float duration, const std::string unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(std::string name, const float duration, const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(std::string name, const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, scaling, unit), name(name) {

}

Time::Time(std::string name, const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(shp::Direction::DEFAULT_RADIANS,
            duration, scaling, unit), name(name) {

}

Time::Time(std::string name, const float change, const float duration)
        : shp::Temporal(change,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(std::string name, const float change, const float duration, const short int scaling)
        : shp::Temporal(change,
            duration, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(std::string name, const float change, const float duration, const short int scaling,
        const std::string unit)
        : shp::Temporal(change, duration, scaling, unit), name(name) {

}

Time::Time(std::string name, const float change, const float duration, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(change, duration, scaling, unit), name(name) {

}

Time::Time(std::string name, const shp::Direction& change,
        const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(change, duration, scaling, unit), name(name) {

}

Time::Time(std::string name, const shp::Direction& change,
        const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(change, duration, scaling, unit), name(name) {

}

Time::~Time() {

}

bool Time::operator==(const Time& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (name == peer.name);
}

Time Time::operator+(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self + other);
    return Time("+", duration.getChange(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator-(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self - other);
    return Time("-", duration.getChange(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator*(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self * other);
    return Time("*", duration.getChange(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator/(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self / other);
    return Time("/", duration.getChange(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator%(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self % other);
    return Time("%", duration.getChange(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

shp::Quantity Time::getTotal() const {
    shp::Temporal result(getChange(), getMagnitude(), getScaling(), getUnit());
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

shp::Temporal Time::copy() {
    Time fresh(name, getChange(), getMagnitude(), getScaling(), getUnit());
    return fresh;
}

void Time::clear() {
    shp::Temporal::clear();
    name.clear();
    return;
}

std::string Time::print() {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TIME) << ":";
    result << shp::Temporal::print();
	return result.str();
}

} // namespace qft