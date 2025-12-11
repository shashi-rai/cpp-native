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

#include "curvature.h"

namespace shp {

Curvature::Curvature() : Point(), deforms(), polarization(0.0f) {

}

Curvature::Curvature(float polarization)
        : Point(), deforms(), polarization(polarization) {

}

Curvature::Curvature(float polarization, float azimuthal)
        : Point(azimuthal), deforms(), polarization(polarization) {

}

Curvature::Curvature(std::string name)
        : Point(name), deforms(), polarization(0.0f) {

}

Curvature::Curvature(std::string name, float polarization)
        : Point(name), deforms(), polarization(polarization) {

}

Curvature::Curvature(std::string name, float polarization, float azimuthal)
        : Point(name, azimuthal), deforms(), polarization(polarization) {

}

Curvature::Curvature(std::string name, PhaseArray& deforms)
        : Point(name), deforms(deforms), polarization(0.0f) {

}

Curvature::Curvature(std::string name, PhaseArray& deforms, float polarization)
        : Point(name), deforms(deforms), polarization(polarization) {

}

Curvature::Curvature(std::string name, PhaseArray& deforms, float polarization, float azimuthal)
        : Point(name, azimuthal), deforms(deforms), polarization(polarization) {

}

Curvature::~Curvature() {

}

bool Curvature::operator==(const Curvature& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (deforms == peer.deforms) && (polarization == peer.polarization);
}

Curvature Curvature::operator+(const Curvature& peer) const {
    Curvature self = *this, other = peer;
    PhaseArray phases(deforms);
    phases.insert(phases.end(), peer.deforms.begin(), peer.deforms.end());
    std::complex<float> ap1 = self.toAzimuthalComplex(self.getGradient()), ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 + ap2;
    std::complex<float> pp1 = self.toPolarizationComplex(polarization), pp2 = other.toPolarizationComplex(peer.polarization);
    std::complex<float> p_phasor = pp1 + pp2;
    Curvature result = Curvature("+", phases, std::arg(p_phasor), std::arg(a_phasor));
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

Curvature Curvature::operator-(const Curvature& peer) const {
    Curvature self = *this, other = peer;
    PhaseArray phases(deforms);
    for (PhaseArray::const_iterator it = peer.deforms.begin(); it != peer.deforms.end(); ++it) {
        PhaseArray::iterator found = std::find(phases.begin(), phases.end(), *it);
        if (found != phases.end()) {
            phases.erase(found);
        }
    }
    std::complex<float> ap1 = self.toAzimuthalComplex(self.getGradient()), ap2 = other.toAzimuthalComplex(peer.getGradient());
    std::complex<float> a_phasor = ap1 - ap2;
    std::complex<float> pp1 = self.toPolarizationComplex(polarization), pp2 = other.toPolarizationComplex(peer.polarization);
    std::complex<float> p_phasor = pp1 - pp2;
    Curvature result = Curvature("-", phases, std::arg(p_phasor), std::arg(a_phasor));
    result.setAmplitude(std::abs(p_phasor));
    return result;
}

int Curvature::getChangeCount() const {
    return deforms.size();
}

Phase Curvature::get(int index) const {
    Phase result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(deforms.size())) {
        return result;
    }
    return deforms[index];
}

void Curvature::set(int index, const Phase& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(deforms.size())) {
        // replace existing element
        deforms[index] = object;
    } else if (index == static_cast<int>(deforms.size())) {
        // append at end
        deforms.push_back(object);
    } else {
        // index beyond current size: append at end
        deforms.push_back(object);
    }
    return;
}

Angular Curvature::getOrientation() const {
    Direction polarity(polarization);
    Direction azimuth(getGradient());
    Angular result(Angular::DEFAULT_RADIUS, polarity, azimuth);
    return result;
}

Point Curvature::copy() {
    Curvature fresh(this->getName(), this->deforms, this->polarization, this->getGradient());
    return fresh;
}

void Curvature::clear() {
    Point::clear();
    polarization = 0.0f;
    deforms.clear();
    return;
}

std::string Curvature::print() {
    std::stringstream result;
    result << "[κ:";
	result << Point::print() << ",𝜃:";
    result << polarization << ",sz:";
	result << deforms.size() << "]";
	return result.str();
}

float Curvature::getAmplitudePolarization(float change) const {
    return getAmplitude() * cos(polarization + change);
}

std::complex<float> Curvature::toPolarizationComplex(float change) {
    return std::complex<float>(getAmplitude() * std::cos(change), getAmplitude() * std::sin(change));
}

} // namespace shp