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

#include "indoor.h"

namespace gis {

Indoor::Indoor()
        : room(), unit(), floor() {

}

Indoor::Indoor(const std::string room)
        : room(room), unit(), floor() {

}

Indoor::Indoor(const std::string room, const std::string unit)
        : room(room), unit(unit), floor() {

}

Indoor::Indoor(const std::string room, const std::string unit, const std::string floor)
        : room(room), unit(unit), floor(floor) {

}

Indoor::~Indoor() {

}

bool Indoor::operator==(const Indoor& peer) const {
    return (room == peer.room)
        && (unit == peer.unit)
        && (floor == peer.floor);
}

Indoor Indoor::copy() {
    Indoor fresh(this->room, this->unit, this->floor);
    return fresh;
}

void Indoor::clear() {
    room.clear();
    unit.clear();
    floor.clear();
    return;
}

std::string Indoor::print() const {
    std::stringstream result;
    result << "(r:";
    result << room << ",u:";
    result << unit << ",flr:";
    result << floor << ")";
	return result.str();
}

} // namespace gis