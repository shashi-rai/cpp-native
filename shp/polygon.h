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

#ifndef SHP_POLYGON_H
#define SHP_POLYGON_H

#include <string>
#include <vector>
#include "point.h"
#include "wave.h"

namespace shp {

class Polygon : public Point {
    int limit;
    WaveArray waves;
public:
    // Constructors
    Polygon();
    Polygon(const float gradient);
    Polygon(std::string name);
    Polygon(std::string name, const int limit);
    Polygon(std::string name, const float gradient);
    Polygon(std::string name, const float gradient, const int limit);
    Polygon(std::string name, const WaveArray& waves);
    Polygon(std::string name, const WaveArray& waves, const float gradient);
    Polygon(std::string name, const WaveArray& waves, const float gradient, const int limit);

    // Destructors
    ~Polygon();

    // Operator overloading
    bool operator==(const Polygon& peer) const;
    Polygon operator+(const Polygon& peer) const;
    Polygon operator-(const Polygon& peer) const;

    // Access operator
    Wave operator()(int x) { return waves[x]; }
    const Wave operator()(int x) const { return waves[x]; }

    // Getters
    int getLimit() const { return limit; }
    WaveArray getWaves() const { return waves; }

    // Setters
    void setLimit(const int value) { this->limit = value; }
    void setWaves(const WaveArray& objects) { this->waves = objects; }

    // Additional methods
    int getWaveCount() const;
    Wave get(int index) const;
    void set(int index, const Wave& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();

public:
    static const int DEFAULT_LIMIT;
};

typedef std::vector<Polygon > OrbitalArray;

} // namespace shp

#endif //SHP_POLYGON_H