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

#include "event.h"

namespace phy {

Event::Event() : name(""), location(), timestamp(),
        impulse(), change() {

}

Event::Event(std::string name) : name(name), location(), timestamp(),
        impulse(), change() {

}

Event::Event(std::string name, const Space& location, const qft::Time& timestamp,
        const Momentum& impulse, const qft::Energy& action)
        : name(name), location(location), timestamp(timestamp),
        impulse(impulse), change(action) {

}

Event::~Event() {

}

Event Event::copy() {
    Event fresh(name, location, timestamp, impulse, change);
    return fresh;
}

void Event::clear() {
	name = "";
    location.clear();
    timestamp.clear();
	impulse.clear();
	change.clear();
    return;
}

std::string Event::print() {
    std::stringstream result;
    result << "{e:";
    result << name << ",";
    result << location.print() << ",";
    result << timestamp.print() << ",";
	result << impulse.print() << ",";
    result << change.print() << "}";
	return result.str();
}

} // namespace phy