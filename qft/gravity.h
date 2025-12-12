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

#ifndef QFT_GRAVITY_H
#define QFT_GRAVITY_H

#include <string>
#include <vector>
#include "field.h"
#include "force.h"

namespace qft {

class Gravity : public Force {
    Field* field;
public:
    // Constructors
    Gravity();
    Gravity(std::string name);
    Gravity(Field* field);
    Gravity(std::string name, Field* field);
    Gravity(const float magnitude);
    Gravity(const float magnitude, Field* field);
    Gravity(const float magnitude, const float direction);
    Gravity(const float magnitude, const float direction, Field* field);
    Gravity(const float magnitude, const float direction, short int scaling);
    Gravity(const float magnitude, const float direction, short int scaling, Field* field);
    Gravity(std::string name, const float magnitude);
    Gravity(std::string name, const float magnitude, Field* field);
    Gravity(std::string name, const float magnitude, const float direction);
    Gravity(std::string name, const float magnitude, const float direction, Field* field);
    Gravity(std::string name, const float magnitude, const float direction, short int scaling);
    Gravity(std::string name, const float magnitude, const float direction, short int scaling, Field* field);

    // Operator overloading
    bool operator==(const Gravity& peer) const;

    // Destructors
    ~Gravity();

    // Getters
    Field getField() const { return field; }

    // Setters
    void setField(Field* value) { this->field = value; }

    // Additional methods
    bool isOwned() const;
    virtual Force copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Gravity > GravityArray;

} // namespace qft

#endif //QFT_GRAVITY_H