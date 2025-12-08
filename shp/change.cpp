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

#include "change.h"

namespace shp {

Change::Change() : gradient() {

}

Change::Change(const float gradient) : gradient(gradient) {

}

Change::Change(const Direction& gradient) : gradient(gradient) {

}

Change::~Change() {

}

bool Change::operator==(const Change& peer) const {
    return (gradient == peer.gradient);
}

Change Change::operator+(const Change& peer) const {
    return Change(gradient + peer.gradient);
}

Change Change::operator-(const Change& peer) const {
    return Change(gradient - peer.gradient);
}

Change Change::operator*(const Change& peer) const {
    return Change(gradient * peer.gradient);
}

Change Change::operator/(const Change& peer) const {
    return Change(gradient / peer.gradient);
}

Change Change::operator%(const Change& peer) const {
    return Change(gradient % peer.gradient);
}

float Change::toRadians() const {
    return gradient.toRadians();
}

Change Change::copy() {
    Change fresh(gradient);
    return fresh;
}

void Change::clear() {
    gradient.clear();
    return;
}

std::string Change::print() {
    std::stringstream result;
    result << gradient.print();
	return result.str();
}

} // namespace shp