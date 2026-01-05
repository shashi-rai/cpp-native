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

#ifndef ACT_OFFICE_H
#define ACT_OFFICE_H

#include <sstream>
#include <string>
#include <vector>
#include "branch.h"

namespace act {

class Office : public Branch {
    doc::Document registration;
public:
    // Constructors
    Office();
    Office(std::string name);
    Office(const doc::Document& registration);
    Office(std::string name, const doc::Document& registration);
    Office(const gis::Address& address);
    Office(const doc::Document& registration, const gis::Address& address);
    Office(std::string name, const gis::Address& address);
    Office(std::string name, const doc::Document& registration, const gis::Address& address);

    // Destructors
    ~Office();

    // Operator overloading
    bool operator==(const Office& peer) const;

    // Getters
    doc::Document getRegistration() const { return registration; }

    // Setters
    void setRegistration(const doc::Document& document) { this->registration = document; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Office > OfficeArray;

} // namespace act

#endif //ACT_OFFICE_H