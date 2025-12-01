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

#include "period.h"

namespace che {

const int Period::ORBITAL_MAX_LIMIT = 16;

Period::Period() : Shell("", ORBITAL_MAX_LIMIT) {

}

Period::Period(std::string name) : Shell(name, ORBITAL_MAX_LIMIT) {

}

Period::Period(std::string name, int limit) : Shell(name, limit) {

}

Period::Period(std::string name, float gradient, int limit)
    : Shell(name, gradient, limit) {

}

Period::~Period() {

}

Orbital Period::getS() const {
	int mapper[1] = { 0 };
	return this->getOrbital(0);
}

std::vector<Orbital> Period::getP() const {
	int mapper[3] = { 1, 2, 3 };
	std::vector<Orbital> result;
	for (int i = 0; i < 3; i++) {
		result.push_back(this->getOrbital(mapper[i]));
	}
	return result;
}

std::vector<Orbital> Period::getD() const {
	int mapper[5] = { 4, 5, 6, 7, 8 };
	std::vector<Orbital> result;
	for (int i = 0; i < 5; i++) {
		result.push_back(this->getOrbital(mapper[i]));
	}
	return result;
}

std::vector<Orbital> Period::getF() const {
	int mapper[7] = { 9, 10, 11, 12, 13, 14, 15 };
	std::vector<Orbital> result;
	for (int i = 0; i < 7; i++) {
		result.push_back(this->getOrbital(mapper[i]));
	}
	return result;
}

void Period::setS(const std::shared_ptr<che::Orbital> object) {
	setOrbital(0, object);
}

void Period::setP(const std::vector<std::shared_ptr<che::Orbital> >& objects) {
	int mapper[3] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++) {
		setOrbital(mapper[i], objects[i]);
	}
}

void Period::setD(const std::vector<std::shared_ptr<che::Orbital> >& objects) {
	int mapper[5] = { 4, 5, 6, 7, 8 };
	for (int i = 0; i < 5; i++) {
		setOrbital(mapper[i], objects[i]);
	}
}

void Period::setF(const std::vector<std::shared_ptr<che::Orbital> >& objects) {
	int mapper[7] = { 9, 10, 11, 12, 13, 14, 15 };
	for (int i = 0; i < 7; i++) {
		setOrbital(mapper[i], objects[i]);
	}
}

Orbital& Period::getOrbital(int azimuthal) const {
	shp::OrbitalArray orbitals = this->getOrbitals();
	Orbital& result = static_cast<Orbital&>(orbitals[azimuthal]);
	return result;
}

void Period::setOrbital(int azimuthal, const std::shared_ptr<che::Orbital> object) {
	shp::Shell* period = this;
	period->set(azimuthal, *object);
	return;
}

Electron& Period::getElectron(int azimuthal, int magnetic) const {
	shp::OrbitalArray orbitals = this->getOrbitals();
	Electron& result = static_cast<Electron&>(orbitals[azimuthal](magnetic));
	return result;
}

void Period::setElectron(int azimuthal, int magnetic, const std::shared_ptr<che::Electron> object) {
	std::shared_ptr<shp::Polygon> orbital = std::make_shared<shp::Polygon>(Shell::get(azimuthal));
	orbital->set(magnetic, *object);
	return;
}

void Period::clear() {
    Shell::clear();
    return;
}

std::string Period::print() {
    std::stringstream result;
    result << "ρ";
	result << Shell::print();
	return result.str();
}

} // namespace che