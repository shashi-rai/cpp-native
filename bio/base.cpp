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

#include "base.h"

namespace bio {

Base::Base()
        : Molecule(), pyrimidine(), imidazole() {

}

Base::Base(const std::string name)
        : Molecule(name), pyrimidine(), imidazole() {

}

Base::Base(const che::Ring& pyrimidine, const che::Ring& imidazole)
    : Molecule(), pyrimidine(pyrimidine), imidazole(imidazole) {

}

Base::Base(const std::string name, const che::Ring& pyrimidine, const che::Ring& imidazole)
    : Molecule(name), pyrimidine(pyrimidine), imidazole(imidazole) {

}

Base::~Base() {

}

bool Base::operator==(const Base& peer) const {
    return (pyrimidine == peer.pyrimidine) && (imidazole == peer.imidazole);
}

Base Base::operator+(const Base& peer) const {
    che::Ring newPyrimidine = (this->pyrimidine + peer.pyrimidine);
    che::Ring newImidazole = (this->imidazole + peer.imidazole);
    return Base("+", newPyrimidine, newImidazole);
}

Base Base::operator-(const Base& peer) const {
    che::Ring newPyrimidine = (this->pyrimidine - peer.pyrimidine);
    che::Ring newImidazole = (this->imidazole - peer.imidazole);
    return Base("-", newPyrimidine, newImidazole);
}

Base Base::copy() {
    Base fresh(Molecule::getName(), this->pyrimidine, this->imidazole);
    return fresh;
}

void Base::clear() {
	Molecule::clear();
	pyrimidine.clear();
    imidazole.clear();
    return;
}

std::string Base::print() const {
    std::stringstream result;
    result << "(";
	result << Molecule::print() << ",";
	result << pyrimidine.print() << ",";
    result << imidazole.print();
    result << ")";
	return result.str();
}

} // namespace bio