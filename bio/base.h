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

#ifndef BIO_BASE_H
#define BIO_BASE_H

#include <string>
#include <vector>
#include "../che/molecule.h"
#include "../che/ring.h"

namespace bio {

class Base : public che::Molecule {
    che::Ring pyrimidine;
    che::Ring imidazole;
public:
    // Constructors
    Base();
    Base(std::string name);
    Base(const che::Ring& pyrimidine, const che::Ring& imidazole);
    Base(std::string name, const che::Ring& pyrimidine, const che::Ring& imidazole);

    // Operator overloading
    bool operator==(const Base& peer) const;
    Base operator+(const Base& peer) const;
    Base operator-(const Base& peer) const;

    // Destructors
    ~Base();

    // Getters
    che::Ring getPyrimidine() const { return pyrimidine; }
    che::Ring getImidazole() const { return imidazole; }

    // Setters
    void setPyrimidine(const che::Ring& molecule) { this->pyrimidine = molecule; }
    void setImidazole(const che::Ring& molecule) { this->imidazole = molecule; }
};

typedef std::vector<Base > BaseArray;

class Adenine : public Base {

public:
    // Constructors
    Adenine() : Base("A") {}

    // Destructors
    ~Adenine() {}
};

class Guanine : public Base {

public:
    // Constructors
    Guanine() : Base("G") {}

    // Destructors
    ~Guanine() {}
};

class Cytosine : public Base {

public:
    // Constructors
    Cytosine() : Base("C") {}

    // Destructors
    ~Cytosine() {}
};

class Thymine : public Base {

public:
    // Constructors
    Thymine() : Base("T") {}

    // Destructors
    ~Thymine() {}
};

class Uracil : public Base {

public:
    // Constructors
    Uracil() : Base("U") {}

    // Destructors
    ~Uracil() {}
};

} // namespace bio

#endif //BIO_BASE_H