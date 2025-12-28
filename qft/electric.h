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

#ifndef QFT_ELECTRIC_H
#define QFT_ELECTRIC_H

#include <string>
#include <vector>
#include "field.h"
#include "force.h"

namespace qft {

class Electric : public Force {
    std::shared_ptr<Field> field;
public:
    // Constructors
    Electric();
    Electric(std::string name);
    Electric(const std::shared_ptr<Field> field);
    Electric(std::string name, const std::shared_ptr<Field> field);
    Electric(const float magnitude);
    Electric(const float magnitude, const std::shared_ptr<Field> field);
    Electric(const float magnitude, const float direction);
    Electric(const float magnitude, const float direction, const std::shared_ptr<Field> field);
    Electric(const float magnitude, const float direction, const short int scaling);
    Electric(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field);
    Electric(std::string name, const float magnitude);
    Electric(std::string name, const float magnitude, const std::shared_ptr<Field> field);
    Electric(std::string name, const float magnitude, const float direction);
    Electric(std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field);
    Electric(std::string name, const float magnitude, const float direction,
        const short int scaling);
    Electric(std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field);

    // Destructors
    ~Electric();

    // Operator overloading
    bool operator==(const Electric& peer) const;

    // Access operator
    Electric operator()(const Charge& host, const Charge& peer, const shp::Distance& sepration) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }

    // Setters
    void setField(const std::shared_ptr<Field> value) { this->field = value; }

    // Additional methods
    virtual Acceleration getAcceleration(const Charge& charge) const;
    bool isOwned() const;
    virtual Force copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Electric > ElectricArray;

} // namespace qft

#endif //QFT_ELECTRIC_H