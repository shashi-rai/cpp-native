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

#include "bond.h"

namespace che {

Bond::Bond() : Point(), left(), right(), energy(), length(), angle() {

}

Bond::Bond(float gradient) : Point(), left(), right(),
        energy(), length(), angle() {

}

Bond::Bond(float amplitude, float gradient) : Point(amplitude, gradient),
		left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::string name) : Point(name), left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::string name, float gradient)
		: Point(name, gradient), left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::string name, float amplitude, float gradient)
		: Point(name, amplitude, gradient), left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right)
        : Point(), left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy)
        : Point(), left(left), right(right),
        energy(energy), length(), angle() {

}

Bond::Bond(std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy, shp::Distance length)
        : Point(), left(left), right(right),
        energy(energy), length(length), angle() {

}

Bond::Bond(std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy, shp::Distance length, shp::Angular angle)
        : Point(), left(left), right(right),
        energy(energy), length(length), angle(angle) {

}

Bond::Bond(std::string name,
		std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right)
        : Point(name), left(), right(), energy(), length(), angle() {

}

Bond::Bond(std::string name,
		std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy)
        : Point(name), left(left), right(right),
        energy(energy), length(), angle() {

}

Bond::Bond(std::string name,
		std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy, shp::Distance length)
        : Point(name), left(left), right(right),
        energy(energy), length(length), angle() {

}

Bond::Bond(std::string name,
		std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy, shp::Angular angle)
        : Point(name), left(left), right(right),
        energy(energy), length(), angle(angle) {

}

Bond::Bond(std::string name,
		std::shared_ptr<che::Orbital> left, std::shared_ptr<che::Orbital> right,
        qft::Energy& energy, shp::Distance length, shp::Angular angle)
        : Point(name), left(left), right(right),
        energy(energy), length(length), angle(angle) {

}

Bond::~Bond() {

}

shp::Point Bond::copy() {
    Bond fresh(getName(), left, right, energy, length, angle);
    return fresh;
}

void Bond::clear() {
    left->clear();
	right->clear();
	energy.clear();
	length.clear();
	angle.clear();
    return;
}

std::string Bond::print() {
    std::stringstream result;
    result << "(B:";
	result << Point::print() << ",e:";
	result << energy.print() << ",l:";
	result << length.print() << ",a:";
	result << angle.print() << ",L:";
	result << left->print() << ",R:";
	result << right->print() << ")";
	return result.str();
}

} // namespace che