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

#include "bond.h"

namespace che {

Bond::Bond() : name(""), left(), right(),
        electron(), energy(), length(0.0), angle(0.0) {

}

Bond::Bond(std::string name) : name(name), left(), right(),
        electron(), energy(), length(0.0), angle(0.0) {

}

Bond::Bond(std::string name, Atom& left, Atom& right)
        : name(name), left(), right(),
        electron(), energy(), length(0.0), angle(0.0) {

}

Bond::Bond(std::string name, Atom& left, Atom& right,
        Electron& electron, Energy& energy, double length, double angle)
        : name(name), left(left), right(right),
        electron(electron), energy(energy), length(length), angle(angle) {

}

Bond::~Bond() {

}

} // namespace che