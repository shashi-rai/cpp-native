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

const float Phase::DEFAULT_VALUE = Quantity::DEFAULT_VALUE; // 0.0f
const std::time_t Phase::DEFAULT_TIME = Phase::getSystem(); // 0L

Phase::Phase()
    : Point(), polarization(DEFAULT_VALUE), timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float gradient)
        : Point(gradient), polarization(DEFAULT_VALUE),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float amplitude, const float gradient)
        : Point(amplitude, gradient), polarization(DEFAULT_VALUE),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(const float amplitude, const float polarization, const float azimuthal)
        : Point(amplitude, azimuthal), polarization(polarization),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(std::string name)
    : Point(name), polarization(DEFAULT_VALUE), timestamp(DEFAULT_TIME) {

}

Phase::Phase(std::string name, const float gradient)
        : Point(name, gradient), polarization(DEFAULT_VALUE),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(std::string name, const float amplitude, const float gradient)
        : Point(name, amplitude, gradient), polarization(DEFAULT_VALUE),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(std::string name, const float amplitude, const float polarization, const float azimuthal)
        : Point(name, amplitude, azimuthal), polarization(polarization),
        timestamp(DEFAULT_TIME) {

}

Phase::Phase(std::string name, const std::time_t timestamp)
        : Point(name), polarization(DEFAULT_VALUE), timestamp(timestamp) {

}

Phase::Phase(std::string name, const float gradient, const std::time_t timestamp)
        : Point(name, gradient), polarization(DEFAULT_VALUE), timestamp(timestamp) {

}

Phase::Phase(std::string name, const float amplitude, const float gradient, const std::time_t timestamp)
        : Point(name, amplitude, gradient), polarization(DEFAULT_VALUE),
        timestamp(timestamp) {

}

Phase::Phase(std::string name, const float amplitude, const float polarization, const float azimuthal,
        const std::time_t timestamp)
        : Point(name, amplitude, azimuthal), polarization(polarization),
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
        ap1 = self.toAzimuthalComplex(self.getGradient()),
        ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 + ap2;
    std::complex<float>
        pp1 = self.toPolarizationComplex(self.polarization),
        pp2 = other.toPolarizationComplex(peer.polarization);
    std::complex<float> p_phasor = pp1 + pp2;
    Phase result = Phase("+", std::arg(p_phasor), std::arg(a_phasor), (timestamp + peer.timestamp));
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

Phase Phase::operator-(const Phase& peer) const {
    Phase self = *this, other = peer;
    std::complex<float>
        ap1 = self.toAzimuthalComplex(self.getGradient()),
        ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 - ap2;
    std::complex<float>
        pp1 = self.toPolarizationComplex(self.polarization),
        pp2 = other.toPolarizationComplex(peer.polarization);
    std::complex<float> p_phasor = pp1 - pp2;
    Phase result = Phase("-", std::arg(p_phasor), std::arg(a_phasor), (timestamp - peer.timestamp));
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

Angular Phase::getOrientation() const {
    Direction polarity(polarization);
    Direction azimuth(getGradient());
    Angular result(Angular::DEFAULT_RADIUS, polarity, azimuth);
    return result;
}

Point Phase::copy() {
    Phase fresh(getName(), getPolarization(), getGradient(), timestamp);
    return fresh;
}

void Phase::clear() {
    Shape::clear();
    polarization = DEFAULT_VALUE;
	timestamp = DEFAULT_TIME;
    return;
}

std::string Phase::print() {
    std::stringstream result;
    result << "[Φ:";
	result << Point::print() << ",𝜃:";
    result << polarization << ",t:";
    result << std::put_time(std::localtime(&timestamp), "[%Y-%m-%d %H:%M:%S]");
    result << "]:";
	return result.str();
}

float Phase::getAmplitudePolarization(float change) const {
    return getAmplitude() * cos(polarization + change);
}

std::complex<float> Phase::toPolarizationComplex(float change) {
    return std::complex<float>(getAmplitude() * std::cos(change), getAmplitude() * std::sin(change));
}

const std::time_t Phase::getSystem() {
    return std::time(nullptr);
}

} // namespace shp