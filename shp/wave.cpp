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

#include "wave.h"

namespace shp {

const long Wave::DEFAULT_FREQUENCY = 0L;

Wave::Wave()
    : Curvature(), wavelets() {

}

Wave::Wave(const float polarization)
        : Curvature(polarization), wavelets() {

}

Wave::Wave(const float polarization, const float azimuthal)
        : Curvature(polarization, azimuthal), wavelets() {

}

Wave::Wave(std::string name)
        : Curvature(name), wavelets() {

}

Wave::Wave(std::string name, const float polarization)
        : Curvature(name, polarization), wavelets() {

}

Wave::Wave(std::string name, const float polarization, const float azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets() {

}

Wave::Wave(std::string name, const CurvatureArray& wavelets)
        : Curvature(name), wavelets(wavelets) {

}

Wave::Wave(std::string name, const CurvatureArray& wavelets,
        const float polarization)
        : Curvature(name, polarization), wavelets(wavelets) {

}

Wave::Wave(std::string name,  const CurvatureArray& wavelets,
        const float polarization, const float azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets(wavelets) {

}

Wave::~Wave() {

}

bool Wave::operator==(const Wave& peer) const {
    return (static_cast<const Curvature&>(*this) == static_cast<const Curvature&>(peer))
        && (wavelets == peer.wavelets);
}

Wave Wave::operator+(const Wave& peer) const {
    Wave self = *this, other = peer;
    CurvatureArray fluctuations(wavelets);
    fluctuations.insert(fluctuations.end(), peer.wavelets.begin(), peer.wavelets.end());
    std::complex<float>
        ap1 = self.toAzimuthalComplex(self.getGradient()),
        ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 + ap2;
    std::complex<float>
        pp1 = self.toPolarizationComplex(self.getPolarization()),
        pp2 = other.toPolarizationComplex(peer.getPolarization());
    std::complex<float> p_phasor = pp1 + pp2;
    Wave result = Wave("+", fluctuations, std::arg(p_phasor), std::arg(a_phasor));
    // TODO: since amplitude would vary due to Polar & Azimuthal angle differences
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

Wave Wave::operator-(const Wave& peer) const {
    Wave self = *this, other = peer;
    CurvatureArray fluctuations(wavelets);
    for (CurvatureArray::const_iterator it = peer.wavelets.begin(); it != peer.wavelets.end(); ++it) {
        CurvatureArray::iterator found = std::find(fluctuations.begin(), fluctuations.end(), *it);
        if (found != fluctuations.end()) {
            fluctuations.erase(found);
        }
    }
    std::complex<float>
        ap1 = self.toAzimuthalComplex(self.getGradient()),
        ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 - ap2;
    std::complex<float>
        pp1 = self.toPolarizationComplex(self.getPolarization()),
        pp2 = other.toPolarizationComplex(peer.getPolarization());
    std::complex<float> p_phasor = pp1 - pp2;
    Wave result = Wave("-", fluctuations, std::arg(p_phasor), std::arg(a_phasor));
    // TODO: since amplitude would vary due to Polar & Azimuthal angle differences
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

int Wave::getWaveletCount() const {
    return wavelets.size();
}

Curvature Wave::get(int index) const {
    Curvature result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(wavelets.size())) {
        return result;
    }
    return wavelets[index];
}

void Wave::set(int index, const Curvature& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(wavelets.size())) {
        // replace existing element
        wavelets[index] = object;
    } else if (index == static_cast<int>(wavelets.size())) {
        // append at end
        wavelets.push_back(object);
    } else {
        // index beyond current size: append at end
        wavelets.push_back(object);
    }
    return;
}

Point Wave::copy() {
    Wave fresh(getName(), wavelets, getPolarization(), getGradient());
    return fresh;
}

void Wave::clear() {
    Point::clear();
    wavelets.clear();
    return;
}

std::string Wave::print() {
    std::stringstream result;
    result << "λ:";
	result << Curvature::print() << ",sz:";
	result << wavelets.size() << "!";
	return result.str();
}

} // namespace shp