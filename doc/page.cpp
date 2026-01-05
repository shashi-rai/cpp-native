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

#include "page.h"

namespace doc {

Page::Page()
        : name(), clauses() {

}

Page::Page(const ClauseArray& clauses)
        : name(), clauses(clauses) {

}

Page::Page(std::string name)
        : name(name), clauses() {

}

Page::Page(std::string name, const ClauseArray& clauses)
        : name(name), clauses(clauses) {

}

Page::~Page() {

}

bool Page::operator==(const Page& peer) const {
    return (name == peer.name) && (clauses == peer.clauses);
}

Page Page::operator+(const Page& peer) const {
    ClauseArray result(clauses);
    result.insert(result.end(), peer.clauses.begin(), peer.clauses.end());
    return Page("+", result);
}

Page Page::operator-(const Page& peer) const {
    ClauseArray result(clauses);
    for (ClauseArray::const_iterator it = peer.clauses.begin(); it != peer.clauses.end(); ++it) {
        ClauseArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Page("-", result);
}

int Page::getClauseCount() const {
    return clauses.size();
}

Clause Page::get(const int index) const {
    Clause result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(clauses.size())) {
        return result;
    }
    return clauses[index];
}

void Page::set(const int index, const Clause& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(clauses.size())) {
        // replace existing element
        clauses[index] = object;
    } else if (index == static_cast<int>(clauses.size())) {
        // append at end
        clauses.push_back(object);
    } else {
        // index beyond current size: append at end
        clauses.push_back(object);
    }
    return;
}

Page Page::copy() {
    Page fresh(getName(), clauses);
    return fresh;
}

void Page::clear() {
    name.clear();
    clauses.clear();
    return;
}

std::string Page::print() {
    std::stringstream result;
    result << "p:";
	result << name << ",sz:";
	result << clauses.size() << "[";
    for (int i = 0; i < clauses.size(); i++) {
        result << "," << clauses[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace doc