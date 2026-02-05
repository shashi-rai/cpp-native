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

#include "medium.h"

namespace shp {

Medium::Medium()
        : Distance(), name(), intrinsic() {

}

Medium::Medium(const Unit& unit)
        : Distance(unit), name(), intrinsic() {

}

Medium::Medium(const short int scaling, const std::string unit)
        : Distance(scaling, unit), name(), intrinsic() {

}

Medium::Medium(const short int scaling, const Unit& unit)
        : Distance(scaling, unit), name(), intrinsic() {

}

Medium::Medium(const float parameter)
        : Distance(parameter), name(), intrinsic() {

}

Medium::Medium(const float parameter, const shp::Signal& intrinsic)
        : Distance(parameter), name(), intrinsic(intrinsic) {

}

Medium::Medium(const float parameter, const std::string unit)
        : Distance(parameter, unit), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Unit& unit)
        : Distance(parameter, unit), name(), intrinsic() {

}

Medium::Medium(const float parameter, const std::string unit, const shp::Signal& intrinsic)
        : Distance(parameter, unit), name(), intrinsic(intrinsic) {

}

Medium::Medium(const float parameter, const Unit& unit, const shp::Signal& intrinsic)
        : Distance(parameter, unit), name(), intrinsic(intrinsic) {

}

Medium::Medium(const float parameter, const short int scaling)
        : Distance(parameter, scaling), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const shp::Signal& intrinsic)
        : Distance(parameter, scaling), name(), intrinsic(intrinsic) {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit)
        : Distance(parameter, scaling, unit), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit)
        : Distance(parameter, scaling, unit), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit, const shp::Signal& intrinsic)
        : Distance(parameter, scaling, unit), name(), intrinsic(intrinsic) {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit, const shp::Signal& intrinsic)
        : Distance(parameter, scaling, unit), name(), intrinsic(intrinsic) {

}

Medium::Medium(const Distance& parameter)
        : Distance(parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
            parameter.getModulation(), parameter.getAzimuth()), name(), intrinsic() {

}

Medium::Medium(const float parameter, const float orientation)
		: Distance(parameter, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const std::string unit, const float orientation)
		: Distance(parameter, unit, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const std::string unit, const Azimuth& orientation)
		: Distance(parameter, unit, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Unit& unit, const float orientation)
		: Distance(parameter, unit, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Unit& unit, const Azimuth& orientation)
		: Distance(parameter, unit, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const float orientation)
		: Distance(parameter, scaling, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Azimuth& orientation)
		: Distance(parameter, scaling, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const float orientation)
		: Distance(parameter, scaling, unit, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Azimuth& orientation)
		: Distance(parameter, scaling, unit, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const float orientation)
		: Distance(parameter, scaling, unit, Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Azimuth& orientation)
		: Distance(parameter, scaling, unit, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Polar& threshold)
		: Distance(parameter, scaling, unit, threshold), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Azimuth& orientation)
		: Distance(parameter, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Polar& threshold)
		: Distance(parameter, threshold), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Polar& threshold)
		: Distance(parameter, scaling, threshold), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, threshold, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, scaling, threshold, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const float threshold, const float orientation)
		: Distance(parameter, Polar(threshold), Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, std::string unit, const float threshold, const float orientation)
		: Distance(parameter, unit, Polar(threshold), Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Unit& unit, const float threshold, const float orientation)
		: Distance(parameter, unit, Polar(threshold), Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const Unit& unit, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, unit, threshold, orientation), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling, const float threshold, const float orientation)
		: Distance(parameter, scaling, Polar(threshold), Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling,
        const std::string unit, const float threshold, const float orientation)
		: Distance(parameter, scaling, unit, Azimuth(orientation), Polar(threshold)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling,
        const std::string unit, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, scaling, unit, orientation, threshold), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling,
        const Unit& unit, const float threshold, const float orientation)
		: Distance(parameter, scaling, unit, Polar(threshold), Azimuth(orientation)), name(), intrinsic() {

}

Medium::Medium(const float parameter, const short int scaling,
        const Unit& unit, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, scaling, unit, orientation, threshold), name(), intrinsic() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling,
        const Unit& unit, const Polar& threshold, const Azimuth& orientation)
		: Distance(parameter, scaling, unit, orientation, threshold), name(), intrinsic() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling,
        const Unit& unit, const Polar& threshold, const Azimuth& orientation, const shp::Signal& intrinsic)
		: Distance(parameter, scaling, unit, orientation, threshold), name(), intrinsic(intrinsic) {

}

Medium::Medium(const shp::Signal& intrinsic)
		: Distance(), name(), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name)
        : Distance(), name(name), intrinsic() {

}

Medium::Medium(const std::string name, const shp::Signal& intrinsic)
		: Distance(), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const std::string unit)
        : Distance(unit), name(name), intrinsic() {

}

Medium::Medium(const std::string name, const Unit& unit)
        : Distance(unit), name(name), intrinsic() {

}

Medium::Medium(const std::string name, const std::string unit, const shp::Signal& intrinsic)
        : Distance(unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const Unit& unit, const shp::Signal& intrinsic)
        : Distance(unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const float parameter, const shp::Signal& intrinsic)
        : Distance(parameter), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const short int scaling, const std::string unit, const shp::Signal& intrinsic)
        : Distance(scaling, unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const short int scaling, const Unit& unit, const shp::Signal& intrinsic)
        : Distance(scaling, unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const std::string unit)
        : Distance(parameter, scaling, unit), name(name), intrinsic() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit)
        : Distance(parameter, scaling, unit), name(name), intrinsic() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Signal& intrinsic)
        : Distance(parameter, scaling, unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit, const shp::Signal& intrinsic)
        : Distance(parameter, scaling, unit), name(name), intrinsic(intrinsic) {

}

Medium::Medium(const Azimuth& orientation)
		: Distance(orientation), name(), intrinsic() {

}

Medium::Medium(const Polar& threshold)
		: Distance(threshold), name(), intrinsic() {

}

Medium::Medium(const Polar& threshold, const Azimuth& orientation)
		: Distance(threshold, orientation), name(), intrinsic() {

}

Medium::~Medium() {

}

bool Medium::operator==(const Medium& peer) const {
    return (static_cast<const Distance&>(*this) == static_cast<const Distance&>(peer))
        && (name == peer.name);
}

bool Medium::operator<(const Medium& peer) const {
    Medium self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) < static_cast<const Distance&>(peer)) {
        result = true;
    }
    return result;
}

bool Medium::operator>(const Medium& peer) const {
    Medium self = *this; bool result = false;
    if (static_cast<const Distance&>(*this) > static_cast<const Distance&>(peer)) {
        result = true;
    }
    return result;
}

bool Medium::operator<=(const Medium& peer) const {
    Medium self = *this;
    return (self < peer) || (self == peer);
}

bool Medium::operator>=(const Medium& peer) const {
    Medium self = *this;
    return (self > peer) || (self == peer);
}

Medium Medium::operator+(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self + other);
    shp::Signal newIntrinsic = (this->intrinsic + peer.intrinsic);
    return Medium("+", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getModulation(), parameter.getAzimuth(), newIntrinsic);
}

Medium Medium::operator-(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self - other);
    shp::Signal newIntrinsic = (this->intrinsic - peer.intrinsic);
    return Medium("-", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getModulation(), parameter.getAzimuth(), newIntrinsic);
}

Medium Medium::operator*(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self * other);
    shp::Signal newIntrinsic = (this->intrinsic * peer.intrinsic);
    return Medium("*", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getModulation(), parameter.getAzimuth(), newIntrinsic);
}

Medium Medium::operator/(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self / other);
    shp::Signal newIntrinsic = (this->intrinsic / peer.intrinsic);
    return Medium("/", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getModulation(), parameter.getAzimuth(), newIntrinsic);
}

Medium Medium::operator%(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self % other);
    shp::Signal newIntrinsic = (this->intrinsic % peer.intrinsic);
    return Medium("%", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getModulation(), parameter.getAzimuth(), newIntrinsic);
}

Medium Medium::operator+(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() + parameter);
    return Medium("+", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getModulation(), newParameter.getAzimuth(), self.intrinsic);
}

Medium Medium::operator-(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() - parameter);
    return Medium("-" ,newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getModulation(), newParameter.getAzimuth(), self.intrinsic);
}

Medium Medium::operator*(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() * parameter);
    return Medium("*", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getModulation(), newParameter.getAzimuth(), self.intrinsic);
}

Medium Medium::operator/(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() / parameter);
    return Medium("/", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getModulation(), newParameter.getAzimuth(), self.intrinsic);
}

Medium Medium::operator%(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() % parameter);
    return Medium("%", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getModulation(), newParameter.getAzimuth(), self.intrinsic);
}

Medium Medium::operator+(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newParameter = (self.getAzimuth() + orientation);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newParameter, self.intrinsic);
}

Medium Medium::operator-(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newParameter = (self.getAzimuth() - orientation);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newParameter, self.intrinsic);
}

Medium Medium::operator*(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newParameter = (self.getAzimuth() * orientation);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newParameter, self.intrinsic);
}

Medium Medium::operator/(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newParameter = (self.getAzimuth() / orientation);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newParameter, self.intrinsic);
}

Medium Medium::operator%(const Azimuth& orientation) const {
    Medium self = *this;
    Azimuth newParameter = (self.getAzimuth() % orientation);
    return Medium("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), newParameter, self.intrinsic);
}

Medium Medium::operator+(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() + threshold);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth(), self.intrinsic);
}

Medium Medium::operator-(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() - threshold);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth(), self.intrinsic);
}

Medium Medium::operator*(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() * threshold);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth(), self.intrinsic);
}

Medium Medium::operator/(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() / threshold);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth(), self.intrinsic);
}

Medium Medium::operator%(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getModulation() % threshold);
    return Medium("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newThreshold, self.getAzimuth(), self.intrinsic);
}

Medium Medium::operator+(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newIntrinsic = (self.intrinsic + modulation);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth(), newIntrinsic);
}

Medium Medium::operator-(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newIntrinsic = (self.intrinsic - modulation);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth(), newIntrinsic);
}

Medium Medium::operator*(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newIntrinsic = (self.intrinsic * modulation);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth(), newIntrinsic);
}

Medium Medium::operator/(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newIntrinsic = (self.intrinsic / modulation);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth(), newIntrinsic);
}

Medium Medium::operator%(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newIntrinsic = (self.intrinsic % modulation);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getModulation(), self.getAzimuth(), newIntrinsic);
}

shp::Signal Medium::operator()(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    return getLinearDiffusion(peer, separation, position);
}

shp::Signal Medium::operator()(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    return getLinearDiffusion(peerX, peerY, separationX, separationY);
}

shp::Signal Medium::getLinearDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearX(position), bx = peer.getLinearX((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearXConvergence(position), bx = peer.getLinearXConvergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ax = self.getLinearXDivergence(position), bx = peer.getLinearXDivergence((separation - position));
    shp::Signal result = (ax - bx); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearY(position), by = peer.getLinearY((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearYConvergence(position), by = peer.getLinearYConvergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal ay = self.getLinearYDivergence(position), by = peer.getLinearYDivergence((separation - position));
    shp::Signal result = (ay - by); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDiffusion(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZ(position), bz = peer.getLinearZ((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdConvergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZConvergence(position), bz = peer.getLinearZConvergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDivergence(const Medium& peer,
        const Distance& separation, const Distance& position) const {
    Medium self = *this;
    shp::Signal az = self.getLinearZDivergence(position), bz = peer.getLinearZDivergence((separation - position));
    shp::Signal result = (az - bz); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDiffusion(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDiffusion(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getLinearDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getLinearDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getLinearDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getIntensifiedDiffusion(peerX, separationX, end);
    shp::Signal azimY = self.getIntensifiedDiffusion(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getIntensifiedConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getIntensifiedConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getIntensifiedDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getIntensifiedDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getIntensifiedDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDiffusion(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdDiffusion(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdDiffusion(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdConvergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdConvergence(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdConvergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

shp::Signal Medium::getThresholdDivergence(const Medium& peerX, const Medium& peerY,
        const Distance& separationX, const Distance& separationY) const {
    Medium self = *this; Distance end = shp::Quantity::DEFAULT_VALUE;
    shp::Signal azimX = self.getThresholdDivergence(peerX, separationX, end);
    shp::Signal azimY = self.getThresholdDivergence(peerY, separationY, end);
    std::complex<float> radial(azimX.getMagnitude(), azimY.getMagnitude());
    shp::Signal result(std::abs(radial), azimX.getScaling(), azimX.getUnit()); result.adjustScaling();
    return result;
}

Distance Medium::getParameter() const {
    return Distance(Distance::getMagnitude(), Distance::getScaling(), Distance::getUnit(),
        Distance::getAzimuth(), Distance::getModulation());
}

void Medium::setParameter(const Distance& length) {
    Medium self = *this;
    self.setParameter(length.getMagnitude(), length.getScaling(), length.getUnit());
    self.setDiffusionFactor(length.getAzimuth());
    self.setThresholdShift(length.getModulation());
}

void Medium::setParameter(const float length) {
    Distance::setMagnitude(length);
}

void Medium::setParameter(const float length, const short int scaling) {
    Distance::setMagnitude(length, scaling);
}

void Medium::setParameter(const float length, const short int scaling, const std::string unit) {
    Distance::setMagnitude(length, scaling, unit);
}

void Medium::setParameter(const float length, const short int scaling, const Unit& unit) {
    Distance::setMagnitude(length, scaling, unit);
}

Direction Medium::getDiffusionFactor() const {
    return Distance::getAzimuth().getCurrent();
}

void Medium::setDiffusionFactor(const float degree) {
    Distance::setChangeDirection(degree);
}

void Medium::setDiffusionFactor(const Azimuth& orientation) {
    Distance::setAzimuth(orientation);
}

Direction Medium::getThresholdCurrent() const {
    return Distance::getModulation().getCurrent();
}

Direction Medium::getThresholdShift() const {
    return Distance::getModulation().getShifting();
}

void Medium::setThresholdShift(const Direction& orientation) {
    Polar threshold = Distance::getModulation();
    threshold.setShifting(orientation);
}

void Medium::setThresholdShift(const float degree) {
    Distance::setChangeCurvature(degree);
}

void Medium::setThresholdShift(const Polar& threshold) {
    Distance::setModulation(threshold);
}

float Medium::getThresholdCyclingRate() const {
    return Distance::getModulation().getCyclingRate();
}

float Medium::getThresholdTimePerCycle() const {
    return Distance::getModulation().getTimePerCycle();
}

float Medium::getThresholdFraction(const Polar& peer) const {
    return Direction::getFraction(Distance::getModulation().toRadians(), peer.toRadians());
}

float Medium::getParameterCyclingRate() const {
    return Distance::getAzimuth().getCyclingRate();
}

float Medium::getParameterTimePerCycle() const {
    return Distance::getAzimuth().getTimePerCycle();
}

Direction Medium::getParameterShift() const {
    return Distance::getAzimuth().getShifting();
}

void Medium::setParameterShift(const Direction& orientation) {
    Azimuth direction = Distance::getAzimuth();
    direction.setShifting(orientation);
}

Direction Medium::getParameterShift(const short int degree) const {
    return Distance::getAzimuth().getRotation(degree);
}

void Medium::setParameterShift(const short int degree) {
    Distance::setChangeDirection(degree);
}

float Medium::getParameterFraction(const Azimuth& peer) const {
    return Direction::getFraction(Distance::getAzimuth().toRadians(), peer.toRadians());
}

shp::Signal Medium::getRelative(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation(position, Direction::DEFAULT_RADIANS);                        // radial, X, Y, Z combined;
}

shp::Signal Medium::getLinearX(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinear(position, Distance::getModulation());               // X component only;
}

shp::Signal Medium::getLinearXConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinearConvergence(position, Distance::getModulation());    // X component only;
}

shp::Signal Medium::getLinearXDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinearDivergence(position, Distance::getModulation());     // X component only;
}

shp::Signal Medium::getLinearY(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonal(position, Distance::getAzimuth());              // Y component only;
}

shp::Signal Medium::getLinearYConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalConvergence(position, Distance::getModulation());// Y component only;
}

shp::Signal Medium::getLinearYDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalDivergence(position, Distance::getModulation()); // Y component only;
}

shp::Signal Medium::getLinearZ(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonal(position, Distance::getModulation());           // Z component only;
}

shp::Signal Medium::getLinearZConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalConvergence(position, Distance::getModulation());// Z component only;
}

shp::Signal Medium::getLinearZDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalDivergence(position, Distance::getModulation()); // Z component only;
}

shp::Signal Medium::getScalarTotal() const {
    Distance self = *this; shp::Signal parameter = self.getTotal();
    shp::Signal result = parameter.getDotFraction(this->intrinsic);
    return result;
}

shp::Signal Medium::getVectorTotal() const {
    Distance self = *this; shp::Signal parameter = self.getTotal();
    shp::Signal result = parameter.getCrossFraction(this->intrinsic);
    return result;
}

shp::Distance Medium::copy() {
    return Distance::copy();
}

void Medium::clear() {
    Distance::clear();
    name.clear();
    intrinsic.clear();
    return;
}

std::string Medium::print() const {
    std::stringstream result;
    result << "{";
    result << name << ",";
    result << Distance::print() << ",";
    result << intrinsic.print();
    result << "}";
	return result.str();
}

std::string Medium::printRadians() const {
    std::stringstream result;
    result << "{";
    result << name << ",";
    result << Distance::printRadians() << ",";
    result << intrinsic.printRadians();
    result << "}";
	return result.str();
}

} // namespace shp