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

#include "action.h"

namespace qft {

Action::Action() : name(""), coordinate(), wave() {

}

Action::Action(std::string name, shp::Coordinate& location, shp::Wave& wave)
        : name(name), coordinate(location), wave(wave) {

}

Action::~Action() {

}

Action Action::copy() {
    Action fresh(name, coordinate, wave);
    return fresh;
}

void Action::clear() {
    coordinate.clear();
    wave.clear();
    name = "";
    return;
}

std::string Action::print() {
    std::stringstream result;
    result << "(";
    result << name << ",";
    result << coordinate.print() << ",";
    result << wave.print() << ")";
	return result.str();
}

} // namespace qft