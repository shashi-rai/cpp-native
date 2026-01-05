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

#include "report.h"

namespace act {

Report::Report() : doc::Document(), owner() {

}

Report::Report(std::string name)
        : doc::Document(name), owner() {

}

Report::Report(const Staff& owner)
        : doc::Document(), owner(owner) {

}

Report::Report(std::string name, const Staff& owner)
        : doc::Document(name), owner(owner) {

}

Report::~Report() {

}

bool Report::operator==(const Report& peer) const {
    return (static_cast<const doc::Document&>(*this) == static_cast<const doc::Document&>(peer))
        && (owner == peer.owner);
}

doc::Document Report::copy() {
    Report fresh(getName(), owner);
    return fresh;
}

void Report::clear() {
    doc::Document::clear();
    owner.clear();
    return;
}

std::string Report::print() {
    std::stringstream result;
    result << "{";
    result << doc::Document::print() << ",O:";
    result << owner.print() << "}";
	return result.str();
}

} // namespace act