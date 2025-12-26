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

#include "depreciation.h"

namespace act {

const float Depreciation::DEFAULT_VALUE = 0.0f;     // Deterioration Rate

Depreciation::Depreciation() : name(), rate(DEFAULT_VALUE), principal() {

}

Depreciation::Depreciation(std::string name)
        : name(name), rate(DEFAULT_VALUE), principal() {

}

Depreciation::Depreciation(const float rate)
        : name(), rate(rate), principal() {

}

Depreciation::Depreciation(const Amount& principal)
        : name(), rate(DEFAULT_VALUE), principal(principal) {

}

Depreciation::Depreciation(const float rate, const Amount& principal)
        : name(), rate(rate), principal(principal) {

}

Depreciation::Depreciation(std::string name, const Amount& principal)
        : name(name), rate(DEFAULT_VALUE), principal(principal) {

}

Depreciation::Depreciation(std::string name, const float rate, const Amount& principal)
        : name(name), rate(rate), principal(principal) {

}

Depreciation::~Depreciation() {

}

bool Depreciation::operator==(const Depreciation& peer) const {
    return (name == peer.name) && (rate == peer.rate) && (principal == peer.principal);
}

Depreciation Depreciation::operator+(const Depreciation& peer) const {
    return Depreciation("+", (rate + peer.rate), (principal + peer.principal));
}

Depreciation Depreciation::operator-(const Depreciation& peer) const {
    return Depreciation("-", (rate - peer.rate), (principal - peer.principal));
}

Depreciation Depreciation::operator*(const Depreciation& peer) const {
    return Depreciation("*", (rate * peer.rate), (principal * peer.principal));
}

Depreciation Depreciation::operator/(const Depreciation& peer) const {
    return Depreciation("/", (rate / peer.rate), (principal / peer.principal));
}

Depreciation Depreciation::operator%(const Depreciation& peer) const {
    return Depreciation("%", fmod(rate, peer.rate), (principal % peer.principal));
}

Amount Depreciation::getSimple(const float time) {
    float total = (principal.getValue() * rate * time);
    return Amount(total, principal.getCurrency());
}

Amount Depreciation::getCompound(const short int period, const float time) {
    float total = (principal.getValue() * pow((1 + (rate / period)), (period * time)));
    return Amount(total, principal.getCurrency());
}

Depreciation Depreciation::copy() {
    Depreciation fresh(name, rate, principal);
    return fresh;
}

void Depreciation::clear() {
    name = "";
    rate = DEFAULT_VALUE;
    principal.clear();
    return;
}

std::string Depreciation::print() {
    std::stringstream result;
    result << name << ",%:";
    result << rate << ",";
    result << principal.print();
	return result.str();
}

} // namespace act