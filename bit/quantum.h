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
#include <limits>
#include <sstream>
#include <string>
#include <vector>

namespace bit {

/*
 * A quantum state vector is represended by two probability amplitudes (between 0 and 1)
 * The real part specifies probability amplitude of being in a zero state.
 * The imaginary part specifies probability amplitude of being in a one state.
 */
typedef std::complex<double> QVector;

/*
 * A quantum bit could exist in multiple states at the same moment
 */
typedef std::vector<QVector> QStates;

class Quantum {
    QStates states;         // list of states (e.g., |0> or |1>)
public:
    // Constructors
    Quantum();
    Quantum(const QStates& states);

    // Destructors
    ~Quantum();

    // Operator overloading
    bool operator==(const Quantum& peer) const;
    Quantum operator+(const Quantum& peer) const;
    Quantum operator-(const Quantum& peer) const;

    // Access operator
    QVector operator()(const int x) { return states[x]; }
    const QVector operator()(const int x) const { return states[x]; }

    // Getters
    QStates getStates() const { return states; }

    // Setters
    void setStates(const QStates& value) { this->states = value; }

    // Additional methods
    int getStateCount() const;
    QVector get(const int index) const;
    void set(const int index, const QVector object);
    double getSumAlphaAmplitude() const;
    double getSumBetaAmplitude() const;
    bool checkStateValidity();
    void applyHadamard();
    int measure();
    Quantum copy();
    void clear();
    std::string print();
    void initialize();
public:
    static const std::string toString(QVector);
    static const bool checkBasisState(QVector state);
    static const QVector inverse(QVector state);
    static const bool equals(QVector a, QVector b);
    static const QVector addition(QVector a, QVector b);
    static const QVector subtraction(QVector a, QVector b);
    static const QVector multiplication(QVector a, QVector b);
    static const QVector division(QVector a, QVector b);
    static const QVector modulus(QVector a, QVector b);
public:
    static const double DEFAULT_VALUE;
    static const double PROBABILITY_MIN;
    static const double PROBABILITY_MAX;
    static const double SQUARE_ROOT_TWO;
};

typedef std::vector<Quantum > QuantumArray;

} // namespace bit

#endif //BIT_QUANTUM_H