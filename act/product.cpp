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

#include "product.h"

namespace act {

Product::Product() : Item(), brand() {

}

Product::Product(std::string name)
        : Item(name), brand() {

}

Product::Product(const shp::Quantity& quantity)
        : Item(quantity), brand() {

}

Product::Product(std::string name, const shp::Quantity& quantity)
        : Item(name, quantity), brand() {

}

Product::Product(const Brand& brand)
        : Item(), brand(brand) {

}

Product::Product(std::string name, const Brand& brand)
        : Item(name), brand(brand) {

}

Product::Product(std::string name, const shp::Quantity& quantity, const Brand& brand)
        : Item(name, quantity), brand(brand) {

}

Product::~Product() {

}

bool Product::operator==(const Product& peer) const {
    return (static_cast<const Item&>(*this) == static_cast<const Item&>(peer))
        && (brand == peer.brand);
}

Product Product::operator+(const Product& peer) const {
    return Product("+", (getQuantity() + peer.getQuantity()), brand);
}

Product Product::operator-(const Product& peer) const {
    return Product("-", (getQuantity() - peer.getQuantity()), brand);
}

Product Product::operator*(const Product& peer) const {
    return Product("*", (getQuantity() * peer.getQuantity()), brand);
}

Product Product::operator/(const Product& peer) const {
    return Product("/", (getQuantity() / peer.getQuantity()), brand);
}

Product Product::operator%(const Product& peer) const {
    return Product("%", (getQuantity() % peer.getQuantity()), brand);
}

Item Product::copy() {
    Product fresh(getName(), getQuantity(), brand);
    return fresh;
}

void Product::clear() {
    Item::clear();
    brand.clear();
    return;
}

std::string Product::print() {
    std::stringstream result;
    result << Item::print() << ",";
    result << brand.print();
	return result.str();
}

} // namespace act