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

#include "rgb.h"
#include "cmy.h"

namespace img {

const char RGB::BYTE_FILL = '0';
const short int RGB::BYTE_WIDTH = 2;
const short int RGB::BYTE_MIN = 0;
const short int RGB::BYTE_MAX = 255;
const float RGB::BYTE_FLT_MAX = 255.0f;
const float RGB::CODE_FLT_MAX = 100.0f;
const float RGB::COLOUR_MIN = 0.0f;
const float RGB::COLOUR_MAX = 1.0f;

RGB::RGB()
        : red(COLOUR_MIN), green(COLOUR_MIN), blue(COLOUR_MIN) {

}

RGB::RGB(const float red)
        : red(getIndexed(red)), green(COLOUR_MIN), blue(COLOUR_MIN) {

}

RGB::RGB(const float red, const float green)
        : red(getIndexed(red)), green(getIndexed(green)), blue(COLOUR_MIN) {

}

RGB::RGB(const float red, const float green, const float blue)
        : red(getIndexed(red)), green(getIndexed(green)), blue(getIndexed(blue)) {

}

RGB::~RGB() {

}

bool RGB::operator==(const RGB& peer) const {
    return (red == peer.red) && (green == peer.green) && (blue == peer.blue);
}

RGB RGB::operator+(const RGB& peer) const {
    return RGB(getByteCode(red + peer.red),
            getByteCode(green + peer.green),
            getByteCode(blue + peer.blue));
}

RGB RGB::operator-(const RGB& peer) const {
    return RGB(getByteCode(red - peer.red),
            getByteCode(green - peer.green),
            getByteCode(blue - peer.blue));
}

RGB RGB::operator*(const RGB& peer) const {
    return RGB(getByteCode(red * peer.red),
            getByteCode(green * peer.green),
            getByteCode(blue * peer.blue));
}

RGB RGB::operator/(const RGB& peer) const {
    return RGB(getByteCode(red / peer.red),
            getByteCode(green / peer.green),
            getByteCode(blue / peer.blue));
}

RGB RGB::operator%(const RGB& peer) const {
    return RGB(getByteCode(fmod(red, peer.red)),
            getByteCode(fmod(green, peer.green)),
            getByteCode(fmod(blue, peer.blue)));
}

RGB RGB::getBlackColour() const {
    return RGB(COLOUR_MIN, COLOUR_MIN, COLOUR_MIN);
}

RGB RGB::getWhiteColour() const {
    return RGB(COLOUR_MAX, COLOUR_MAX, COLOUR_MAX);
}

RGB RGB::copy() {
    RGB fresh(red, green, blue);
    return fresh;
}

void RGB::clear() {
    red = green = blue = COLOUR_MIN;
    return;
}

std::string RGB::toByte() {
    short int r = getByteIndex(static_cast<short int>(getByteCode(red)));
    short int g = getByteIndex(static_cast<short int>(getByteCode(green)));
    short int b = getByteIndex(static_cast<short int>(getByteCode(blue)));
    std::stringstream result;
    result << "(" << r << "," << g << "," << b << ")";
    return result.str();
}

std::string RGB::toDecimal() {
    std::stringstream result;
    result << "(" << red << "," << green << "," << blue << ")";
    return result.str();
}

std::string RGB::toHex() {
    short int r = getByteIndex(static_cast<short int>(getByteCode(red)));
    short int g = getByteIndex(static_cast<short int>(getByteCode(green)));
    short int b = getByteIndex(static_cast<short int>(getByteCode(blue)));
    std::stringstream result;
    result << "#";
    result << std::hex << std::uppercase;
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << r;
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << g;
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << b;
    return result.str();
}

std::string RGB::print() {
    std::stringstream result;
    result << "(";
    result << toHex();
    result << ")";
	return result.str();
}

const float RGB::getWhiteness(const RGB& colour) {
    float rg = std::min(colour.red, colour.green);
    float gb = std::min(colour.green, colour.blue);
    float rb = std::min(rg, gb);
    return (COLOUR_MIN + rb);
}

const float RGB::getBlackness(const RGB& colour) {
    float rg = std::max(colour.red, colour.green);
    float gb = std::max(colour.green, colour.blue);
    float rb = std::max(rg, gb);
    return (COLOUR_MAX - rb);
}

const CMY RGB::getModel(const RGB& colour) {
    float cyan, magenta, yellow, key = colour.getBlackness(colour);
    if (key == COLOUR_MAX) {
        cyan = magenta = yellow = COLOUR_MIN;
    } else {
        cyan = (COLOUR_MAX - colour.red - key) / (COLOUR_MAX - key);
        magenta = (COLOUR_MAX - colour.green - key) / (COLOUR_MAX - key);
        yellow = (COLOUR_MAX - colour.blue - key) / (COLOUR_MAX - key);
    }
    CMY result(getByteCode(cyan), getByteCode(magenta), getByteCode(yellow), getByteCode(key));
    return result;
}

const short int RGB::getByteIndex(const short int value) {
    return std::fmax(BYTE_MIN, std::fmin(BYTE_MAX, value));
}

const float RGB::getIndexed(const float value) {
    return std::fmax(COLOUR_MIN, std::fmin(COLOUR_MAX, (value / BYTE_FLT_MAX)));
}

const float RGB::getByteCode(const float value) {
    return (value * BYTE_FLT_MAX);
}

} // namespace img