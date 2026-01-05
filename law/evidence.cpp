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

#include "evidence.h"

namespace law {

Evidence::Evidence()
        : name(), documents() {

}

Evidence::Evidence(const doc::DocumentArray& documents)
        : name(), documents(documents) {

}

Evidence::Evidence(std::string name)
        : name(name), documents() {

}

Evidence::Evidence(std::string name, const doc::DocumentArray& documents)
        : name(name), documents(documents) {

}

Evidence::~Evidence() {

}

bool Evidence::operator==(const Evidence& peer) const {
    return (name == peer.name) && (documents == peer.documents);
}

Evidence Evidence::operator+(const Evidence& peer) const {
    doc::DocumentArray result(documents);
    result.insert(result.end(), peer.documents.begin(), peer.documents.end());
    return Evidence("+", result);
}

Evidence Evidence::operator-(const Evidence& peer) const {
    doc::DocumentArray result(documents);
    for (doc::DocumentArray::const_iterator it = peer.documents.begin(); it != peer.documents.end(); ++it) {
        doc::DocumentArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Evidence("-", result);
}

int Evidence::getDocumentCount() const {
    return documents.size();
}

doc::Document Evidence::get(const int index) const {
    doc::Document result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(documents.size())) {
        return result;
    }
    return documents[index];
}

void Evidence::set(const int index, const doc::Document& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(documents.size())) {
        // replace existing element
        documents[index] = object;
    } else if (index == static_cast<int>(documents.size())) {
        // append at end
        documents.push_back(object);
    } else {
        // index beyond current size: append at end
        documents.push_back(object);
    }
    return;
}

Evidence Evidence::copy() {
    Evidence fresh(getName(), documents);
    return fresh;
}

void Evidence::clear() {
    name.clear();
    documents.clear();
    return;
}

std::string Evidence::print() {
    std::stringstream result;
    result << "e:";
	result << name << ",sz:";
	result << documents.size() << "[";
    for (int i = 0; i < documents.size(); i++) {
        result << "," << documents[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace law