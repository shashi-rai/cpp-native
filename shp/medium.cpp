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
        : Distance(), name(), transform() {

}

Medium::Medium(const Unit& unit)
        : Distance(unit), name(), transform() {

}

Medium::Medium(const float parameter)
        : Distance(parameter), name(), transform() {

}

Medium::Medium(const float parameter, const shp::Signal& transform)
        : Distance(parameter), name(), transform(transform) {

}

Medium::Medium(const float parameter, const std::string unit)
        : Distance(parameter, unit), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit)
        : Distance(parameter, unit), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const shp::Signal& transform)
        : Distance(parameter, unit), name(), transform(transform) {

}

Medium::Medium(const float parameter, const Unit& unit, const shp::Signal& transform)
        : Distance(parameter, unit), name(), transform(transform) {

}

Medium::Medium(const float parameter, const short int scaling)
        : Distance(parameter, scaling), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const shp::Signal& transform)
        : Distance(parameter, scaling), name(), transform(transform) {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit)
        : Distance(parameter, scaling, unit), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit)
        : Distance(parameter, scaling, unit), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit, const shp::Signal& transform)
        : Distance(parameter, scaling, unit), name(), transform(transform) {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit, const shp::Signal& transform)
        : Distance(parameter, scaling, unit), name(), transform(transform) {

}

Medium::Medium(const Distance& parameter)
        : Distance(parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
            parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical()),
        name(), transform() {

}

Medium::Medium(const float parameter, const float density)
		: Distance(parameter, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const float density)
		: Distance(parameter, unit, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const Intrinsic& density)
		: Distance(parameter, unit, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const float density)
		: Distance(parameter, unit, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Intrinsic& density)
		: Distance(parameter, unit, density), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const float density)
		: Distance(parameter, scaling, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Intrinsic& density)
		: Distance(parameter, scaling, density), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const float density)
		: Distance(parameter, scaling, unit, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density)
		: Distance(parameter, scaling, unit, density), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const float density)
		: Distance(parameter, scaling, unit, Intrinsic(density)), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density)
		: Distance(parameter, scaling, unit, density), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Azimuth& current)
		: Distance(parameter, scaling, unit, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Azimuth& current)
		: Distance(parameter, scaling, unit, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Polar& threshold)
		: Distance(parameter, scaling, unit, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Polar& threshold)
		: Distance(parameter, scaling, unit, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, scaling, unit, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, scaling, unit, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Azimuth& current, const Polar& threshold)
		: Distance(parameter, scaling, unit, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold)
		: Distance(parameter, scaling, unit, density, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Intrinsic& density)
		: Distance(parameter, density), name(), transform() {

}

Medium::Medium(const float parameter, const Azimuth& current)
		: Distance(parameter, current), name(), transform() {

}

Medium::Medium(const float parameter, const Polar& threshold)
		: Distance(parameter, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Intrinsic& density, const Azimuth& current, const Polar& threshold)
		: Distance(parameter, density, current, threshold), name(), transform() {

}


Medium::Medium(const float parameter, const std::string unit, const Azimuth& current)
		: Distance(parameter, unit, current), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Azimuth& current)
		: Distance(parameter, unit, current), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const Polar& threshold)
		: Distance(parameter, unit, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Polar& threshold)
		: Distance(parameter, unit, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const Azimuth& current, const Polar& threshold)
		: Distance(parameter, unit, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Azimuth& current, const Polar& threshold)
		: Distance(parameter, unit, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, unit, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, unit, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const std::string unit, const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, unit, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const Unit& unit, const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, unit, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Azimuth& current)
		: Distance(parameter, scaling, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const Polar& threshold)
		: Distance(parameter, scaling, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling,
        const Azimuth& current, const Polar& threshold)
		: Distance(parameter, scaling, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling,
        const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, scaling, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling,
        const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, scaling, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Azimuth& current, const Polar& threshold)
		: Distance(parameter, scaling, unit, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current)
		: Distance(parameter, scaling, unit, density, current), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Polar& threshold)
		: Distance(parameter, scaling, unit, density, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold)
		: Distance(parameter, scaling, unit, density, current, threshold), name(), transform() {

}

Medium::Medium(const float parameter, const short int scaling, const std::string unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold, const shp::Signal& transform)
		: Distance(parameter, scaling, unit, density, current, threshold), name(), transform(transform) {

}

Medium::Medium(const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold, const shp::Signal& transform)
		: Distance(parameter, scaling, unit, density, current, threshold), name(), transform(transform) {

}

Medium::Medium(const shp::Signal& transform)
		: Distance(), name(), transform(transform) {

}

Medium::Medium(const std::string name)
        : Distance(), name(name), transform() {

}

Medium::Medium(const std::string name, const shp::Signal& transform)
		: Distance(), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const std::string unit)
        : Distance(unit), name(name), transform() {

}

Medium::Medium(const std::string name, const Unit& unit)
        : Distance(unit), name(name), transform() {

}

Medium::Medium(const std::string name, const std::string unit, const shp::Signal& transform)
        : Distance(unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const Unit& unit, const shp::Signal& transform)
        : Distance(unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const shp::Signal& transform)
        : Distance(parameter), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const std::string unit,
        const shp::Signal& transform)
        : Distance(parameter, unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const Unit& unit,
        const shp::Signal& transform)
        : Distance(parameter, unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling)
        : Distance(parameter, scaling), name(name), transform() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const shp::Signal& transform)
        : Distance(parameter, scaling), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const std::string unit)
        : Distance(parameter, scaling, unit), name(name), transform() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit)
        : Distance(parameter, scaling, unit), name(name), transform() {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const std::string unit, const shp::Signal& transform)
        : Distance(parameter, scaling, unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit,
        const shp::Signal& transform)
        : Distance(parameter, scaling, unit), name(name), transform(transform) {

}

Medium::Medium(const std::string name, const float parameter, const short int scaling, const Unit& unit,
        const Intrinsic& density, const Azimuth& current, const Polar& threshold,
        const shp::Signal& transform)
        : Distance(parameter, scaling, unit, density, current, threshold), name(name), transform(transform) {

}

Medium::Medium(const Intrinsic& density)
		: Distance(density), name(), transform() {

}

Medium::Medium(const Azimuth& current)
		: Distance(current), name(), transform() {

}

Medium::Medium(const Polar& threshold)
		: Distance(threshold), name(), transform() {

}

Medium::Medium(const Intrinsic& density, const Azimuth& current)
		: Distance(density, current), name(), transform() {

}

Medium::Medium(const Intrinsic& density, const Polar& threshold)
		: Distance(density, threshold), name(), transform() {

}

Medium::Medium(const Intrinsic& density, const Azimuth& current, const Polar& threshold)
		: Distance(density, current, threshold), name(), transform() {

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
    shp::Signal newTransform = (this->transform + peer.transform);
    return Medium("+", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical(), newTransform);
}

Medium Medium::operator-(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self - other);
    shp::Signal newTransform = (this->transform - peer.transform);
    return Medium("-", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical(), newTransform);
}

Medium Medium::operator*(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self * other);
    shp::Signal newTransform = (this->transform * peer.transform);
    return Medium("*", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical(), newTransform);
}

Medium Medium::operator/(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self / other);
    shp::Signal newTransform = (this->transform / peer.transform);
    return Medium("/", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical(), newTransform);
}

Medium Medium::operator%(const Medium& peer) const {
    Distance self = *this, other = peer, parameter = (self % other);
    shp::Signal newTransform = (this->transform % peer.transform);
    return Medium("%", parameter.getMagnitude(), parameter.getScaling(), parameter.getUnit(),
        parameter.getIntrinsic(), parameter.getHorizontal(), parameter.getVertical(), newTransform);
}

Medium Medium::operator+(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() + parameter);
    return Medium("+", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getIntrinsic(), newParameter.getHorizontal(), newParameter.getVertical(), self.transform);
}

Medium Medium::operator-(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() - parameter);
    return Medium("-" ,newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getIntrinsic(), newParameter.getHorizontal(), newParameter.getVertical(), self.transform);
}

Medium Medium::operator*(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() * parameter);
    return Medium("*", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getIntrinsic(), newParameter.getHorizontal(), newParameter.getVertical(), self.transform);
}

Medium Medium::operator/(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() / parameter);
    return Medium("/", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getIntrinsic(), newParameter.getHorizontal(), newParameter.getVertical(), self.transform);
}

Medium Medium::operator%(const Distance& parameter) const {
    Medium self = *this;
    Distance newParameter = (self.getParameter() % parameter);
    return Medium("%", newParameter.getMagnitude(), newParameter.getScaling(), newParameter.getUnit(),
        newParameter.getIntrinsic(), newParameter.getHorizontal(), newParameter.getVertical(), self.transform);
}

Medium Medium::operator+(const Intrinsic& phase) const {
    Medium self = *this;
    Intrinsic newParameter = (self.getIntrinsic() + phase);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newParameter, self.getHorizontal(), self.getVertical(), self.transform);
}

Medium Medium::operator-(const Intrinsic& phase) const {
    Medium self = *this;
    Intrinsic newParameter = (self.getIntrinsic() - phase);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newParameter, self.getHorizontal(), self.getVertical(), self.transform);
}

Medium Medium::operator*(const Intrinsic& phase) const {
    Medium self = *this;
    Intrinsic newParameter = (self.getIntrinsic() * phase);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newParameter, self.getHorizontal(), self.getVertical(), self.transform);
}

Medium Medium::operator/(const Intrinsic& phase) const {
    Medium self = *this;
    Intrinsic newParameter = (self.getIntrinsic() / phase);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newParameter, self.getHorizontal(), self.getVertical(), self.transform);
}

Medium Medium::operator%(const Intrinsic& phase) const {
    Medium self = *this;
    Intrinsic newParameter = (self.getIntrinsic() % phase);
    return Medium("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
        newParameter, self.getHorizontal(), self.getVertical(), self.transform);
}

Medium Medium::operator+(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getVertical() + threshold);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), newThreshold, self.transform);
}

Medium Medium::operator-(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getVertical() - threshold);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), newThreshold, self.transform);
}

Medium Medium::operator*(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getVertical() * threshold);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), newThreshold, self.transform);
}

Medium Medium::operator/(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getVertical() / threshold);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), newThreshold, self.transform);
}

Medium Medium::operator%(const Polar& threshold) const {
    Medium self = *this;
    Polar newThreshold = (self.getVertical() % threshold);
    return Medium("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), newThreshold, self.transform);
}

Medium Medium::operator+(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newTransform = (self.transform + modulation);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), self.getVertical(), newTransform);
}

Medium Medium::operator-(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newTransform = (self.transform - modulation);
    return Medium("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), self.getVertical(), newTransform);
}

Medium Medium::operator*(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newTransform = (self.transform * modulation);
    return Medium("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), self.getVertical(), newTransform);
}

Medium Medium::operator/(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newTransform = (self.transform / modulation);
    return Medium("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), self.getVertical(), newTransform);
}

Medium Medium::operator%(const shp::Signal& modulation) const {
    Medium self = *this;
    shp::Signal newTransform = (self.transform % modulation);
    return Medium("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getIntrinsic(), self.getHorizontal(), self.getVertical(), newTransform);
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
        Distance::getIntrinsic(), Distance::getHorizontal(), Distance::getVertical());
}

void Medium::setParameter(const Distance& value) {
    Medium self = *this;
    self.setParameter(value.getMagnitude(), value.getScaling(), value.getUnit());
    self.setDiffusionFactor(value.getIntrinsic());
    self.setThresholdShift(value.getVertical());
}

void Medium::setParameter(const float value) {
    Distance::setMagnitude(value);
}

void Medium::setParameter(const float value, const short int scaling) {
    Distance::setMagnitude(value, scaling);
}

void Medium::setParameter(const float value, const short int scaling, const std::string unit) {
    Distance::setMagnitude(value, scaling, unit);
}

void Medium::setParameter(const float value, const short int scaling, const Unit& unit) {
    Distance::setMagnitude(value, scaling, unit);
}

Direction Medium::getDiffusionCurrent() const {
    return Distance::getIntrinsic().getCurrent();
}

Intrinsic Medium::getDiffusionFactor() const {
    return Distance::getIntrinsic();
}

void Medium::setDiffusionFactor(const float degree) {
    Distance::setChangeIntrinsic(degree);
}

void Medium::setDiffusionFactor(const Intrinsic& phase) {
    Distance::setIntrinsic(phase);
}

float Medium::getDiffusionCyclingRate() const {
    return Distance::getIntrinsic().getCyclingRate();
}

float Medium::getDiffusionTimePerCycle() const {
    return Distance::getIntrinsic().getTimePerCycle();
}

Direction Medium::getDiffusionShift() const {
    return Distance::getIntrinsic().getShifting();
}

void Medium::setDiffusionShift(const short int degree) {
    Distance::setChangeIntrinsic(degree);
}

float Medium::getDiffusionFraction(const Intrinsic& peer) const {
    return Direction::getFraction(Distance::getIntrinsic().toRadians(), peer.toRadians());
}

Direction Medium::getMobilityCurrent() const {
    return Distance::getVertical().getCurrent();
}

Azimuth Medium::getMobilityFactor() const {
    return Distance::getHorizontal();
}

void Medium::setMobilityFactor(const Azimuth& current) {
    Distance::setHorizontal(current);
}

Direction Medium::getMobilityShift() const {
    return Distance::getHorizontal().getShifting();
}

void Medium::setMobilityShift(const float degree) {
    Distance::setHorizontalCurvature(degree);
}

void Medium::setMobilityShift(const Azimuth& threshold) {
    Distance::setHorizontal(threshold);
}

float Medium::getMobilityCyclingRate() const {
    return Distance::getHorizontal().getCyclingRate();
}

float Medium::getMobilityTimePerCycle() const {
    return Distance::getHorizontal().getTimePerCycle();
}

float Medium::getMobilityFraction(const Azimuth& peer) const {
    return Direction::getFraction(Distance::getHorizontal().toRadians(), peer.toRadians());
}

Direction Medium::getThresholdCurrent() const {
    return Distance::getVertical().getCurrent();
}

Polar Medium::getThresholdFactor() const {
    return Distance::getVertical();
}

Direction Medium::getThresholdShift() const {
    return Distance::getVertical().getShifting();
}

void Medium::setThresholdShift(const float degree) {
    Distance::setVerticalCurvature(degree);
}

void Medium::setThresholdShift(const Polar& threshold) {
    Distance::setVertical(threshold);
}

float Medium::getThresholdCyclingRate() const {
    return Distance::getVertical().getCyclingRate();
}

float Medium::getThresholdTimePerCycle() const {
    return Distance::getVertical().getTimePerCycle();
}

float Medium::getThresholdFraction(const Polar& peer) const {
    return Direction::getFraction(Distance::getVertical().toRadians(), peer.toRadians());
}

shp::Signal Medium::getRelative(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation(position, Polar(Direction::DEFAULT_RADIANS));                 // radial, X, Y, Z combined;
}

shp::Signal Medium::getLinearX(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinear(position, Distance::getIntrinsic());                // X component only;
}

shp::Signal Medium::getLinearXConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinearConvergence(position, Distance::getIntrinsic());     // X component only;
}

shp::Signal Medium::getLinearXDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getLinearDivergence(position, Distance::getIntrinsic());      // X component only;
}

shp::Signal Medium::getLinearY(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getPlanar(position, Distance::getHorizontal());               // Y component only;
}

shp::Signal Medium::getLinearYConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getPlanarConvergence(position, Distance::getHorizontal());    // Y component only;
}

shp::Signal Medium::getLinearYDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getPlanarDivergence(position, Distance::getHorizontal());     // Y component only;
}

shp::Signal Medium::getLinearZ(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonal(position, Distance::getVertical());             // Z component only;
}

shp::Signal Medium::getLinearZConvergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalConvergence(position, Distance::getVertical());  // Z component only;
}

shp::Signal Medium::getLinearZDivergence(const Distance& position) const {
    Medium self = *this; Distance separation = self.getParameter();
    return separation.getOrthogonalDivergence(position, Distance::getVertical());   // Z component only;
}

shp::Signal Medium::getScalarParameter() const {
    Distance self = *this; shp::Signal parameter = self.getScalarTotal();
    shp::Signal result = parameter.getDotFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Signal Medium::getVectorParameter() const {
    Distance self = *this; shp::Signal parameter = self.getVectorTotal();
    shp::Signal result = parameter.getDotFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Signal Medium::getScalarFieldDrift() const {
    Distance self = *this; shp::Signal parameter = self.getHorizontalDrift();
    shp::Signal result = parameter.getDotFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Signal Medium::getScalarFieldTotal() const {
    Distance self = *this; shp::Signal parameter = self.getHorizontalTotal();
    shp::Signal result = parameter.getDotFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Signal Medium::getVectorFieldDrift() const {
    Distance self = *this; shp::Signal parameter = self.getVerticalDrift();
    shp::Signal result = parameter.getCrossFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Signal Medium::getVectorFieldTotal() const {
    Distance self = *this; shp::Signal parameter = self.getVerticalTotal();
    shp::Signal result = parameter.getCrossFraction(this->transform.getVectorAbsolute());
    return result;
}

shp::Medium Medium::copy() {
    Medium self = *this;
    return Medium(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getDiffusionFactor(), self.getMobilityFactor(), self.getThresholdFactor(),
        this->transform);
}

void Medium::clear() {
    Distance::clear();
    name.clear();
    transform.clear();
    return;
}

std::string Medium::print() const {
    std::stringstream result;
    result << "{";
    result << name << ",";
    result << Distance::print() << ",";
    result << transform.print();
    result << "}";
	return result.str();
}

std::string Medium::printRadians() const {
    std::stringstream result;
    result << "{";
    result << name << ",";
    result << Distance::printRadians() << ",";
    result << transform.printRadians();
    result << "}";
	return result.str();
}

} // namespace shp