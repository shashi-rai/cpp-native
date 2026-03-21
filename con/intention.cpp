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

#include "intention.h"

namespace con {

const std::string Intention::UNIT = "⌘";   // Unit of Measure

Intention::Intention()
        : shp::Distance(UNIT), name() {
	setTraining(nullptr);
}

Intention::Intention(const std::shared_ptr<Pattern> context)
        : shp::Distance(UNIT), name() {
	setTraining(context);
}

Intention::Intention(const std::string name)
        : shp::Distance(UNIT), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(UNIT), name(name) {
	setTraining(context);
}

Intention::Intention(const shp::Unit& unit)
        : shp::Distance(unit), name() {
	setTraining(nullptr);
}

Intention::Intention(const shp::Unit& unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(unit), name() {
	setTraining(context);
}

Intention::Intention(const shp::Intrinsic& bias)
        : shp::Distance(UNIT, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(UNIT, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment)
        : shp::Distance(commitment, UNIT), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const std::string unit)
        : shp::Distance(commitment, unit), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const std::string unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const shp::Unit& unit)
        : shp::Distance(commitment, unit), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const shp::Unit& unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling)
        : shp::Distance(commitment, scaling, UNIT), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const float bias)
        : shp::Distance(commitment, UNIT, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const float bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const shp::Intrinsic& bias)
        : shp::Distance(commitment, UNIT, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const std::string unit, const float bias)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const std::string unit, const float bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const std::string unit, const shp::Intrinsic& bias)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const std::string unit, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const shp::Unit& unit, const shp::Intrinsic& bias)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const shp::Unit& unit, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit)
        : shp::Distance(commitment, scaling, unit), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const shp::Unit& unit)
        : shp::Distance(commitment, scaling, unit), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const shp::Unit& unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const float bias)
        : shp::Distance(commitment, scaling, UNIT, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const float bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, UNIT, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const shp::Intrinsic& bias)
        : shp::Distance(commitment, scaling, UNIT, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, UNIT, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit,
        const float bias)
        : shp::Distance(commitment, scaling, unit, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit, bias), name() {
	setTraining(context);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit,
        const shp::Intrinsic& bias)
        : shp::Distance(commitment, scaling, unit, bias), name() {
	setTraining(nullptr);
}

Intention::Intention(const float commitment, const short int scaling, const std::string unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit, bias), name() {
	setTraining(context);
}

Intention::Intention(const std::string name, const std::string unit)
        : shp::Distance(unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const std::string unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(unit), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const shp::Unit& unit)
        : shp::Distance(unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const shp::Unit& unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(unit), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const shp::Intrinsic& bias)
        : shp::Distance(UNIT, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(UNIT, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment)
        : shp::Distance(commitment, UNIT), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const std::string unit)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const std::string unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling)
        : shp::Distance(commitment, scaling, UNIT), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
		const std::string unit)
        : shp::Distance(commitment, scaling, unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
		const shp::Unit& unit)
        : shp::Distance(commitment, scaling, unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const float bias)
        : shp::Distance(commitment, UNIT, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const float bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const shp::Intrinsic& bias)
        : shp::Distance(commitment, UNIT, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const shp::Intrinsic& bias,
		const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, UNIT, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const std::string unit,
        const float bias)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const std::string unit,
        const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const float bias)
        : shp::Distance(commitment, unit, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias)
        : shp::Distance(commitment, unit, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const shp::Unit& unit,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, unit, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const float bias)
        : shp::Distance(commitment, scaling, UNIT, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, UNIT, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Intrinsic& bias)
        : shp::Distance(commitment, scaling, UNIT, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, UNIT, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const std::string unit, const float bias)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const std::string unit, const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Unit& unit, const float bias)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Unit& unit, const float bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(context);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Unit& unit, const shp::Intrinsic& bias)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(nullptr);
}

Intention::Intention(const std::string name, const float commitment, const short int scaling,
        const shp::Unit& unit, const shp::Intrinsic& bias, const std::shared_ptr<Pattern> context)
        : shp::Distance(commitment, scaling, unit, bias), name(name) {
	setTraining(context);
}

Intention::~Intention() {
	setTraining(nullptr);
}

bool Intention::operator==(const Intention& peer) const {
	return (static_cast<const shp::Distance&>(*this) == static_cast<const shp::Distance&>(peer))
		&& (training == peer.training);
}

bool Intention::operator<(const Intention& peer) const {
	Intention self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) < static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Intention::operator>(const Intention& peer) const {
	Intention self = *this; bool result = false;
    if (static_cast<const shp::Distance&>(*this) > static_cast<const shp::Distance&>(peer)) {
		result = true;
	}
	return result;
}

bool Intention::operator<=(const Intention& peer) const {
    Intention self = *this;
    return (self < peer) || (self == peer);
}

bool Intention::operator>=(const Intention& peer) const {
    Intention self = *this;
    return (self > peer) || (self == peer);
}

Intention Intention::operator+(const Intention& peer) const {
    shp::Distance self = *this, other = peer, commitment = (self + other);
    return Intention("+", commitment.getMagnitude(), commitment.getScaling(), self.getUnit(),
		commitment.getIntrinsic(), this->training);
}

Intention Intention::operator-(const Intention& peer) const {
    shp::Distance self = *this, other = peer, commitment = (self - other);
    return Intention("-", commitment.getMagnitude(), commitment.getScaling(), self.getUnit(),
		commitment.getIntrinsic(), this->training);
}

Intention Intention::operator*(const Intention& peer) const {
    shp::Distance self = *this, other = peer, commitment = (self * other);
    return Intention("*", commitment.getMagnitude(), commitment.getScaling(), self.getUnit(),
		commitment.getIntrinsic(), this->training);
}

Intention Intention::operator/(const Intention& peer) const {
    shp::Distance self = *this, other = peer, commitment = (self / other);
    return Intention("/", commitment.getMagnitude(), commitment.getScaling(), self.getUnit(),
		commitment.getIntrinsic(), this->training);
}

Intention Intention::operator%(const Intention& peer) const {
    shp::Distance self = *this, other = peer, commitment = (self % other);
    return Intention("%", commitment.getMagnitude(), commitment.getScaling(), self.getUnit(),
		commitment.getIntrinsic(), this->training);
}

Intention Intention::operator+(const float influence) const {
    Intention self = *this; shp::Distance commitment = (self + influence);
    return Intention("+", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator-(const float influence) const {
    Intention self = *this; shp::Distance commitment = (self - influence);
    return Intention("-", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator*(const float influence) const {
    Intention self = *this; shp::Distance commitment = (self * influence);
    return Intention("*", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator/(const float influence) const {
    Intention self = *this; shp::Distance commitment = (self / influence);
    return Intention("/", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator%(const float influence) const {
    Intention self = *this; shp::Distance commitment = (self % influence);
    return Intention("%", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator+(const shp::Quantity& influence) const {
    Intention self = *this; shp::Distance commitment = (self + influence);
    return Intention("+", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator-(const shp::Quantity& influence) const {
    Intention self = *this; shp::Distance commitment = (self - influence);
    return Intention("-", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator*(const shp::Quantity& influence) const {
    Intention self = *this; shp::Distance commitment = (self * influence);
    return Intention("*", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator/(const shp::Quantity& influence) const {
    Intention self = *this; shp::Distance commitment = (self / influence);
    return Intention("/", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator%(const shp::Quantity& influence) const {
    Intention self = *this; shp::Distance commitment = (self % influence);
    return Intention("%", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator+(const shp::Distance& influence) const {
    Intention self = *this; shp::Distance commitment = (self + influence);
    return Intention("+", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator-(const shp::Distance& influence) const {
    Intention self = *this; shp::Distance commitment = (self - influence);
    return Intention("-", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator*(const shp::Distance& influence) const {
    Intention self = *this; shp::Distance commitment = (self * influence);
    return Intention("*", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator/(const shp::Distance& influence) const {
    Intention self = *this; shp::Distance commitment = (self / influence);
    return Intention("/", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator%(const shp::Distance& influence) const {
    Intention self = *this; shp::Distance commitment = (self % influence);
    return Intention("%", commitment.getMagnitude(), commitment.getScaling(), commitment.getUnit(),
		commitment.getIntrinsic(), self.training);
}

Intention Intention::operator+(const shp::Intrinsic& bias) const {
    Intention self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() + bias);
    return Intention("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.training);
}

Intention Intention::operator-(const shp::Intrinsic& bias) const {
    Intention self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() - bias);
    return Intention("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.training);
}

Intention Intention::operator*(const shp::Intrinsic& bias) const {
    Intention self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() * bias);
    return Intention("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.training);
}

Intention Intention::operator/(const shp::Intrinsic& bias) const {
    Intention self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() / bias);
    return Intention("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.training);
}

Intention Intention::operator%(const shp::Intrinsic& bias) const {
    Intention self = *this; shp::Intrinsic newIntrinsic = (self.getIntrinsic() % bias);
    return Intention("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		newIntrinsic, self.training);
}

Intention Intention::operator+(const shp::Polar& fatigue) const {
    Intention self = *this; shp::Polar newSaturation = (self.getVertical() + fatigue);
    Intention result("+", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.training);
	result.setVertical(newSaturation);
	return result;
}

Intention Intention::operator-(const shp::Polar& fatigue) const {
    Intention self = *this; shp::Polar newSaturation = (self.getVertical() - fatigue);
    Intention result("-", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.training);
	result.setVertical(newSaturation);
	return result;
}

Intention Intention::operator*(const shp::Polar& fatigue) const {
    Intention self = *this; shp::Polar newSaturation = (self.getVertical() * fatigue);
    Intention result("*", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.training);
	result.setVertical(newSaturation);
	return result;
}

Intention Intention::operator/(const shp::Polar& fatigue) const {
    Intention self = *this; shp::Polar newSaturation = (self.getVertical() / fatigue);
    Intention result("/", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.training);
	result.setVertical(newSaturation);
	return result;
}

Intention Intention::operator%(const shp::Polar& fatigue) const {
    Intention self = *this; shp::Polar newSaturation = (self.getVertical() % fatigue);
    Intention result("%", self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), self.training);
	result.setVertical(newSaturation);
	return result;
}

shp::Distance Intention::getCommitment() const {
	shp::Distance result = *this;
	return result;
}

void Intention::setCommitment(const shp::Quantity& desire, const shp::Intrinsic& bias) {
	shp::Distance::setMagnitude(desire.getMagnitude(), desire.getScaling(), desire.getUnit());
	shp::Distance::setIntrinsic(bias);
}

void Intention::setCommitment(const shp::Quantity& desire, const shp::Azimuth& clarity) {
	shp::Distance::setMagnitude(desire.getMagnitude(), desire.getScaling(), desire.getUnit());
	shp::Distance::setHorizontal(clarity);
}

void Intention::setCommitment(const shp::Quantity& desire, const shp::Polar& trust) {
	shp::Distance::setMagnitude(desire.getMagnitude(), desire.getScaling(), desire.getUnit());
	shp::Distance::setVertical(trust);
}

void Intention::setCommitment(const shp::Distance& objective) {
	shp::Distance::setMagnitude(objective.getMagnitude(), objective.getScaling(), objective.getUnit());
	shp::Distance::setIntrinsic(objective.getIntrinsic());		// bias by others
	shp::Distance::setHorizontal(objective.getHorizontal());	// clarity of thought
	shp::Distance::setVertical(objective.getVertical());		// trust in the idea
}

void Intention::setCommitment(const float desire) {
	shp::Distance::setMagnitude(desire);
}

void Intention::setCommitment(const float desire, const short int scale) {
	shp::Distance::setMagnitude(desire, scale);
}

void Intention::setCommitment(const float desire, const short int scale, const std::string unit) {
	shp::Distance::setMagnitude(desire, scale, unit);
}

void Intention::setCommitment(const float desire, const short int scale, const shp::Unit& unit) {
	shp::Distance::setMagnitude(desire, scale, unit);
}

short int Intention::getScaling() const {
    return shp::Distance::getScaling();
}

void Intention::setScaling(const short int factor) {
    shp::Distance::setScaling(factor);
}

shp::Unit Intention::getUnit() const {
	return shp::Distance::getUnit();
}

void Intention::setUnit(const shp::Unit& unit) {
	shp::Distance::setUnit(unit);
}

shp::Intrinsic Intention::getBias() const {
	return shp::Distance::getIntrinsic();
}

void Intention::setBias(const float intensity) {
	shp::Distance::setIntrinsic(intensity);
}

void Intention::setBias(const shp::Intrinsic& intensity) {
	shp::Distance::setIntrinsic(intensity);
}

void Intention::setChangeBias(const float degree) {
	shp::Distance::setChangeIntrinsic(degree);
}

shp::Azimuth Intention::getClarityThought() const {
	return shp::Distance::getHorizontal();
}

void Intention::setClarityThought(const float deviation) {
	shp::Distance::setHorizontal(deviation);
}

void Intention::setClarityThought(const shp::Azimuth& deviation) {
	shp::Distance::setHorizontal(deviation);
}

void Intention::setChangeClarityThought(const float degree) {
	shp::Distance::setHorizontalCurvature(degree);
}

void Intention::setChangeClarityShiftRate(const float degree) {
	shp::Distance::setHorizontalCurvatureShiftRate(degree);
}

shp::Polar Intention::getTrustSaturation() const {
	return shp::Distance::getVertical();
}

void Intention::setTrustSaturation(const float fatigue) {
	shp::Distance::setVertical(fatigue);
}

void Intention::setTrustSaturation(const shp::Polar& fatigue) {
	shp::Distance::setVertical(fatigue);
}

void Intention::setChangeTrustSaturation(const float degree) {
	shp::Distance::setVerticalCurvature(degree);
}

void Intention::setChangeTrustShiftRate(const float degree) {
	shp::Distance::setVerticalCurvatureShiftRate(degree);
}

void Intention::setChangeCommitment(const float drift) {
	shp::Distance::setChangeMagnitude(drift);
}

void Intention::setChangeCommitment(const float drift, const short int scale) {
	shp::Distance::setChangeMagnitude(drift, scale);
}

/*
 * Its impossible to calculate continuous desire without referring to a self
 */
shp::Signal Intention::getAttitude() const {
	shp::Signal commitment = shp::Distance::getVectorTotal(), interval, desire;
	if (isTrained()) {	// selfless beings cannot have a continuous desire
		interval = training->getMemorable();
		desire = (commitment / interval);
	}
    shp::Signal result(desire.getOrientation(),
		desire.getMagnitude(), desire.getScaling(), UNIT);
    return result;
}

shp::Signal Intention::getTrusted() {
	const float timeperiod = 1.0f;
	return this->getTrusted(timeperiod);
}

shp::Signal Intention::getTrusted(const Pattern& awareness) {
	shp::Distance self = *this; shp::Signal familiar(shp::Quantity::DEFAULT_VALUE);
	float desire = shp::Quantity::DEFAULT_VALUE; short int scaling = shp::Quantity::DEFAULT_SCALE;
	if (isTrained()) {
		familiar = training->getIndicative();
		desire = ((self.getAmplitude() * familiar.getMagnitude()) / awareness.getTemporalDelay());
		scaling = (self.getScaling() + familiar.getScaling());
	}
    shp::Signal result(shp::Direction::DEFAULT_RADIANS, desire, scaling, UNIT); result.adjustScaling();
    return result;
}

shp::Signal Intention::getInfluenced() {
	return this->getInfluenced(shp::Direction::DEFAULT_RADIANS);
}

shp::Signal Intention::getInfluenced(const shp::Direction& promotion) {
	shp::Distance self = *this; shp::Quantity convoluted;
	shp::Intrinsic biasing = self.getIntrinsic();
	if (isTrained()) {
		convoluted = training->getAgeShift();
		biasing.setRotation(convoluted.getMagnitude() + promotion.toRadians());
	}
	std::string unit = convoluted.getUnit().getName() + '/' + shp::Unit::getBaseSymbol(shp::Unit::TIME);
    shp::Signal result(biasing, convoluted.getMagnitude(), convoluted.getScaling(), unit);
    return result;
}

void Intention::adjustNumeric() {
    shp::Distance::adjustNumeric();
}

void Intention::adjustScaling() {
    shp::Distance::adjustScaling();
}

bool Intention::checkNonZero() const {
	return shp::Distance::checkNonZero();
}

bool Intention::checkInfinity() const {
    return shp::Distance::checkInfinity();
}

short int Intention::checkScaling(const float amount) const {
    return shp::Distance::checkScaling(amount);
}

shp::Signal Intention::getScalarNegative() const {
    return shp::Distance::getScalarNegative();
}

shp::Signal Intention::getVectorNegative() const {
    return shp::Distance::getVectorNegative();
}

shp::Signal Intention::getScalarInverse() const {
    return shp::Distance::getScalarInverse();
}

shp::Signal Intention::getVectorInverse() const {
    return shp::Distance::getVectorInverse();
}

shp::Signal Intention::getScalarSquare() const {
    return shp::Distance::getScalarSquare();
}

shp::Signal Intention::getVectorSquare() const {
    return shp::Distance::getVectorSquare();
}

shp::Signal Intention::getScalarFraction(const float desire) const {
    return shp::Distance::getScalarFraction(desire);
}

shp::Signal Intention::getScalarFraction(const float desire, const short int scale) const {
    return shp::Distance::getScalarFraction(desire, scale);
}

shp::Signal Intention::getScalarSquareFraction(const float desire) const {
    return shp::Distance::getScalarSquareFraction(desire);
}

shp::Signal Intention::getScalarSquareFraction(const float desire, const short int scale) const {
    return shp::Distance::getScalarSquareFraction(desire, scale);
}

bool Intention::isTrained() const {
    return (training != nullptr);
}

shp::Distance Intention::copy() {
	shp::Distance self = *this;
    Intention fresh(getName(), self.getMagnitude(), self.getScaling(), self.getUnit(),
		self.getIntrinsic(), this->training);
    return fresh;
}

void Intention::clear() {
	shp::Distance::clear();
	name.clear();
    return;
}

std::string Intention::print() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print();
	result << ")";
	return result.str();
}

std::string Intention::printTraining() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::print() << ",";
	result << (isTrained() ? training->print() : "");
	result << ")";
	return result.str();
}

std::string Intention::printRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians();
	result << ")";
	return result.str();
}

std::string Intention::printTrainingRadians() const {
    std::stringstream result;
    result << "(" << name << ",";
    result << shp::Distance::printRadians() << ",";
	result << (isTrained() ? training->printRadians() : "");
	result << ")";
	return result.str();
}

shp::Signal Intention::getCosComponent(const float phase) const {
	shp::Signal desire = this->getAttitude();
	return shp::Signal(desire.getCosComponent(phase), desire.getScaling(), desire.getUnit());
}

shp::Signal Intention::getSinComponent(const float phase) const {
	shp::Signal desire = this->getAttitude();
	return shp::Signal(desire.getSinComponent(phase), desire.getScaling(), desire.getUnit());
}

shp::Direction Intention::getBiasMoment(const Pattern& awareness) const {
	float rate = (shp::Distance::getIntrinsic().toRadians() / awareness.getTemporalDelay());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Intention::getClarityMoment(const Pattern& awareness) const {
	float rate = (shp::Distance::getHorizontal().toRadians() / awareness.getTemporalDelay());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Intention::getTrustMoment(const Pattern& awareness) const {
	float rate = (shp::Distance::getVertical().toRadians() / awareness.getTemporalDelay());
	rate = std::isinf(rate) ? 0 : rate;		// if time interval = zero
	shp::Direction result(rate * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Intention::getBiasShiftRate() const {
	shp::Direction result(shp::Distance::getIntrinsic().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Intention::getClarityShiftRate() const {
	shp::Direction result(shp::Distance::getHorizontal().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

shp::Direction Intention::getTrustShiftRate() const {
	shp::Direction result(shp::Distance::getVertical().toRadians() * shp::Direction::DEGREE_001);
	return result;
}

std::complex<float> Intention::toComplex(const float coefficient, const float change) {
    return std::complex<float>(
        coefficient * std::cos(change),
        coefficient * std::sin(change));
}

} // namespace con