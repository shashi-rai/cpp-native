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

#include "nucleus.h"

namespace che {

Nucleus::Nucleus()
        : symbol(""), proton(0), neutron(0), mass(), charge(), energy() {

}

Nucleus::Nucleus(std::string symbol)
        : symbol(symbol), proton(0), neutron(0), mass(), charge(), energy() {

}

Nucleus::Nucleus(short proton)
        : symbol(""), proton(0), neutron(0), mass(), charge(), energy() {

}

Nucleus::Nucleus(std::string symbol, short proton)
        : symbol(symbol), proton(proton), neutron(proton), mass(), charge(), energy() {

}

Nucleus::Nucleus(std::string symbol, short proton, short neutron)
        : symbol(symbol), proton(proton), neutron(neutron), mass(), charge(), energy() {

}

Nucleus::Nucleus(std::string symbol, short proton, short neutron,
        qft::Mass& mass, qft::Charge& charge, qft::Energy& energy)
        : symbol(symbol), proton(proton), neutron(neutron),
        mass(mass), charge(charge), energy(energy) {

}

Nucleus::~Nucleus() {

}

void Nucleus::clear() {
    mass.clear();
	charge.clear();
	energy.clear();
    return;
}

std::string Nucleus::print() {
    std::stringstream result;
	result << symbol << ",p:";
	result << proton << ",n:";
	result << neutron << ",";
	result << mass.print() << ",";
	result << charge.print() << ",";
	result << energy.print();
	return result.str();
}

} // namespace che