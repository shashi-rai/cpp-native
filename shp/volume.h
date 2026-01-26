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

#include "area.h"

namespace shp {

class Volume {
    Area surface;
    Signal depth;
public:
    // Constructors
    Volume();
    Volume(const std::string unit);
    Volume(const Unit& unit);
    Volume(const short int scaling, const std::string unit);
    Volume(const short int scaling, const Unit& unit);
    Volume(const Area& surface);
    Volume(const Area& surface, const std::string unit);
    Volume(const Area& surface, const Unit& unit);
    Volume(const Area& surface, const short int scaling, const std::string unit);
    Volume(const Area& surface, const short int scaling, const Unit& unit);
    Volume(const Area& surface, const float depth);
    Volume(const Area& surface, const float depth, const std::string unit);
    Volume(const Area& surface, const float depth, const Unit& unit);
    Volume(const Area& surface, const float depth, const short int scaling, const std::string unit);
    Volume(const Area& surface, const float depth, const short int scaling, const Unit& unit);
    Volume(const Area& surface, const Signal& depth);
    Volume(const float length);
    Volume(const float length, const std::string unit);
    Volume(const float length, const Unit& unit);
    Volume(const float length, const short int scaling, const std::string unit);
    Volume(const float length, const short int scaling, const Unit& unit);
    Volume(const float length, const float breadth);
    Volume(const float length, const float breadth, const std::string unit);
    Volume(const float length, const float breadth, const Unit& unit);
    Volume(const float length, const float breadth, const short int scaling, const std::string unit);
    Volume(const float length, const float breadth, const short int scaling, const Unit& unit);
    Volume(const float length, const float breadth, const float height);
    Volume(const float length, const float breadth, const float height, const std::string unit);
    Volume(const float length, const float breadth, const float height, const Unit& unit);
    Volume(const float length, const float breadth, const float height, const short int scaling);
    Volume(const float length, const float breadth, const float height, const short int scaling, const std::string unit);
    Volume(const float length, const float breadth, const float height, const short int scaling, const Unit& unit);
    Volume(const Signal& length);
    Volume(const Signal& length, const Signal& breadth);
    Volume(const Signal& length, const Signal& breadth, const Signal& height);

    // Destructors
    ~Volume();

    // Operator overloading
    bool operator==(const Volume& peer) const;
    bool operator<(const Volume& peer) const;
    bool operator>(const Volume& peer) const;
    bool operator<=(const Volume& peer) const;
    bool operator>=(const Volume& peer) const;
    Volume operator+(const Volume& peer) const;
    Volume operator-(const Volume& peer) const;
    Volume operator*(const Volume& peer) const;
    Volume operator/(const Volume& peer) const;
    Volume operator%(const Volume& peer) const;

    // Surface operator
    Volume operator+(const Area& peer) const;
    Volume operator-(const Area& peer) const;
    Volume operator*(const Area& peer) const;
    Volume operator/(const Area& peer) const;
    Volume operator%(const Area& peer) const;

    // Depth operator
    Volume operator+(const Signal& peer) const;
    Volume operator-(const Signal& peer) const;
    Volume operator*(const Signal& peer) const;
    Volume operator/(const Signal& peer) const;
    Volume operator%(const Signal& peer) const;

    // Getters
    Area getSurface() const { return surface; }
    Signal getDepth() const { return depth; }

    // Setters
    void setSurface(const Area& area) { this->surface = area; }
    void setDepth(const Quantity& depth) { this->depth = depth; }

    // Additional methods
    Signal getScalarTotal() const;
    Signal getScalarSurfaceTotal() const;
    Signal getVectorTotal() const;
    Signal getVectorSurfaceTotal() const;
    Signal getLengthRotation(const short int degree) const;
    Direction getLengthPhase() const;
    void setLengthPhase(const float direction);
    void setLengthPhase(const Direction& direction);
    void setLength(const float value);
    void setLength(const float value, const short int scale);
    void setLength(const float value, const short int scale, const std::string unit);
    void setLength(const float value, const short int scale, const Unit& unit);
    Signal getBreadthRotation(const short int degree) const;
    Direction getBreadthPhase() const;
    void setBreadthPhase(const float direction);
    void setBreadthPhase(const Direction& direction);
    void setBreadth(const float value);
    void setBreadth(const float value, const short int scale);
    void setBreadth(const float value, const short int scale, const std::string unit);
    void setBreadth(const float value, const short int scale, const Unit& unit);
    Signal getHeight() const;
    void setHeight(const Signal& height);
    Signal getHeightRotation(const short int degree) const;
    Direction getHeightPhase() const;
    void setHeightPhase(const float direction);
    void setHeightPhase(const Direction& direction);
    void setHeight(const float value);
    void setHeight(const float value, const short int scale);
    void setHeight(const float value, const short int scale, const std::string unit);
    void setHeight(const float value, const short int scale, const Unit& unit);
    short int getLengthScaling() const;
    void setLengthScaling(const short int factor);
    short int getBreadthScaling() const;
    void setBreadthScaling(const short int factor);
    short int getHeightScaling() const;
    void setHeightScaling(const short int factor);
    std::string getLengthUnit() const;
    void setLengthUnit(const Unit& object);
    std::string getBreadthUnit() const;
    void setBreadthUnit(const Unit& object);
    std::string getHeightUnit() const;
    void setHeightUnit(const Unit& object);
    virtual Volume copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    Signal getCosComponent(const float phase) const;
    Signal getSinComponent(const float phase) const;
public:
    static const std::string UNIT;
    static const short int SCALING_FACTOR;
};

typedef std::vector<Volume > VolumeArray;

} // namespace shp

#endif //SHP_VOLUME_H