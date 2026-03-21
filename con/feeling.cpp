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

#include "feeling.h"

namespace con {

const std::string Feeling::UNIT = "x/s";   // Unit of Measure

Feeling::Feeling()
        : shp::Distance(UNIT), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::shared_ptr<Behaviour> realm)
        : shp::Distance(UNIT), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name)
        : shp::Distance(UNIT), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(UNIT), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const shp::Unit& unit)
        : shp::Distance(unit), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const shp::Unit& unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(unit), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const shp::Intrinsic& direction)
        : shp::Distance(UNIT, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(UNIT, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse)
        : shp::Distance(impulse, UNIT), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const std::string unit)
        : shp::Distance(impulse, unit), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const std::string unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const shp::Unit& unit)
        : shp::Distance(impulse, unit), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const shp::Unit& unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling)
        : shp::Distance(impulse, scaling, UNIT), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const float direction)
        : shp::Distance(impulse, UNIT, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const float direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const shp::Intrinsic& direction)
        : shp::Distance(impulse, UNIT, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const std::string unit, const float direction)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const std::string unit, const float direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const std::string unit, const shp::Intrinsic& direction)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const std::string unit, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const shp::Unit& unit, const shp::Intrinsic& direction)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const shp::Unit& unit, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit)
        : shp::Distance(impulse, scaling, unit), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const shp::Unit& unit)
        : shp::Distance(impulse, scaling, unit), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const shp::Unit& unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const float direction)
        : shp::Distance(impulse, scaling, UNIT, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const float direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, UNIT, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const shp::Intrinsic& direction)
        : shp::Distance(impulse, scaling, UNIT, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, UNIT, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit,
        const float direction)
        : shp::Distance(impulse, scaling, unit, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit,
        const shp::Intrinsic& direction)
        : shp::Distance(impulse, scaling, unit, direction), name() {
	setBehaviour(nullptr);
}

Feeling::Feeling(const float impulse, const short int scaling, const std::string unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit, direction), name() {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const std::string unit)
        : shp::Distance(unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const std::string unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(unit), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const shp::Unit& unit)
        : shp::Distance(unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const shp::Unit& unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(unit), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const shp::Intrinsic& direction)
        : shp::Distance(UNIT, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(UNIT, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse)
        : shp::Distance(impulse, UNIT), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const std::string unit)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const std::string unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling)
        : shp::Distance(impulse, scaling, UNIT), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
		const std::string unit)
        : shp::Distance(impulse, scaling, unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
		const shp::Unit& unit)
        : shp::Distance(impulse, scaling, unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const float direction)
        : shp::Distance(impulse, UNIT, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const float direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Intrinsic& direction)
        : shp::Distance(impulse, UNIT, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Intrinsic& direction,
		const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, UNIT, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const std::string unit,
        const float direction)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const std::string unit,
        const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const float direction)
        : shp::Distance(impulse, unit, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction)
        : shp::Distance(impulse, unit, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const shp::Unit& unit,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, unit, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const float direction)
        : shp::Distance(impulse, scaling, UNIT, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, UNIT, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Intrinsic& direction)
        : shp::Distance(impulse, scaling, UNIT, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, UNIT, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const std::string unit, const float direction)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const std::string unit, const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Unit& unit, const float direction)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Unit& unit, const float direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(realm);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Unit& unit, const shp::Intrinsic& direction)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(nullptr);
}

Feeling::Feeling(const std::string name, const float impulse, const short int scaling,
        const shp::Unit& unit, const shp::Intrinsic& direction, const std::shared_ptr<Behaviour> realm)
        : shp::Distance(impulse, scaling, unit, direction), name(name) {
	setBehaviour(realm);
}

Feeling::~Feeling() {
	setBehaviour(nullptr);
}

bool Feeling::operator==(const Feeling& peer) const {
	return (static_cast<const shp::Distance&>(*this) == static_cast<const shp::Distance&>(peer))
		&& (behaviour == peer.behaviour);
}

bool Feeling::operator<(const Feeling& peer) const {
	Feeling self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) < static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Feeling::operator>(const Feeling& peer) const {
	Feeling self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) > static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Feeling::operator<=(const Feeling& peer) const {
    Feeling self = *this;
    return (self < peer) || (self == peer);
}

bool Feeling::operator>=(const Feeling& peer) const {
    Feeling self = *this;
    return (self > peer) || (self == peer);
}

Feeling Feeling::operator+(const Feeling& peer) const {
    shp::Distance self = *this, other = peer, feeling = (self + other);
    return Feeling("+", feeling.getMagnitude(), feeling.getScaling(), self.getUnit(),
		feeling.getIntrinsic(), this->behaviour);
}

Feeling Feeling::operator-(const Feeling& peer) const {
    shp::Distance self = *this, other = peer, feeling = (self - other);
    return Feeling("-", feeling.getMagnitude(), feeling.getScaling(), self.getUnit(),
		feeling.getIntrinsic(), this->behaviour);
}

Feeling Feeling::operator*(const Feeling& peer) const {
    shp::Distance self = *this, other = peer, feeling = (self * other);
    return Feeling("*", feeling.getMagnitude(), feeling.getScaling(), self.getUnit(),
		feeling.getIntrinsic(), this->behaviour);
}

Feeling Feeling::operator/(const Feeling& peer) const {
    shp::Distance self = *this, other = peer, feeling = (self / other);
    return Feeling("/", feeling.getMagnitude(), feeling.getScaling(), self.getUnit(),
		feeling.getIntrinsic(), this->behaviour);
}

Feeling Feeling::operator%(const Feeling& peer) const {
    shp::Distance self = *this, other = peer, feeling = (self % other);
    return Feeling("%", feeling.getMagnitude(), feeling.getScaling(), self.getUnit(),
		feeling.getIntrinsic(), this->behaviour);
}

Feeling Feeling::operator+(const float emotion) const {
    Feeling self = *this; shp::Distance impulse = (self + emotion);
    return Feeling("+", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator-(const float emotion) const {
    Feeling self = *this; shp::Distance impulse = (self - emotion);
    return Feeling("-", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator*(const float emotion) const {
    Feeling self = *this; shp::Distance impulse = (self * emotion);
    return Feeling("*", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator/(const float emotion) const {
    Feeling self = *this; shp::Distance impulse = (self / emotion);
    return Feeling("/", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator%(const float emotion) const {
    Feeling self = *this; shp::Distance impulse = (self % emotion);
    return Feeling("%", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator+(const shp::Quantity& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self + emotion);
    return Feeling("+", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator-(const shp::Quantity& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self - emotion);
    return Feeling("-", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator*(const shp::Quantity& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self * emotion);
    return Feeling("*", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator/(const shp::Quantity& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self / emotion);
    return Feeling("/", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator%(const shp::Quantity& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self % emotion);
    return Feeling("%", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator+(const shp::Distance& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self + emotion);
    return Feeling("+", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator-(const shp::Distance& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self - emotion);
    return Feeling("-", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator*(const shp::Distance& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self * emotion);
    return Feeling("*", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator/(const shp::Distance& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self / emotion);
    return Feeling("/", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator%(const shp::Distance& emotion) const {
    Feeling self = *this; shp::Distance impulse = (self % emotion);
    return Feeling("%", impulse.getMagnitude(), impulse.getScaling(), impulse.getUnit(),
		impulse.getIntrinsic(), self.behaviour);
}

Feeling Feeling::operator+(const shp::Intrinsic& intensity) const {
    Feeling self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() + intensity);
    return Feeling("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.behaviour);
}

Feeling Feeling::operator-(const shp::Intrinsic& intensity) const {
    Feeling self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() - intensity);
    return Feeling("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.behaviour);
}

Feeling Feeling::operator*(const shp::Intrinsic& intensity) const {
    Feeling self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() * intensity);
    return Feeling("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.behaviour);
}

Feeling Feeling::operator/(const shp::Intrinsic& intensity) const {
    Feeling self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() / intensity);
    return Feeling("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.behaviour);
}

Feeling Feeling::operator%(const shp::Intrinsic& intensity) const {
    Feeling self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() % intensity);
    return Feeling("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.behaviour);
}

Feeling Feeling::operator+(const shp::Polar& moderation) const {
    Feeling self = *this; shp::Polar newModeration = (self.getVertical() + moderation);
    Feeling result("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.behaviour);
	result.setVertical(newModeration);
	return result;
}

Feeling Feeling::operator-(const shp::Polar& moderation) const {
    Feeling self = *this; shp::Polar newModeration = (self.getVertical() - moderation);
    Feeling result("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.behaviour);
	result.setVertical(newModeration);
	return result;
}

Feeling Feeling::operator*(const shp::Polar& moderation) const {
    Feeling self = *this; shp::Polar newModeration = (self.getVertical() * moderation);
    Feeling result("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.behaviour);
	result.setVertical(newModeration);
	return result;
}

Feeling Feeling::operator/(const shp::Polar& moderation) const {
    Feeling self = *this; shp::Polar newModeration = (self.getVertical() / moderation);
    Feeling result("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.behaviour);
	result.setVertical(newModeration);
	return result;
}

Feeling Feeling::operator%(const shp::Polar& moderation) const {
    Feeling self = *this; shp::Polar newModeration = (self.getVertical() % moderation);
    Feeling result("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.behaviour);
	result.setVertical(newModeration);
	return result;
}

shp::Distance Feeling::getEmotion() const {
	shp::Distance result = *this;
	return result;
}

void Feeling::setEmotion(const shp::Quantity& emotion, const shp::Intrinsic& direction) {
	shp::Distance::setMagnitude(emotion.getMagnitude(), emotion.getScaling(), emotion.getUnit());
	shp::Distance::setIntrinsic(direction);
}

void Feeling::setEmotion(const shp::Quantity& emotion, const shp::Polar& moderation) {
	shp::Distance::setMagnitude(emotion.getMagnitude(), emotion.getScaling(), emotion.getUnit());
	shp::Distance::setVertical(moderation);
}

void Feeling::setEmotion(const shp::Distance& emotion) {
	shp::Distance::setMagnitude(emotion.getMagnitude(), emotion.getScaling(), emotion.getUnit());
	shp::Distance::setIntrinsic(emotion.getIntrinsic());
	shp::Distance::setHorizontal(emotion.getHorizontal());
	shp::Distance::setVertical(emotion.getVertical());
}

void Feeling::setEmotion(const float emotion) {
	shp::Distance::setMagnitude(emotion);
}

void Feeling::setEmotion(const float emotion, const short int scale) {
	shp::Distance::setMagnitude(emotion, scale);
}

void Feeling::setEmotion(const float emotion, const short int scale, const std::string unit) {
	shp::Distance::setMagnitude(emotion, scale, unit);
}

void Feeling::setEmotion(const float emotion, const short int scale, const shp::Unit& unit) {
	shp::Distance::setMagnitude(emotion, scale, unit);
}

short int Feeling::getScaling() const {
    return shp::Distance::getScaling();
}

void Feeling::setScaling(const short int factor) {
    shp::Distance::setScaling(factor);
}

shp::Unit Feeling::getUnit() const {
	return shp::Distance::getUnit();
}

void Feeling::setUnit(const shp::Unit& unit) {
	shp::Distance::setUnit(unit);
}

shp::Intrinsic Feeling::getIntensity() const {
	return shp::Distance::getIntrinsic();
}

void Feeling::setIntensity(const float intensity) {
	shp::Distance::setIntrinsic(intensity);
}

void Feeling::setIntensity(const shp::Intrinsic& intensity) {
	shp::Distance::setIntrinsic(intensity);
}

void Feeling::setChangeIntensity(const float degree) {
	shp::Distance::setChangeIntrinsic(degree);
}

shp::Polar Feeling::getSituationModeration() const {
	return shp::Distance::getVertical();
}

void Feeling::setSituationModeration(const float moderation) {
	shp::Distance::setVertical(moderation);
}

void Feeling::setSituationModeration(const shp::Polar& moderation) {
	shp::Distance::setVertical(moderation);
}

void Feeling::setChangeSituationModeration(const float degree) {
	shp::Distance::setVerticalCurvature(degree);
}

void Feeling::setChangeEmotion(const float drift) {
	shp::Distance::setChangeMagnitude(drift);
}

void Feeling::setChangeEmotion(const float drift, const short int scale) {
	shp::Distance::setChangeMagnitude(drift, scale);
}

/*
 * Its impossible to hold persistent feelings without referring to a self realm
 */
shp::Signal Feeling::getSummary() const {
	shp::Signal impulse = shp::Distance::getVectorTotal(), interval, feeling;
	if (isTimeBoxed()) {	// selfless beings cannot have a organic feelings
		interval = behaviour->getEndurance();
		feeling = (impulse / interval);
	}
    shp::Signal result(feeling.getOrientation(),
		feeling.getMagnitude(), feeling.getScaling(), UNIT);
    return result;
}

shp::Signal Feeling::getStandard() {
	const float timeperiod = 1.0f;
	return this->getStandard(timeperiod);
}

shp::Signal Feeling::getStandard(const Behaviour& instant) {
	shp::Distance self = *this; shp::Signal frequency(shp::Quantity::DEFAULT_VALUE);
	float emotion = shp::Quantity::DEFAULT_VALUE; short int scaling = shp::Quantity::DEFAULT_SCALE;
	if (isTimeBoxed()) {
		frequency = behaviour->getRepeating();
		emotion = ((self.getAmplitude() * frequency.getMagnitude()) / instant.getDelay());
		scaling = (self.getScaling() + frequency.getScaling());
	}
    shp::Signal result(shp::Direction::DEFAULT_RADIANS, emotion, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Signal Feeling::getPragmatic() {
	return this->getPragmatic(shp::Direction::DEFAULT_RADIANS);
}

shp::Signal Feeling::getPragmatic(const shp::Direction& inclination) {
	shp::Distance self = *this; shp::Quantity convoluted;
	shp::Intrinsic impulse = self.getIntrinsic();
	if (isTimeBoxed()) {
		convoluted = behaviour->getDelayShift();
		impulse.setRotation(convoluted.getMagnitude() + inclination.toRadians());
	}
	std::string unit = convoluted.getUnit().getName() + '/' + shp::Unit::getBaseSymbol(shp::Unit::TIME);
    shp::Signal result(impulse, convoluted.getMagnitude(), convoluted.getScaling(), unit);
    return result;
}

void Feeling::adjustNumeric() {
    shp::Distance::adjustNumeric();
}

void Feeling::adjustScaling() {
    shp::Distance::adjustScaling();
}

bool Feeling::checkNonZero() const {
	return shp::Distance::checkNonZero();
}

bool Feeling::checkInfinity() const {
    return shp::Distance::checkInfinity();
}

short int Feeling::checkScaling(const float amount) const {
    return shp::Distance::checkScaling(amount);
}

shp::Signal Feeling::getScalarNegative() const {
    return shp::Distance::getScalarNegative();
}

shp::Signal Feeling::getVectorNegative() const {
    return shp::Distance::getVectorNegative();
}

shp::Signal Feeling::getScalarInverse() const {
    return shp::Distance::getScalarInverse();
}

shp::Signal Feeling::getVectorInverse() const {
    return shp::Distance::getVectorInverse();
}

shp::Signal Feeling::getScalarSquare() const {
    return shp::Distance::getScalarSquare();
}

shp::Signal Feeling::getVectorSquare() const {
    return shp::Distance::getVectorSquare();
}

shp::Signal Feeling::getScalarFraction(const float length) const {
    return shp::Distance::getScalarFraction(length);
}

shp::Signal Feeling::getScalarFraction(const float length, const short int scale) const {
    return shp::Distance::getScalarFraction(length, scale);
}

shp::Signal Feeling::getScalarSquareFraction(const float length) const {
    return shp::Distance::getScalarSquareFraction(length);
}

shp::Signal Feeling::getScalarSquareFraction(const float length, const short int scale) const {
    return shp::Distance::getScalarSquareFraction(length, scale);
}

bool Feeling::isTimeBoxed() const {
    return (behaviour != nullptr);
}

shp::Distance Feeling::copy() {
	shp::Distance self = *this;
    Feeling fresh(getName(), self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), this->behaviour);
    return fresh;
}

void Feeling::clear() {
	shp::Distance::clear();
	name.clear();
    return;
}

std::string Feeling::print() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print();
	result << ")";
	return result.str();
}

std::string Feeling::printTimeBoxed() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print() << ",";
	result << (isTimeBoxed() ? behaviour->print() : "");
	result << ")";
	return result.str();
}

std::string Feeling::printRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians();
	result << ")";
	return result.str();
}

std::string Feeling::printTimeBoxedRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians() << ",";
	result << (isTimeBoxed() ? behaviour->printRadians() : "");
	result << ")";
	return result.str();
}

shp::Signal Feeling::getCosComponent(const float phase) const {
	shp::Signal feeling = this->getSummary();
	return shp::Signal(feeling.getCosComponent(phase), feeling.getScaling(), feeling.getUnit());
}

shp::Signal Feeling::getSinComponent(const float phase) const {
	shp::Signal feeling = this->getSummary();
	return shp::Signal(feeling.getSinComponent(phase), feeling.getScaling(), feeling.getUnit());
}

shp::Direction Feeling::getEmotionalFeeling(const Behaviour& instant) const {
	float rate = (shp::Distance::getIntrinsic().toRadians() / instant.getDelay());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Feeling::getSituationalFeeling(const Behaviour& instant) const {
	float rate = (shp::Distance::getVertical().toRadians() / instant.getDelay());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Feeling::getEmotionalShiftRate() const {
	shp::Direction result(shp::Distance::getIntrinsic().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Feeling::getSituationalShiftRate() const {
	shp::Direction result(shp::Distance::getVertical().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

std::complex<float> Feeling::toComplex(const float coefficient, const float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace con