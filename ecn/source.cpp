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

#include "source.h"

namespace ecn {

Source::Source()
        : Neutral(), positive() {

}

Source::Source(const Conductor& positive)
        : Neutral(), positive(positive) {

}

Source::Source(const Conductor& positive, const Conductor& negative)
        : Neutral(negative), positive(positive) {

}

Source::Source(std::string name)
        : Neutral(name), positive() {

}

Source::Source(std::string name, const Conductor& positive)
        : Neutral(name), positive(positive) {

}

Source::Source(std::string name, const Conductor& positive, const Conductor& negative)
        : Neutral(name, negative), positive(positive) {

}

Source::~Source() {

}

bool Source::operator==(const Source& peer) const {
    return (static_cast<const Neutral&>(*this) == static_cast<const Neutral&>(peer))
        && (positive == peer.positive);
}

Source Source::operator+(const Source& peer) const {
    Neutral self = *this, other = peer;
    Neutral negative = (self + other);
    return Source("+", (positive + peer.positive), negative.getLine());
}

Source Source::operator-(const Source& peer) const {
    Neutral self = *this, other = peer;
    Neutral negative = (self - other);
    return Source("-", (positive - peer.positive), negative.getLine());
}

Source Source::operator*(const Source& peer) const {
    Neutral self = *this, other = peer;
    Neutral negative = (self * other);
    return Source("*", (positive * peer.positive), negative.getLine());
}

Source Source::operator/(const Source& peer) const {
    Neutral self = *this, other = peer;
    Neutral negative = (self / other);
    return Source("/", (positive / peer.positive), negative.getLine());
}

Source Source::operator%(const Source& peer) const {
    Neutral self = *this, other = peer;
    Neutral negative = (self % other);
    return Source("%", (positive % peer.positive), negative.getLine());
}

Conductor Source::getNegative() const {
    return Neutral::getLine();
}

void Source::setNegative(const Conductor& line) {
    Neutral::setLine(line);
}

shp::Potential Source::getVoltage() const {
    Conductor negative = getNegative();
    shp::Temporal charge = (positive.getCharge() - negative.getCharge());
    short int scaling = charge.getScaling();
    shp::Potential fresh(positive.getCharge().getMagnitude(), negative.getCharge().getMagnitude(),
        scaling, shp::Unit::getDerivedSymbol(shp::Unit::ELECTRIC_POTENTIAL));
    return fresh;
}

Source Source::copy() {
    Source fresh(getName(), positive, getNegative());
    return fresh;
}

void Source::clear() {
    Neutral::clear();
    positive.clear();
    return;
}

std::string Source::print() {
    std::stringstream result;
    result << Neutral::print() << ",+:";
    result << positive.print();
	return result.str();
}

} // namespace ecn