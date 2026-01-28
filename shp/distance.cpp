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
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const std::string unit)
        : Signal(unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Unit& unit)
        : Signal(unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length)
        : Signal(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const std::string unit)
        : Signal(length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Unit& unit)
        : Signal(length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling)
        : Signal(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit)
        : Signal(length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit)
        : Signal(length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Azimuth& orientation)
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Polar& modulation)
        : Signal(shp::Unit::getBaseSymbol(shp::Unit::LENGTH)), modulation(modulation) {

}

Distance::Distance(const std::string unit, const Azimuth& orientation)
        : Signal(orientation, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Unit& unit, const Azimuth& orientation)
        : Signal(orientation, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const Unit& unit, const Polar& modulation)
        : Signal(unit), modulation(modulation) {

}

Distance::Distance(const float length, const Azimuth& orientation)
        : Signal(orientation, length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Polar& modulation)
        : Signal(length, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(modulation) {

}

Distance::Distance(const float length, const std::string unit, const float orientation)
        : Signal(orientation, length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const std::string unit, const Azimuth& orientation)
        : Signal(orientation, length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Unit& unit, const float orientation)
        : Signal(orientation, length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const Unit& unit, const Azimuth& orientation)
        : Signal(orientation, length, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const std::string unit, const Polar& modulation)
        : Signal(length, unit), modulation(modulation) {

}

Distance::Distance(const float length, const Unit& unit, const Polar& modulation)
        : Signal(length, unit), modulation(modulation) {

}

Distance::Distance(const float length, const short int scaling, const float orientation)
        : Signal(orientation, length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Azimuth& orientation)
        : Signal(orientation, length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Polar& modulation)
        : Signal(length, scaling, shp::Unit::getBaseSymbol(shp::Unit::LENGTH)),
        modulation(modulation) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit,
        const float orientation)
        : Signal(orientation, length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit,
        const Azimuth& orientation)
        : Signal(orientation, length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation)
        : Signal(orientation, length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const Azimuth& orientation)
        : Signal(orientation, length, scaling, unit), modulation(Direction::DEFAULT_RADIANS) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const Polar& modulation)
        : Signal(length, scaling, unit), modulation(modulation) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const float orientation, const Polar& modulation)
        : Signal(orientation, length, scaling, unit), modulation(modulation) {

}

Distance::Distance(const float length, const short int scaling, const std::string unit,
        const float orientation, const Polar& modulation)
        : Signal(orientation, length, scaling, unit), modulation(modulation) {

}

Distance::Distance(const float length, const short int scaling, const Unit& unit,
        const Azimuth& orientation, const Polar& modulation)
        : Signal(orientation, length, scaling, unit), modulation(modulation) {

}

Distance::~Distance() {

}

bool Distance::operator==(const Distance& peer) const {
    return (static_cast<const Signal&>(*this) == static_cast<const Signal&>(peer))
        && (modulation == peer.modulation);
}

bool Distance::operator<(const Distance& peer) const {
    Distance self = *this; bool result = false;
    if (static_cast<const Signal&>(*this) < static_cast<const Signal&>(peer)) {
        result = true;
    } else if (modulation < peer.modulation) {
        result = true;
    }
    return result;
}

bool Distance::operator>(const Distance& peer) const {
    Distance self = *this; bool result = false;
    if (static_cast<const Signal&>(*this) > static_cast<const Signal&>(peer)) {
        result = true;
    } else if (modulation > peer.modulation) {
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
    Signal self = *this, other = peer;
    Signal distance = (self + other);
    Polar relativity = (this->modulation + peer.modulation);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), relativity);
}

Distance Distance::operator-(const Distance& peer) const {
    Signal self = *this, other = peer;
    Signal distance = (self - other);
    Polar relativity = (this->modulation - peer.modulation);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), relativity);
}

Distance Distance::operator*(const Distance& peer) const {
    Signal self = *this, other = peer;
    Signal distance = (self * other);
    Polar relativity = (this->modulation * peer.modulation);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), relativity);
}

Distance Distance::operator/(const Distance& peer) const {
    Signal self = *this, other = peer;
    Signal distance = (self / other);
    Polar relativity = (this->modulation / peer.modulation);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), relativity);
}

Distance Distance::operator%(const Distance& peer) const {
    Signal self = *this, other = peer;
    Signal distance = (self % other);
    Polar relativity = (this->modulation % peer.modulation);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), relativity);
}

Distance Distance::operator+(const float length) const {
    Signal self = *this, other(length, self.getScaling(), self.getUnit());
    Signal distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator-(const float length) const {
    Signal self = *this, other(length, self.getScaling(), self.getUnit());
    Signal distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator*(const float length) const {
    Signal self = *this, other(length, self.getScaling(), self.getUnit());
    Signal distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator/(const float length) const {
    Signal self = *this, other(length, self.getScaling(), self.getUnit());
    Signal distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator%(const float length) const {
    Signal self = *this, other(length, self.getScaling(), self.getUnit());
    Signal distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator+(const shp::Quantity length) const {
    Signal self = *this, other(length.getMagnitude(), length.getScaling(), length.getUnit());
    Signal distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator-(const shp::Quantity length) const {
    Signal self = *this, other(length.getMagnitude(), length.getScaling(), length.getUnit());
    Signal distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator*(const shp::Quantity length) const {
    Signal self = *this, other(length.getMagnitude(), length.getScaling(), length.getUnit());
    Signal distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator/(const shp::Quantity length) const {
    Signal self = *this, other(length.getMagnitude(), length.getScaling(), length.getUnit());
    Signal distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator%(const shp::Quantity length) const {
    Signal self = *this, other(length.getMagnitude(), length.getScaling(), length.getUnit());
    Signal distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator+(const shp::Signal factor) const {
    Signal self = *this, other(factor.getMagnitude(), factor.getScaling(), factor.getUnit());
    Signal distance = (self + other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator-(const shp::Signal factor) const {
    Signal self = *this, other(factor.getMagnitude(), factor.getScaling(), factor.getUnit());
    Signal distance = (self - other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator*(const shp::Signal factor) const {
    Signal self = *this, other(factor.getMagnitude(), factor.getScaling(), factor.getUnit());
    Signal distance = (self * other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator/(const shp::Signal factor) const {
    Signal self = *this, other(factor.getMagnitude(), factor.getScaling(), factor.getUnit());
    Signal distance = (self / other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator%(const shp::Signal factor) const {
    Signal self = *this, other(factor.getMagnitude(), factor.getScaling(), factor.getUnit());
    Signal distance = (self % other);
    return Distance(distance.getMagnitude(), distance.getScaling(), distance.getUnit(),
        distance.getOrientation(), this->modulation);
}

Distance Distance::operator+(const Azimuth& rotation) const {
    Distance self = *this;
    Azimuth orientation = (self.getOrientation() + rotation.toRadians());
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        orientation, self.modulation);
}

Distance Distance::operator-(const Azimuth& rotation) const {
    Distance self = *this;
    Azimuth orientation = (self.getOrientation() - rotation.toRadians());
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        orientation, self.modulation);
}

Distance Distance::operator*(const Azimuth& rotation) const {
    Distance self = *this;
    Azimuth orientation = (self.getOrientation() * rotation.toRadians());
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        orientation, self.modulation);
}

Distance Distance::operator/(const Azimuth& rotation) const {
    Distance self = *this;
    Azimuth orientation = (self.getOrientation() / rotation.toRadians());
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        orientation, self.modulation);
}

Distance Distance::operator%(const Azimuth& rotation) const {
    Distance self = *this;
    Azimuth orientation = fmod(self.getOrientation(), rotation.toRadians());
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        orientation, self.modulation);
}

Distance Distance::operator+(const Polar& rotation) const {
    Distance self = *this;
    Polar direction = (self.modulation + rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), direction);
}

Distance Distance::operator-(const Polar& rotation) const {
    Distance self = *this;
    Polar direction = (self.modulation - rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), direction);
}

Distance Distance::operator*(const Polar& rotation) const {
    Distance self = *this;
    Polar direction = (self.modulation * rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), direction);
}

Distance Distance::operator/(const Polar& rotation) const {
    Distance self = *this;
    Polar direction = (self.modulation / rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), direction);
}

Distance Distance::operator%(const Polar& rotation) const {
    Distance self = *this;
    Polar direction = (self.modulation % rotation);
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), direction);
}

Signal Distance::operator()(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Direction poi(Direction::DEFAULT_RADIANS);
    Signal radial = (self.getRadial(poi) + peer.getRadial(elevation));
    Distance result(radial.getMagnitude(), radial.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    result.adjustScaling();
    return result;
}

float Distance::getAmplitude() const {
    return Signal::getAmplitude();
}

float Distance::getMagnitude() const {
    return Signal::getMagnitude();
}

void Distance::setMagnitude(const float value) {
    Signal::setMagnitude(value);
}

void Distance::setMagnitude(const float value, const short int scale) {
    Signal::setMagnitude(value, scale);
}

void Distance::setMagnitude(const float value, const short int scale, const std::string unit) {
    Signal::setMagnitude(value, scale, unit);
}

void Distance::setMagnitude(const float value, const short int scale, const Unit& unit) {
    Signal::setMagnitude(value, scale, unit);
}

short int Distance::getScaling() const {
    return Signal::getScaling();
}

void Distance::setScaling(const short int factor) {
    Signal::setScaling(factor);
}

Unit Distance::getUnit() const {
    return Signal::getUnit();
}

void Distance::setUnit(const Unit& object) {
    Signal::setUnit(object);
}

Azimuth Distance::getAzimuth() const {
    return Signal::getOrientation();
}

void Distance::setAzimuth(const float orientation) {
    Signal::setOrientation(orientation);
}

void Distance::setAzimuth(const Azimuth& orientation) {
    Signal::setOrientation(orientation.toRadians());
}

void Distance::setModulation(const float relativity) {
    modulation = Polar(relativity);
}

void Distance::setChangeMagnitude(const float motion) {
	if (motion != shp::Quantity::DEFAULT_VALUE) {
        Signal self = *this, other(motion, self.getScaling()), displacement = (self + other);
        Signal::setMagnitude(displacement.getMagnitude(), displacement.getScaling());
	}
}

void Distance::setChangeMagnitude(const float motion, const short int scale) {
	if (motion != shp::Quantity::DEFAULT_VALUE) {
        Signal self = *this, other(motion, scale), displacement = (self + other);
        Signal::setMagnitude(displacement.getMagnitude(), displacement.getScaling());
	}
}

void Distance::setChangeDirection(const float degree) {
    if (degree != shp::Quantity::DEFAULT_VALUE) {
        Signal direction = (*this + Azimuth(Direction::DEGREE_001 * degree));
        Signal::setOrientation(direction.getOrientation());
    }
}

bool Distance::checkNonZero() const {
    return Signal::checkNonZero();
}

bool Distance::checkInfinity() const {
    return Signal::checkInfinity();
}

short int Distance::checkScaling(const float amount) const {
    return Signal::checkScaling(amount);
}

void Distance::adjustNumeric() {
    return Signal::adjustNumeric();
}

void Distance::adjustScaling() {
    Signal::adjustScaling();
}

Signal Distance::getScalarNegative() const {
    return Signal::getScalarNegative();
}

Signal Distance::getVectorNegative() const {
    return Signal::getVectorNegative();
}

Signal Distance::getScalarInverse() const {
    return Signal::getScalarInverse();
}

Signal Distance::getVectorInverse() const {
    return Signal::getVectorInverse();
}

Signal Distance::getScalarSquare() const {
    return Signal::getDotProductSquare();
}

Signal Distance::getVectorSquare() const {
    return Signal::getCrossProductSquare();
}

Signal Distance::getScalarFraction(const float length) const {
    return Signal::getDotFraction(length);
}

Signal Distance::getScalarFraction(const float length, const short int scale) const {
    return Signal::getDotFraction(length, scale);
}

Signal Distance::getScalarSquareFraction(const float length) const {
    return Signal::getDotFractionSquare(length);
}

Signal Distance::getScalarSquareFraction(const float length, const short int scale) const {
    return Signal::getDotFractionSquare(length, scale);
}

Polar Distance::getRelativity(const Direction& elevation) const {
    return Direction::getConstructive(modulation.getPhase(), elevation.getPhase());
}

Azimuth Distance::getDeviation(const Direction& elevation) const {
    Azimuth orientation = this->getOrientation();
    return Direction::getConstructive(orientation.getPhase(), elevation.getPhase());
}

Signal Distance::getLinear(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getLinearX(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getLinearConvergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getSquareX(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getLinearDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getInverseSquareX(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getPlanar(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getLinearY(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getPlanarConvergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getSquareY(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getPlanarDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getInverseSquareY(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getOrthogonal(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getLinearZ(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getOrthogonalConvergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getSquareZ(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getOrthogonalDivergence(const Distance& peer, const Direction& elevation) const {
    Distance self = *this; Signal component = self.getInverseSquareZ(peer, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getTotal() const {
    Signal self = *this;
    return Distance(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), this->modulation);
}

Signal Distance::getRadial(const Direction& elevation) const {
    Distance self = *this; Direction change = this->getOrientation();
    Signal sumtotal = self.getRadialXSquare(change)
            + self.getRadialYSquare(change)
            + self.getRadialZSquare(elevation);
    Signal diagonal = sumtotal.getDotProductSquareRoot();
    shp::Signal result(diagonal.getOrientation(), diagonal.getMagnitude(),
        diagonal.getScaling(), self.getUnit()); result.adjustScaling();
    return result;
}

Signal Distance::getRadialX(const Direction& elevation) const {
    Distance self = *this;
    shp::Quantity component = self.getLinearX(shp::Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getRadialY(const Direction& elevation) const {
    Distance self = *this;
    shp::Quantity component = self.getLinearY(shp::Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getRadialZ(const Direction& elevation) const {
    Distance self = *this;
    shp::Quantity component = self.getLinearZ(shp::Quantity::DEFAULT_VALUE, elevation);
    Distance result(component.getMagnitude(), component.getScaling(), self.getUnit(),
        self.getDeviation(elevation), self.getRelativity(elevation));
    return result;
}

Signal Distance::getRadialXSquare(const Direction& elevation) const {
    return getRadialX(elevation).getDotProductSquare();
}

Signal Distance::getRadialYSquare(const Direction& elevation) const {
    return getRadialY(elevation).getDotProductSquare();
}

Signal Distance::getRadialZSquare(const Direction& elevation) const {
    return getRadialZ(elevation).getDotProductSquare();
}

Distance Distance::copy() {
    Distance self = *this;
    Distance fresh(self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getOrientation(), self.modulation);
    return fresh;
}

void Distance::clear() {
    Signal::clear();
    modulation.clear();
    return;
}

std::string Distance::print() const {
    std::stringstream result;
    result << Signal::print() << "⌒";
    result << modulation.print();
	return result.str();
}

std::string Distance::printRadians() const {
    std::stringstream result;
    result << Signal::print() << "⌒";
    result << modulation.printRadians();
	return result.str();
}

/*
 * The peer is assumed to be point of interest, where the x_component is zero,
 * while y_component spreads horizontally, the z_component spreads vertically.
 * Only if peer is a variant, then y_component contributes its change. Also, if
 * peer remains invariant, then z_component could still contribute its stretch.
 */
const std::complex<float> Distance::getDiffusion(const Distance& peer, const Direction& elevation) {
    Azimuth orientation = peer.getOrientation();
    return Direction::getConstructive(orientation.getPhase(), elevation.getPhase());
}

shp::Quantity Distance::getLinearX(const Distance& peer, const Direction& elevation) const {
    shp::Signal self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    shp::Quantity diffusion(Direction::getCosine(concentration), self.getScaling(), self.getUnit());
    shp::Signal result = self + (other * diffusion); result.adjustScaling();
    return shp::Quantity(result.getMagnitude(), result.getScaling(), result.getUnit());
}

shp::Quantity Distance::getSquareX(const Distance& peer, const Direction& elevation) const {
    return getLinearX(peer, elevation).getSquare();
}

shp::Quantity Distance::getInverseX(const Distance& peer, const Direction& elevation) const {
    return getLinearX(peer, elevation).getInverse();
}

shp::Quantity Distance::getInverseSquareX(const Distance& peer, const Direction& elevation) const {
    return getInverseX(peer, elevation).getSquare();
}

shp::Quantity Distance::getLinearY(const Distance& peer, const Direction& elevation) const {
    shp::Signal self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    shp::Quantity diffusion(Direction::getCosine(concentration), peer.getScaling(), peer.getUnit());
    shp::Signal result = (other * diffusion); result.adjustScaling();
    return shp::Quantity(result.getMagnitude(), result.getScaling(), result.getUnit());
}

shp::Quantity Distance::getSquareY(const Distance& peer, const Direction& elevation) const {
    return getLinearY(peer, elevation).getSquare();
}

shp::Quantity Distance::getInverseY(const Distance& peer, const Direction& elevation) const {
    return getLinearY(peer, elevation).getInverse();
}

shp::Quantity Distance::getInverseSquareY(const Distance& peer, const Direction& elevation) const {
    return getInverseY(peer, elevation).getSquare();
}

shp::Quantity Distance::getLinearZ(const Distance& peer, const Direction& elevation) const {
    shp::Signal self = *this, other = peer;
    std::complex<float> concentration = Distance::getDiffusion(peer, elevation);
    shp::Quantity diffusion(Direction::getSine(concentration), peer.getScaling(), peer.getUnit());
    shp::Signal result = (other * diffusion); result.adjustScaling();
    return shp::Quantity(result.getMagnitude(), result.getScaling(), result.getUnit());
}

shp::Quantity Distance::getSquareZ(const Distance& peer, const Direction& elevation) const {
    return getLinearZ(peer, elevation).getSquare();
}

shp::Quantity Distance::getInverseZ(const Distance& peer, const Direction& elevation) const {
    return getLinearZ(peer, elevation).getInverse();
}

shp::Quantity Distance::getInverseSquareZ(const Distance& peer, const Direction& elevation) const {
    return getInverseZ(peer, elevation).getSquare();
}

} // namespace shp