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

#include "curvature.h"

namespace shp {

class Wave : public Curvature {
    int limit;
    CurvatureArray wavelets;
public:
    // Constructors
    Wave();
    Wave(const Intrinsic& azimuthal);
    Wave(const Polar& polarization);
    Wave(const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const float magnitude);
    Wave(const float magnitude, const short int scaling);
    Wave(const float magnitude, const short int scaling, const std::string unit);
    Wave(const float magnitude, const short int scaling, const Unit& unit);
    Wave(const float magnitude, const Polar& polarization,
        const Intrinsic& azimuthal);
    Wave(const float magnitude, const short int scaling,
        const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const float magnitude, const short int scaling, const std::string unit,
        const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name);
    Wave(const std::string name, const Intrinsic& azimuthal);
    Wave(const std::string name, const Polar& polarization);
    Wave(const std::string name, const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name, const float magnitude);
    Wave(const std::string name, const float magnitude, const short int scaling);
    Wave(const std::string name, const float magnitude, const short int scaling, const std::string unit);
    Wave(const std::string name, const float magnitude, const short int scaling, const Unit& unit);
    Wave(const std::string name, const float magnitude,
        const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name, const float magnitude, const short int scaling,
        const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name, const float magnitude, const short int scaling,
		const std::string unit, const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name, const float magnitude, const short int scaling,
		const Unit& unit, const Polar& polarization, const Intrinsic& azimuthal);
    Wave(const std::string name, const Intrinsic& gradient, const int limit);
	Wave(const std::string name, const CurvatureArray& wavelets);
	Wave(const std::string name, const CurvatureArray& wavelets, const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const Intrinsic& azimuthal);
	Wave(const std::string name, const CurvatureArray& wavelets, const Intrinsic& azimuthal,
		const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const float polarization);
	Wave(const std::string name, const CurvatureArray& wavelets, const float polarization,
		const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const Polar& polarization);
	Wave(const std::string name, const CurvatureArray& wavelets, const Polar& polarization,
		const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const float polarization,
		const float azimuthal);
	Wave(const std::string name, const CurvatureArray& wavelets, const float polarization,
		const float azimuthal, const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const Polar& polarization,
		const Intrinsic& azimuthal);
	Wave(const std::string name, const CurvatureArray& wavelets, const Polar& polarization,
		const Intrinsic& azimuthal, const int limit);
    Wave(const std::string name, const CurvatureArray& wavelets, const float magnitude,
		const short int scaling, const Unit& unit, const Polar& polarization, const Intrinsic& azimuthal);
	Wave(const std::string name, const CurvatureArray& wavelets, const float magnitude,
		const short int scaling, const Unit& unit, const Polar& polarization, const Intrinsic& azimuthal,
		const int limit);

    // Destructors
    ~Wave();

    // Operator overloading
    bool operator==(const Wave& peer) const;
    bool operator<(const Wave& peer) const;
    bool operator>(const Wave& peer) const;
    bool operator<=(const Wave& peer) const;
    bool operator>=(const Wave& peer) const;
    Wave operator+(const Wave& peer) const;
    Wave operator-(const Wave& peer) const;

    // Access operator
    Curvature operator()(const int index) { return wavelets[index]; }
    const Curvature operator()(const int index) const { return wavelets[index]; }

    // Getters
    int getLimit() const { return limit; }
    CurvatureArray getWavelets() const { return wavelets; }

    // Setters
    void setLimit(const int value) { this->limit = value; }
    void setWavelets(const CurvatureArray& curves) { this->wavelets = curves; }

    // Additional methods
    int getWaveletCount() const;
    Curvature get(const int index) const;
    void set(const int index, const Curvature& object);
    virtual Point copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    virtual std::string printWavelets() const;
    virtual std::string printWaveletRadians() const;
public:
	static const int DEFAULT_LIMIT;
    static const long DEFAULT_FREQUENCY;
};

typedef std::vector<Wave > WaveArray;

} // namespace shp

#endif //SHP_WAVE_H