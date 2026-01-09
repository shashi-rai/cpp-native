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

#include "direction.h"

namespace shp {

const float Direction::DEFAULT_RADIANS = 0.000000000000000000f;
const short int Direction::DEGREES_MIN = 0;
const short int Direction::DEGREES_MAX = 360;
const short int Direction::MINUTES_MIN = 0;
const short int Direction::MINUTES_MAX = 60;
const short int Direction::SECONDS_MIN = 0;
const short int Direction::SECONDS_MAX = 3600;

const float Direction::DEGREE_001 = 0.017453292519943295f;
const float Direction::DEGREE_005 = 0.087266462599716000f;
const float Direction::DEGREE_010 = 0.174532925199432950f;
const float Direction::DEGREE_030 = 0.523598775598299000f;
const float Direction::DEGREE_045 = 0.785398163397448000f;
const float Direction::DEGREE_060 = 1.047197551196598000f;
const float Direction::DEGREE_090 = 1.570796326794897000f;
const float Direction::DEGREE_180 = 3.141592653589793000f;
const float Direction::DEGREE_270 = 4.712388980384690000f;
const float Direction::DEGREE_360 = 6.283185307179586000f;

Direction::Direction()
        : degrees(DEGREES_MIN), minutes(MINUTES_MIN), seconds(SECONDS_MIN) {

}

/*
 * Used for converting radians to degrees, minutes, seconds
 */
Direction::Direction(const float radians) {
    float deciDegrees = radians * (180.0 / M_PI);
    degrees = getIndexDegrees(static_cast<int>(deciDegrees));
    float fraDegrees = deciDegrees - degrees;

    float deciMinutes = fraDegrees * 60.0;
    minutes = getIndexMinutes(static_cast<int>(deciMinutes));
    float fraMinutes = deciMinutes - minutes;

    float deciSeconds = fraMinutes * 60.0;
    seconds = getIndexSeconds(static_cast<int>(round(deciSeconds)));
}

Direction::Direction(const short int degrees)
        : degrees(getIndexDegrees(degrees)), minutes(0), seconds(0) {

}

Direction::Direction(const short int degrees, const short int minutes)
        : degrees(getIndexDegrees(degrees)),
        minutes(getIndexMinutes(minutes)), seconds(0) {

}

Direction::Direction(const short int degrees, const short int minutes, const short int seconds)
        : degrees(getIndexDegrees(degrees)),
        minutes(getIndexMinutes(minutes)), seconds(getIndexSeconds(seconds)) {

}

Direction::~Direction() {

}

bool Direction::operator==(const Direction& peer) const {
    return (degrees == peer.degrees) &&
            (minutes == peer.minutes) &&
            (seconds == peer.seconds);
}

Direction Direction::operator+(const Direction& peer) const {
    return Direction(getIndexDegrees(degrees + peer.degrees),
            getIndexMinutes(minutes + peer.minutes),
            getIndexSeconds(seconds + peer.seconds));
}

Direction Direction::operator-(const Direction& peer) const {
    return Direction(getIndexDegrees(degrees - peer.degrees),
            getIndexMinutes(minutes - peer.minutes),
            getIndexSeconds(seconds - peer.seconds));
}

Direction Direction::operator*(const Direction& peer) const {
    return Direction(getIndexDegrees(degrees * peer.degrees),
            getIndexMinutes(minutes * peer.minutes),
            getIndexSeconds(seconds * peer.seconds));
}

Direction Direction::operator/(const Direction& peer) const {
    return Direction(getIndexDegrees(degrees / peer.degrees),
            getIndexMinutes(minutes / peer.minutes),
            getIndexSeconds(seconds / peer.seconds));
}

Direction Direction::operator%(const Direction& peer) const {
    return Direction(getIndexDegrees(degrees % peer.degrees),
            getIndexMinutes(minutes % peer.minutes),
            getIndexSeconds(seconds % peer.seconds));
}

float Direction::getCyclingRate() const {
    return (toRadians() / (2 * M_PI));
}

float Direction::getTimePerCycle() const {
    return ((2 * M_PI) / toRadians());
}

float Direction::toRadians() const {
    // compute total degrees as floating-point to avoid integer division,
    // then convert degrees to radians
    float total = degrees + (minutes / 60.0f) + (seconds / 3600.0f);
    return (total * (M_PI / 180.0f));
}

bool Direction::checkNonZero() const {
    return ((seconds != SECONDS_MIN) || (minutes != MINUTES_MIN) || (degrees != DEGREES_MIN));

}

Direction Direction::getInverse() const {
    return Direction((toRadians() + DEGREE_180));
}

Direction Direction::getNormal() const {
    return Direction((toRadians() + DEGREE_090));
}

Direction Direction::getRotation(const short int degree) const {
    return Direction((toRadians() + (DEGREE_001 * degree)));
}

Direction Direction::copy() const {
    Direction fresh(degrees, minutes, seconds);
    return fresh;
}

void Direction::clear() {
    degrees = DEGREES_MIN; minutes = MINUTES_MIN; seconds = SECONDS_MIN;
    return;
}

std::string Direction::print() {
    std::stringstream result;
    result << "[";
    result << degrees << ",";
    result << minutes << ",";
    result << seconds << "]";
	return result.str();
}

/*
 * Used for converting degrees between 0 ~ 360
 */
short int Direction::getIndexDegrees(const short int value) const {
    int result = (value % DEGREES_MAX);
    if (value >= MINUTES_MIN)
        return result;
    else
        return (DEGREES_MAX + result);
}

/*
 * Used for converting minutes between 0 ~ 60
 */
short int Direction::getIndexMinutes(const short int value) const {
    int result = (value % MINUTES_MAX);
    if (value >= MINUTES_MIN)
        return result;
    else
        return (MINUTES_MAX + result);
}

/*
 * Used for converting seconds between 0 ~ 3600
 */
short int Direction::getIndexSeconds(const short int value) const {
    int result = (value % SECONDS_MAX);
    if (value >= SECONDS_MIN)
        return result;
    else
        return (SECONDS_MAX + result);
}

} // namespace shp