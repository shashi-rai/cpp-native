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

#ifndef QFT_FIELD_H
#define QFT_FIELD_H

#include "action.h"
#include "particle.h"

namespace qft {

// To enable compiler resolve forward declarations
class Charge;
class Mass;

class Field : protected qft::Time {
    shp::Potential potential;
public:
    // Constructors
    Field();
    Field(const shp::Unit& unit);
    Field(const shp::Potential& potential);
    Field(const shp::Distance& radius);
    Field(const shp::Azimuth& azimuth);
    Field(const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const shp::Polar& polar);
    Field(const shp::Distance& radius, const shp::Polar& polar);
    Field(const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Angular& origin);
    Field(const float magnitude);
    Field(const float magnitude, const std::string unit);
    Field(const float magnitude, const shp::Unit& unit);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Angular& origin);
    Field(const float magnitude, const short int scaling);
    Field(const float magnitude, const short int scaling, const std::string unit);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Distance& radius);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Polar& polar);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Angular& origin);
    Field(const shp::Signal& modulation);
    Field(const shp::Signal& modulation, const std::string unit);
    Field(const shp::Signal& modulation, const shp::Unit& unit);
    Field(const shp::Signal& modulation, const float magnitude);
    Field(const shp::Signal& modulation, const float magnitude, const std::string unit);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const shp::Unit& unit,
        const shp::Angular& origin);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const std::string unit);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Potential& potential);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Field(const shp::Signal& modulation, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Angular& origin);
    Field(const std::string name);
    Field(const std::string name, const std::string unit);
    Field(const std::string name, const shp::Unit& unit);
    Field(const std::string name, const shp::Potential& potential);
    Field(const std::string name, const shp::Distance& radius);
    Field(const std::string name, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Polar& polar);
    Field(const std::string name, const shp::Distance& radius, const shp::Polar& polar);
    Field(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Distance& radius,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Angular& origin);
    Field(const std::string name, const float magnitude);
    Field(const std::string name, const float magnitude, const std::string unit);
    Field(const std::string name, const float magnitude, const shp::Unit& unit);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Distance& radius, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const shp::Unit& unit,
        const shp::Angular& origin);
    Field(const std::string name, const float magnitude, const short int scaling);
    Field(const std::string name, const float magnitude, const short int scaling,
        const std::string unit);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Potential& potential);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const float magnitude, const short int scaling,
        const shp::Unit& unit, const shp::Angular& origin);
    Field(const std::string name, const shp::Signal& modulation);
    Field(const std::string name, const shp::Signal& modulation, const std::string unit);
    Field(const std::string name, const shp::Signal& modulation, const shp::Unit& unit);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const std::string unit);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Potential& potential);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Distance& radius);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Polar& polar);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Distance& radius, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const shp::Unit& unit, const shp::Angular& origin);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const std::string unit);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Potential& potential);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Distance& radius);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Distance& radius,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Polar& polar);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Distance& radius,
        const shp::Polar& polar);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Distance& radius,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Signal& modulation, const float magnitude,
        const short int scaling, const shp::Unit& unit, const shp::Angular& origin);

    // Destructors
    ~Field();

    // Operator overloading
    bool operator==(const Field& peer) const;
    bool operator<(const Field& peer) const;
    bool operator>(const Field& peer) const;
    bool operator<=(const Field& peer) const;
    bool operator>=(const Field& peer) const;
    Field operator+(const Field& peer) const;
    Field operator-(const Field& peer) const;
    Field operator*(const Field& peer) const;
    Field operator/(const Field& peer) const;
    Field operator%(const Field& peer) const;

    // Access operator
    shp::Signal operator()(const Field& peer,
        const shp::Distance& separation, const shp::Distance& position) const;
    shp::Signal operator()(const Field& peerX, const Field& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const;

    // Getters
    shp::Potential getPotential() const { return potential; }

    // Setters
    void setPotential(const shp::Potential& difference) { this->potential = difference; }

    // Additional methods
    shp::Azimuth getSpatialChange() const;
    void setSpatialChange(const shp::Azimuth& curvature);
    void setSpatialChange(const float motion, const shp::Azimuth& curvature);
    void setSpatialChange(const float motion, const short int scale, const shp::Azimuth& curvature);
    void setSpatialChange(const float motion, const short int scale, const std::string unit, const shp::Azimuth& curvature);
    void setSpatialChange(const float motion, const short int scale, const shp::Unit& unit, const shp::Azimuth& curvature);
    shp::Azimuth getTemporalChange() const;
    void setTemporalChange(const shp::Azimuth& phase);
    void setTemporalChange(const shp::Signal& signal);
    void setTemporalChange(const float magnitude);
    void setTemporalChange(const float magnitude, const short int scale);
    void setTemporalChange(const float magnitude, const short int scale, const std::string unit);
    void setTemporalChange(const float magnitude, const short int scale, const shp::Unit& unit);
    shp::Angular getOrigin() const;
    void setOrigin(const shp::Angular& source);
    shp::Distance getRadius() const;
    void setRadius(const shp::Distance& length);
    void setRadius(const float length);
    void setRadius(const float length, const short int scale);
    void setRadius(const float length, const short int scale, const std::string unit);
    void setRadius(const float length, const short int scale, const shp::Unit& unit);
    shp::Azimuth getLinear() const;
    void setLinear(const shp::Azimuth& orientation);
    shp::Polar getCircular() const;
    void setCircular(const shp::Polar& orientation);
    void changePoint(const Action& action);
    std::shared_ptr<Particle> getDivergence(const Action& action) const;
    std::shared_ptr<Particle> getConvergence(const Action& action) const;
    shp::Temporal getTotal() const;
    virtual Time copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    Time getFluctuation(const float phase) const;
public:
    static const std::shared_ptr<qft::Field> shareable(const std::string name,
        const float magnitude, const short int scaling);
};

typedef std::vector<Field > FieldArray;

} // namespace qft

#endif //QFT_FIELD_H