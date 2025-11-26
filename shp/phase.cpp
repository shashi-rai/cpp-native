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

#include "phase.h"

namespace shp {

Phase::Phase() : Point(), timestamp(0L) {

}

Phase::Phase(std::string name) : Point(name), timestamp(0L) {

}

Phase::Phase(std::string name, long timestamp)
        : Point(name), timestamp(timestamp) {

}

Phase::~Phase() {

}

bool Phase::operator==(const Phase& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (timestamp == peer.timestamp);
}

void Phase::clear() {
    Shape::clear();
	timestamp = 0L;
    return;
}

std::string Phase::print() {
    std::stringstream result;
    result << "[";
	result << Point::print() << ",t:";
    result << timestamp << "]:";
	return result.str();
}

} // namespace shp