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

Phase::Phase() : Point(), polarization(0.0f), timestamp(0L) {

}

Phase::Phase(float gradient) : Point(gradient), polarization(0.0f), timestamp(0L) {

}

Phase::Phase(float polarization, float azimuthal)
        : Point(azimuthal), polarization(polarization), timestamp(0L) {

}

Phase::Phase(std::string name) : Point(name), polarization(0.0f), timestamp(0L) {

}

Phase::Phase(std::string name, float gradient)
        : Point(name, gradient), polarization(0.0f), timestamp(0L) {

}

Phase::Phase(std::string name, float polarization, float azimuthal)
        : Point(name, azimuthal), polarization(polarization), timestamp(0L) {

}

Phase::Phase(std::string name, long timestamp)
        : Point(name), polarization(0.0f), timestamp(timestamp) {

}

Phase::Phase(std::string name, float gradient, long timestamp)
        : Point(name, gradient), polarization(0.0f), timestamp(timestamp) {

}

Phase::Phase(std::string name, float polarization, float azimuthal, long timestamp)
        : Point(name, azimuthal), polarization(polarization), timestamp(timestamp) {

}

Phase::~Phase() {

}

bool Phase::operator==(const Phase& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (polarization == peer.polarization) && (timestamp == peer.timestamp);
}

Phase Phase::operator+(const Phase& peer) const {
    Phase result = Phase("+",
        (polarization + peer.polarization),
        (this->getGradient() + peer.getGradient()),
        (timestamp + peer.timestamp));
    result.setAmplitude(getPolarAmplitudeAscent(peer));
    return result;
}

Phase Phase::operator-(const Phase& peer) const {
    Phase result = Phase("-",
        (polarization - peer.polarization),
        (this->getGradient() - peer.getGradient()),
        (timestamp - peer.timestamp));
    result.setAmplitude(getPolarAmplitudeDescent(peer));
    return result;
}

Angular Phase::getOrientation() const {
    Direction polarity(polarization);
    Direction azimuth(getGradient());
    Angular result(0, polarity, azimuth);
    return result;
}

Point Phase::copy() {
    Phase fresh(this->getName(), this->getPolarization(), this->getGradient(), timestamp);
    return fresh;
}

void Phase::clear() {
    Shape::clear();
    polarization = 0.0f;
	timestamp = 0L;
    return;
}

std::string Phase::print() {
    std::stringstream result;
    result << "[Φ:";
	result << Point::print() << ",𝜃:";
    result << polarization << ",t:";
    result << timestamp << "]:";
	return result.str();
}

float Phase::getPolarAmplitudeAscent(const Phase& peer) const {
    return getAmplitudePolarization(peer, (polarization - peer.polarization));
}

float Phase::getPolarAmplitudeDescent(const Phase& peer) const {
    return getAmplitudePolarization(peer, (polarization + peer.polarization));
}

float Phase::getAmplitudePolarization(const Point& peer, float phase) const {
    float R_squared =
            (getAmplitude() * getAmplitude()) + (peer.getAmplitude() * peer.getAmplitude())
            + (2 * getAmplitude() * peer.getAmplitude()) * cos(phase);

    return std::sqrt(std::max(0.0f, R_squared));
}

} // namespace shp