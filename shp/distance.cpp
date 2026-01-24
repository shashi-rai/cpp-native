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

#include "distance.h"

namespace shp {

const std::string Distance::UNIT = "m";     // System International

Distance::Distance()
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const std::string unit)
        : Quantity(unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Unit& unit)
        : Quantity(unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length)
        : Quantity(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const std::string unit)
        : Quantity(length, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Unit& unit)
        : Quantity(length, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling)
        : Quantity(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit)
        : Quantity(length, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit)
        : Quantity(length, scaling, unit),
        change(shp::Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Direction& change)
        : Quantity(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const std::string unit, const Direction& change)
        : Quantity(unit), change(change) {

}

Distance::Distance(const Unit& unit, const Direction& change)
        : Quantity(unit), change(change) {

}

Distance::Distance(const float length, const Direction& change)
        : Quantity(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const float length, const std::string unit, const Direction& change)
        : Quantity(length, unit), change(change) {

}

Distance::Distance(const float length, const Unit& unit, const Direction& change)
        : Quantity(length, unit), change(change) {

}

Distance::Distance(const float length, const short int scaling, const Direction& change)
        : Quantity(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), change(change) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit,
        const Direction& change)
        : Quantity(length, scaling, unit), change(change) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const Direction& change)
        : Quantity(length, scaling, unit), change(change) {

}

Distance::~Distance() {

}

bool Distance::operator==(const Distance& peer) const {
    return (static_cast<const Quantity&>(*this) == static_cast<const Quantity&>(peer))
        && (change == peer.change);
}

bool Distance::operator<(const Distance& peer) const {
    Distance self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) < static_cast<const Quantity&>(peer)) {
        result = true;
    } else if (change < peer.change) {
        result = true;
    }
    return result;
}

bool Distance::operator>(const Distance& peer) const {
    Distance self = *this; bool result = false;
    if (static_cast<const Quantity&>(*this) > static_cast<const Quantity&>(peer)) {
        result = true;
    } else if (change > peer.change) {
        result = true;
    }
    return result;
}

bool Distance::operator<=(const Distance& peer) const {
    Distance self = *this;
    return (self < peer) || (self == peer);
}

bool Distance::operator>=(const Distance& peer) const {
    Distance self = *this;
    return (self > peer) || (self == peer);
}

Distance Distance::operator+(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator-(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator*(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator/(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator%(const Distance& peer) const {
    Quantity self = *this, other = peer;
    Quantity distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator+(const float value) const {
    Quantity self = *this, other(value, self.getScaling(), self.getUnit());
    Quantity distance = (self + other);
    return Distance(distance.getMagnitude() + value, distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator-(const float value) const {
    Quantity self = *this, other(value, self.getScaling(), self.getUnit());
    Quantity distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(), change);
}

Distance Distance::operator+(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change + rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator-(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change - rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator*(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change * rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator/(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change / rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator%(const Direction& rotation) const {
    Distance self = *this;
    Direction orientation = (self.change % rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), orientation);
}

Distance Distance::operator()(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Direction poi(Direction::DEFAULT_RADIANS);
    Quantity radial = (self.getRadial(poi) + peer.getRadial(elevation));
    Distance result(radial.getMagnitude(),
        radial.getScaling(), self.getUnit(), self.getDeviation(elevation));
    result.adjustScaling();
    return result;
}

Direction Distance::getDeviation(const Direction& elevation) const {
    return Direction::getConstructive(change.getPhase(), elevation.getPhase());
}

Distance Distance::getLinear(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getLinearX(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getLinearAmplified(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getSquareX(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getLinearDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getInverseSquareX(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getPlanar(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getLinearY(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getPlanarAmplified(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getSquareY(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getPlanarDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getInverseSquareY(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getOrthogonal(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getLinearZ(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getOrthogonalAmplified(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getSquareZ(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Distance Distance::getOrthogonalDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Quantity component = self.getInverseSquareZ(peer, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getTotal() const {
    Quantity self = *this;
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(), this->change);
}

Quantity Distance::getRadial(const Direction& elevation) const {
    Distance self = *this; Quantity sumtotal, diagonal;
    sumtotal = self.getRadialXSquare(change)
            + self.getRadialYSquare(change)
            + self.getRadialZSquare(elevation);
    diagonal = sumtotal.getSquareRoot();
    Quantity result(diagonal.getMagnitude(),
        diagonal.getScaling(), self.getUnit()); result.adjustScaling();
    return result;
}

Quantity Distance::getRadialX(const Direction& elevation) const {
    Distance self = *this;
    Quantity component = self.getLinearX(Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getRadialY(const Direction& elevation) const {
    Distance self = *this;
    Quantity component = self.getLinearY(Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getRadialZ(const Direction& elevation) const {
    Distance self = *this;
    Quantity component = self.getLinearZ(Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(),
        component.getScaling(), self.getUnit(), self.getDeviation(elevation));
    return result;
}

Quantity Distance::getRadialXSquare(const Direction& elevation) const {
    return getRadialX(elevation).getSquare();
}

Quantity Distance::getRadialYSquare(const Direction& elevation) const {
    return getRadialY(elevation).getSquare();
}

Quantity Distance::getRadialZSquare(const Direction& elevation) const {
    return getRadialZ(elevation).getSquare();
}

Distance Distance::copy() {
    Distance self = *this;
    Distance fresh(self.getMagnitude(), self.getScaling(), self.getUnit(), self.change);
    return fresh;
}

void Distance::clear() {
    Quantity::clear();
    change.clear();
    return;
}

std::string Distance::print() const {
    std::stringstream result;
    result << Quantity::print() << "δ";
    result << change.print();
	return result.str();
}

std::string Distance::printRadians() const {
    std::stringstream result;
    result << Quantity::print() << "δ";
    result << change.printRadians();
	return result.str();
}

/*
 * The peer is assumed to be point of interest, where the x_component is zero,
 * while y_component spreads horizontally, the z_component spreads vertically.
 * Only if peer is a variant, then y_component contributes its change. Also, if
 * peer remains invariant, then z_component could still contribute its stretch.
 */
const std::complex<float> Distance::getDiffusion(const Distance& peer, const Direction& elevation) {
    return Direction::getConstructive(peer.change.getPhase(), elevation.getPhase());
}

Quantity Distance::getLinearX(const Distance& peer, const Direction& elevation) const {
    Quantity self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    Quantity diffusion(Direction::getCosine(concentration), self.getScaling(), self.getUnit());
    Quantity result = self + (other * diffusion); result.adjustScaling();
    return result;
}

Quantity Distance::getSquareX(const Distance& peer, const Direction& elevation) const {
    return getLinearX(peer, elevation).getSquare();
}

Quantity Distance::getInverseX(const Distance& peer, const Direction& elevation) const {
    return getLinearX(peer, elevation).getInverse();
}

Quantity Distance::getInverseSquareX(const Distance& peer, const Direction& elevation) const {
    return getInverseX(peer, elevation).getSquare();
}

Quantity Distance::getLinearY(const Distance& peer, const Direction& elevation) const {
    Quantity self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    Quantity diffusion(Direction::getCosine(concentration), peer.getScaling(), peer.getUnit());
    Quantity result = (other * diffusion); result.adjustScaling();
    return result;
}

Quantity Distance::getSquareY(const Distance& peer, const Direction& elevation) const {
    return getLinearY(peer, elevation).getSquare();
}

Quantity Distance::getInverseY(const Distance& peer, const Direction& elevation) const {
    return getLinearY(peer, elevation).getInverse();
}

Quantity Distance::getInverseSquareY(const Distance& peer, const Direction& elevation) const {
    return getInverseY(peer, elevation).getSquare();
}

Quantity Distance::getLinearZ(const Distance& peer, const Direction& elevation) const {
    Quantity self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    Quantity diffusion(Direction::getSine(concentration), peer.getScaling(), peer.getUnit());
    Quantity result = (other * diffusion); result.adjustScaling();
    return result;
}

Quantity Distance::getSquareZ(const Distance& peer, const Direction& elevation) const {
    return getLinearZ(peer, elevation).getSquare();
}

Quantity Distance::getInverseZ(const Distance& peer, const Direction& elevation) const {
    return getLinearZ(peer, elevation).getInverse();
}

Quantity Distance::getInverseSquareZ(const Distance& peer, const Direction& elevation) const {
    return getInverseZ(peer, elevation).getSquare();
}

} // namespace shp