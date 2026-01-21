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

Wave::Wave(const Azimuth& azimuthal)
        : Curvature(azimuthal), wavelets() {

}

Wave::Wave(const float polarization)
        : Curvature(polarization), wavelets() {

}

Wave::Wave(const Polar& polarization)
        : Curvature(polarization), wavelets() {

}

Wave::Wave(const float polarization, const float azimuthal)
        : Curvature(polarization, azimuthal), wavelets() {

}

Wave::Wave(const Polar& polarization, const Azimuth& azimuthal)
        : Curvature(polarization, azimuthal), wavelets() {

}

Wave::Wave(const std::string name)
        : Curvature(name), wavelets() {

}

Wave::Wave(const std::string name, const Azimuth& azimuthal)
        : Curvature(name, azimuthal), wavelets() {

}

Wave::Wave(const std::string name, const float polarization)
        : Curvature(name, polarization), wavelets() {

}

Wave::Wave(const std::string name, const Polar& polarization)
        : Curvature(name, polarization), wavelets() {

}

Wave::Wave(const std::string name, const float polarization, const float azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets() {

}

Wave::Wave(const std::string name, const Polar& polarization, const Azimuth& azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets() {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets)
        : Curvature(name), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const Azimuth& azimuthal)
        : Curvature(name, azimuthal), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const float polarization)
        : Curvature(name, polarization), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const Polar& polarization)
        : Curvature(name, polarization), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const float polarization, const float azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const Polar& polarization, const Azimuth& azimuthal)
        : Curvature(name, polarization, azimuthal), wavelets(wavelets) {

}

Wave::Wave(const std::string name, const CurvatureArray& wavelets,
        const float magnitude, const short int scaling, const Unit& unit,
        const Polar& polarization, const Azimuth& azimuthal)
        : Curvature(name, magnitude, scaling, unit, polarization, azimuthal),
        wavelets(wavelets) {

}

Wave::~Wave() {

}

bool Wave::operator==(const Wave& peer) const {
    return (static_cast<const Curvature&>(*this) == static_cast<const Curvature&>(peer))
        && (wavelets == peer.wavelets);
}

bool Wave::operator<(const Wave& peer) const {
    return (static_cast<const Curvature&>(*this) < static_cast<const Curvature&>(peer))
        && (wavelets < peer.wavelets);
}

bool Wave::operator>(const Wave& peer) const {
    return (static_cast<const Curvature&>(*this) > static_cast<const Curvature&>(peer))
        && (wavelets > peer.wavelets);
}

bool Wave::operator<=(const Wave& peer) const {
    Wave self = *this;
    return (self < peer) || (self == peer);
}

bool Wave::operator>=(const Wave& peer) const {
    Wave self = *this;
    return (self > peer) || (self == peer);
}

Wave Wave::operator+(const Wave& peer) const {
    Wave self = *this, other = peer;
    CurvatureArray fluctuations(wavelets);
    fluctuations.insert(fluctuations.end(), peer.wavelets.begin(), peer.wavelets.end());
    std::complex<float>
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(peer.getGradient());
    std::complex<float> a_phasor = ap1 + ap2;
    std::complex<float>
        pp1 = self.toComplexPolar(self.getPolarization()),
        pp2 = other.toComplexPolar(peer.getPolarization());
    std::complex<float> p_phasor = pp1 + pp2;
    Wave result = Wave("+", fluctuations, std::arg(p_phasor), std::arg(a_phasor));
    // TODO: since amplitude would vary due to Polar & Azimuthal angle differences
    result.setMagnitude(std::abs(p_phasor), self.getScaling(), self.getUnit());
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
        ap1 = self.toComplexAzimuth(self.getGradient()),
        ap2 = other.toComplexAzimuth(peer.getGradient());
    std::complex<float> a_phasor = ap1 - ap2;
    std::complex<float>
        pp1 = self.toComplexPolar(self.getPolarization()),
        pp2 = other.toComplexPolar(peer.getPolarization());
    std::complex<float> p_phasor = pp1 - pp2;
    Wave result = Wave("-", fluctuations, std::arg(p_phasor), std::arg(a_phasor));
    // TODO: since amplitude would vary due to Polar & Azimuthal angle differences
    result.setMagnitude(std::abs(p_phasor), self.getScaling(), self.getUnit());
    return result;
}

int Wave::getWaveletCount() const {
    return wavelets.size();
}

Curvature Wave::get(const int index) const {
    Curvature result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(wavelets.size())) {
        return result;
    }
    return wavelets[index];
}

void Wave::set(const int index, const Curvature& object) {
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
    Wave self = *this;
    Wave fresh(self.getName(), self.wavelets,
        self.getMagnitude(), self.getScaling(), self.getUnit(),
        self.getPolarization(), self.getGradient());
    return fresh;
}

void Wave::clear() {
    Point::clear();
    wavelets.clear();
    return;
}

std::string Wave::print() const {
    std::stringstream result;
    result << "λ:";
	result << Curvature::print() << ",sz:";
	result << wavelets.size() << "!";
	return result.str();
}

std::string Wave::printRadians() const {
    std::stringstream result;
    result << "λ:";
	result << Curvature::printRadians() << ",sz:";
	result << wavelets.size() << "!";
	return result.str();
}

} // namespace shp