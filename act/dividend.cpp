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

#include "dividend.h"

namespace act {

const float Dividend::DEFAULT_VALUE = 0.0f;     // Stock Growth Rate

Dividend::Dividend() : name(), rate(DEFAULT_VALUE), principal() {

}

Dividend::Dividend(std::string name)
        : name(name), rate(DEFAULT_VALUE), principal() {

}

Dividend::Dividend(const float rate)
        : name(), rate(rate), principal() {

}

Dividend::Dividend(const Amount& principal)
        : name(), rate(DEFAULT_VALUE), principal(principal) {

}

Dividend::Dividend(const float rate, const Amount& principal)
        : name(), rate(rate), principal(principal) {

}

Dividend::Dividend(std::string name, const Amount& principal)
        : name(name), rate(DEFAULT_VALUE), principal(principal) {

}

Dividend::Dividend(std::string name, const float rate, const Amount& principal)
        : name(name), rate(rate), principal(principal) {

}

Dividend::~Dividend() {

}

bool Dividend::operator==(const Dividend& peer) const {
    return (name == peer.name) && (rate == peer.rate) && (principal == peer.principal);
}

Dividend Dividend::operator+(const Dividend& peer) const {
    return Dividend("+", (rate + peer.rate), (principal + peer.principal));
}

Dividend Dividend::operator-(const Dividend& peer) const {
    return Dividend("-", (rate - peer.rate), (principal - peer.principal));
}

Dividend Dividend::operator*(const Dividend& peer) const {
    return Dividend("*", (rate * peer.rate), (principal * peer.principal));
}

Dividend Dividend::operator/(const Dividend& peer) const {
    return Dividend("/", (rate / peer.rate), (principal / peer.principal));
}

Dividend Dividend::operator%(const Dividend& peer) const {
    return Dividend("%", fmod(rate, peer.rate), (principal % peer.principal));
}

Amount Dividend::getSimple(const float time) {
    float total = (principal.getValue() * rate * time);
    return Amount(total, principal.getCurrency());
}

Amount Dividend::getCompound(const short int period, const float time) {
    float total = (principal.getValue() * pow((1 + (rate / period)), (period * time)));
    return Amount(total, principal.getCurrency());
}

Dividend Dividend::copy() {
    Dividend fresh(name, rate, principal);
    return fresh;
}

void Dividend::clear() {
    name = "";
    rate = DEFAULT_VALUE;
    principal.clear();
    return;
}

std::string Dividend::print() {
    std::stringstream result;
    result << name << ",%:";
    result << rate << ",";
    result << principal.print();
	return result.str();
}

} // namespace act