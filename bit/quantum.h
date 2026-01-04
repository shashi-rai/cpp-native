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

#ifndef BIT_QUANTUM_H
#define BIT_QUANTUM_H

#include <cmath>
#include <complex>
#include <sstream>
#include <string>
#include <vector>

namespace bit {

typedef std::vector<std::complex<double> > QuStates;

class Quantum {
    QuStates states;
public:
    // Constructors
    Quantum();
    Quantum(const QuStates& states);

    // Destructors
    ~Quantum();

    // Operator overloading
    bool operator==(const Quantum& peer) const;
    Quantum operator+(const Quantum& peer) const;
    Quantum operator-(const Quantum& peer) const;

    // Access operator
    std::complex<double> operator()(const int x) { return states[x]; }
    const std::complex<double> operator()(const int x) const { return states[x]; }

    // Getters
    QuStates getStates() const { return states; }

    // Setters
    void setStates(const QuStates& value) { this->states = value; }

    // Additional methods
    int getStateCount() const;
    std::complex<double> get(const int index) const;
    void set(const int index, const std::complex<double> object);
    void applyHadamard();
    int measure();
    Quantum copy();
    void clear();
    std::string print();

private:
    void initialize();
public:
    static const std::complex<double> addition(std::complex<double> a, std::complex<double> b);
    static const std::complex<double> subtraction(std::complex<double> a, std::complex<double> b);
    static const std::complex<double> multiplication(std::complex<double> a, std::complex<double> b);
    static const std::complex<double> division(std::complex<double> a, std::complex<double> b);
    static const std::complex<double> modulus(std::complex<double> a, std::complex<double> b);
public:
    static const float DEFAULT_VALUE;
    static const float STATE_ZERO;
    static const float STATE_ONE;
};

typedef std::vector<Quantum > QuantumArray;

} // namespace bit

#endif //BIT_QUANTUM_H