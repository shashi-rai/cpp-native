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
#include "charge.h"
#include "mass.h"
#include "particle.h"
#include "../shp/cellular.h"
#include "../shp/potential.h"

namespace qft {

// To enable compiler resolve forward declarations
class Charge;
class Mass;

class Field : public shp::Temporal {
    std::shared_ptr<shp::Cellular> physical;
    shp::Potential potential;
    shp::Angular orientation;
public:
    // Constructors
    Field();
    Field(const std::string name);
    Field(const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Potential potential);
    Field(const shp::Potential potential, const std::shared_ptr<shp::Cellular> physical);
    Field(const float azimuth);
    Field(const float azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Azimuth& azimuth);
    Field(const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Polar& azimuth);
    Field(const shp::Polar& azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Angular& orientation);
    Field(const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const float potential, const float azimuth);
    Field(const float potential, const float azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Potential& potential, const shp::Azimuth& azimuth);
    Field(const shp::Potential& potential, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Potential& potential, const shp::Polar& polar);
    Field(const shp::Potential& potential, const shp::Polar& polar,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Potential& potential, const shp::Polar& polar,
        const shp::Azimuth& azimuth);
    Field(const shp::Potential& potential, const shp::Polar& polar,
        const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Potential& potential, const shp::Angular& orientation);
    Field(const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Signal& modulation,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Signal& modulation, const shp::Azimuth& phase,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const shp::Signal& modulation, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Potential potential);
    Field(const std::string name, const shp::Potential potential,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const float azimuth);
    Field(const std::string name, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Polar& polar);
    Field(const std::string name, const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const float azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Polar& polar,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Polar& polar,
        const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const float potential, const float azimuth);
    Field(const std::string name, const float potential,
        const float azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Azimuth& azimuth, const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Polar& polar, const shp::Azimuth& azimuth,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Angular& orientation);
    Field(const std::string name, const shp::Potential& potential,
        const shp::Angular& orientation, const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Signal& modulation,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Signal& modulation, const shp::Azimuth& phase,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name,
        const float magnitude, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);
    Field(const std::string name, const shp::Signal& modulation, const shp::Azimuth& phase,
        const float magnitude, const short int scaling, const shp::Unit& unit,
        const shp::Potential& potential, const shp::Angular& orientation,
        const std::shared_ptr<shp::Cellular> physical);

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
    shp::Point operator()(const int x, const int y, const int z);
	const shp::Point operator()(const int x, const int y, const int z) const;
    shp::Signal operator()(const Field& peer,
        const shp::Distance& separation, const shp::Distance& position) const;
    shp::Signal operator()(const Field& peerX, const Field& peerY,
        const shp::Distance& separationX, const shp::Distance& separationY) const;

    // Getters
    std::shared_ptr<shp::Cellular> getPhysical() const { return physical; }
    shp::Potential getPotential() const { return potential; }
    shp::Angular getOrientation() const { return orientation; }

    // Setters
    void setPhysical(const std::shared_ptr<shp::Cellular> structure) { this->physical = structure; }
    void setPotential(const shp::Potential& difference) { this->potential = difference; }
    void setOrientation(const shp::Angular& direction) { this->orientation = direction; }

    // Additional methods
    std::string getFieldLabel() const;
    void setFieldLabel(const std::string name);
    bool isStructured() const;
    shp::Distance getRadius() const;
    void setRadius(const shp::Distance& length);
    shp::Direction getLinear() const;
    void setLinear(const shp::Direction& azimuth);
    shp::Direction getCircular() const;
    void setCircular(const shp::Direction& azimuth);
    void changePoint(const Action& action);
    std::shared_ptr<Particle> getDivergence(const Action& action) const;
    std::shared_ptr<Particle> getConvergence(const Action& action) const;
    shp::Temporal getTotal() const;
    virtual shp::Temporal copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printRadians() const;
    shp::Temporal getFluctuation(const float phase) const;
public:
    static std::shared_ptr<qft::Field> shareable(const std::string name);
};

typedef std::vector<Field > FieldArray;

} // namespace qft

#endif //QFT_FIELD_H