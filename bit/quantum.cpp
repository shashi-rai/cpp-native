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

#include "quantum.h"

namespace bit {

const float Quantum::DEFAULT_VALUE = 0.0f;
const float Quantum::STATE_ZERO = 0.0f;
const float Quantum::STATE_ONE = 1.0f;

Quantum::Quantum() : states() {
    initialize();
}

Quantum::Quantum(const QuStates& states) : states(states) {
    initialize();
}

Quantum::~Quantum() {
    states.clear();
}

bool Quantum::operator==(const Quantum& peer) const {
    return (states == peer.states);
}

Quantum Quantum::operator+(const Quantum& peer) const {
    QuStates result(states);
    result.insert(result.end(), peer.states.begin(), peer.states.end());
    return Quantum(result);
}

Quantum Quantum::operator-(const Quantum& peer) const {
    QuStates result(states);
    for (QuStates::const_iterator it = peer.states.begin(); it != peer.states.end(); ++it) {
        QuStates::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Quantum(result);
}

int Quantum::getStateCount() const {
    return states.size();
}

std::complex<double> Quantum::get(const int index) const {
    std::complex<double> result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(states.size())) {
        return result;
    }
    return states[index];
}

void Quantum::set(const int index, const std::complex<double> object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(states.size())) {
        // replace existing element
        states[index] = object;
    } else if (index == static_cast<int>(states.size())) {
        // append at end
        states.push_back(object);
    } else {
        // index beyond current size: append at end
        states.push_back(object);
    }
    return;
}

void Quantum::applyHadamard() {

}

int Quantum::measure() {
    return 0;
}

Quantum Quantum::copy() {
    Quantum fresh(states);
    return fresh;
}

void Quantum::clear() {
    states.clear();
    return;
}

std::string Quantum::print() {
    std::stringstream result;
    result << "{";
    for (int i = 0; i < states.size(); i++) {
        result << "," << states[i] << std::endl;
    }
    result << "}";
	return result.str();
}

void Quantum::initialize() {
    // amplitude for |0>
    std::complex<double> zero = std::complex<double>(STATE_ONE, DEFAULT_VALUE); set(0, zero);
    // amplitude for |1>
    std::complex<double> one = std::complex<double>(STATE_ZERO, DEFAULT_VALUE); set(1, one);
}

const std::complex<double> Quantum::addition(std::complex<double> a, std::complex<double> b) {
    return (a + b);
}

const std::complex<double> Quantum::subtraction(std::complex<double> a, std::complex<double> b) {
    return (a - b);
}

const std::complex<double> Quantum::multiplication(std::complex<double> a, std::complex<double> b) {
    return (a * b);
}

const std::complex<double> Quantum::division(std::complex<double> a, std::complex<double> b) {
    return (a / b);
}

const std::complex<double> Quantum::modulus(std::complex<double> a, std::complex<double> b) {
    return fmod(std::abs(a), std::abs(b));
}

} // namespace bit