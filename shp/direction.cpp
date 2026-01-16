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

const short int Direction::DEGREES_MIN = 0;
const short int Direction::DEGREES_MAX = 360;
const short int Direction::MINUTES_MIN = 0;
const short int Direction::MINUTES_MAX = 60;
const short int Direction::SECONDS_MIN = 0;
const short int Direction::SECONDS_MAX = 3600;

const float Direction::DEGREE_000 = 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000f;
const float Direction::DEGREE_001 = 0.0174532925199432957692369076848861271344287188854172545609719144017100911460344944368224156963450948221230449250737905924838546922f;
const float Direction::DEGREE_005 = 0.0872664625997164788461718712501509787673570650949700364603591981880513801861053180424520935579930267231145554620000000000000000000f;
const float Direction::DEGREE_010 = 0.1745329251994329576923690772719685651268340119106090710188494191317676751759604322497678598104396000000000000000000000000000000000f;
const float Direction::DEGREE_030 = 0.5235987755982988730771072305465838140328615665625176368291574320513027343810348331046724708903528446636913477522137177740000000000f;
const float Direction::DEGREE_045 = 0.7853981633974483096156608458198757210492923498437764552437361480769541015715522496570087063355292669955370216283205766617735000000f;
const float Direction::DEGREE_060 = 1.0471975511965977461542144610931676280657231331250352736583148641026054687620696662093449417807056893273826955044274355490000000000f;
const float Direction::DEGREE_090 = 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533240000000000f;
const float Direction::DEGREE_180 = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095f;
const float Direction::DEGREE_270 = 4.7123889803846898576939650749192543262957540990626587314624168884617246094293134979420522380131756019732221297699234599700000000000f;
const float Direction::DEGREE_360 = 6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341359642961730265646132942000000000f;
const float Direction::DEGREE_720 = 12.566370614359172953850573533118011536788677597500423283899778369231265625144835994512139301368468271928592346053129226588375378440f;
const float Direction::DEFAULT_RADIANS = Direction::DEGREE_000;
const int Direction::DEFAULT_PRECISION = 10000000;

Direction::Direction()
        : degrees(DEGREES_MIN), minutes(MINUTES_MIN), seconds(SECONDS_MIN) {

}

Direction::Direction(const float radians) {
    fromRadians(radians);
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
    return (toRadians() / (2 * Direction::DEGREE_180));
}

float Direction::getTimePerCycle() const {
    return ((2 * Direction::DEGREE_180) / toRadians());
}

float Direction::toRadians() const {
    // compute total degrees as floating-point to avoid integer division,
    // then convert degrees to radians
    float total = degrees + (minutes / 60.0f) + (seconds / 3600.0f);
    return (total * (Direction::DEGREE_180 / 180.0f));
}

/*
 * Used for converting radians to degrees, minutes, seconds
 */
void Direction::fromRadians(const float radians) {
    float deciDegrees = radians * (180.0f / M_PI);
    degrees = getIndexDegrees(static_cast<int>(deciDegrees));
    float fraDegrees = deciDegrees - degrees;

    float deciMinutes = fraDegrees * 60.0f;
    minutes = getIndexMinutes(static_cast<int>(deciMinutes));
    float fraMinutes = deciMinutes - minutes;

    float deciSeconds = fraMinutes * 60.0f;
    seconds = getIndexSeconds(static_cast<int>(round(deciSeconds)));
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

Direction Direction::getSquare() const {
    return getInverse();
}

Direction Direction::getRotation(const short int degree) const {
    return Direction((toRadians() + (DEGREE_001 * degree)));
}

Direction Direction::getMultiple(const float coefficient) const {
    float result = (toRadians() * coefficient);
    return Direction(result);
}

Direction Direction::getDivision(const float coefficient) const {
    float result = DEFAULT_RADIANS;
    if (coefficient != DEFAULT_RADIANS) {
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

const short int Direction::getQuadrant(const float radians) {
    return ((getPeriodic(radians) / DEGREE_090) + 1);
}

const float Direction::getPeriodic(const float radians) {
    return getTwoPiAngle(radians);
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

const float Direction::getFourPiAngle(const float radians) {
    return fmod(radians, Direction::DEGREE_720);
}

const Direction Direction::getDifference(const float x_radians, const float y_radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * DEFAULT_PRECISION;
    float left = getHalfPiAngle(getPeriodic(x_radians)), right = getHalfPiAngle(getPeriodic(y_radians));
    float difference = DEFAULT_RADIANS;
    if (y_radians > x_radians) {
        float delta = (right - left);
        switch (getQuadrant(y_radians)) {
        case 4:
            difference = (delta > DEGREE_000) ? ((std::abs(right - DEGREE_090) < epsilon) ? delta : (DEGREE_090 - delta)) : (DEGREE_090 + delta);
            break;
        case 3:
            difference = (delta > DEGREE_000) ? delta : -delta;
            break;
        case 2:
            difference = (delta > DEGREE_000) ? (DEGREE_090 - delta) : (DEGREE_090 + delta);
            break;
        case 1:
            difference = (delta > DEGREE_000) ? delta : (DEGREE_090 - left);
            break;
        }
    } else if ((x_radians > y_radians)) {
        float delta = (left - right);
        switch (getQuadrant(x_radians)) {
        case 4:
            difference = (delta > DEGREE_000) ? ((std::abs(left - DEGREE_090) < epsilon) ? delta : (DEGREE_090 - delta)) : (DEGREE_090 + delta);
            break;
        case 3:
            difference = (delta > DEGREE_000) ? delta : -delta;
            break;
        case 2:
            difference = (delta > DEGREE_000) ? (DEGREE_090 - delta) : (DEGREE_090 + delta);
            break;
        case 1:
            difference = (delta > DEGREE_000) ? delta : (DEGREE_090 - right);
            break;
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

const float Direction::getFraction(const float x_radians, const float y_radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * DEFAULT_PRECISION;
    float left = getHalfPiAngle(getPeriodic(x_radians)), right = getHalfPiAngle(getPeriodic(y_radians));
    float fraction = DEFAULT_RADIANS;
    if ((y_radians > x_radians)) {
        float delta = (right - left);
        if (delta > DEGREE_000) {
            switch (getQuadrant(y_radians)) {
            case 4:
                fraction = (left / ((std::abs(right - DEGREE_090) < epsilon) ? right : (DEGREE_090 - right)));
                break;
            case 3:
                fraction = (left / right);
                break;
            case 2:
                fraction = (left / ((std::abs(right - DEGREE_090) < epsilon) ? right : (DEGREE_090 - right)));
                break;
            case 1:
                fraction = (left / right);
                break;
            }
        } else {
            if (delta < DEGREE_000) {
                fraction = (left / right);
            } else {
                fraction = 1.0f;
            }
        }
    } else if ((x_radians > y_radians)) {
        float delta = (left - right);
        if (delta > DEGREE_000) {
            switch (getQuadrant(x_radians)) {
            case 4:
                fraction = (right / ((std::abs(left - DEGREE_090) < epsilon) ? left : (DEGREE_090 - left)));
                break;
            case 3:
                fraction = (right / left);
                break;
            case 2:
                fraction = (right / ((std::abs(left - DEGREE_090) < epsilon) ? left : (DEGREE_090 - left)));
                break;
            case 1:
                fraction = (right / left);
                break;
            }
        } else {
            if (delta < DEGREE_000) {
                fraction = (right / left);
            } else {
                fraction = 1.0f;
            }
        }
    }
    return fraction;
}

const float Direction::getFraction(const Direction& x, const Direction& y) {
    return getFraction(x.toRadians(), y.toRadians());
}

const bool Direction::checkTranslation(const Direction& x, const Direction& y) {
    return !(checkRotation(x.toRadians(), y.toRadians()));
}

const bool Direction::checkRotation(const Direction& x, const Direction& y) {
    return getDifference(x.toRadians(), y.toRadians()).checkNonZero();
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