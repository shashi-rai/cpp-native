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

#include "cmy.h"
#include "rgb.h"

namespace img {

const char CMY::BYTE_FILL = '0';
const short int CMY::BYTE_WIDTH = 2;
const short int CMY::BYTE_MIN = 0;
const short int CMY::BYTE_MAX = 255;
const float CMY::BYTE_FLT_MAX = 255.0f;
const float CMY::CODE_FLT_MAX = 100.0f;
const float CMY::COLOUR_MIN = 0.0f;
const float CMY::COLOUR_MAX = 1.0f;

CMY::CMY()
        : cyan(COLOUR_MIN), magenta(COLOUR_MIN), yellow(COLOUR_MIN), key(COLOUR_MIN) {

}

CMY::CMY(const float cyan)
        : cyan(getIndexed(cyan)), magenta(COLOUR_MIN), yellow(COLOUR_MIN), key(COLOUR_MIN) {

}

CMY::CMY(const float cyan, const float magenta)
        : cyan(getIndexed(cyan)), magenta(getIndexed(magenta)), yellow(COLOUR_MIN), key(COLOUR_MIN) {

}

CMY::CMY(const float cyan, const float magenta, const float yellow)
        : cyan(getIndexed(cyan)), magenta(getIndexed(magenta)), yellow(getIndexed(yellow)), key(COLOUR_MIN) {

}

CMY::CMY(const float cyan, const float magenta, const float yellow, const float key)
        : cyan(getIndexed(cyan)), magenta(getIndexed(magenta)), yellow(getIndexed(yellow)), key(key) {

}

CMY::~CMY() {

}

bool CMY::operator==(const CMY& peer) const {
    return (cyan == peer.cyan) && (magenta == peer.magenta) && (yellow == peer.yellow)
        && (key == peer.key);
}

CMY CMY::operator+(const CMY& peer) const {
    return CMY(getByteCode(cyan + peer.cyan),
            getByteCode(magenta + peer.magenta),
            getByteCode(yellow + peer.yellow),
            getByteCode(key + peer.key));
}

CMY CMY::operator-(const CMY& peer) const {
    return CMY(getByteCode(cyan - peer.cyan),
            getByteCode(magenta - peer.magenta),
            getByteCode(yellow - peer.yellow),
            getByteCode(key - peer.key));
}

CMY CMY::operator*(const CMY& peer) const {
    return CMY(getByteCode(cyan * peer.cyan),
            getByteCode(magenta * peer.magenta),
            getByteCode(yellow * peer.yellow),
            getByteCode(key * peer.key));
}

CMY CMY::operator/(const CMY& peer) const {
    return CMY(getByteCode(cyan / peer.cyan),
            getByteCode(magenta / peer.magenta),
            getByteCode(yellow / peer.yellow),
            getByteCode(key / peer.key));
}

CMY CMY::operator%(const CMY& peer) const {
    return CMY(getByteCode(fmod(cyan, peer.cyan)),
            getByteCode(fmod(magenta, peer.magenta)),
            getByteCode(fmod(yellow, peer.yellow)),
            getByteCode(fmod(key, peer.key)));
}

CMY CMY::getBlackColour() const {
    return CMY(COLOUR_MIN, COLOUR_MIN, COLOUR_MIN, COLOUR_MAX);
}

CMY CMY::getWhiteColour() const {
    return CMY(COLOUR_MIN, COLOUR_MIN, COLOUR_MIN, COLOUR_MIN);
}

CMY CMY::copy() {
    CMY fresh(cyan, magenta, yellow, key);
    return fresh;
}

void CMY::clear() {
    cyan = magenta = yellow = key = COLOUR_MIN;
    return;
}

std::string CMY::toByte() {
    short int c = getByteIndex(static_cast<short int>(getByteCode(cyan)));
    short int m = getByteIndex(static_cast<short int>(getByteCode(magenta)));
    short int y = getByteIndex(static_cast<short int>(getByteCode(yellow)));
    short int k = getByteIndex(static_cast<short int>(getByteCode(key)));
    std::stringstream result;
    result << "(" << c << "," << m << "," << y << "," << k << ")";
    return result.str();
}

std::string CMY::toDecimal() {
    std::stringstream result;
    result << "(" << cyan << "," << magenta << "," << yellow << "," << key << ")";
    return result.str();
}

std::string CMY::toHex() {
    CMY self = *this;
    float c, m, y, k = getBlackness(self);
    if (k == COLOUR_MAX) {
        c = m = y = COLOUR_MIN;
    } else {
        c = (COLOUR_MAX - cyan - k) / (COLOUR_MAX - k);
        m = (COLOUR_MAX - magenta - k) / (COLOUR_MAX - k);
        y = (COLOUR_MAX - yellow - k) / (COLOUR_MAX - k);
    }
    std::stringstream result;
    result << "#";
    result << std::hex << std::uppercase;
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << getByteIndex(static_cast<short int>(CODE_FLT_MAX * c));
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << getByteIndex(static_cast<short int>(CODE_FLT_MAX * m));
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << getByteIndex(static_cast<short int>(CODE_FLT_MAX * y));
    result << std::setw(BYTE_WIDTH) << std::setfill(BYTE_FILL) << getByteIndex(static_cast<short int>(CODE_FLT_MAX * k));
    return result.str();
}

std::string CMY::print() {
    std::stringstream result;
    result << "(" << toHex() << ")";
	return result.str();
}

const float CMY::getWhiteness(const CMY& colour) {
    float cm = std::min(colour.cyan, colour.magenta);
    float my = std::min(colour.magenta, colour.yellow);
    float cy = std::min(cm, my);
    return (COLOUR_MIN + cy);
}

const float CMY::getBlackness(const CMY& colour) {
    float cm = std::max(colour.cyan, colour.magenta);
    float my = std::max(colour.magenta, colour.yellow);
    float cy = std::max(cm, my);
    return (COLOUR_MAX - cy);
}

const RGB CMY::getModel(const CMY& colour) {
    float middle = (COLOUR_MAX / 2);
    short int red = static_cast<int>(getByteCode((COLOUR_MAX - colour.cyan) * (COLOUR_MAX - colour.key) + middle));
    short int green = static_cast<int>(getByteCode((COLOUR_MAX - colour.magenta) * (COLOUR_MAX - colour.key) + middle));
    short int blue = static_cast<int>(getByteCode((COLOUR_MAX - colour.yellow) * (COLOUR_MAX - colour.key) + middle));
    RGB result(red, green, blue);
    return result;
}

const short int CMY::getByteIndex(const short int value) {
    return std::fmax(BYTE_MIN, std::fmin(BYTE_MAX, value));
}

const float CMY::getIndexed(const float value) {
    return std::fmax(COLOUR_MIN, std::fmin(COLOUR_MAX, (value / BYTE_FLT_MAX)));
}

const float CMY::getByteCode(const float value) {
    return (value * BYTE_FLT_MAX);
}

} // namespace img