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

#ifndef QFT_REALITY_H
#define QFT_REALITY_H

#include <sstream>
#include <string>
#include <vector>
#include "field.h"

namespace qft {

class Reality {
    std::shared_ptr<qft::Field> gravity;
    std::shared_ptr<qft::Field> gluonic;
    std::shared_ptr<qft::Field> electric;
    std::shared_ptr<qft::Field> magnetic;
public:
    // Constructors
    Reality();
    Reality(const float mass, const float colour, const float charge);

    // Destructors
    ~Reality();

    // Operator overloading
    bool operator==(const Reality& peer) const;

    // Getters
    std::shared_ptr<qft::Field> getGravity() const { return gravity; }
    std::shared_ptr<qft::Field> getGluonic() const { return gluonic; }
    std::shared_ptr<qft::Field> getElectric() const { return electric; }
    std::shared_ptr<qft::Field> getMagnetic() const { return magnetic; }

    // Setters
    void setGravity(const std::shared_ptr<qft::Field> field) { this->gravity = field; }
    void setGluonic(const std::shared_ptr<qft::Field> field) { this->gluonic = field; }
    void setElectric(const std::shared_ptr<qft::Field> field) { this->electric = field; }
    void setMagnetic(const std::shared_ptr<qft::Field> field) { this->magnetic = field; }

    // Additional methods
    virtual Reality copy();
    virtual void clear();
    virtual std::string print();

private:
    void initialize(const float mass, const float colour, const float charge);
public:
    static const float DEFAULT_VALUE;
    static const float DEFAULT_FIELD;
};

typedef std::vector<Reality > RealityArray;

} // namespace qft

#endif //QFT_REALITY_H