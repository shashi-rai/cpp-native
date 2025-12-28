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

#ifndef SHP_CURVATURE_H
#define SHP_CURVATURE_H

#include <string>
#include <vector>
#include "phase.h"
#include "point.h"

namespace shp {

class Curvature : public Point {
    float polarization;
    PhaseArray deforms;
public:
    // Constructors
    Curvature();
    Curvature(const float polarization);
    Curvature(const float polarization, const float azimuthal);
    Curvature(std::string name);
    Curvature(std::string name, const float polarization);
    Curvature(std::string name, const float polarization, const float azimuthal);
    Curvature(std::string name, const PhaseArray& deforms);
    Curvature(std::string name, const PhaseArray& deforms, const float polarization);
    Curvature(std::string name, const PhaseArray& deforms, const float polarization, const float azimuthal);

    // Destructors
    ~Curvature();

    // Operator overloading
    bool operator==(const Curvature& peer) const;
    Curvature operator+(const Curvature& peer) const;
    Curvature operator-(const Curvature& peer) const;

    // Access operator
    Phase operator()(int position) { return deforms[position]; }
    const Phase operator()(int position) const { return deforms[position]; }

    // Getters
    float getPolarization() const { return polarization; }
    PhaseArray getDeforms() const { return deforms; }

    // Setters
    void setPolarization(float value) { this->polarization = value; }
    void setDeforms(const PhaseArray& states) { this->deforms = states; }

    // Additional methods
    int getChangeCount() const;
    Phase get(int index) const;
    void set(int index, const Phase& object);
    virtual Angular getOrientation() const;
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
    float getAmplitudePolarization(float change) const;
protected:
    std::complex<float> toPolarizationComplex(float change);
};

typedef std::vector<Curvature > CurvatureArray;

} // namespace shp

#endif //SHP_CURVATURE_H