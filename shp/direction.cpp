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

const float Direction::DEFAULT_RADIANS = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000f;
const short int Direction::DEGREES_MIN = 0;
const short int Direction::DEGREES_MAX = 360;
const short int Direction::MINUTES_MIN = 0;
const short int Direction::MINUTES_MAX = 60;
const short int Direction::SECONDS_MIN = 0;
const short int Direction::SECONDS_MAX = 3600;

const float Direction::DEGREE_001 = 0.01745329251994329576923690768488612713442871888541725456097191440171009114603449443682241569634509482000f;
const float Direction::DEGREE_005 = 0.08726646259971647000000000000000000000000000000000000000000000000000000000000000000000000000000000000000f;
const float Direction::DEGREE_010 = 0.17453292519943295769236907684886127134428718885417254560971914401710091146034494436822415696345094820000f;
const float Direction::DEGREE_030 = 0.52359877559829887307710723054658381403286156656251763682915743205130273438103483310467247089035284460000f;
const float Direction::DEGREE_045 = 0.78539816339744830961566084581987572104929234984381014855260173666687445771661358586419309459800262624510f;
const float Direction::DEGREE_060 = 1.04719755119659770533265448951472838719685872395833333333333333333333333333333333333333333333333333333333f;
const float Direction::DEGREE_090 = 1.57079632679489655799898173427209258079528808593750000000000000000000000000000000000000000000000000000000f;
const float Direction::DEGREE_180 = 3.14159265358979323846264338327950288419716939937510582097494000000000000000000000000000000000000000000000f;
const float Direction::DEGREE_270 = 4.71238898038469000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000f;
const float Direction::DEGREE_360 = 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413600000f;

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
    Direction result(this->toRadians() / peer.toRadians());
    return Direction(getIndexDegrees(result.degrees),
            getIndexMinutes(result.minutes),
            getIndexSeconds(result.seconds));
}

Direction Direction::operator%(const Direction& peer) const {
    Direction result(fmod(this->toRadians(), peer.toRadians()));
    return Direction(getIndexDegrees(result.degrees),
            getIndexMinutes(result.minutes),
            getIndexSeconds(result.seconds));
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

Direction Direction::getMultiple(const float coefficient) const {
    float result = (toRadians() * coefficient);
    return Direction(result);
}

Direction Direction::getDivision(const float coefficient) const {
    float result = 0.0f;
    if (coefficient != 0.0f) {
        result = (toRadians() / coefficient);
    }
    return Direction(result);
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

const float Direction::getHalfPiAngle(const float radians) {
    return fmod(radians, Direction::DEGREE_090);
}

const float Direction::getFullPiAngle(const float radians) {
    return fmod(radians, Direction::DEGREE_180);
}

const float Direction::getTwoPiAngle(const float radians) {
    return fmod(radians, Direction::DEGREE_360);
}

const Direction Direction::getDifference(const float x_radians, const float y_radians) {
    float left = getHalfPiAngle(x_radians), right = getHalfPiAngle(y_radians);
    float difference = DEFAULT_RADIANS;
    if (y_radians > x_radians) {
        float quadrant = (y_radians / DEGREE_090);
        if (quadrant >= 3) {
            difference = (DEGREE_090 - (right - left));
        } else if (quadrant >= 2) {
            difference = (right - left);
        } else if (quadrant >= 1) {
            difference = (DEGREE_090 - (right - left));
        } else {
            difference = (right - left);
        }
    } else if (x_radians > y_radians) {
        float quadrant = (x_radians / DEGREE_090);
        if (quadrant >= 3) {
            difference = (DEGREE_090 - (left - right));
        } else if (quadrant >= 2) {
            difference = (left - right);
        } else if (quadrant >= 1) {
            difference = (DEGREE_090 - (left - right));
        } else {
            difference = (left - right);
        }
    }
    return Direction(difference);
}

const Direction Direction::getDifference(const Direction& x, const Direction& y) {
    return getDifference(x.toRadians(), y.toRadians());
}

const Direction Direction::getNormal(const Direction& x, const Direction& y) {
    Direction difference = getDifference(x.toRadians(), y.toRadians());
    return difference.getNormal();
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