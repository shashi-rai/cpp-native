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

#ifndef SHP_CHANGE_H
#define SHP_CHANGE_H

#include "signal.h"

namespace shp {

/*
 * A change represents some action in Nature.
 * - an infinitesimal change in a physical quantity (e.g., Energy) results
 *   into certain conversion from its potential form into dynamical form or
 *   vice versa
 * - a rate of change could be represented by a gradient (i.e., direction)
 * - a change in direction (e.g., angular) alone represents an action in some
 *   cases (e.g., momentum) 
 */
class Change {
    Direction rate;
    Signal dynamical;
    Signal potential;
public:
    // Constructors
    Change();
    Change(const float rate);
    Change(const float rate, short int scaling);
    Change(const float rate, short int scaling, std::string unit);
    Change(const float rate, short int scaling, const Unit& unit);
    Change(const Direction& rate);
    Change(const float rate, const float potential);
    Change(const float rate, const float potential, short int scaling);
    Change(const float rate, const float potential, short int scaling, std::string unit);
    Change(const float rate, const float potential, short int scaling, const Unit& unit);
    Change(const Signal& potential);
    Change(const Signal& dynamical, const Signal& potential);
    Change(const Direction& rate, const Signal& potential);
    Change(const Direction& rate, const Signal& dynamical, const Signal& potential);
    Change(const float rate, const float dynamical, const float potential);
    Change(const float rate, const float dynamical, const float potential, short int scaling);
    Change(const float rate, const float dynamical, const float potential, short int scaling, std::string unit);
    Change(const float rate, const float dynamical, const float potential, short int scaling, const Unit& unit);

    // Destructors
    ~Change();

    // Operator overloading
    bool operator==(const Change& peer) const;
    bool operator<(const Change& peer) const;
    bool operator>(const Change& peer) const;
    bool operator<=(const Change& peer) const;
    bool operator>=(const Change& peer) const;
    Change operator+(const Change& peer) const;
    Change operator-(const Change& peer) const;
    Change operator*(const Change& peer) const;
    Change operator/(const Change& peer) const;
    Change operator%(const Change& peer) const;

    // Getters
    Direction getRate() const { return rate; }
    Signal getDynamical() const { return dynamical; }
    Signal getPotential() const { return potential; }

    // Setters
    void setRate(const Direction& change) { this->rate = change; }
    void setDynamical(const Signal& property) { this->dynamical = property; }
    void setPotential(const Signal& property) { this->potential = property; }

    // Additional methods
    float toRadians() const;
    void setConversion(const float rate);
    Signal getLagrangian() const;
    Signal getHamiltonian() const;
    float leastAction();
    virtual Change copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
};

typedef std::vector<Change > ChangeArray;

} // namespace shp

#endif //SHP_CHANGE_H