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

class Volume : private Quantity {
    Area surface;
    Distance depth;
public:
    // Constructors
    Volume();
    Volume(const std::string unit);
    Volume(const Unit& unit);
    Volume(const float magnitude);
    Volume(const float magnitude, const std::string unit);
    Volume(const float magnitude, const Unit& unit);
    Volume(const float magnitude, const short int scaling);
    Volume(const float magnitude, const short int scaling, const std::string unit);
    Volume(const float magnitude, const short int scaling, const Unit& unit);
    Volume(const Area& surface);
    Volume(const std::string unit, const Area& surface);
    Volume(const Unit& unit, const Area& surface);
    Volume(const float magnitude, const Area& surface);
    Volume(const float magnitude, const std::string unit, const Area& surface);
    Volume(const float magnitude, const Unit& unit, const Area& surface);
    Volume(const float magnitude, const short int scaling, const Area& surface);
    Volume(const float magnitude, const short int scaling, const std::string unit, const Area& surface);
    Volume(const float magnitude, const short int scaling, const Unit& unit, const Area& surface);
    Volume(const Distance& depth);
    Volume(const std::string unit, const Distance& depth);
    Volume(const Unit& unit, const Distance& depth);
    Volume(const float magnitude, const Distance& depth);
    Volume(const float magnitude, const std::string unit, const Distance& depth);
    Volume(const float magnitude, const Unit& unit, const Distance& depth);
    Volume(const float magnitude, const short int scaling, const Distance& depth);
    Volume(const float magnitude, const short int scaling, const std::string unit, const Distance& depth);
    Volume(const float magnitude, const short int scaling, const Unit& unit, const Distance& depth);
    Volume(const Area& surface, const Distance& depth);
    Volume(const float magnitude, const short int scaling, const std::string unit,
        const Area& surface, const Distance& depth);
    Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Area& surface, const Distance& depth);
    Volume(const Distance& length, const Distance& breadth);
    Volume(const float magnitude, const short int scaling, const std::string unit,
        const Distance& length, const Distance& breadth);
    Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Distance& length, const Distance& breadth);
    Volume(const Distance& length, const Distance& breadth, const Distance& height);
    Volume(const float magnitude, const short int scaling, const std::string unit,
        const Distance& length, const Distance& breadth, const Distance& height);
    Volume(const float magnitude, const short int scaling, const Unit& unit,
        const Distance& length, const Distance& breadth, const Distance& height);

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
    Volume operator+(const Area& planar) const;
    Volume operator-(const Area& planar) const;
    Volume operator*(const Area& planar) const;
    Volume operator/(const Area& planar) const;
    Volume operator%(const Area& planar) const;

    // Depth operator
    Volume operator+(const Distance& height) const;
    Volume operator-(const Distance& height) const;
    Volume operator*(const Distance& height) const;
    Volume operator/(const Distance& height) const;
    Volume operator%(const Distance& height) const;

    // Getters
    Area getSurface() const { return surface; }
    Distance getDepth() const { return depth; }

    // Setters
    void setSurface(const Area& area) { this->surface = area; }
    void setDepth(const Distance& height) { this->depth = height; }

    // Additional methods
    void setMagnitude(const Signal& signal);
    Signal getScalar() const;
    Signal getSurfaceTension() const;
    Signal getSurfaceCurrent() const;
    Signal getPhaseShift() const;
    Signal getFlux() const;
    Signal getMobility() const;
    Signal getCurvature() const;
    Signal getSurfaceScalar() const;
    Signal getSurfaceRotation() const;
    Signal getSurfaceAligned() const;
    Signal getSurfaceNormal() const;
    Signal getLengthRotation(const short int degree) const;
    Intrinsic getLengthPhase() const;
    void setLengthPhase(const float direction);
    void setLengthPhase(const Intrinsic& intrinsic);
    void setLength(const float value);
    void setLength(const float value, const short int scale);
    void setLength(const float value, const short int scale, const std::string unit);
    void setLength(const float value, const short int scale, const Unit& unit);
    Signal getBreadthRotation(const short int degree) const;
    Intrinsic getBreadthPhase() const;
    void setBreadthPhase(const float direction);
    void setBreadthPhase(const Intrinsic& intrinsic);
    void setBreadth(const float value);
    void setBreadth(const float value, const short int scale);
    void setBreadth(const float value, const short int scale, const std::string unit);
    void setBreadth(const float value, const short int scale, const Unit& unit);
    void setSurface(const Distance& length, const Distance& breadth);
    void setSurface(const float length, const float breadth);
    void setSurface(const float length, const float breadth, const short int scale);
    void setSurface(const float length, const float breadth, const short int scale, const std::string unit);
    void setSurface(const float length, const float breadth, const short int scale, const Unit& unit);
    Distance getHeight() const;
    void setHeight(const Distance& height);
    Signal getHeightRotation(const short int degree) const;
    Intrinsic getHeightPhase() const;
    void setHeightPhase(const float direction);
    void setHeightPhase(const Intrinsic& intrinsic);
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