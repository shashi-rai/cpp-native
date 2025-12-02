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

#include "reaction.h"

namespace che {

Reaction::Reaction() : Point(), reactants(), products(), change() {

}

Reaction::Reaction(float gradient) : Point(), reactants(), products(), change() {

}

Reaction::Reaction(float amplitude, float gradient)
		: Point(amplitude, gradient), reactants(), products(), change()  {

}

Reaction::Reaction(std::string name) : Point(name), reactants(), products(), change() {

}

Reaction::Reaction(std::string name, float gradient)
		: Point(name, gradient), reactants(), products(), change() {

}

Reaction::Reaction(std::string name, float amplitude, float gradient)
		: Point(name, amplitude, gradient), reactants(), products(), change() {

}

Reaction::Reaction(std::string name,
		MoleculeArray& reactants, MoleculeArray& products, qft::Energy& change)
        : Point(name), reactants(reactants), products(products), change(change) {

}

Reaction::~Reaction() {

}

void Reaction::clear() {
	Point::clear();
	reactants.clear();
	products.clear();
	change.clear();
    return;
}

std::string Reaction::print() {
    std::stringstream result;
    result << "(R:";
	result << Point::print() << ",h:";
	result << change.print() << ",r:";
	result << reactants.size() << ",p:";
	result << products.size() << ")";
	return result.str();
}

} // namespace che