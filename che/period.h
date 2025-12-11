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

#ifndef CHE_PERIOD_H
#define CHE_PERIOD_H

#include <string>
#include <vector>
#include "orbital.h"
#include "../qft/electron.h"
#include "../shp/shell.h"

namespace che {

class Period : public shp::Shell {

public:
    // Constructors
    Period();
    Period(std::string name);
    Period(std::string name, int limit);
    Period(std::string name, float gradient, int limit);

    // Destructors
    ~Period();

    // Operator overloading
    bool operator==(const Period& peer) const;

    // Access operator
    Orbital operator()(int x) { return getOrbital(x); }
    const Orbital operator()(int x) const { return getOrbital(x); }
    qft::Electron operator()(int x, int y) { return getOrbital(x).getElectron(y); }
    const qft::Electron operator()(int x, int y) const { return getOrbital(x).getElectron(y); }

    // Getters
    Orbital getS() const;
    std::vector<Orbital> getP() const;
    std::vector<Orbital> getD() const;
    std::vector<Orbital> getF() const;

    // Setters
    void setS(const std::shared_ptr<che::Orbital> object);
    void setP(const std::vector<std::shared_ptr<che::Orbital> >& object);
    void setD(const std::vector<std::shared_ptr<che::Orbital> >& object);
    void setF(const std::vector<std::shared_ptr<che::Orbital> >& object);

    // Additional methods
    Orbital getOrbital(int azimuthal) const;
    void setOrbital(int azimuthal, const std::shared_ptr<che::Orbital> object);
    qft::Electron getElectron(int azimuthal, int magnetic) const;
    void setElectron(int azimuthal, int magnetic, const std::shared_ptr<qft::Electron> object);
    virtual void clear();
    virtual std::string print();
public:
    static const int MAX_LIMIT;
    static const int ORBITAL_MAX_LIMIT;
    static const int ELECTRON_LIMIT[];
    static const std::string NAME[];
};

typedef std::vector<Period > PeriodArray;

} // namespace che

#endif //CHE_PERIOD_H