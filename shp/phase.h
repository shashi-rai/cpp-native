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

#ifndef SHP_PHASE_H
#define SHP_PHASE_H

#include <chrono>
#include <iomanip>
#include <string>
#include <vector>
#include "point.h"

namespace shp {

class Phase : public Point {
    float polarization;
    std::time_t timestamp;
public:
    // Constructors
    Phase();
    Phase(const float gradient);
    Phase(const float amplitude, const float gradient);
    Phase(const float amplitude, const float polarization, const float azimuthal);
    Phase(std::string name);
    Phase(std::string name, const float gradient);
    Phase(std::string name, const float amplitude, const float gradient);
    Phase(std::string name, const float amplitude, const float polarization, const float azimuthal);
    Phase(std::string name, const std::time_t timestamp);
    Phase(std::string name, const float gradient, const std::time_t timestamp);
    Phase(std::string name, const float amplitude, const float gradient, const std::time_t timestamp);
    Phase(std::string name, const float amplitude, const float polarization, const float azimuthal, const std::time_t timestamp);

    // Destructors
    ~Phase();

    // Operator overloading
    bool operator==(const Phase& peer) const;
    Phase operator+(const Phase& peer) const;
    Phase operator-(const Phase& peer) const;
    Phase operator*(const Phase& peer) const;
    Phase operator/(const Phase& peer) const;
    Phase operator%(const Phase& peer) const;

    // Getters
    float getPolarization() const { return polarization; }
    std::time_t getTimestamp() const { return timestamp; }

    // Setters
    void setPolarization(const float value) { this->polarization = value; }
    void setTimestamp(const std::time_t value) { this->timestamp = value; }

    // Additional methods
    void setPolarization(const Direction& orientation);
    virtual Angular getOrientation() const;
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
    Quantity getAmplitudePolarization(float change) const;
protected:
    std::complex<float> toPolarizationComplex(float change);
public:
    static const std::time_t getSystem();
public:
    static const float DEFAULT_VALUE;
    static const std::time_t DEFAULT_TIME;
};

typedef std::vector<Phase > PhaseArray;

} // namespace shp

#endif //SHP_PHASE_H