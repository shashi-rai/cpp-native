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

#include "vehicle.h"

namespace act {

Vehicle::Vehicle() : Asset(), number() {

}

Vehicle::Vehicle(std::string number)
        : Asset(), number(number) {

}

Vehicle::~Vehicle() {

}

bool Vehicle::operator==(const Vehicle& peer) const {
    return (static_cast<const Asset&>(*this) == static_cast<const Asset&>(peer))
        && (number == peer.number);
}

Asset Vehicle::copy() {
    Vehicle fresh(number);
    return fresh;
}

void Vehicle::clear() {
    Asset::clear();
    number = "";
    return;
}

std::string Vehicle::print() {
    std::stringstream result;
    result << Asset::print() << ",";
    result << number;
	return result.str();
}

} // namespace act