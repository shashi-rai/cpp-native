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

#ifndef CHE_BOND_H
#define CHE_BOND_H

#include <string>
#include <vector>
#include "atom.h"
#include "electron.h"
#include "../qft/energy.h"
#include "../shp/angular.h"
#include "../shp/point.h"
#include "../shp/quantity.h"

namespace che {

class Bond : public shp::Point {
    std::shared_ptr<che::Orbital> left;
    std::shared_ptr<che::Orbital> right;
    qft::Energy energy;
    shp::Quantity length;
    shp::Angular angle;
public:
    // Constructors
    Bond();
    Bond(float gradient);
    Bond(float amplitude, float gradient);
    Bond(std::string name);
    Bond(std::string name, float gradient);
    Bond(std::string name, float amplitude, float gradient);
    Bond(std::string name, const std::shared_ptr<che::Orbital> left,
        const std::shared_ptr<che::Orbital> right);
    Bond(std::string name, const std::shared_ptr<che::Orbital> left,
        const std::shared_ptr<che::Orbital> right, qft::Energy& energy,
        shp::Quantity length, shp::Angular angle);

    // Destructors
    ~Bond();

    // Getters
    std::shared_ptr<che::Orbital> getLeft() const { return left; }
    std::shared_ptr<che::Orbital> getRight() const { return right; }
    qft::Energy getEnergy() const { return energy; }
    shp::Quantity getLength() const { return length; }
    shp::Angular getAngle() const { return angle; }

    // Setters
    void setLeft(const std::shared_ptr<che::Orbital> orbital) { this->left = orbital; }
    void setRight(const std::shared_ptr<che::Orbital>orbital) { this->right = orbital; }
    void setEnergy(const qft::Energy& value) { this->energy = value; }
    void setLength(shp::Quantity value) { this->length = value; }
    void setAngle(shp::Angular value) { this->angle = value; }

    // Additional methods
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Bond > BondArray;

} // namespace che

#endif //CHE_BOND_H