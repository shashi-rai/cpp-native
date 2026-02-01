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

#ifndef QFT_THERMAL_H
#define QFT_THERMAL_H

#include "heat.h"
#include "field.h"
#include "force.h"

namespace qft {

class Thermal : public Force {
    std::shared_ptr<Field> field;
    Heat heat;
public:
    // Constructors
    Thermal();
    Thermal(const Heat& heat);
    Thermal(const std::string name);
    Thermal(const std::string name, const Heat& heat);
    Thermal(const std::shared_ptr<Field> field);
    Thermal(const Heat& heat, const std::shared_ptr<Field> field);
    Thermal(const std::string name, const std::shared_ptr<Field> field);
    Thermal(const std::string name, const Heat& heat, const std::shared_ptr<Field> field);
    Thermal(const float magnitude);
    Thermal(const float magnitude, const std::shared_ptr<Field> field);
    Thermal(const float magnitude, const float direction);
    Thermal(const float magnitude, const float direction, const std::shared_ptr<Field> field);
    Thermal(const float magnitude, const float direction, const short int scaling);
    Thermal(const float magnitude, const float direction, const short int scaling,
        const std::shared_ptr<Field> field);
    Thermal(const std::string name, const float magnitude);
    Thermal(const std::string name, const float magnitude, const std::shared_ptr<Field> field);
    Thermal(const std::string name, const float magnitude, const float direction);
    Thermal(const std::string name, const float magnitude, const float direction,
        const std::shared_ptr<Field> field);
    Thermal(const std::string name, const float magnitude, const float direction,
        const short int scaling);
    Thermal(const std::string name, const float magnitude, const float direction,
        const short int scaling, const std::shared_ptr<Field> field);

    // Destructors
    ~Thermal();

    // Operator overloading
    bool operator==(const Thermal& peer) const;

    // Getters
    std::shared_ptr<Field> getField() const { return field; }
    Heat getHeat() const { return heat; }

    // Setters
    void setField(const std::shared_ptr<Field> address) { this->field = address; }
    void setHeat(const Heat& thermal) { this->heat = thermal; }

    // Additional methods
    bool isOwned() const;
    virtual Force copy() const;
    virtual void clear();
    virtual std::string print();
public:
    static const Thermal getForce(const Thermal& force, const float multiplier);
};

typedef std::vector<Thermal > ThermalArray;

} // namespace qft

#endif //QFT_THERMAL_H