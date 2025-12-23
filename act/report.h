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

#ifndef ACT_REPORT_H
#define ACT_REPORT_H

#include <sstream>
#include <string>
#include <vector>
#include "document.h"
#include "staff.h"

namespace act {

class Report : public Document {
    Staff owner;
public:
    // Constructors
    Report();
    Report(std::string name);
    Report(const Staff& owner);
    Report(std::string name, const Staff& owner);

    // Destructors
    ~Report();

    // Operator overloading
    bool operator==(const Report& peer) const;

    // Getters
    Staff getOwner() const { return owner; }

    // Setters
    void setOwner(const Staff& issuer) { this->owner = issuer; }

    // Additional methods
    virtual Document copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Report > ReportArray;

} // namespace act

#endif //ACT_REPORT_H