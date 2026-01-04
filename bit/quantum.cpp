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

const double Quantum::DEFAULT_VALUE = 0.0;
const double Quantum::PROBABILITY_MIN = 0.0;
const double Quantum::PROBABILITY_MAX = 1.0;
const double Quantum::SQUARE_ROOT_TWO = 1.414213562373095048801688724209698078569671875376948073176679;

Quantum::Quantum() : states() {

}

Quantum::Quantum(const QStates& states) : states(states) {

}

Quantum::~Quantum() {
    states.clear();
}

bool Quantum::operator==(const Quantum& peer) const {
    return (states == peer.states);
}

Quantum Quantum::operator+(const Quantum& peer) const {
    QStates result(states);
    result.insert(result.end(), peer.states.begin(), peer.states.end());
    return Quantum(result);
}

Quantum Quantum::operator-(const Quantum& peer) const {
    QStates result(states);
    for (QStates::const_iterator it = peer.states.begin(); it != peer.states.end(); ++it) {
        QStates::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Quantum(result);
}

int Quantum::getStateCount() const {
    return states.size();
}

QVector Quantum::get(const int index) const {
    QVector result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(states.size())) {
        return result;
    }
    return states[index];
}

void Quantum::set(const int index, const QVector object) {
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

double Quantum::getSumAlphaAmplitude() const {
    double alpha = PROBABILITY_MIN;
    for (QStates::const_iterator it = states.begin(); it != states.end(); ++it) {
        alpha += ((*it).real() * (*it).real());
    }
    return alpha;
}

double Quantum::getSumBetaAmplitude() const {
    double beta = PROBABILITY_MIN;
    for (QStates::const_iterator it = states.begin(); it != states.end(); ++it) {
        beta += ((*it).imag() * (*it).imag());
    }
    return (beta - PROBABILITY_MAX);
}

bool Quantum::checkStateValidity() {
    const double epsilon = std::numeric_limits<double>::epsilon() * 100;
    double alpha = getSumAlphaAmplitude(), beta = getSumBetaAmplitude();
    double result = (alpha - beta);
    if (std::abs(result) < epsilon) {
        if (std::abs(alpha - PROBABILITY_MAX) < epsilon) {
            return true;
        } else if (std::abs(beta - PROBABILITY_MAX) < epsilon) {
            return true;
        } else {
            if ((std::abs(alpha) < PROBABILITY_MAX) || (std::abs(beta) < PROBABILITY_MAX)) {
                return false;;
            } else {
                return true;
            }
        }
    } else {
        result = (alpha - (beta + 1));
        if (std::abs(result) < epsilon){
            return true;
        } else {
            return false;
        }
    }
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
    result << "|ψ⟩{" << std::endl;
    for (int i = 0; i < states.size(); i++) {
        result << "\t" << Quantum::toString(states[i]) << std::endl;
    }
    result << "}";
	return result.str();
}

const std::string Quantum::toString(QVector state) {
    std::stringstream result;
    result << "α|";
    result << state.real() << "⟩,β|";
    result << state.imag() << "⟩";
    return result.str();
}

void Quantum::initialize() {
    // probability for |0> in the range (% of being zero, % of being 1)
    QVector zero = QVector(PROBABILITY_MAX, PROBABILITY_MIN); set(0, zero);
    // probability for |1> in the range (% of being zero, % of being 1)
    QVector one = QVector(PROBABILITY_MIN, PROBABILITY_MAX); set(1, one);
}

const bool Quantum::checkBasisState(QVector state) {
    const double epsilon = std::numeric_limits<double>::epsilon() * 100;
    double alpha = state.real(), beta = state.imag();
    double result = sqrt((alpha * alpha) + (beta * beta));
    return (std::abs(result - PROBABILITY_MAX) < epsilon) ? true : false;
}

const QVector Quantum::inverse(QVector state) {
    return QVector(state.imag(), state.real());
}

const bool Quantum::equals(QVector a, QVector b) {
    return (a == b);
}

const QVector Quantum::addition(QVector a, QVector b) {
    return (a + b);
}

const QVector Quantum::subtraction(QVector a, QVector b) {
    return (a - b);
}

const QVector Quantum::multiplication(QVector a, QVector b) {
    return (a * b);
}

const QVector Quantum::division(QVector a, QVector b) {
    return (a / b);
}

const QVector Quantum::modulus(QVector a, QVector b) {
    return fmod(std::abs(a), std::abs(b));
}

} // namespace bit