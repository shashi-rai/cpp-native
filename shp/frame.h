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

#ifndef SHP_FRAME_H
#define SHP_FRAME_H

#include "planar.h"

namespace shp {

class Frame : public Point {
    int limit;
    PlanarArray planes;
public:
    // Constructors
    Frame();
    Frame(const Azimuth& gradient);
    Frame(const float magnitude);
    Frame(const float magnitude, const short int scaling);
    Frame(const float magnitude, const short int scaling, const std::string unit);
    Frame(const float magnitude, const short int scaling, const Unit& unit);
    Frame(const float magnitude, const Azimuth& gradient);
    Frame(const float magnitude, const short int scaling, const Azimuth& gradient);
    Frame(const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Frame(const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);
    Frame(const std::string name);
    Frame(const std::string name, const Azimuth& gradient);
    Frame(const std::string name, const float magnitude);
    Frame(const std::string name, const float magnitude, const short int scaling);
    Frame(const std::string name, const float magnitude, const short int scaling, const std::string unit);
    Frame(const std::string name, const float magnitude, const short int scaling, const Unit& unit);
    Frame(const std::string name, const float magnitude, const Azimuth& gradient);
    Frame(const std::string name, const float magnitude, const short int scaling, const Azimuth& gradient);
    Frame(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Frame(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);
    Frame(const std::string name, const Azimuth& gradient, const int limit);
    Frame(const std::string name, const PlanarArray& planes);
    Frame(const std::string name, const PlanarArray& planes, const float gradient);
    Frame(const std::string name, const PlanarArray& planes, const Azimuth& gradient);
    Frame(const std::string name, const PlanarArray& planes, const float gradient, const int limit);
    Frame(const std::string name, const PlanarArray& planes, const Azimuth& gradient, const int limit);

    // Destructors
    ~Frame();

    // Operator overloading
    bool operator==(const Frame& peer) const;
    bool operator<(const Frame& peer) const;
    bool operator>(const Frame& peer) const;
    bool operator<=(const Frame& peer) const;
    bool operator>=(const Frame& peer) const;
    Frame operator+(const Frame& peer) const;
    Frame operator-(const Frame& peer) const;

    // Access operator
    Planar operator()(const int x) { return planes[x]; }
    const Planar operator()(const int x) const { return planes[x]; }
    Linear operator()(const int x, const int y) { return planes[x](y); }
	const Linear operator()(const int x, const int y) const { return planes[x](y); }
    Point operator()(const int x, const int y, const int z) { return planes[x](y)(z); }
	const Point operator()(const int x, const int y, const int z) const { return planes[x](y)(z); }

    // Getters
    int getLimit() const { return limit; }
    PlanarArray getPlanes() const { return planes; }

    // Setters
    void setLimit(const int value) { this->limit = value; }
    void setPlanes(const PlanarArray& objects) { this->planes = objects; }

    // Additional methods
    int getPlaneCount() const;
    Planar get(const int index) const;
    void set(const int index, const Planar& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printPlanes() const;
    virtual std::string printPlaneRadians() const;
public:
    static const int DEFAULT_LIMIT;
};

typedef std::vector<Frame > FrameArray;

} // namespace shp

#endif //SHP_FRAME_H