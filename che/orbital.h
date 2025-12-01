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

#ifndef CHE_ORBITAL_H
#define CHE_ORBITAL_H

#include <string>
#include <vector>
#include "electron.h"
#include "../shp/polygon.h"

namespace che {

class Orbital : public shp::Polygon {

public:
    // Constructors
    Orbital();
    Orbital(std::string name);
    Orbital(const std::shared_ptr<che::Electron> left,
        const std::shared_ptr<che::Electron> right);
    Orbital(std::string name, int limit);
    Orbital(std::string name, float gradient, int limit);
    Orbital(std::string name, int limit,
        const std::shared_ptr<che::Electron> left,
        const std::shared_ptr<che::Electron> right);

    // Destructors
    ~Orbital();

    // Access operator
    Electron& operator()(int x) { return getElectron(x); }
    const Electron& operator()(int x) const { return getElectron(x); }

    // Getters
    Electron getLeftSpinor() const { return this->getElectron(0); }
    Electron getRightSpinor() const { return this->getElectron(1); }

    // Setters
    void setLeftSpinor(const std::shared_ptr<che::Electron> spinor) { this->setElectron(0, spinor); }
    void setRightSpinor(const std::shared_ptr<che::Electron> spinor) { this->setElectron(1, spinor); }

    // Additional methods
    int getParticleCount() const;
    Electron& getElectron(int magnetic) const;
    void setElectron(int magnetic, const std::shared_ptr<che::Electron> object);
    virtual void clear();
    virtual std::string print();
public:
    static const int ELECTRON_MAX_LIMIT;
};

} // namespace che

#endif //CHE_ORBITAL_H