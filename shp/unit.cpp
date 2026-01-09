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
const std::string Unit::PER_UNIT = "/";

const short int Unit::PREFIX_MIN = 0;
const short int Unit::PREFIX_MAX = 25;
const std::string Unit::PREFIX_NAME[] = {
    "quetta", "ronna", "yotta", "zetta", "exa", "peta", "tera", "giga", "mega", "kilo", "hecto", "deca",
    "zero",
    "deci", "centi", "milli", "micro", "nano", "pico", "femto", "atto", "zepto", "yocto", "ronto", "quecto",
};
const std::string Unit::PREFIX_SYMBOL[] = {
    "Q", "R", "Y", "Z", "E", "P", "T", "G", "M", "k", "h", "da",
    "",
    "d", "c", "m", "μ", "n", "p", "f", "a", "z", "y", "r", "q",
};
const short int Unit::PREFIX_BASE[] = {
    30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 2, 1,
    0,
    -1, -2, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30,
};

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

Unit Unit::operator+(const Unit& peer) const {
    return (name + peer.name);
}

const std::string Unit::getPrefixName(short int index) {
    if ((index >= PREFIX_MIN) && (index < PREFIX_MAX)) {
        return PREFIX_NAME[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getBaseName(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_NAME[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getPrefixSymbol(short int index) {
    if ((index >= PREFIX_MIN) && (index < PREFIX_MAX)) {
        return PREFIX_SYMBOL[index];
    } else {
        return UNKNOWN;
    }
}

const short int Unit::getPrefixBase(short int index) {
    if ((index >= PREFIX_MIN) && (index < PREFIX_MAX)) {
        return PREFIX_BASE[index];
    } else {
        return 0;
    }
}

const std::string Unit::getBaseDimension(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_DIMENSION[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getBaseSymbol(short int index) {
    if ((index >= SI_BASE_MIN) && (index < SI_BASE_MAX)) {
        return BASE_SYMBOL[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getDerivedName(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_NAME[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getDerivedDimension(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_DIMENSION[index];
    } else {
        return UNKNOWN;
    }
}

const std::string Unit::getDerivedSymbol(short int index) {
    if ((index >= SI_DERIVED_MIN) && (index < SI_DERIVED_MAX)) {
        return DERIVED_SYMBOL[index];
    } else {
        return UNKNOWN;
    }
}

std::string Unit::getInverse() const {
    return (PER_UNIT + name);
}

std::string Unit::getPercent() const {
    return (name + "%");
}

std::string Unit::getSquare() const {
    return (name + "²");
}

std::string Unit::getSquareRoot() const {
    return ("√" + name);
}

std::string Unit::getCube() const {
    return (name + "³");
}

std::string Unit::getCubeRoot() const {
    return ("∛" + name);
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