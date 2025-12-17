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

#ifndef QFT_ACTION_H
#define QFT_ACTION_H

#include <string>
#include <vector>
#include "../shp/change.h"
#include "../shp/coordinate.h"
#include "../shp/wave.h"

namespace qft {

class Action : public shp::Change {
    std::string name;
    shp::Coordinate coordinate;
    shp::Wave wave;
public:
    // Constructors
    Action();
    Action(std::string name);
    Action(const shp::Coordinate& location);
    Action(const shp::Coordinate& location, shp::Wave& wave);
    Action(const shp::Quantity& potential);
    Action(const shp::Quantity& kinetic, const shp::Quantity& potential);
    Action(std::string name, const shp::Quantity& potential);
    Action(std::string name, const shp::Quantity& kinetic, const shp::Quantity& potential);
    Action(std::string name, const shp::Quantity& kinetic, const shp::Quantity& potential, const shp::Coordinate& location);
    Action(std::string name, const shp::Quantity& kinetic, const shp::Quantity& potential, const shp::Coordinate& location, const shp::Wave& wave);
    Action(std::string name, const shp::Coordinate& location);
    Action(std::string name, const shp::Coordinate& location, const shp::Wave& wave);

    // Destructors
    ~Action();

    // Operator overloading
    bool operator==(const Action& peer) const;
    Action operator+(const Action& peer) const;
    Action operator-(const Action& peer) const;

    // Getters
    std::string getName() const { return name; }
    shp::Coordinate getCoordinate() const { return coordinate; }
    shp::Wave getWave() const { return wave; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCoordinate(const shp::Coordinate& location) { this->coordinate = location; }
    void setWave(const shp::Wave& pulse) { this->wave = pulse; }

    // Additional methods
    shp::Quantity getTotal() const;
    virtual shp::Change copy();
    virtual void clear();
    virtual std::string print();
    shp::Quantity getComponent(float phase) const;
};

typedef std::vector<Action > ActionArray;

} // namespace qft

#endif //QFT_ACTION_H