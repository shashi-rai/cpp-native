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

#ifndef SHP_WAVE_H
#define SHP_WAVE_H

#include <vector>
#include "curvature.h"

namespace shp {

class Wave : public Curvature {
    long frequency;
    float length;
    CurvatureArray wavelets;
public:
    // Constructors
    Wave();
    Wave(float polarization);
    Wave(float polarization, float azimuthal);
    Wave(std::string name);
    Wave(std::string name, float polarization);
    Wave(std::string name, float polarization, float azimuthal);
    Wave(std::string name, long frequency, float length);
    Wave(std::string name, long frequency, float length, float polarization);
    Wave(std::string name, long frequency, float length, float polarization, float azimuthal);
    Wave(std::string name, long frequency, float length, CurvatureArray& wavelets);
    Wave(std::string name, long frequency, float length, CurvatureArray& wavelets, float polarization);
    Wave(std::string name, long frequency, float length, CurvatureArray& wavelets, float polarization, float azimuthal);

    // Destructors
    ~Wave();

    // Operator overloading
    bool operator==(const Wave& peer) const;
    Wave operator+(const Wave& peer) const;
    Wave operator-(const Wave& peer) const;

    // Access operator
    Curvature& operator()(int index) { return wavelets[index]; }
    const Curvature& operator()(int index) const { return wavelets[index]; }

    // Getters
    long getFrequency() const { return frequency; }
    float getLength() const { return length; }
    CurvatureArray getWavelets() const { return wavelets; }

    // Setters
    void setFrequency(long value) { this->frequency = value; }
    void setLength(float value) { this->length = value; }
    void setWavelets(const CurvatureArray& curves) { this->wavelets = curves; }

    // Additional methods
    int getWaveletCount() const;
    Curvature get(int index) const;
    void set(int index, const Curvature& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Wave > WaveArray;

} // namespace shp

#endif //SHP_WAVE_H