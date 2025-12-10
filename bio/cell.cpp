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

#include "cell.h"

namespace bio {

Cell::Cell() : Shape(), membranes() {

}

Cell::Cell(std::string name) : Shape(name), membranes() {

}

Cell::Cell(MembraneArray& objects) : Shape(), membranes(objects) {

}

Cell::Cell(std::string name, MembraneArray& objects) : Shape(name), membranes(objects) {

}

Cell::~Cell() {

}

bool Cell::operator==(const Cell& peer) const {
    return (membranes == peer.membranes);
}

Cell Cell::operator+(const Cell& peer) const {
    MembraneArray result(membranes);
    result.insert(result.end(), peer.membranes.begin(), peer.membranes.end());
    return Cell("+", result);
}

Cell Cell::operator-(const Cell& peer) const {
    MembraneArray result(membranes);
    for (MembraneArray::const_iterator it = peer.membranes.begin(); it != peer.membranes.end(); ++it) {
        MembraneArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Cell("-", result);
}

int Cell::getMembraneCount() const {
    return membranes.size();
}

Membrane Cell::get(int index) const {
    Membrane result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(membranes.size())) {
        return result;
    }
    return membranes[index];
}

void Cell::set(int index, const Membrane& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(membranes.size())) {
        // replace existing element
        membranes[index] = object;
    } else if (index == static_cast<int>(membranes.size())) {
        // append at end
        membranes.push_back(object);
    } else {
        // index beyond current size: append at end
        membranes.push_back(object);
    }
    return;
}

Cell Cell::copy() {
    Cell fresh(this->getName(), this->membranes);
    return fresh;
}

void Cell::clear() {
    Shape::clear();
    membranes.clear();
    return;
}

std::string Cell::print() {
    std::stringstream result;
    result << "{ce";
	result << Shape::print() << ",sz:";
	result << membranes.size() << "}";
	return result.str();
}

} // namespace bio
