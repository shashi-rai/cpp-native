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

#ifndef SHP_CELLULAR_H
#define SHP_CELLULAR_H

#include "shell.h"

namespace shp {

class Cellular : public Point {
    int limit;
    ShellArray shells;
public:
    // Constructors
    Cellular();
    Cellular(const Azimuth& gradient);
    Cellular(const float magnitude);
    Cellular(const float magnitude, const short int scaling);
    Cellular(const float magnitude, const short int scaling, const std::string unit);
    Cellular(const float magnitude, const short int scaling, const Unit& unit);
    Cellular(const float magnitude, const Azimuth& gradient);
    Cellular(const float magnitude, const short int scaling, const Azimuth& gradient);
    Cellular(const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Cellular(const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);
    Cellular(const std::string name);
    Cellular(const std::string name, const Azimuth& gradient);
    Cellular(const std::string name, const float magnitude);
    Cellular(const std::string name, const float magnitude, const short int scaling);
    Cellular(const std::string name, const float magnitude, const short int scaling, const std::string unit);
    Cellular(const std::string name, const float magnitude, const short int scaling, const Unit& unit);
    Cellular(const std::string name, const float magnitude, const Azimuth& gradient);
    Cellular(const std::string name, const float magnitude, const short int scaling, const Azimuth& gradient);
    Cellular(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Azimuth& gradient);
    Cellular(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Azimuth& gradient);
    Cellular(const std::string name, const Azimuth& gradient, const int limit);
    Cellular(const std::string name, const ShellArray& waves);
    Cellular(const std::string name, const ShellArray& waves, const float gradient);
    Cellular(const std::string name, const ShellArray& waves, const Azimuth& gradient);
    Cellular(const std::string name, const ShellArray& waves, const float gradient, const int limit);
    Cellular(const std::string name, const ShellArray& waves, const Azimuth& gradient, const int limit);

    // Destructors
    ~Cellular();

    // Operator overloading
    bool operator==(const Cellular& peer) const;
    bool operator<(const Cellular& peer) const;
    bool operator>(const Cellular& peer) const;
    bool operator<=(const Cellular& peer) const;
    bool operator>=(const Cellular& peer) const;
    Cellular operator+(const Cellular& peer) const;
    Cellular operator-(const Cellular& peer) const;

    // Access operator
    Shell operator()(const int x) { return shells[x]; }
    const Shell operator()(const int x) const { return shells[x]; }
    Polygon operator()(const int x, const int y) { return shells[x](y); }
	const Polygon operator()(const int x, const int y) const { return shells[x](y); }
    Wave operator()(const int x, const int y, const int z) { return shells[x](y)(z); }
	const Wave operator()(const int x, const int y, const int z) const { return shells[x](y)(z); }

    // Getters
    int getLimit() const { return limit; }
    ShellArray getShells() const { return shells; }

    // Setters
    void setLimit(const int value) { this->limit = value; }
    void setShells(const ShellArray& objects) { this->shells = objects; }

    // Additional methods
    int getShellCount() const;
    Shell get(const int index) const;
    void set(const int index, const Shell& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printShells() const;
    virtual std::string printShellRadians() const;
public:
    static const int DEFAULT_LIMIT;
};

typedef std::vector<Cellular > CellularArray;

} // namespace shp

#endif //SHP_CELLULAR_H