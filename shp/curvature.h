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

#include "phase.h"

namespace shp {

class Curvature : public Point {
    float polarization;
    PhaseArray deformations;
public:
    // Constructors
    Curvature();
    Curvature(const float polarization);
    Curvature(const Azimuth& azimuthal);
    Curvature(const Polar& polarization);
    Curvature(const float polarization, const float azimuthal);
    Curvature(const Polar& polarization, const Azimuth& azimuthal);
    Curvature(const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal);
    Curvature(const PhaseArray& deformations);
    Curvature(const std::string name);
    Curvature(const std::string name, const float polarization);
    Curvature(const std::string name, const Azimuth& azimuthal);
    Curvature(const std::string name, const Polar& polarization);
    Curvature(const std::string name, const float polarization, const float azimuthal);
    Curvature(const std::string name, const Polar& polarization, const Azimuth& azimuthal);
    Curvature(const std::string name, const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal);
    Curvature(const std::string name, const PhaseArray& deformations);
    Curvature(const std::string name, const PhaseArray& deformations,
        const float polarization);
    Curvature(const std::string name, const PhaseArray& deformations,
        const Azimuth& azimuthal);
    Curvature(const std::string name, const PhaseArray& deformations,
        const Polar& polarization);
    Curvature(const std::string name, const PhaseArray& deformations,
        const float polarization, const float azimuthal);
    Curvature(const std::string name, const PhaseArray& deformations,
        const Polar& polarization, const Azimuth& azimuthal);
    Curvature(const std::string name, const PhaseArray& deformations,
        const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal);

    // Destructors
    ~Curvature();

    // Operator overloading
    bool operator==(const Curvature& peer) const;
    bool operator<(const Curvature& peer) const;
    bool operator>(const Curvature& peer) const;
    bool operator<=(const Curvature& peer) const;
    bool operator>=(const Curvature& peer) const;
    Curvature operator+(const Curvature& peer) const;
    Curvature operator-(const Curvature& peer) const;

    // Access operator
    Phase operator()(int position) { return deformations[position]; }
    const Phase operator()(int position) const { return deformations[position]; }

    // Getters
    float getPolarization() const { return polarization; }
    PhaseArray getDeformations() const { return deformations; }

    // Setters
    void setPolarization(const float value) { this->polarization = value; }
    void setDeformations(const PhaseArray& states) { this->deformations = states; }

    // Additional methods
    int getChangeCount() const;
    Phase get(const int index) const;
    void set(const int index, const Phase& object);
    void setPolarization(const Direction& orientation);
    virtual Angular getOrientation() const;
    virtual Point copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    Quantity getPolarCosComponent(float change) const;
    Quantity getPolarSinComponent(float change) const;
protected:
    std::complex<float> toComplexPolar(float change);
};

typedef std::vector<Curvature > CurvatureArray;

} // namespace shp

#endif //SHP_CURVATURE_H