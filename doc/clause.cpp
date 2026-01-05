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

#include "clause.h"

namespace doc {

Clause::Clause()
        : number(), sentence() {

}

Clause::Clause(std::string number, std::string sentence)
        : number(number), sentence(sentence) {

}

Clause::~Clause() {

}

bool Clause::operator==(const Clause& peer) const {
    return (number == peer.number) && (sentence == peer.sentence);
}

Clause Clause::operator+(const Clause& peer) const {
    return Clause("+", (sentence + peer.sentence));
}

Clause Clause::operator-(const Clause& peer) const {
    return Clause("-", sentence);
}

Clause Clause::copy() {
    Clause fresh(number, sentence);
    return fresh;
}

void Clause::clear() {
    number.clear();
    sentence.clear();
    return;
}

std::string Clause::print() {
    std::stringstream result;
    result << "(";
	result << number << ",";
	result << sentence;
    result << ")";
	return result.str();
}

} // namespace doc