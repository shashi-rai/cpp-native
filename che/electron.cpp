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

#include "electron.h"

namespace che {

Electron::Electron()
        : Wave(""), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge() {

}

Electron::Electron(float polarization)
        : Wave(polarization), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge()  {

}

Electron::Electron(float polarization, float azimuthal)
        : Wave(polarization, azimuthal), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge()  {

}

Electron::Electron(std::string name)
        : Wave(name), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge()  {

}

Electron::Electron(std::string name, float polarization)
        : Wave(name, polarization), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge()  {

}

Electron::Electron(std::string name, float polarization, float azimuthal)
        : Wave(name, polarization, azimuthal), principal(0), azimuthal(0), magnetic(0), spin(0.0f), charge() {

}

Electron::Electron(short int principal, short int azimuthal, short int magnetic, float spin)
        : Wave(""), principal(0), azimuthal(0), magnetic(0), spin(spin), charge() {

}

Electron::Electron(std::string name,
        short int principal, short int azimuthal, short int magnetic, float spin,
        Charge& charge)
        : Wave(name), principal(0), azimuthal(0), magnetic(0), spin(spin), charge(charge) {

}

Electron::~Electron() {

}

void Electron::clear() {
    Wave::clear();
    return;
}

std::string Electron::print() {
    std::stringstream result;
    result << "{E:";
	result << Wave::print() << ",sz:";
    result << "}";
	return result.str();
}

} // namespace che