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

const int Direction::DEGREES_MIN = 0;
const int Direction::DEGREES_MAX = 360;
const int Direction::MINUTES_MIN = 0;
const int Direction::MINUTES_MAX = 60;
const int Direction::SECONDS_MIN = 0;
const int Direction::SECONDS_MAX = 3600;

Direction::Direction()
        : degrees(DEGREES_MIN), minutes(MINUTES_MIN), seconds(SECONDS_MIN) {

}

/*
 * Used for converting radians to degrees, minutes, seconds
 */
Direction::Direction(float radians) {
    float deciDegrees = radians * (180.0 / M_PI);
    degrees = getIndexDegrees(static_cast<int>(deciDegrees));
    float fraDegrees = deciDegrees - degrees;

    float deciMinutes = fraDegrees * 60.0;
    minutes = getIndexMinutes(static_cast<int>(deciMinutes));
    float fraMinutes = deciMinutes - minutes;

    float deciSeconds = fraMinutes * 60.0;
    seconds = getIndexSeconds(static_cast<int>(round(deciSeconds)));
}

Direction::Direction(int degrees)
        : degrees(getIndexDegrees(degrees)), minutes(0), seconds(0) {

}

Direction::Direction(int degrees, int minutes)
        : degrees(getIndexDegrees(degrees)),
        minutes(getIndexMinutes(minutes)), seconds(0) {

}

Direction::Direction(int degrees, int minutes, int seconds)
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

float Direction::toRadians() const {
    // compute total degrees as floating-point to avoid integer division,
    // then convert degrees to radians
    float total = degrees + (minutes / 60.0f) + (seconds / 3600.0f);
    return (total * (M_PI / 180.0f));
}

Direction Direction::copy() {
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
int Direction::getIndexDegrees(const int value) const {
    int result = (value % DEGREES_MAX);
    if (value >= MINUTES_MIN)
        return result;
    else
        return (DEGREES_MAX + result);
}

/*
 * Used for converting minutes between 0 ~ 60
 */
int Direction::getIndexMinutes(const int value) const {
    int result = (value % MINUTES_MAX);
    if (value >= MINUTES_MIN)
        return result;
    else
        return (MINUTES_MAX + result);
}

/*
 * Used for converting seconds between 0 ~ 3600
 */
int Direction::getIndexSeconds(const int value) const {
    int result = (value % SECONDS_MAX);
    if (value >= SECONDS_MIN)
        return result;
    else
        return (SECONDS_MAX + result);
}

} // namespace shp