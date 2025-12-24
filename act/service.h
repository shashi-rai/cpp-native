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

#ifndef ACT_SERVICE_H
#define ACT_SERVICE_H

#include <sstream>
#include <string>
#include <vector>
#include "brand.h"
#include "item.h"

namespace act {

class Service : public Item {
    Brand brand;
public:
    // Constructors
    Service();
    Service(std::string name);
    Service(const Brand& brand);
    Service(std::string name, const Brand& brand);

    // Destructors
    ~Service();

    // Operator overloading
    bool operator==(const Service& peer) const;

    // Getters
    Brand getBrand() const { return brand; }

    // Setters
    void setBrand(const Brand& object) { this->brand = object; }

    // Additional methods
    virtual Item copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Service > ServiceArray;

} // namespace act

#endif //ACT_SERVICE_H