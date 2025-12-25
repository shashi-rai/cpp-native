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

#include "interest.h"

namespace act {

const float Interest::DEFAULT_VALUE = 0.0f;     // Interest Rate

Interest::Interest() : name(), rate(DEFAULT_VALUE), principal() {

}

Interest::Interest(std::string name)
        : name(name), rate(DEFAULT_VALUE), principal() {

}

Interest::Interest(const float rate)
        : name(), rate(rate), principal() {

}

Interest::Interest(const Amount& principal)
        : name(), rate(DEFAULT_VALUE), principal(principal) {

}

Interest::Interest(const float rate, const Amount& principal)
        : name(), rate(rate), principal(principal) {

}

Interest::Interest(std::string name, const Amount& principal)
        : name(name), rate(DEFAULT_VALUE), principal(principal) {

}

Interest::Interest(std::string name, const float rate, const Amount& principal)
        : name(name), rate(rate), principal(principal) {

}

Interest::~Interest() {

}

bool Interest::operator==(const Interest& peer) const {
    return (name == peer.name) && (rate == peer.rate) && (principal == peer.principal);
}

Interest Interest::operator+(const Interest& peer) const {
    return Interest("+", (rate + peer.rate), (principal + peer.principal));
}

Interest Interest::operator-(const Interest& peer) const {
    return Interest("-", (rate - peer.rate), (principal - peer.principal));
}

Interest Interest::operator*(const Interest& peer) const {
    return Interest("*", (rate * peer.rate), (principal * peer.principal));
}

Interest Interest::operator/(const Interest& peer) const {
    return Interest("/", (rate / peer.rate), (principal / peer.principal));
}

Interest Interest::operator%(const Interest& peer) const {
    return Interest("%", fmod(rate, peer.rate), (principal % peer.principal));
}

Amount Interest::getSimple(const float time) {
    float total = (principal.getValue() * rate * time);
    return Amount(total, principal.getCurrency());
}

Amount Interest::getCompound(const short int period, const float time) {
    float total = (principal.getValue() * pow((1 + (rate / period)), (period * time)));
    return Amount(total, principal.getCurrency());
}

Interest Interest::copy() {
    Interest fresh(name, rate, principal);
    return fresh;
}

void Interest::clear() {
    name = "";
    rate = DEFAULT_VALUE;
    principal.clear();
    return;
}

std::string Interest::print() {
    std::stringstream result;
    result << name << ",%:";
    result << rate << ",";
    result << principal.print();
	return result.str();
}

} // namespace act