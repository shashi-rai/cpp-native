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

#include "stock.h"

namespace fin {

Stock::Stock() : act::Item() {

}

Stock::Stock(std::string name)
        : act::Item(name) {

}

Stock::Stock(std::string name, const shp::Quantity& quantity)
        : act::Item(name, quantity) {

}

Stock::~Stock() {

}

bool Stock::operator==(const Stock& peer) const {
    return (static_cast<const act::Item&>(*this) == static_cast<const act::Item&>(peer));
}

Stock Stock::operator+(const Stock& peer) const {
    return Stock("+", (getQuantity() + peer.getQuantity()));
}

Stock Stock::operator-(const Stock& peer) const {
    return Stock("-", (getQuantity() - peer.getQuantity()));
}

Stock Stock::operator*(const Stock& peer) const {
    return Stock("*", (getQuantity() * peer.getQuantity()));
}

Stock Stock::operator/(const Stock& peer) const {
    return Stock("/", (getQuantity() / peer.getQuantity()));
}

Stock Stock::operator%(const Stock& peer) const {
    return Stock("%", (getQuantity() % peer.getQuantity()));
}

act::Item Stock::copy() {
    Stock fresh(getName(), getQuantity());
    return fresh;
}

void Stock::clear() {
    act::Item::clear();
    return;
}

std::string Stock::print() {
    std::stringstream result;
    result << act::Item::print();
	return result.str();
}

} // namespace fin