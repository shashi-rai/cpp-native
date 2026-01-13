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

#include "alternating.h"

namespace ecn {

Alternating::Alternating()
        : Neutral(), line1(), line2(), line3() {

}

Alternating::Alternating(const Conductor& line1)
        : Neutral(), line1(line1), line2(), line3() {

}

Alternating::Alternating(const Conductor& line1,
        const Conductor& neutral)
        : Neutral(neutral), line1(line1), line2(), line3() {

}

Alternating::Alternating(const Conductor& line1, const Conductor& line2,
        const Conductor& neutral)
        : Neutral(neutral), line1(line1), line2(line2), line3() {

}

Alternating::Alternating(const Conductor& line1, const Conductor& line2, const Conductor& line3,
        const Conductor& neutral)
        : Neutral(neutral), line1(line1), line2(line2), line3(line3) {

}

Alternating::Alternating(std::string name)
        : Neutral(name), line1(), line2(), line3() {

}

Alternating::Alternating(std::string name, const Conductor& line1)
        : Neutral(name), line1(line1), line2(), line3() {

}

Alternating::Alternating(std::string name, const Conductor& line1,
        const Conductor& neutral)
        : Neutral(name, neutral), line1(line1), line2(), line3() {

}

Alternating::Alternating(std::string name, const Conductor& line1, const Conductor& line2,
        const Conductor& neutral)
        : Neutral(name, neutral), line1(line1), line2(line2), line3() {

}

Alternating::Alternating(std::string name, const Conductor& line1, const Conductor& line2,
        const Conductor& line3, const Conductor& neutral)
        : Neutral(name, neutral), line1(line1), line2(line2), line3(line3) {

}

Alternating::~Alternating() {

}

bool Alternating::operator==(const Alternating& peer) const {
    return (static_cast<const Neutral&>(*this) == static_cast<const Neutral&>(peer))
        && (line1 == peer.line1) && ((line2 == peer.line2)) && ((line3 == peer.line3));
}

Alternating Alternating::operator+(const Alternating& peer) const {
    Neutral self = *this, other = peer;
    Neutral neutral = (self + other);
    return Alternating("+", (line1 + peer.line1), (line2 + peer.line2), (line3 + peer.line3),
        neutral.getLine());
}

Alternating Alternating::operator-(const Alternating& peer) const {
    Neutral self = *this, other = peer;
    Neutral neutral = (self - other);
    return Alternating("-", (line1 - peer.line1), (line2 - peer.line2), (line3 - peer.line3),
        neutral.getLine());
}

Alternating Alternating::operator*(const Alternating& peer) const {
    Neutral self = *this, other = peer;
    Neutral neutral = (self * other);
    return Alternating("*", (line1 * peer.line1), (line2 * peer.line2), (line3 * peer.line3),
        neutral.getLine());
}

Alternating Alternating::operator/(const Alternating& peer) const {
    Neutral self = *this, other = peer;
    Neutral neutral = (self / other);
    return Alternating("/", (line1 / peer.line1), (line2 / peer.line2), (line3 / peer.line3),
        neutral.getLine());
}

Alternating Alternating::operator%(const Alternating& peer) const {
    Neutral self = *this, other = peer;
    Neutral neutral = (self % other);
    return Alternating("%", (line1 % peer.line1), (line2 % peer.line2), (line3 % peer.line3),
        neutral.getLine());
}

Conductor Alternating::getNeutral() const {
    return Neutral::getLine();
}

void Alternating::setNeutral(const Conductor& line) {
    Neutral::setLine(line);
}

shp::Potential Alternating::getVoltageL1() const {
    Conductor neutral = getNeutral();
    shp::Temporal charge = (line1.getCharge() - neutral.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(line1.getCharge().getMagnitude(), neutral.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

shp::Potential Alternating::getVoltageL2() const {
    Conductor neutral = getNeutral();
    shp::Temporal charge = (line2.getCharge() - neutral.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(line2.getCharge().getMagnitude(), neutral.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

shp::Potential Alternating::getVoltageL3() const {
    Conductor neutral = getNeutral();
    shp::Temporal charge = (line3.getCharge() - neutral.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(line3.getCharge().getMagnitude(), neutral.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

Alternating Alternating::copy() {
    Alternating fresh(getName(), line1, line2, line3, getNeutral());
    return fresh;
}

void Alternating::clear() {
    Neutral::clear();
    line1.clear();
    line2.clear();
    line3.clear();
    return;
}

std::string Alternating::print() {
    std::stringstream result;
    result << Neutral::print() << ",L1:";
    result << line1.print() << ",L2:";
    result << line2.print() << ",L3:";
    result << line3.print();
	return result.str();
}

} // namespace ecn