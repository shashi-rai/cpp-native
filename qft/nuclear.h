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

#ifndef QFT_NUCLEAR_H
#define QFT_NUCLEAR_H

#include <string>
#include <vector>
#include "field.h"
#include "force.h"

namespace qft {

class Nuclear : public Force {
    std::shared_ptr<Field> field;
public:
    // Constructors
    Nuclear();
    Nuclear(std::string name);
    Nuclear(const std::shared_ptr<Field> field);
    Nuclear(std::string name, const std::shared_ptr<Field> field);
    Nuclear(const float magnitude);
    Nuclear(const float magnitude, const std::shared_ptr<Field> field);
    Nuclear(const float magnitude, const float direction);
    Nuclear(const float magnitude, const float direction, const std::shared_ptr<Field> field);
    Nuclear(const float magnitude, const float direction, const short int scaling);
    Nuclear(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field);
    Nuclear(std::string name, const float magnitude);
    Nuclear(std::string name, const float magnitude, const std::shared_ptr<Field> field);
    Nuclear(std::string name, const float magnitude, const float direction);
    Nuclear(std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field);
    Nuclear(std::string name, const float magnitude, const float direction,
        const short int scaling);
    Nuclear(std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field);

    // Destructors
    ~Nuclear();

    // Operator overloading
    bool operator==(const Nuclear& peer) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }

    // Setters
    void setField(const std::shared_ptr<Field> address) { this->field = address; }

    // Additional methods
    bool isOwned() const;
    virtual Force copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Nuclear > NuclearArray;

} // namespace qft

#endif //QFT_NUCLEAR_H