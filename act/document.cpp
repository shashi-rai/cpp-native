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

#include "document.h"

namespace act {

Document::Document() : name(), created(), expired() {

}

Document::Document(std::string name)
        : name(name), created(), expired() {

}

Document::Document(const DateTime& expired)
        : name(), created(), expired(expired) {

}

Document::Document(std::string name, const DateTime& expired)
        : name(name), created(), expired(expired) {

}

Document::Document(const DateTime& created, const DateTime& expired)
        : name(), created(created), expired(expired) {

}

Document::Document(std::string name, const DateTime& created, const DateTime& expired)
        : name(name), created(created), expired(expired) {

}

Document::~Document() {

}

bool Document::operator==(const Document& peer) const {
    return (name == peer.name)
        && (created == peer.created)
        && (expired == peer.expired);
}

Document Document::copy() {
    Document fresh(name, created, expired);
    return fresh;
}

void Document::clear() {
    name = "";
    created.clear();
    expired.clear();
    return;
}

std::string Document::print() {
    std::stringstream result;
    result << name << ",";
    result << created.print() << ",";
    result << expired.print();
	return result.str();
}

} // namespace act