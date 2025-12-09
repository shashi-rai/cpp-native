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

#ifndef SHP_VOLUME_H
#define SHP_VOLUME_H

#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include "area.h"
#include "quantity.h"

namespace shp {

class Volume {
    Area surface;
    Quantity depth;
public:
    // Constructors
    Volume();
    Volume(const Area& surface);
    Volume(const Area& surface, const std::string unit);
    Volume(const Area& surface, short int scaling, const std::string unit);
    Volume(const Area& surface, const float depth);
    Volume(const Area& surface, const float depth, const std::string unit);
    Volume(const Area& surface, const float depth, short int scaling, const std::string unit);
    Volume(const Area& surface, const Quantity& depth);
    Volume(const float length);
    Volume(const float length, const std::string unit);
    Volume(const float length, short int scaling, const std::string unit);
    Volume(const float length, const float breadth);
    Volume(const float length, const float breadth, const std::string unit);
    Volume(const float length, const float breadth, short int scaling, const std::string unit);
    Volume(const float length, const float breadth, const float height);
    Volume(const float length, const float breadth, const float height, const std::string unit);
    Volume(const float length, const float breadth, const float height, short int scaling, const std::string unit);
    Volume(const Quantity& length);
    Volume(const Quantity& length, const Quantity& breadth);
    Volume(const Quantity& length, const Quantity& breadth, const Quantity& height);

    // Destructors
    ~Volume();

    // Operator overloading
    bool operator==(const Volume& peer) const;
    Volume operator+(const Volume& peer) const;
    Volume operator-(const Volume& peer) const;
    Volume operator*(const Volume& peer) const;
    Volume operator/(const Volume& peer) const;
    Volume operator%(const Volume& peer) const;

    // Getters
    Area getSurface() const { return surface; }
    Quantity getDepth() const { return depth; }
    Quantity getLength() const { return surface.getLength(); }
    Quantity getBreadth() const { return surface.getBreadth(); }
    Quantity getHeight() const { return depth; }

    // Setters
    void setSurface(const Area& area) { this->surface = area; }
    void setDepth(const Quantity& depth) { this->depth = depth; }
    void setLength(const Quantity& length) { this->surface.setLength(length); }
    void setBreadth(const Quantity& breadth) { this->surface.setBreadth(breadth); }
    void setHeight(const Quantity& height) { this->depth = height; }

    // Additional methods
    float getTotal() const;
    std::string getUnit() const;
    virtual Volume copy();
    virtual void clear();
    virtual std::string print();
    float getComponent(float phase) const;
public:
    static const std::string UNIT;
};

typedef std::vector<Volume > VolumeArray;

} // namespace shp

#endif //SHP_VOLUME_H