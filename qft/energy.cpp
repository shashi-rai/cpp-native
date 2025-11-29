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

#include "energy.h"

namespace qft {

Energy::Energy() : kinetic(0.0f), potential(0.0f) {

}

Energy::Energy(float kinetic) : kinetic(kinetic), potential(0.0f) {

}

Energy::Energy(float kinetic, float potential)
        : kinetic(kinetic), potential(potential) {

}

Energy::Energy(float kinetic, float potential, const shp::Unit& unit)
        : kinetic(kinetic, unit), potential(potential, unit) {

}

Energy::~Energy() {

}

bool Energy::operator==(const Energy& peer) const {
    return (kinetic == peer.kinetic) && (potential == peer.potential);
}

Energy Energy::operator+(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((kinetic + peer.kinetic).getValue(),
            (potential + peer.potential).getValue(), newunit);
}

Energy Energy::operator-(const Energy& peer) const {
    shp::Unit newunit = kinetic.getUnit();
    return Energy((kinetic - peer.kinetic).getValue(),
            (potential - peer.potential).getValue(), newunit);
}

Energy Energy::copy() {
    Energy fresh(kinetic.getValue(), potential.getValue(), kinetic.getUnit());
    return fresh;
}

void Energy::clear() {
    kinetic.clear();
    potential.clear();
    return;
}

std::string Energy::print() {
    std::stringstream result;
    result << "(k:";
    result << kinetic.print() << ",p:";
    result << potential.print() << ")";
	return result.str();
}

} // namespace qft