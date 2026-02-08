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

#include "polygon.h"

namespace shp {

const int Polygon::DEFAULT_LIMIT = 0;

Polygon::Polygon()
        : Point(Direction::DEFAULT_RADIANS), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const Intrinsic& gradient)
        : Point(gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude)
        : Point(magnitude, Direction::DEFAULT_RADIANS), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling)
        : Point(magnitude, scaling, Direction::DEFAULT_RADIANS), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling, const std::string unit)
        : Point(magnitude, scaling, unit), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling, const Unit& unit)
        : Point(magnitude, scaling, unit), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const Intrinsic& gradient)
        : Point(magnitude, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling, const Intrinsic& gradient)
        : Point(magnitude, scaling, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling, const std::string unit, const Intrinsic& gradient)
        : Point(magnitude, scaling, unit, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const float magnitude, const short int scaling, const Unit& unit, const Intrinsic& gradient)
        : Point(magnitude, scaling, unit, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name)
        : Point(name), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const Intrinsic& gradient)
        : Point(name, gradient), waves(), limit(0) {

}

Polygon::Polygon(const std::string name, const float magnitude)
        : Point(name, magnitude, Direction::DEFAULT_RADIANS), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling)
        : Point(name, magnitude, scaling), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling, const std::string unit)
        : Point(name, magnitude, scaling, unit), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling, const Unit& unit)
        : Point(name, magnitude, scaling, unit), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const Intrinsic& gradient)
        : Point(name, magnitude, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling, const std::string unit, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, unit, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const float magnitude, const short int scaling, const Unit& unit, const Intrinsic& gradient)
        : Point(name, magnitude, scaling, unit, gradient), waves(), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const Intrinsic& gradient, const int limit)
        : Point(name, gradient), waves(), limit(limit) {

}

Polygon::Polygon(const std::string name, const WaveArray& waves)
        : Point(name), waves(waves), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const WaveArray& waves, const float gradient)
        : Point(name, gradient), waves(waves), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const WaveArray& waves, const Intrinsic& gradient)
        : Point(name, gradient), waves(waves), limit(DEFAULT_LIMIT) {

}

Polygon::Polygon(const std::string name, const WaveArray& waves, const float gradient, const int limit)
        : Point(name, gradient), waves(waves), limit(limit) {

}

Polygon::Polygon(const std::string name, const WaveArray& waves, const Intrinsic& gradient, const int limit)
        : Point(name, gradient), waves(waves), limit(limit) {

}

Polygon::~Polygon() {

}

bool Polygon::operator==(const Polygon& peer) const {
    return (static_cast<const Point&>(*this) == static_cast<const Point&>(peer))
        && (limit == peer.limit) && (waves == peer.waves);
}

bool Polygon::operator<(const Polygon& peer) const {
    return (static_cast<const Point&>(*this) < static_cast<const Point&>(peer))
        && (limit < peer.limit) && (waves < peer.waves);
}

bool Polygon::operator>(const Polygon& peer) const {
    return (static_cast<const Point&>(*this) > static_cast<const Point&>(peer))
        && (limit > peer.limit) && (waves > peer.waves);
}

bool Polygon::operator<=(const Polygon& peer) const {
    Polygon self = *this;
    return (self < peer) || (self == peer);
}

bool Polygon::operator>=(const Polygon& peer) const {
    Polygon self = *this;
    return (self > peer) || (self == peer);
}

Polygon Polygon::operator+(const Polygon& peer) const {
    WaveArray result(waves);
    result.insert(result.end(), peer.waves.begin(), peer.waves.end());
    return Polygon("+", result, (getGradient() + peer.getGradient()), limit);
}

Polygon Polygon::operator-(const Polygon& peer) const {
    WaveArray result(waves);
    for (WaveArray::const_iterator it = peer.waves.begin(); it != peer.waves.end(); ++it) {
        WaveArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Polygon("-", result, (getGradient() - peer.getGradient()), limit);
}

int Polygon::getWaveCount() const {
    return waves.size();
}

Wave Polygon::get(const int index) const {
    Wave result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(waves.size())) {
        return result;
    }
    return waves[index];
}

void Polygon::set(const int index, const Wave& object) {
    if (index < 0 || index >= limit) {
        return;
    }
    if (index < static_cast<int>(waves.size())) {
        // replace existing element
        waves[index] = object;
    } else if (index == static_cast<int>(waves.size())) {
        // append at end
        waves.push_back(object);
    } else {
        // index beyond current size: append at end
        waves.push_back(object);
    }
    return;
}

void Polygon::setMultiPhase() {
    Polygon self = *this; waves.clear();  // cleanup past allocations
    if (limit > 0) {
        Direction angle = Direction::getSectorAngle(limit);
        for (int index=0; index < limit; index++) {
            std::string name = "S" + std::to_string(index+1);
            shp::Wave side(name, self.getMagnitude(), self.getScaling(), Intrinsic(index * angle.toRadians()));
            this->set(index, side);
        }
    }
}

void Polygon::setRotation(const float degree) {
    int index = 0;
    for (WaveArray::const_iterator it = waves.begin(); it != waves.end(); ++it, index++) {
        Wave wave = (*it);
        wave.setIntrinsic((wave.getIntrinsic() + (Direction::DEGREE_001 * degree)));
        this->set(index, wave);
    }
}

Point Polygon::copy() {
    Point self = *this;
    Polygon fresh(self.getName(), this->waves, self.getGradient(), this->limit);
    return fresh;
}

void Polygon::clear() {
    Point::clear();
    limit = DEFAULT_LIMIT;
    waves.clear();
    return;
}

std::string Polygon::print() const {
    std::stringstream result;
    result << "[ψ";
	result << Point::print() << "→";
    result << limit;
	result << "]";
    result << printWaves();
	return result.str();
}

std::string Polygon::printRadians() const {
    std::stringstream result;
    result << "[ψ";
	result << Point::printRadians() << "→";
    result << limit;
	result << "]";
    result << printWaveRadians();
	return result.str();
}

std::string Polygon::printWaves() const {
    std::stringstream result; int size = waves.size();
    if (size > 0) {
        result << ",sz:";
	    result << waves.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << waves[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

std::string Polygon::printWaveRadians() const {
    std::stringstream result; int size = waves.size();
    if (size > 0) {
        result << ",sz:";
	    result << waves.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << waves[i].printRadians() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

Direction Polygon::getLoopAngle() const {
    Direction result; int size = waves.size();
    if (size > 0) {
        result = Direction::getSectorAngle(size);
    }
    return result;
}

} // namespace shp