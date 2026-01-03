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

#ifndef ECO_MATERIAL_H
#define ECO_MATERIAL_H

#include <sstream>
#include <string>
#include <vector>
#include "market.h"

namespace eco {

class Material : public Market {

public:
    // Constructors
    Material();
    Material(const Demand& demand);
    Material(const Supply& supply);
    Material(const Population& population);
    Material(const Demand& demand, const Supply& supply);
    Material(const Demand& demand, const Population& population);
    Material(const Supply& supply, const Population& population);
    Material(const Demand& demand, const Supply& supply, const Population& population);
    Material(std::string name);
    Material(std::string name, const Demand& demand);
    Material(std::string name, const Supply& supply);
    Material(std::string name, const Population& population);
    Material(std::string name, const Demand& demand, const Supply& supply);
    Material(std::string name, const Demand& demand, const Population& population);
    Material(std::string name, const Supply& supply, const Population& population);
    Material(std::string name, const Demand& demand, const Supply& supply, const Population& population);

    // Destructors
    ~Material();

    // Operator overloading
    bool operator==(const Material& peer) const;

    // Getters

    // Setters

    // Additional methods
    virtual Market copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Material > MaterialArray;

} // namespace eco

#endif //ECO_MATERIAL_H