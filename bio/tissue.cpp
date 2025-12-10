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

#include "tissue.h"

namespace bio {

Tissue::Tissue() : Shape() {

}

Tissue::Tissue(std::string name) : Shape(name) {

}

Tissue::Tissue(std::string name, CellArray& objects) : cells(objects) {

}

Tissue::~Tissue() {

}

bool Tissue::operator==(const Tissue& peer) const {
    return (cells == peer.cells);
}

Tissue Tissue::operator+(const Tissue& peer) const {
    CellArray result(cells);
    result.insert(result.end(), peer.cells.begin(), peer.cells.end());
    return Tissue("+", result);
}

Tissue Tissue::operator-(const Tissue& peer) const {
    CellArray result(cells);
    for (CellArray::const_iterator it = peer.cells.begin(); it != peer.cells.end(); ++it) {
        CellArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Tissue("-", result);
}

int Tissue::getCellCount() const {
    return cells.size();
}

Cell Tissue::get(int index) const {
    Cell result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(cells.size())) {
        return result;
    }
    return cells[index];
}

void Tissue::set(int index, const Cell& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(cells.size())) {
        // replace existing element
        cells[index] = object;
    } else if (index == static_cast<int>(cells.size())) {
        // append at end
        cells.push_back(object);
    } else {
        // index beyond current size: append at end
        cells.push_back(object);
    }
    return;
}

Tissue Tissue::copy() {
    Tissue fresh(this->getName(), this->cells);
    return fresh;
}

void Tissue::clear() {
    Shape::clear();
    cells.clear();
    return;
}

std::string Tissue::print() {
    std::stringstream result;
    result << "{ts:";
	result << Shape::print() << ",sz:";
	result << cells.size() << "}";
	return result.str();
}

} // namespace bio
