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

#ifndef ECO_INDUSTRY_H
#define ECO_INDUSTRY_H

#include <sstream>
#include <string>
#include <vector>
#include "freight.h"
#include "labour.h"
#include "material.h"

namespace eco {

class Industry {
    std::string name;
    Labour labour;
    Material material;
    Freight freight;
public:
    // Constructors
    Industry();
    Industry(const Labour& labour);
    Industry(const Material& material);
    Industry(const Freight& freight);
    Industry(const Labour& labour, const Material& material);
    Industry(const Labour& labour, const Freight& freight);
    Industry(const Material& material, const Freight& freight);
    Industry(const Labour& labour, const Material& material, const Freight& freight);
    Industry(std::string name);
    Industry(std::string name, const Labour& labour);
    Industry(std::string name, const Material& material);
    Industry(std::string name, const Freight& freight);
    Industry(std::string name, const Labour& labour, const Material& material);
    Industry(std::string name, const Labour& labour, const Freight& freight);
    Industry(std::string name, const Material& material, const Freight& freight);
    Industry(std::string name, const Labour& labour, const Material& material, const Freight& freight);

    // Destructors
    ~Industry();

    // Operator overloading
    bool operator==(const Industry& peer) const;

    // Getters
    std::string getName() const { return name; }
    Labour getLabour() const { return labour; }
    Material getMaterial() const { return material; }
    Freight getFreight() const { return freight; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setLabour(const Labour& object) { this->labour = object; }
    void setMaterial(const Material& object) { this->material = object; }
    void setFreight(const Freight& object) { this->freight = object; }

    // Additional methods
    virtual Industry copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Industry > IndustryArray;

} // namespace eco

#endif //ECO_INDUSTRY_H