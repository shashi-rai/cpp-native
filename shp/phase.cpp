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

#include "phase.h"

namespace shp {

const std::time_t Phase::DEFAULT_TIME = Phase::getSystem(); // 0L

Phase::Phase()
        : Point(), polarization(Direction::DEFAULT_RADIANS), timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float gradient)
        : Point(gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const Azimuth& gradient)
        : Point(gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const Polar& polarization)
        : Point(), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const float gradient)
        : Point(magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const Azimuth& gradient)
        : Point(magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling,
        const Azimuth& gradient)
        : Point(magnitude, scaling, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const std::string unit,
        const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const Unit& unit,
        const Azimuth& gradient)
        : Point(magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const Polar& polarization)
        : Point(magnitude), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling,
        const Polar& polarization)
        : Point(magnitude, scaling), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization)
        : Point(magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization)
        : Point(magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const float polarization, const float azimuthal)
        : Point(magnitude, azimuthal), polarization(polarization),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const Polar& polarization, const Azimuth& azimuthal)
        : Point(magnitude, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(magnitude, scaling, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name)
    : Point(name), polarization(Direction::DEFAULT_RADIANS), timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float gradient)
        : Point(name, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const Azimuth& gradient)
        : Point(name, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const Polar& polarization)
        : Point(name), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const float gradient)
        : Point(name, magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const Azimuth& gradient)
        : Point(name, magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
        const Azimuth& gradient)
        : Point(name, magnitude, scaling, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
        const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Azimuth& gradient)
        : Point(name, magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude,
        const Polar& polarization)
        : Point(name, magnitude), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
        const Polar& polarization)
        : Point(name, magnitude, scaling), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization)
        : Point(name, magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization)
        : Point(name, magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const float polarization, const float azimuthal)
        : Point(name, magnitude, azimuthal), polarization(polarization),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(name, magnitude, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(name, magnitude, scaling, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(name, magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal)
        : Point(name, magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(DEFAULT_TIME) {

}


Phase::Phase(const std::string name, const std::time_t timestamp)
        : Point(name), polarization(Direction::DEFAULT_RADIANS), timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float gradient, const std::time_t timestamp)
        : Point(name, gradient), polarization(Direction::DEFAULT_RADIANS), timestamp(timestamp) {

}

Phase::Phase(const std::string name, const Azimuth& gradient, const std::time_t timestamp)
        : Point(name, gradient), polarization(Direction::DEFAULT_RADIANS), timestamp(timestamp) {

}

Phase::Phase(const std::string name, const Polar& polarization, const std::time_t timestamp)
        : Point(name), polarization(polarization.toRadians()), timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const float gradient, const std::time_t timestamp)
        : Point(name, magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude,
    const Azimuth& gradient, const std::time_t timestamp)
        : Point(name, magnitude, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
    const Azimuth& gradient, const std::time_t timestamp)
        : Point(name, magnitude, scaling, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
    const Azimuth& gradient, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
    const Azimuth& gradient, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit, gradient), polarization(Direction::DEFAULT_RADIANS),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
        const Polar& polarization, const std::time_t timestamp)
        : Point(name, magnitude, scaling), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude,
        const Polar& polarization, const std::time_t timestamp)
        : Point(name, magnitude), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude,
        const float polarization, const float azimuthal, const std::time_t timestamp)
        : Point(name, magnitude, azimuthal), polarization(polarization),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude,
        const Polar& polarization, const Azimuth& azimuthal, const std::time_t timestamp)
        : Point(name, magnitude, azimuthal), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling,
        const Polar& polarization, const Azimuth& azimuthal, const std::time_t timestamp)
        : Point(name, magnitude, scaling, azimuthal), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization, const Azimuth& azimuthal, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::Phase(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal, const std::time_t timestamp)
        : Point(name, magnitude, scaling, unit, azimuthal), polarization(polarization.toRadians()),
        timestamp(timestamp) {

}

Phase::~Phase() {

}

bool Phase::operator==(const Phase& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (polarization == peer.polarization) && (timestamp == peer.timestamp);
}

Phase Phase::operator+(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(other.getGradient());
    std::complex<float> a_phasor = (ap1 + ap2);
    std::complex<float>
        pp1 = self.toComplexPolar(self.polarization),
        pp2 = other.toComplexPolar(other.polarization);
    std::complex<float> p_phasor = (pp1 + pp2);
    Phase result = Phase("+", std::abs(p_phasor), self.getScaling(), self.getUnit(),
        std::arg(p_phasor), std::arg(a_phasor), (timestamp + peer.timestamp));
    return result;
}

Phase Phase::operator-(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(other.getGradient());
    std::complex<float> a_phasor = (ap1 - ap2);
    std::complex<float>
        pp1 = self.toComplexPolar(self.polarization),
        pp2 = other.toComplexPolar(other.polarization);
    std::complex<float> p_phasor = (pp1 - pp2);
    Phase result = Phase("-", std::abs(p_phasor), self.getScaling(), self.getUnit(),
        std::arg(p_phasor), std::arg(a_phasor), (timestamp - peer.timestamp));
    return result;
}

Phase Phase::operator*(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(other.getGradient());
    std::complex<float> a_phasor = (ap1 * ap2);
    std::complex<float>
        pp1 = self.toComplexPolar(self.polarization),
        pp2 = other.toComplexPolar(other.polarization);
    std::complex<float> p_phasor = (pp1 * pp2);
    Phase result = Phase("*", std::abs(p_phasor), (self.getScaling() + other.getScaling()), self.getUnit(),
        std::arg(p_phasor), std::arg(a_phasor), (timestamp * peer.timestamp));
    return result;
}

Phase Phase::operator/(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(other.getGradient());
    std::complex<float> a_phasor;
	if (ap2 == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		a_phasor = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		a_phasor = (ap1 / ap2);
	}
    std::complex<float>
        pp1 = self.toComplexPolar(self.polarization),
        pp2 = other.toComplexPolar(other.polarization);
    std::complex<float> p_phasor;
	if (pp2 == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		p_phasor = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		p_phasor = (pp1 / pp2);
	}
    Phase result = Phase("/", std::abs(p_phasor), (self.getScaling() - other.getScaling()), self.getUnit(),
        std::arg(p_phasor), std::arg(a_phasor), (timestamp / peer.timestamp));
    return result;
}

Phase Phase::operator%(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(other.getGradient());
    std::complex<float> a_phasor;
	if (ap2 == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		a_phasor = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		std::complex<float> quotient = (ap1 / ap2);
    	std::complex<float> cycles(std::trunc(quotient.real()), std::trunc(quotient.imag()));
    	a_phasor = (ap1 - (cycles * ap2));
	}
    std::complex<float>
        pp1 = self.toComplexPolar(self.polarization),
        pp2 = other.toComplexPolar(other.polarization);
    std::complex<float> p_phasor;
	if (pp2 == std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE)) {
		p_phasor = std::complex<float>(shp::Quantity::DEFAULT_VALUE, shp::Quantity::DEFAULT_VALUE);
	} else {
		std::complex<float> quotient = (pp1 / pp2);
    	std::complex<float> cycles(std::trunc(quotient.real()), std::trunc(quotient.imag()));
    	p_phasor = (pp1 - (cycles * pp2));
	}
    Phase result = Phase("%", std::abs(p_phasor), self.getScaling(), self.getUnit(),
        std::arg(p_phasor), std::arg(a_phasor), (timestamp % peer.timestamp));
    return result;
}

void Phase::setPolarization(const Direction& orientation) {
    polarization = orientation.toRadians();
}

Angular Phase::getOrientation() const {
    Phase self = *this;
    Distance radius = self.getMagnitude();
    Polar polarity(self.polarization);
    Azimuth azimuthal(self.getGradient());
    Angular result(Distance(radius.getMagnitude(), radius.getScaling()), polarity, azimuthal);
    return result;
}

Point Phase::copy() const {
    Phase self = *this;
    Phase fresh(self.getName(), self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getPolarization(), self.getGradient(), self.timestamp);
    return fresh;
}

void Phase::clear() {
    Point::clear();
    polarization = Direction::DEFAULT_RADIANS;
	timestamp = DEFAULT_TIME;
    return;
}

std::string Phase::print() {
    std::stringstream result;
    result << "[Φ:";
	result << Point::print() << ",𝜃:";
    result << polarization << ",t:";
    if (timestamp != DEFAULT_TIME) {
        result << std::put_time(std::localtime(&timestamp), "[%Y-%m-%d %H:%M:%S]");
    }
    result << "]:";
	return result.str();
}

Quantity Phase::getPolarCosComponent(const float change) const {
    Signal signal = Point::getSignal();
    float amplitude = signal.getCosComponent(polarization + change);
    return Quantity(amplitude, Point::getScaling(), Point::getUnit());
}

Quantity Phase::getPolarSinComponent(const float change) const {
    Signal signal = Point::getSignal();
    float amplitude = signal.getSinComponent(polarization + change);
    return Quantity(amplitude, Point::getScaling(), Point::getUnit());
}

std::complex<float> Phase::toComplexPolar(const float change) {
    Signal signal = Point::getSignal();
    return std::complex<float>(
        signal.getCosComponent(change),
        signal.getSinComponent(change));
}

const std::time_t Phase::getSystem() {
    return std::time(nullptr);
}

} // namespace shp