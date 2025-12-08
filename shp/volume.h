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
    Quantity height;
public:
    // Constructors
    Volume();
    Volume(const float length, const float breadth, const float height);
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
    Quantity getLength() const { return surface.getLength(); }
    Quantity getBreadth() const { return surface.getBreadth(); }
    Quantity getHeight() const { return height; }

    // Setters
    void setLength(const Quantity& length) { this->surface.setLength(length); }
    void setBreadth(const Quantity& breadth) { this->surface.setBreadth(breadth); }
    void setHeight(const Quantity& height) { this->height = height; }

    // Additional methods
    float getTotal() const;
    virtual Volume copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Volume > VolumeArray;

} // namespace shp

#endif //SHP_VOLUME_H