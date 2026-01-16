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

namespace shp {

class Volume {
    Area surface;
    Signal depth;
public:
    // Constructors
    Volume();
    Volume(const std::string unit);
    Volume(const Area& surface);
    Volume(const Area& surface, const std::string unit);
    Volume(const Area& surface, const short int scaling, const std::string unit);
    Volume(const Area& surface, const float depth);
    Volume(const Area& surface, const float depth, const std::string unit);
    Volume(const Area& surface, const float depth, const short int scaling, const std::string unit);
    Volume(const Area& surface, const Signal& depth);
    Volume(const float length);
    Volume(const float length, const std::string unit);
    Volume(const float length, const short int scaling, const std::string unit);
    Volume(const float length, const float breadth);
    Volume(const float length, const float breadth, const std::string unit);
    Volume(const float length, const float breadth, const short int scaling, const std::string unit);
    Volume(const float length, const float breadth, const float height);
    Volume(const float length, const float breadth, const float height, const std::string unit);
    Volume(const float length, const float breadth, const float height, const short int scaling);
    Volume(const float length, const float breadth, const float height, const short int scaling, const std::string unit);
    Volume(const Signal& length);
    Volume(const Signal& length, const Signal& breadth);
    Volume(const Signal& length, const Signal& breadth, const Signal& height);

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
    Signal getDepth() const { return depth; }
    Signal getLength() const { return surface.getLength(); }
    Signal getBreadth() const { return surface.getBreadth(); }
    Signal getHeight() const { return depth; }

    // Setters
    void setSurface(const Area& area) { this->surface = area; }
    void setDepth(const Quantity& depth) { this->depth = depth; }
    void setLength(const Quantity& length) { this->surface.setLength(length); }
    void setBreadth(const Quantity& breadth) { this->surface.setBreadth(breadth); }
    void setHeight(const Quantity& height) { this->depth = height; }

    // Additional methods
    Signal getTotal() const;
    std::string getUnit() const;
    virtual Volume copy();
    virtual void clear();
    virtual std::string print();
    Signal getComponent(float phase) const;
public:
    static const std::string UNIT;
    static const short int SCALING_FACTOR;
};

typedef std::vector<Volume > VolumeArray;

} // namespace shp

#endif //SHP_VOLUME_H