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

#include "circumstance.h"

namespace con {

Circumstance::Circumstance()
        : Behaviour(), confidence() {

}

Circumstance::Circumstance(const shp::Unit& unit)
        : Behaviour(unit), confidence() {

}

Circumstance::Circumstance(const shp::Potential& confidence)
        : Behaviour(), confidence(confidence) {

}

Circumstance::Circumstance(const shp::Distance& impact)
        : Behaviour(), confidence(impact) {

}

Circumstance::Circumstance(const shp::Azimuth& azimuth)
        : Behaviour(), confidence(azimuth) {

}

Circumstance::Circumstance(const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const shp::Polar& polar)
        : Behaviour(), confidence(polar) {

}

Circumstance::Circumstance(const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(), confidence(impact, polar) {

}

Circumstance::Circumstance(const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const shp::Angular& knowledge)
        : Behaviour(), confidence(knowledge) {

}

Circumstance::Circumstance(const float necessity)
        : Behaviour(necessity), confidence() {

}

Circumstance::Circumstance(const float necessity, const std::string unit)
        : Behaviour(necessity, unit), confidence() {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit)
        : Behaviour(necessity, unit), confidence() {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Potential& confidence)
        : Behaviour(necessity, unit), confidence(confidence) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Distance& impact)
        : Behaviour(necessity, unit), confidence(impact) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Behaviour(necessity, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Distance& impact,
        const shp::Azimuth& azimuth)
        : Behaviour(necessity, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Polar& polar)
        : Behaviour(necessity, unit), confidence(polar) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Distance& impact,
		const shp::Polar& polar)
        : Behaviour(necessity, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(necessity, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(necessity, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const float necessity, const shp::Unit& unit, const shp::Angular& knowledge)
        : Behaviour(necessity, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const float necessity, const short int scaling)
        : Behaviour(necessity, scaling), confidence() {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const std::string unit)
        : Behaviour(necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit)
        : Behaviour(necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Potential& confidence)
        : Behaviour(necessity,scaling, unit), confidence(confidence) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Distance& impact)
        : Behaviour(necessity,scaling, unit), confidence(impact) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Azimuth& azimuth)
        : Behaviour(necessity,scaling, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(necessity,scaling, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Polar& polar)
        : Behaviour(necessity, scaling, unit), confidence(polar) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(necessity, scaling, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(necessity, scaling, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(necessity, scaling, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const float necessity, const short int scaling, const shp::Unit& unit,
		const shp::Angular& knowledge)
        : Behaviour(necessity, scaling, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const shp::Signal& experience)
        : Behaviour(experience), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const std::string unit)
        : Behaviour(experience, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const shp::Unit& unit)
        : Behaviour(experience, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity)
        : Behaviour(experience, necessity), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const std::string unit)
        : Behaviour(experience, necessity, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit)
        : Behaviour(experience, necessity, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Potential& confidence)
        : Behaviour(experience, necessity, unit), confidence(confidence) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact)
        : Behaviour(experience, necessity, unit), confidence(impact) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Polar& polar)
        : Behaviour(experience, necessity, unit), confidence(polar) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(experience, necessity, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const shp::Unit& unit,
		const shp::Angular& knowledge)
        : Behaviour(experience, necessity, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling)
        : Behaviour(experience, necessity, scaling), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const std::string unit)
        : Behaviour(experience, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit)
        : Behaviour(experience, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Potential& confidence)
        : Behaviour(experience, necessity,scaling, unit), confidence(confidence) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact)
        : Behaviour(experience, necessity,scaling, unit), confidence(impact) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity,scaling, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity,scaling, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Polar& polar)
        : Behaviour(experience, necessity, scaling, unit), confidence(polar) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(experience, necessity, scaling, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, scaling, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(experience, necessity, scaling, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const shp::Signal& experience, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Angular& knowledge)
        : Behaviour(experience, necessity, scaling, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const std::string name, const std::string unit)
        : Behaviour(name, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Unit& unit)
        : Behaviour(name, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Potential& confidence)
        : Behaviour(name), confidence(confidence) {

}

Circumstance::Circumstance(const std::string name, const shp::Distance& impact)
        : Behaviour(name), confidence(impact) {

}

Circumstance::Circumstance(const std::string name, const shp::Azimuth& azimuth)
        : Behaviour(name), confidence(azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(name), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Polar& polar)
        : Behaviour(name), confidence(polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(name), confidence(impact, polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Distance& impact,
		const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Angular& knowledge)
        : Behaviour(name), confidence(knowledge) {

}

Circumstance::Circumstance(const std::string name, const float necessity)
        : Behaviour(name, necessity), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const std::string unit)
        : Behaviour(name, necessity, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit)
        : Behaviour(name, necessity, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Potential& confidence)
        : Behaviour(name, necessity, unit), confidence(confidence) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact)
        : Behaviour(name, necessity, unit), confidence(impact) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Polar& polar)
        : Behaviour(name, necessity, unit), confidence(polar) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(name, necessity, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Distance& impact, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const shp::Unit& unit,
		const shp::Angular& knowledge)
        : Behaviour(name, necessity, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling)
        : Behaviour(name, necessity, scaling), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const std::string unit)
        : Behaviour(name, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit)
        : Behaviour(name, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Potential& confidence)
        : Behaviour(name, necessity, scaling, unit), confidence(confidence) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact)
        : Behaviour(name, necessity, scaling, unit), confidence(impact) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, scaling, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, scaling, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Polar& polar)
        : Behaviour(name, necessity, scaling, unit), confidence(polar) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(name, necessity, scaling, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, scaling, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar,
		const shp::Azimuth& azimuth)
        : Behaviour(name, necessity, scaling, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const float necessity, const short int scaling,
		const shp::Unit& unit, const shp::Angular& knowledge)
        : Behaviour(name, necessity, scaling, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience)
        : Behaviour(name, experience), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const std::string unit)
        : Behaviour(name, experience, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const shp::Unit& unit)
        : Behaviour(name, experience, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity)
        : Behaviour(name, experience, necessity), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const std::string unit)
        : Behaviour(name, experience, necessity, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit)
        : Behaviour(name, experience, necessity, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Potential& confidence)
        : Behaviour(name, experience, necessity, unit), confidence(confidence) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Distance& impact)
        : Behaviour(name, experience, necessity, unit), confidence(impact) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Polar& polar)
        : Behaviour(name, experience, necessity, unit), confidence(polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar)
        : Behaviour(name, experience, necessity, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Distance& impact, const shp::Polar& polar,
			const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const shp::Unit& unit, const shp::Angular& knowledge)
        : Behaviour(name, experience, necessity, unit), confidence(knowledge) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling)
        : Behaviour(name, experience, necessity, scaling), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const std::string unit)
        : Behaviour(name, experience, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit)
        : Behaviour(name, experience, necessity, scaling, unit), confidence() {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Potential& confidence)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(confidence) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Distance& impact)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(impact) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
		const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(impact, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Polar& polar)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
		const shp::Polar& polar)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(impact, polar) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Distance& impact,
		const shp::Polar& polar, const shp::Azimuth& azimuth)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(impact, polar, azimuth) {

}

Circumstance::Circumstance(const std::string name, const shp::Signal& experience, const float necessity,
		const short int scaling, const shp::Unit& unit, const shp::Angular& knowledge)
        : Behaviour(name, experience, necessity, scaling, unit), confidence(knowledge) {

}

Circumstance::~Circumstance() {

}

bool Circumstance::operator==(const Circumstance& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (confidence == peer.confidence);
}

bool Circumstance::operator<(const Circumstance& peer) const {
    return (static_cast<const Behaviour&>(*this) < static_cast<const Behaviour&>(peer))
        && (confidence < peer.confidence);
}

bool Circumstance::operator>(const Circumstance& peer) const {
    return (static_cast<const Behaviour&>(*this) > static_cast<const Behaviour&>(peer))
        && (confidence > peer.confidence);
}

bool Circumstance::operator<=(const Circumstance& peer) const {
    Circumstance self = *this;
    return (self < peer) || (self == peer);
}

bool Circumstance::operator>=(const Circumstance& peer) const {
    Circumstance self = *this;
    return (self > peer) || (self == peer);
}

Circumstance Circumstance::operator+(const Circumstance& peer) const {
    Behaviour self = *this, other = peer, situation = (self + other);
    shp::Potential newConfidence = (confidence + peer.confidence);
    return Circumstance("+", situation.getExperience(), situation.getDelay(),
		situation.getScaling(), situation.getUnit(), newConfidence);
}

Circumstance Circumstance::operator-(const Circumstance& peer) const {
    Behaviour self = *this, other = peer, situation = (self - other);
    shp::Potential newConfidence = (confidence - peer.confidence);
    return Circumstance("-", situation.getExperience(), situation.getDelay(),
		situation.getScaling(), situation.getUnit(), newConfidence);
}

Circumstance Circumstance::operator*(const Circumstance& peer) const {
    Behaviour self = *this, other = peer, situation = (self * other);
    shp::Potential newConfidence = (confidence * peer.confidence);
    return Circumstance("*", situation.getExperience(), situation.getDelay(),
		situation.getScaling(), situation.getUnit(), newConfidence);
}

Circumstance Circumstance::operator/(const Circumstance& peer) const {
    Behaviour self = *this, other = peer, situation = (self / other);
    shp::Potential newConfidence = (confidence / peer.confidence);
    return Circumstance("/", situation.getExperience(), situation.getDelay(),
		situation.getScaling(), situation.getUnit(), newConfidence);
}

Circumstance Circumstance::operator%(const Circumstance& peer) const {
    Behaviour self = *this, other = peer, situation = (self % other);
    shp::Potential newConfidence = (confidence % peer.confidence);
    return Circumstance("%", situation.getExperience(), situation.getDelay(),
		situation.getScaling(), situation.getUnit(), newConfidence);
}

shp::Signal Circumstance::operator()(const Circumstance& peer,
        const shp::Distance& awareness, const shp::Distance& stance) const {
    shp::Signal result = confidence(peer.confidence, awareness, stance);
    result.adjustScaling();
    return result;
}

shp::Signal Circumstance::operator()(const Circumstance& peerX, const Circumstance& peerY,
        const shp::Distance& awarenessX, const shp::Distance& awarenessY) const {
    shp::Signal result = confidence(peerX.getConfidence(), peerY.getConfidence(), awarenessX, awarenessY);
    result.adjustScaling();
    return result;
}

shp::Azimuth Circumstance::getExperienceChange() const {
    return Behaviour::getExperienceShift();
}

void Circumstance::setExperienceChange(const shp::Azimuth& moderation) {
    Behaviour::setExperienceShift(moderation);
}

void Circumstance::setExperienceChange(const float action, const shp::Azimuth& moderation) {
    Behaviour::setExperienceShift(action, moderation);
}

void Circumstance::setExperienceChange(const float action, const short int scale,
        const shp::Azimuth& moderation) {
    Behaviour::setExperienceShift(action, scale, moderation);
}

void Circumstance::setExperienceChange(const float action, const short int scale, const std::string unit,
        const shp::Azimuth& moderation) {
    Behaviour::setExperienceShift(action, scale, unit, moderation);
}

void Circumstance::setExperienceChange(const float action, const short int scale, const shp::Unit& unit,
        const shp::Azimuth& moderation) {
    Behaviour::setExperienceShift(action, scale, unit, moderation);
}

shp::Azimuth Circumstance::getIntentionChange() const {
    return Behaviour::getIntentionDrift();
}

void Circumstance::setIntentionChange(const shp::Azimuth& moderation) {
    Behaviour::setIntentionDrift(moderation);
}

void Circumstance::setIntentionChange(const float intent) {
    Behaviour::setDelay(intent);
}

void Circumstance::setIntentionChange(const shp::Signal& signal) {
    Behaviour::setExperience(signal);
}

void Circumstance::setIntentionChange(const float intent, const short int scale) {
    Behaviour::setDelay(intent, scale);
}

void Circumstance::setIntentionChange(const float intent, const short int scale, const std::string unit) {
    Behaviour::setDelay(intent, scale, unit);
}

void Circumstance::setIntentionChange(const float intent, const short int scale, const shp::Unit& unit) {
    Behaviour::setDelay(intent, scale, unit);
}

shp::Angular Circumstance::getContext() const {
    return confidence.getOrigin();
}

void Circumstance::setContext(const shp::Angular& knowledge) {
    confidence.setOrigin(knowledge);
}

shp::Distance Circumstance::getCapability() const {
    return confidence.getRadius();
}

void Circumstance::setCapability(const shp::Distance& knowledge) {
    confidence.setRadius(knowledge.getMagnitude(), knowledge.getScaling(), knowledge.getUnit());
}

void Circumstance::setCapability(const float knowledge) {
    confidence.setRadius(knowledge);
}

void Circumstance::setCapability(const float knowledge, const short int scale) {
    confidence.setRadius(knowledge, scale);
}

void Circumstance::setCapability(const float knowledge, const short int scale, const std::string unit) {
    confidence.setRadius(knowledge, scale, unit);
}

void Circumstance::setCapability(const float knowledge, const short int scale, const shp::Unit& unit) {
    confidence.setRadius(knowledge, scale, unit);
}

shp::Azimuth Circumstance::getCentral() const {
    return confidence.getAzimuthOrientation();
}

void Circumstance::setCentral(const shp::Azimuth& impact) {
    this->confidence.setAzimuthOrientation(impact);
}

shp::Polar Circumstance::getPeripheral() const {
    return confidence.getPolarOrientation();
}

void Circumstance::setPeripheral(const shp::Polar& impact) {
    this->confidence.setPolarOrientation(impact);
}

Circumstance Circumstance::getLevel() const {
	Behaviour self = *this, gap = confidence.getDifference();
    return Circumstance(gap.getIntentionDrift(), gap.getDelay(), gap.getScaling(), gap.getUnit());
}

Circumstance Circumstance::copy() {
    Behaviour self = *this;
    Circumstance fresh(Behaviour::getName(),
		self.getExperience(), self.getDelay(), self.getScaling(), self.getUnit(), this->confidence);
    return fresh;
}

void Circumstance::clear() {
    Behaviour::clear();
    confidence.clear();
    return;
}

std::string Circumstance::print() const {
    std::stringstream result;
    result << "≡";
    result << confidence.print() << ",";
    result << Behaviour::print();
	return result.str();
}

std::string Circumstance::printRadians() const {
    std::stringstream result;
    result << "≡";
    result << confidence.printRadians() << ",";
    result << Behaviour::printRadians();
	return result.str();
}

Circumstance Circumstance::getFluctuation(const float phase) const {
	shp::Temporal temporary = this->getEndurance();
    temporary.setIntensityDrift(shp::Azimuth(phase));
	return Circumstance(Behaviour::getName(), temporary.getMagnitude(), temporary.getScaling(), temporary.getUnit());
}

const std::shared_ptr<con::Circumstance> Circumstance::shareable(const std::string name,
		const float necessity, const short int scaling) {
    std::shared_ptr<con::Circumstance> result = std::make_shared<con::Circumstance>(name, necessity, scaling);
    return result;
}

} // namespace con