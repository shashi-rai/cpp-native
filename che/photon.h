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

#ifndef CHE_PHOTON_H
#define CHE_PHOTON_H

#include <string>
#include <vector>
#include "../qft/energy.h"
#include "../shp/wave.h"

namespace che {

class Photon : public shp::Wave {
    qft::Energy energy;
public:
    // Constructors
    Photon();
    Photon(std::string name, qft::Energy& energy);
    Photon(std::string name, qft::Energy& energy, long frequency, float wavelength);

    // Destructors
    ~Photon();

    // Getters
    qft::Energy getEnergy() const { return energy; }

    // Setters
    void setEnergy(const qft::Energy& value) { this->energy = value; }

    // Additional methods
    virtual shp::Point copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Photon > PhotonArray;

} // namespace che

#endif //CHE_PHOTON_H