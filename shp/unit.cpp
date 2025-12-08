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

#include "unit.h"

namespace shp {

const std::string Unit::UNKNOWN = "";

const short int Unit::SI_BASE_MIN = 0;
const short int Unit::SI_BASE_MAX = 7;

const std::string Unit::BASE_NAME[] = {
    "time", "length", "mass", "electric current", "temperature",
    "amount of substance", "luminous intensity",
};

const std::string Unit::BASE_DIMENSION[] = {
    "T", "L", "M", "I", "Θ", "N", "J",
};

const std::string Unit::BASE_SYMBOL[] = {
    "s", "m", "kg", "A", "K", "mol", "cd"
};

const short int Unit::SI_DERIVED_MIN = 0;
const short int Unit::SI_DERIVED_MAX = 22;

const std::string Unit::DERIVED_NAME[] = {
    "plane angle", "solid angle", "frequency", "force", "pressure", "energy",
    "power", "electric charge", "electric potential difference", "capacitance",
    "electrical resistance", "electrical conductance", "magnetic flux",
    "magnetic flux density", "inductance", "Celsius temperature",
    "luminous flux", "illuminance", "activity referred to a radionuclide",
    "absorbed dose", "dose equivalent", "catalytic activity",
};

const std::string Unit::DERIVED_DIMENSION[] = {
    "radian", "steradian", "hertz", "newton", "pascal", "joule", "watt", "coulomb",
    "volt", "farad", "ohm", "siemens", "weber", "tesla", "henry", "celsius",
    "lumen", "lux", "becquerel", "gray", "sievert", "katal",
};

const std::string Unit::DERIVED_SYMBOL[] = {
    "rad", "sr", "Hz", "N", "Pa", "J", "W", "C", "V", "F", "Ω", "S", "Wb", "T",
    "H", "°C", "lm", "lx", "Bq", "Gy", "Sv", "kat",
};

Unit::Unit() : name(UNKNOWN) {

}

Unit::Unit(std::string name) : name(name) {

}

Unit::~Unit() {

}

bool Unit::operator==(const Unit& peer) const {
    return (name == peer.name);
}

std::string Unit::getBaseName(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_NAME[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getBaseDimension(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_DIMENSION[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getBaseSymbol(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_SYMBOL[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getDerivedName(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_NAME[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getDerivedDimension(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_DIMENSION[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getDerivedSymbol(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_SYMBOL[index];
    } else {
        return UNKNOWN;
    }
}

Unit Unit::copy() {
    Unit fresh(name);
    return fresh;
}

void Unit::clear() {
    name = UNKNOWN;
    return;
}

std::string Unit::print() {
    std::stringstream result;
    result << name;
	return result.str();
}

} // namespace shp