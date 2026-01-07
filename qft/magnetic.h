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

#ifndef QFT_MAGNETIC_H
#define QFT_MAGNETIC_H

#include <string>
#include <vector>
#include "current.h"
#include "field.h"
#include "force.h"

namespace qft {

class Magnetic : public Force {
    std::shared_ptr<Field> field;
    Current current;
public:
    // Constructors
    Magnetic();
    Magnetic(const Current& current);
    Magnetic(std::string name);
    Magnetic(std::string name, const Current& current);
    Magnetic(const std::shared_ptr<Field> field);
    Magnetic(const Current& current, const std::shared_ptr<Field> field);
    Magnetic(std::string name, const std::shared_ptr<Field> field);
    Magnetic(std::string name, const Current& current, const std::shared_ptr<Field> field);
    Magnetic(const float magnitude);
    Magnetic(const float magnitude, const std::shared_ptr<Field> field);
    Magnetic(const float magnitude, const float direction);
    Magnetic(const float magnitude, const float direction, const std::shared_ptr<Field> field);
    Magnetic(const float magnitude, const float direction, const short int scaling);
    Magnetic(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field);
    Magnetic(std::string name, const float magnitude);
    Magnetic(std::string name, const float magnitude, const std::shared_ptr<Field> field);
    Magnetic(std::string name, const float magnitude, const float direction);
    Magnetic(std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field);
    Magnetic(std::string name, const float magnitude, const float direction,
        const short int scaling);
    Magnetic(std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field);

    // Destructors
    ~Magnetic();

    // Operator overloading
    bool operator==(const Magnetic& peer) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }
    Current getCurrent() const { return current; }

    // Setters
    void setField(const std::shared_ptr<Field> address) { this->field = address; }
    void setCurrent(const Current& electric) { this->current = electric; }

    // Additional methods
    bool isOwned() const;
    virtual Force copy() const;
    virtual void clear();
    virtual std::string print();
public:
    static const Magnetic getForce(const Magnetic& force, const float multiplier);
};

typedef std::vector<Magnetic > MagneticArray;

} // namespace qft

#endif //QFT_MAGNETIC_H