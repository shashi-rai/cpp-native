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

#include "light.h"

namespace phy {

Light::Light() : Wave("") {

}

Light::Light(std::string name) : Wave(name) {

}

Light::Light(std::string name, long frequency, float wavelength)
        : Wave(name, frequency, wavelength) {

}

Light::~Light() {

}

bool Light::operator==(const Light& peer) const {
    return (getAmplitude() == peer.getAmplitude())
        && (getFrequency() == peer.getFrequency())
        && (getWavelength() == peer.getWavelength());
}

shp::Point Light::copy() {
    Light fresh(this->getName());
    fresh.setAmplitude(this->getAmplitude());
	fresh.setGradient(this->getGradient());
	fresh.setPolarization(this->getPolarization());
	fresh.setFrequency(this->getFrequency());
	fresh.setWavelength(this->getWavelength());
    return fresh;
}

void Light::clear() {
    Wave::clear();
    return;
}

std::string Light::print() {
    std::stringstream result;
    result << "{L:";
	result << Wave::print() << ",sz:";
    result << "}";
	return result.str();
}

} // namespace phy