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

#include "judgement.h"

namespace law {

Judgement::Judgement() : Document(), number(), jury(), suit() {

}

Judgement::Judgement(std::string number)
        : Document(), number(), jury(), suit() {

}

Judgement::Judgement(const Case& suit)
        : Document(), number(), jury(), suit(suit) {

}

Judgement::Judgement(std::string number, const Case& suit)
        : Document(), number(number), jury(), suit(suit) {

}

Judgement::Judgement(const Authority& jury, const Case& suit)
        : Document(), number(), jury(jury), suit(suit) {

}

Judgement::Judgement(std::string number, const Authority& jury, const Case& suit)
        : Document(), number(number), jury(jury), suit(suit) {

}

Judgement::~Judgement() {

}

bool Judgement::operator==(const Judgement& peer) const {
    return (static_cast<const doc::Document&>(*this) == static_cast<const doc::Document&>(peer))
	    && (number == peer.number)
        && (jury == peer.jury)
        && (suit == peer.suit);
}

doc::Document Judgement::copy() {
    Judgement fresh(number, jury, suit);
    return fresh;
}

void Judgement::clear() {
    number.clear();
    jury.clear();
    suit.clear();
    return;
}

std::string Judgement::print() {
    std::stringstream result;
	result << "J(";
    result << number << ",j:";
    result << jury.print() << ",s:";
    result << suit.print() << ")";
	return result.str();
}

} // namespace law