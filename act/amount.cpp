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

#include "amount.h"

namespace act {

const float Amount::DEFAULT_VALUE = 0.0f;

Amount::Amount()
        : datetime(), value(DEFAULT_VALUE), currency(), remarks() {

}

Amount::Amount(const float value)
        : datetime(), value(value), currency(), remarks() {

}

Amount::Amount(std::string remarks)
        : datetime(), value(), currency(), remarks(remarks) {

}

Amount::Amount(const Currency& currency)
        : datetime(), value(), currency(currency), remarks() {

}

Amount::Amount(const Currency& currency, std::string remarks)
        : datetime(), value(), currency(currency), remarks(remarks) {

}

Amount::Amount(const float value, std::string remarks)
        : datetime(), value(value), currency(), remarks(remarks) {

}

Amount::Amount(const float value, const Currency& currency)
        : datetime(), value(value), currency(currency), remarks() {

}

Amount::Amount(const float value, const Currency& currency, std::string remarks)
        : datetime(), value(value), currency(currency), remarks(remarks) {

}

Amount::Amount(const long datetime, const float value, std::string remarks)
        : datetime(datetime), value(value), currency(), remarks(remarks) {

}

Amount::Amount(const long datetime, const float value, const Currency& currency, std::string remarks)
        : datetime(datetime), value(value), currency(currency), remarks(remarks) {

}

Amount::~Amount() {

}

bool Amount::operator==(const Amount& peer) const {
    return (datetime == peer.datetime)
        && (value == peer.value)
        && (currency == peer.currency)
        && (remarks == peer.remarks);
}

Amount Amount::operator+(const Amount& peer) const {
    return Amount((value + peer.value), currency);
}

Amount Amount::operator-(const Amount& peer) const {
    return Amount((value - peer.value), currency);
}

Amount Amount::operator*(const Amount& peer) const {
    return Amount((value * peer.value), currency);
}

Amount Amount::operator/(const Amount& peer) const {
    return Amount((value / peer.value), currency);
}

Amount Amount::operator%(const Amount& peer) const {
    return Amount(fmod(value, peer.value), currency);
}

Amount Amount::operator+(const float number) const {
    return Amount((value + number), currency);
}

Amount Amount::operator-(const float number) const {
    return Amount((value - number), currency);
}

Amount Amount::operator*(const float number) const {
    return Amount((value * number), currency);
}

Amount Amount::operator/(const float number) const {
    return Amount((value / number), currency);
}

Amount Amount::operator%(const float number) const {
    return Amount(fmod(value, number), currency);
}

Amount Amount::copy() {
    Amount fresh(datetime.getValue(), value, currency, remarks);
    return fresh;
}

void Amount::clear() {
    datetime.clear();
    value = DEFAULT_VALUE;
    currency.clear();
    remarks.clear();
    return;
}

std::string Amount::print() {
    std::stringstream result;
    result << "(";
    result << currency.print();
    result << value << " @";
    result << datetime.print() << "!";
    result << remarks << ")";
	return result.str();
}

} // namespace act