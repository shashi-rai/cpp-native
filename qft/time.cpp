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
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TIME)),
        name() {

}

Time::Time(const std::string name)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE,
            shp::Unit::getBaseSymbol(shp::Unit::TIME)),
        name(name) {

}

Time::Time(const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit),
		name() {

}

Time::Time(const std::string name, const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            shp::Quantity::DEFAULT_VALUE, ATOMIC_SCALE, unit),
		name(name) {

}

Time::Time(const float duration)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		name() {

}

Time::Time(const float duration, const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, unit),
		name() {

}

Time::Time(const float duration, const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, unit),
		name() {

}

Time::Time(const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, scaling, unit),
		name() {

}

Time::Time(const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, scaling, unit),
		name() {

}

Time::Time(const float modulation, const float duration)
        : shp::Temporal(modulation,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		name() {

}

Time::Time(const float modulation, const float duration, const short int scaling)
        : shp::Temporal(modulation,
            duration, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)),
		name() {

}

Time::Time(const float modulation, const float duration, const short int scaling,
		const std::string unit)
        : shp::Temporal(modulation, duration, scaling, unit),
		name() {

}

Time::Time(const float modulation, const float duration, const short int scaling,
		const shp::Unit& unit)
        : shp::Temporal(modulation, duration, scaling, unit),
		name() {

}

Time::Time(const shp::Signal& modulation)
        : shp::Temporal(modulation), name() {

}

Time::Time(const shp::Signal& modulation, const std::string unit)
        : shp::Temporal(modulation, unit), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Unit& unit)
        : shp::Temporal(modulation, unit), name() {

}

Time::Time(const shp::Signal& modulation, const float duration)
        : shp::Temporal(modulation, duration, modulation.getUnit()), name() {

}

Time::Time(const shp::Signal& modulation, const float duration, const std::string unit)
        : shp::Temporal(modulation, duration, unit), name() {

}

Time::Time(const shp::Signal& modulation, const float duration, const shp::Unit& unit)
        : shp::Temporal(modulation, duration, unit), name() {

}

Time::Time(const shp::Signal& modulation, const float duration, const short int scaling,
        const std::string unit)
        : shp::Temporal(modulation, duration, scaling, unit), name() {

}

Time::Time(const shp::Signal& modulation, const float duration, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(modulation, duration, scaling, unit), name() {

}

Time::Time(const shp::Azimuth& dilation)
        : shp::Temporal(dilation), name() {

}

Time::Time(const shp::Azimuth& dilation, const std::string unit)
        : shp::Temporal(dilation, unit), name() {

}

Time::Time(const shp::Azimuth& dilation, const shp::Unit& unit)
        : shp::Temporal(dilation, unit), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration)
        : shp::Temporal(dilation, duration), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration, const std::string unit)
        : shp::Temporal(dilation, duration, unit), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration, const shp::Unit& unit)
        : shp::Temporal(dilation, duration, unit), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration, const short int scaling)
        : shp::Temporal(dilation, duration, scaling), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration, const short int scaling,
		const std::string unit)
        : shp::Temporal(dilation, duration, scaling, unit), name() {

}

Time::Time(const shp::Azimuth& dilation, const float duration, const short int scaling,
		const shp::Unit& unit)
        : shp::Temporal(dilation, duration, scaling, unit), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Azimuth& dilation)
        : shp::Temporal(modulation, dilation, modulation.getUnit()), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Azimuth& dilation, const float duration)
        : shp::Temporal(modulation, dilation, duration, modulation.getUnit()), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Azimuth& dilation, const float duration,
        const short int scaling)
        : shp::Temporal(modulation, dilation, duration, scaling), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Azimuth& dilation, const float duration,
        const short int scaling, const std::string unit)
        : shp::Temporal(modulation, dilation, duration, scaling, unit), name() {

}

Time::Time(const shp::Signal& modulation, const shp::Azimuth& dilation, const float duration,
        const short int scaling, const shp::Unit& unit)
        : shp::Temporal(modulation, dilation, duration, scaling, unit), name() {

}

Time::Time(const std::string name, const float duration)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(const std::string name, const float duration, const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(const std::string name, const float duration, const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, ATOMIC_SCALE, unit), name(name) {

}

Time::Time(const std::string name, const float duration, const short int scaling)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE, duration, scaling), name(name) {

}

Time::Time(const std::string name, const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(shp::Quantity::DEFAULT_VALUE,
            duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const float modulation, const float duration)
        : shp::Temporal(modulation,
            duration, ATOMIC_SCALE, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(const std::string name, const float modulation, const float duration, const short int scaling)
        : shp::Temporal(modulation,
            duration, scaling, shp::Unit::getBaseSymbol(shp::Unit::TIME)), name(name) {

}

Time::Time(const std::string name, const float modulation, const float duration, const short int scaling,
        const std::string unit)
        : shp::Temporal(modulation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const float modulation, const float duration, const short int scaling,
        const shp::Unit& unit)
        : shp::Temporal(modulation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation)
        : shp::Temporal(dilation), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation, const std::string unit)
        : shp::Temporal(dilation, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation, const shp::Unit& unit)
        : shp::Temporal(dilation, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation, const float duration)
        : shp::Temporal(dilation, duration), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation, const float duration,
		const std::string unit)
        : shp::Temporal(dilation, duration, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation, const float duration,
		const shp::Unit& unit)
        : shp::Temporal(dilation, duration, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation,
        const float duration, const short int scaling)
        : shp::Temporal(dilation, duration, scaling), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation,
        const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(dilation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Azimuth& dilation,
        const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(dilation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation)
        : shp::Temporal(modulation), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const std::string unit)
        : shp::Temporal(modulation, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Unit& unit)
        : shp::Temporal(modulation, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const float duration)
        : shp::Temporal(modulation, duration, modulation.getUnit()), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const float duration,
		const std::string unit)
        : shp::Temporal(modulation, duration, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const float duration,
		const shp::Unit& unit)
        : shp::Temporal(modulation, duration, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation,
        const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(modulation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation,
        const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(modulation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Azimuth& dilation)
        : shp::Temporal(modulation, dilation), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Azimuth& dilation,
        const float duration)
        : shp::Temporal(modulation, dilation, duration), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Azimuth& dilation,
        const float duration, const short int scaling)
        : shp::Temporal(modulation, dilation, duration, scaling), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Azimuth& dilation,
        const float duration, const short int scaling, const std::string unit)
        : shp::Temporal(modulation, dilation, duration, scaling, unit), name(name) {

}

Time::Time(const std::string name, const shp::Signal& modulation, const shp::Azimuth& dilation,
        const float duration, const short int scaling, const shp::Unit& unit)
        : shp::Temporal(modulation, dilation, duration, scaling, unit), name(name) {

}

Time::~Time() {

}

bool Time::operator==(const Time& peer) const {
    return (static_cast<const shp::Temporal&>(*this) == static_cast<const shp::Temporal&>(peer))
        && (name == peer.name);
}

bool Time::operator<(const Time& peer) const {
    return (static_cast<const shp::Temporal&>(*this) < static_cast<const shp::Temporal&>(peer));
}

bool Time::operator>(const Time& peer) const {
    return (static_cast<const shp::Temporal&>(*this) > static_cast<const shp::Temporal&>(peer));
}

bool Time::operator<=(const Time& peer) const {
    Time self = *this;
    return (self < peer) || (self == peer);
}

bool Time::operator>=(const Time& peer) const {
    Time self = *this;
    return (self > peer) || (self == peer);
}

Time Time::operator+(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self + other);
    return Time("+", duration.getSpatialDrift(), duration.getIntensityDrift(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator-(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self - other);
    return Time("-", duration.getSpatialDrift(), duration.getIntensityDrift(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator*(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self * other);
    return Time("*", duration.getSpatialDrift(), duration.getIntensityDrift(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator/(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self / other);
    return Time("/", duration.getSpatialDrift(), duration.getIntensityDrift(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

Time Time::operator%(const Time& peer) const {
    Temporal self = *this, other = peer;
    Temporal duration = (self % other);
    return Time("%", duration.getSpatialDrift(), duration.getIntensityDrift(),
        duration.getMagnitude(), duration.getScaling(), duration.getUnit());
}

shp::Signal Time::getEntropy() const {
    return shp::Temporal::getModulation();
}

void Time::setEntropy(const shp::Signal& traversal) {
    shp::Temporal::setModulation(traversal);
}

float Time::getMagnitude() const {
    return shp::Temporal::getMagnitude();
}

void Time::setMagnitude(const float value) {
    shp::Temporal::setMagnitude(value);
}

void Time::setMagnitude(const float value, const short int scale) {
    shp::Temporal::setMagnitude(value, scale);
}

void Time::setMagnitude(const float value, const short int scale, const std::string unit) {
    shp::Temporal::setMagnitude(value, scale, unit);
}

void Time::setMagnitude(const float value, const short int scale, const shp::Unit& unit) {
    shp::Temporal::setMagnitude(value, scale, unit);
}

float Time::getPeriod() const {
    return shp::Temporal::getIntensity();
}

float Time::getPeriodDrift() const {
    return shp::Temporal::getIntensityDrift();
}

void Time::setPeriodDrift(const shp::Azimuth& direction) {
    shp::Temporal::setIntensityDrift(direction.toRadians());
}

float Time::getDopplerShift() const {
    return shp::Temporal::getSpatialDrift();
}

void Time::setDopplerShift(const shp::Azimuth& curvature) {
	shp::Temporal::setSpatialDrift(curvature);
}

void Time::setDopplerShift(const float motion,
        const shp::Azimuth& curvature) {
	shp::Temporal::setSpatialDrift(motion, curvature);
}

void Time::setDopplerShift(const float motion, const short int scale,
        const shp::Azimuth& curvature) {
	shp::Temporal::setSpatialDrift(motion, scale, curvature);
}

void Time::setDopplerShift(const float motion, const short int scale, const std::string unit,
        const shp::Azimuth& curvature) {
	shp::Temporal::setSpatialDrift(motion, scale, unit, curvature);
}

void Time::setDopplerShift(const float motion, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& curvature) {
	shp::Temporal::setSpatialDrift(motion, scale, unit, curvature);
}

short int Time::getScaling() const {
    return shp::Temporal::getScaling();
}

void Time::setScaling(const short int factor) {
    shp::Temporal::setScaling(factor);
}

shp::Unit Time::getUnit() const {
    return shp::Temporal::getUnit();
}

void Time::setUnit(const shp::Unit& object) {
    shp::Temporal::setUnit(object);
}

bool Time::checkNonZero() const {
    return shp::Temporal::checkNonZero();
}

bool Time::checkInfinity() const {
    return shp::Temporal::checkInfinity();
}

short int Time::checkScaling(const float amount) const {
    return shp::Temporal::checkScaling(amount);
}

void Time::adjustNumeric() {
    return shp::Temporal::adjustNumeric();
}

void Time::adjustScaling() {
    shp::Temporal::adjustScaling();
}

shp::Quantity Time::getCurvature() const {
    return shp::Temporal::getPhaseShift();
}

shp::Quantity Time::getPhaseScaling() const {
    return shp::Temporal::getPhaseScaling();
}

shp::Quantity Time::getPeriodScaling() const {
    return shp::Temporal::getPeriodScaling();
}

shp::Signal Time::getLinearSpace() const {
    return shp::Temporal::getLinearSpace();
}

shp::Signal Time::getCurvedSpace() const {
    return shp::Temporal::getCurvedSpace();
}

shp::Frequency Time::getFrequency() const {
    shp::Signal frequency = shp::Temporal::getFrequency();
    return shp::Frequency(frequency.getMagnitude(), frequency.getScaling(), frequency.getUnit());
}

shp::Signal Time::getTotal() const {
    return shp::Temporal::getTotal();
}

long Time::getSeconds() const {
    Temporal self = *this;
    std::chrono::duration<float> period(self.getMagnitude());
    std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(period);
    long result = seconds.count();
    return result;
}

long Time::getMilliseconds() const {
    Temporal self = *this;
    std::chrono::duration<float> period(self.getMagnitude());
    std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(period);
    long result = milliseconds.count();
    return result;
}

long long Time::getNanoseconds() const {
    Temporal self = *this;
    std::chrono::duration<float> period(self.getMagnitude());
    std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(period);
    long long result = nanoseconds.count();
    return result;
}

Time Time::copy() {
    Time self = *this;
    Time fresh(name, self.getDopplerShift(), self.getPeriodDrift(),
        self.getMagnitude(), self.getScaling(), self.getUnit());
    return fresh;
}

void Time::clear() {
    shp::Temporal::clear();
    name.clear();
    return;
}

std::string Time::print() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TIME);
    result << shp::Temporal::print();
	return result.str();
}

std::string Time::printRadians() const {
    std::stringstream result;
    result << shp::Unit::getBaseDimension(shp::Unit::TIME);
    result << shp::Temporal::printRadians();
	return result.str();
}

std::shared_ptr<qft::Time> Time::shareable(const std::string name,
        const float ticking, const short int scaling) {
    std::shared_ptr<qft::Time> result = std::make_shared<qft::Time> (name, ticking, scaling);
    return result;
}

} // namespace qft