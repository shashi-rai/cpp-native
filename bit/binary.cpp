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

#include "binary.h"

namespace bit {

const uint8_t Binary::DEFAULT_VALUE = 0;

Binary::Binary() : data() {
    initialize();
}

Binary::Binary(const uint8_t data) : data(data) {
    initialize();
}

Binary::~Binary() {

}

bool Binary::operator==(const Binary& peer) const {
    return (data == peer.data);
}

Binary Binary::operator+(const Binary& peer) const {
    return Binary((data + peer.data));
}

Binary Binary::operator-(const Binary& peer) const {
    return Binary((data - peer.data));
}

Binary Binary::operator*(const Binary& peer) const {
    return Binary((data * peer.data));
}

Binary Binary::operator/(const Binary& peer) const {
    return Binary((data / peer.data));
}

Binary Binary::operator%(const Binary& peer) const {
    return Binary((data % peer.data));
}

Binary Binary::copy() {
    Binary fresh(data);
    return fresh;
}

void Binary::clear() {
    data = DEFAULT_VALUE;
    return;
}

std::string Binary::print() {
    std::stringstream result;
    result << data;
	return result.str();
}

void Binary::initialize() {
    data = DEFAULT_VALUE;
}

} // namespace bit