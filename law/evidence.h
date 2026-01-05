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

#ifndef LAW_EVIDENCE_H
#define LAW_EVIDENCE_H

#include <sstream>
#include <string>
#include <vector>
#include "../doc/document.h"

namespace law {

class Evidence {
    std::string name;
    doc::DocumentArray documents;
public:
    // Constructors
    Evidence();
    Evidence(const doc::DocumentArray& documents);
    Evidence(std::string name);
    Evidence(std::string name, const doc::DocumentArray& documents);

    // Destructors
    ~Evidence();

    // Operator overloading
    bool operator==(const Evidence& peer) const;
    Evidence operator+(const Evidence& peer) const;
    Evidence operator-(const Evidence& peer) const;

    // Access operator
    doc::Document operator()(const int x) { return documents[x]; }
    const doc::Document operator()(const int x) const { return documents[x]; }

    // Getters
    std::string getName() const { return name; }
    doc::DocumentArray getBytes() const { return documents; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setBytes(const doc::DocumentArray& data) { this->documents = data; }

    // Additional methods
    int getDocumentCount() const;
    doc::Document get(const int index) const;
    void set(const int index, const doc::Document& object);
    virtual Evidence copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Evidence > EvidenceArray;

} // namespace law

#endif //LAW_EVIDENCE_H