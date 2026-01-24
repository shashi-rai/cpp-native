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
const float Direction::DEGREE_1440 = 25.13274122871834590770114706623602307357735519500084656779955673846253125028967198902427860273693654385718469210625845f;
const float Direction::DEFAULT_RADIANS = Direction::DEGREE_000;
const int Direction::DEFAULT_PRECISION = 10000000;
const float Direction::EULER_NUMBER = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632336898f;

Direction::Direction()
        : degrees(Direction::DEGREES_MIN), minutes(Direction::MINUTES_MIN), seconds(Direction::SECONDS_MIN) {

}

Direction::Direction(const float radians) {
    fromRadians(radians);
}

Direction::Direction(const std::complex<float> polar) {
    fromRadians(std::arg(polar));
}

Direction::Direction(const short int degrees)
        : degrees(getIndexDegrees(degrees)), minutes(Direction::MINUTES_MIN), seconds(Direction::SECONDS_MIN) {

}

Direction::Direction(const short int degrees, const short int minutes)
        : degrees(getIndexDegrees(degrees)),
        minutes(getIndexMinutes(minutes)), seconds(Direction::SECONDS_MIN) {

}

Direction::Direction(const short int degrees, const short int minutes, const short int seconds)
        : degrees(getIndexDegrees(degrees)),
        minutes(getIndexMinutes(minutes)), seconds(getIndexSeconds(seconds)) {

}

Direction::~Direction() {

}

bool Direction::operator==(const Direction& peer) const {
    Direction self = *this;
    return (self.degrees == peer.degrees) &&
            (self.minutes == peer.minutes) &&
            (self.seconds == peer.seconds);
}

bool Direction::operator<(const Direction& peer) const {
    Direction self = *this; bool result = false;
    if (self.degrees < peer.degrees) {
        result = true;
    }
    if (self.minutes < peer.minutes) {
        result = true;
    }
    if (self.seconds < peer.seconds) {
        result = true;
    }
    return result;
}

bool Direction::operator>(const Direction& peer) const {
    Direction self = *this; bool result = false;
    if (self.degrees > peer.degrees) {
        result = true;
    }
    if (self.minutes > peer.minutes) {
        result =true;
    }
    if (self.seconds > peer.seconds) {
        result = true;
    }
    return result;
}

bool Direction::operator<=(const Direction& peer) const {
    Direction self = *this;
    return (self < peer) || (self == peer);
}

bool Direction::operator>=(const Direction& peer) const {
    Direction self = *this;
    return (self > peer) || (self == peer);
}

Direction Direction::operator+(const Direction& peer) const {
    Direction self = *this;
    return Direction(getIndexDegrees(self.degrees + peer.degrees),
            getIndexMinutes(self.minutes + peer.minutes),
            getIndexSeconds(self.seconds + peer.seconds));
}

Direction Direction::operator-(const Direction& peer) const {
    Direction self = *this;
    return Direction(getIndexDegrees(self.degrees - peer.degrees),
            getIndexMinutes(self.minutes - peer.minutes),
            getIndexSeconds(self.seconds - peer.seconds));
}

Direction Direction::operator*(const Direction& peer) const {
    Direction self = *this;
    return Direction(getIndexDegrees(self.degrees * peer.degrees),
            getIndexMinutes(self.minutes * peer.minutes),
            getIndexSeconds(self.seconds * peer.seconds));
}

Direction Direction::operator/(const Direction& peer) const {
    Direction self = *this;
    Direction result(self.toRadians() / peer.toRadians());
    return Direction(getIndexDegrees(result.degrees),
            getIndexMinutes(result.minutes),
            getIndexSeconds(result.seconds));
}

Direction Direction::operator%(const Direction& peer) const {
    Direction self = *this;
    Direction result(fmod(self.toRadians(), peer.toRadians()));
    return Direction(getIndexDegrees(result.degrees),
            getIndexMinutes(result.minutes),
            getIndexSeconds(result.seconds));
}

void Direction::setAngle(const short int degrees) {
    this->setDegrees(degrees);
}

void Direction::setAngle(const short int degrees, const short int minutes) {
    this->setDegrees(degrees);
    this->setMinutes(minutes);
}

void Direction::setAngle(const short int degrees, const short int minutes, const short int seconds) {
    this->setDegrees(degrees);
    this->setMinutes(minutes);
    this->setSeconds(seconds);
}

float Direction::getCyclingRate() const {
    Direction self = *this;
    return (self.toRadians() / Direction::getTwoPiRadians());
}

float Direction::getTimePerCycle() const {
    Direction self = *this;
    return (Direction::getTwoPiRadians() / self.toRadians());
}

/*
 * Using machine dependent library for Pi value has higher precision
 */
float Direction::toRadians() const {
    // compute total degrees as floating-point to avoid integer division,
    // then convert degrees to radians
    float degValue = degrees, minValue = (minutes / 60.0f), secValue = (seconds / 3600.0f);
    return ((degValue + minValue + secValue) * (M_PI / 180.0f));
}

/*
 * Used for converting radians to degrees, minutes, seconds
 * Error: 320 seconds per 360° cycle on macOS using M_PI
 */
void Direction::fromRadians(const float radians) {
    float deciDegrees = (radians * (180.0f / M_PI));
    degrees = getIndexDegrees(static_cast<short int>(deciDegrees));

    float deciMinutes = ((deciDegrees - degrees) * 60.0f);
    minutes = getIndexMinutes(static_cast<short int>(deciMinutes));

    float deciSeconds = ((deciMinutes - minutes) * 60.0f);
    seconds = getIndexSeconds(static_cast<short int>(std::round(deciSeconds)));
}

bool Direction::checkNonZero() const {
    Direction self = *this; bool result = true;
    if (self.seconds != Direction::SECONDS_MIN) {
        result = false;
    }
    if (self.minutes != Direction::MINUTES_MIN) {
        result = false;
    }
    if (self.degrees != Direction::DEGREES_MIN) {
        result = false;
    }
    return result;
}

float Direction::getSine() const {
    Direction self = *this;
    return std::sin(self.toRadians());
}

float Direction::getCosine() const {
    Direction self = *this;
    return std::cos(self.toRadians());
}

float Direction::getTangent() const {
    Direction self = *this;
    return std::tan(self.toRadians());
}

std::complex<float> Direction::getPhase() const {
    Direction self = *this;
    return self.getCyclic(Direction::DEFAULT_RADIANS);
}

std::complex<float> Direction::getCyclic(const float coefficient) const {
    Direction self = *this;
    std::complex<float> exponent(coefficient, self.toRadians());
    return std::exp(exponent);
}

Direction Direction::getInverse() const {
    Direction self = *this;
    return Direction(self.toRadians() + Direction::DEGREE_180);
}

Direction Direction::getNormal() const {
    Direction self = *this;
    return Direction(self.toRadians() + Direction::DEGREE_090);
}

Direction Direction::getSquare() const {
    Direction self = *this;
    return self.getInverse();
}

Direction Direction::getRotation(const short int degree) const {
    Direction self = *this;
    return Direction(self.toRadians() + (Direction::DEGREE_001 * degree));
}

void Direction::setRotation(const short int degree) {
    Direction self = *this;
    self.fromRadians(self.toRadians() + (Direction::DEGREE_001 * degree));
}

Direction Direction::getMultiple(const float coefficient) const {
    Direction self = *this;
    float result = (self.toRadians() * coefficient);
    return Direction(result);
}

Direction Direction::getDivision(const float coefficient) const {
    Direction self = *this; float result = Direction::DEFAULT_RADIANS;
    if (coefficient != Direction::DEFAULT_RADIANS) {
        result = (self.toRadians() / coefficient);
    }
    return Direction(result);
}

Direction Direction::copy() const {
    Direction self = *this;
    Direction fresh(self.degrees, self.minutes, self.seconds);
    return fresh;
}

void Direction::clear() {
    Direction self = *this;
    self.degrees = Direction::DEGREES_MIN;
    self.minutes = Direction::MINUTES_MIN;
    self.seconds = Direction::SECONDS_MIN;
    return;
}

std::string Direction::print() const {
    std::stringstream result;
    result << "[";
    result << degrees << "°,";
    result << minutes << "′,";
    result << seconds << "″]";
	return result.str();
}

std::string Direction::printRadians() const {
    Direction self = *this; std::stringstream result;
    result << std::setfill('0') << std::setprecision(8);
    result << self.toRadians();
    result << shp::Unit::getDerivedSymbol(shp::Unit::PLANE_ANGLE);
	return result.str();
}

std::string Direction::printEuler() const {
    Direction self = *this; std::stringstream result;
    std::complex<float> phase = self.getPhase();
    result << ":";
    result << self.getTheta(phase) << "(";
    result << self.getCosine(phase) << "+𝑖";
    result << self.getSine(phase) << ")";
	return result.str();
}

const float Direction::getMagnitude(const std::complex<float> phase) {
    return std::abs(phase);
}

const float Direction::getTheta(const std::complex<float> phase) {
    return (std::arg(phase) * 180.0f / Direction::DEGREE_180);
}

const float Direction::getSine(const std::complex<float> phase) {
    return phase.imag();
}

const float Direction::getCosine(const std::complex<float> phase) {
    return phase.real();
}

const float Direction::getTangent(const std::complex<float> phase) {
    return (Direction::getSine(phase) / Direction::getCosine(phase));
}

const std::complex<float> Direction::getConstructive(const std::complex<float> phase_a,
        const std::complex<float> phase_b) {
    return (phase_a * phase_b);
}

const std::complex<float> Direction::getDestructive(const std::complex<float> phase_a,
        const std::complex<float> phase_b) {
    return (phase_a / phase_b);
}
const short int Direction::getQuadrant(const float radians) {
    return ((Direction::getPeriodic(radians) / Direction::DEGREE_090) + 1);
}

const float Direction::getPeriodic(const float radians) {
    return Direction::getTwoPiAngle(radians);
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

const float Direction::getEightPiAngle(const float radians) {
    return fmod(radians, Direction::DEGREE_1440);
}

const Direction Direction::getDifference(const float x_radians, const float y_radians) {
    float difference = Direction::DEFAULT_RADIANS;
    float left = getHalfPiAngle(getPeriodic(x_radians));
    float right = getHalfPiAngle(getPeriodic(y_radians));
    if (y_radians > x_radians) {
        float delta = (right - left);
        switch (Direction::getQuadrant(y_radians)) {
        case 4:
            difference = Direction::checkPositive(delta)
                    ? (Direction::check90degree(right) ? delta : Direction::get90minus(delta))
                    : Direction::get90plus(delta);
            break;
        case 3:
            difference = Direction::checkPositive(delta)
                    ? delta : -delta;
            break;
        case 2:
            difference = Direction::checkPositive(delta)
                    ? Direction::get90minus(delta) : Direction::get90plus(delta);
            break;
        case 1:
            difference = Direction::checkPositive(delta)
                    ? delta : Direction::get90minus(left);
            break;
        }
    } else if ((x_radians > y_radians)) {
        float delta = (left - right);
        switch (Direction::getQuadrant(x_radians)) {
        case 4:
            difference = Direction::checkPositive(delta)
                    ? (Direction::check90degree(left) ? delta : Direction::get90minus(delta))
                    : Direction::get90plus(delta);
            break;
        case 3:
            difference = Direction::checkPositive(delta)
                    ? delta : -delta;
            break;
        case 2:
            difference = Direction::checkPositive(delta)
                    ? Direction::get90minus(delta) : Direction::get90plus(delta);
            break;
        case 1:
            difference = Direction::checkPositive(delta)
                    ? delta : Direction::get90minus(right);
            break;
        }
    }
    return Direction(difference);
}

const Direction Direction::getDifference(const Direction& x, const Direction& y) {
    return Direction::getDifference(x.toRadians(), y.toRadians());
}

const Direction Direction::getNormal(const Direction& x, const Direction& y) {
    Direction difference = Direction::getDifference(x.toRadians(), y.toRadians());
    return difference.getNormal();
}

const float Direction::getFraction(const float x_radians, const float y_radians) {
    float fraction = Direction::DEFAULT_RADIANS;
    float left = getHalfPiAngle(getPeriodic(x_radians));
    float right = getHalfPiAngle(getPeriodic(y_radians));
    if ((y_radians > x_radians)) {
        float delta = (right - left);
        if (Direction::checkPositive(delta)) {
            switch (Direction::getQuadrant(y_radians)) {
            case 4:
                fraction = (left / (Direction::check90degree(right)
                        ? right : Direction::get90minus(right)));
                break;
            case 3:
                fraction = (left / right);
                break;
            case 2:
                fraction = (left / (Direction::check90degree(right)
                        ? right : Direction::get90minus(right)));
                break;
            case 1:
                fraction = (left / right);
                break;
            }
        } else {
            if (Direction::checkNegative(delta)) {
                fraction = (left / right);
            } else {
                fraction = 1.0f;
            }
        }
    } else if ((x_radians > y_radians)) {
        float delta = (left - right);
        if (Direction::checkPositive(delta)) {
            switch (Direction::getQuadrant(x_radians)) {
            case 4:
                fraction = (right / (Direction::check90degree(left)
                        ? left : Direction::get90minus(left)));
                break;
            case 3:
                fraction = (right / left);
                break;
            case 2:
                fraction = (right / (Direction::check90degree(left)
                        ? left : Direction::get90minus(left)));
                break;
            case 1:
                fraction = (right / left);
                break;
            }
        } else {
            if (Direction::checkNegative(delta)) {
                fraction = (right / left);
            } else {
                fraction = 1.0f;
            }
        }
    }
    return fraction;
}

const float Direction::getFraction(const Direction& x, const Direction& y) {
    return Direction::getFraction(x.toRadians(), y.toRadians());
}

const bool Direction::checkTranslation(const Direction& x, const Direction& y) {
    return !(checkRotation(x.toRadians(), y.toRadians()));
}

const bool Direction::checkRotation(const Direction& x, const Direction& y) {
    return Direction::getDifference(x.toRadians(), y.toRadians()).checkNonZero();
}

/*
 * Used for converting degrees between 0 ~ 360
 */
short int Direction::getIndexDegrees(const short int value) const {
    int result = (value % Direction::DEGREES_MAX);
    if (value >= Direction::DEGREES_MIN)
        return result;
    else
        return (Direction::DEGREES_MAX + result);
}

/*
 * Used for converting minutes between 0 ~ 60
 */
short int Direction::getIndexMinutes(const short int value) const {
    int result = (value % Direction::MINUTES_MAX);
    if (value >= Direction::MINUTES_MIN)
        return result;
    else
        return (Direction::MINUTES_MAX + result);
}

/*
 * Used for converting seconds between 0 ~ 3600
 */
short int Direction::getIndexSeconds(const short int value) const {
    int result = (value % Direction::SECONDS_MAX);
    if (value >= Direction::SECONDS_MIN)
        return result;
    else
        return (Direction::SECONDS_MAX + result);
}

const float Direction::get90minus(const float radians) {
    return (Direction::DEGREE_090 - radians);
}

const float Direction::get90plus(const float radians) {
    return (Direction::DEGREE_090 + radians);
}

const float Direction::getHalfPiRadians() {
    return Direction::DEGREE_090;
}

const float Direction::getFullPiRadians() {
    return Direction::DEGREE_180;
}

const float Direction::getTwoPiRadians() {
    return Direction::DEGREE_360;
}

const float Direction::getFourPiRadians() {
    return Direction::DEGREE_720;
}

const float Direction::getEightPiRadians() {
    return Direction::DEGREE_1440;
}

const bool Direction::checkPositive(const float radians) {
    return (radians > Direction::DEGREE_000);
}

const bool Direction::checkNegative(const float radians) {
    return (radians > Direction::DEGREE_000);
}

const bool Direction::check0degree(const float radians) {
    return (radians == Direction::DEGREE_000);
}

const bool Direction::check30degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getHalfPiAngle(radians) - Direction::DEGREE_030) < epsilon);
    else
        return (std::abs(getHalfPiAngle(-radians) - Direction::DEGREE_030) < epsilon);
}

const bool Direction::check45degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getHalfPiAngle(radians) - Direction::DEGREE_045) < epsilon);
    else
        return (std::abs(getHalfPiAngle(-radians) - Direction::DEGREE_045) < epsilon);
}

const bool Direction::check60degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getHalfPiAngle(radians) - Direction::DEGREE_060) < epsilon);
    else
        return (std::abs(getHalfPiAngle(-radians) - Direction::DEGREE_030) < epsilon);
}

const bool Direction::check90degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getFullPiAngle(radians) - Direction::DEGREE_090) < epsilon);
    else
        return (std::abs(getFullPiAngle(-radians) - Direction::DEGREE_090) < epsilon);
}

const bool Direction::check180degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getTwoPiAngle(radians) - Direction::DEGREE_180) < epsilon);
    else
        return (std::abs(getTwoPiAngle(-radians) - Direction::DEGREE_180) < epsilon);
}

const bool Direction::check270degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getTwoPiAngle(radians) - Direction::DEGREE_270) < epsilon);
    else
        return (std::abs(getTwoPiAngle(-radians) - Direction::DEGREE_270) < epsilon);
}

const bool Direction::check360degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getFourPiAngle(radians) - Direction::DEGREE_360) < epsilon);
    else
        return (std::abs(getFourPiAngle(-radians) - Direction::DEGREE_360) < epsilon);
}

const bool Direction::check720degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getEightPiAngle(radians) - Direction::DEGREE_720) < epsilon);
    else
        return (std::abs(getEightPiAngle(-radians) - Direction::DEGREE_720) < epsilon);
}

const bool Direction::check1440degree(const float radians) {
    const float epsilon = std::numeric_limits<float>::epsilon() * Direction::DEFAULT_PRECISION;
    if (Direction::checkPositive(radians))
        return (std::abs(getEightPiAngle(radians)) < epsilon);
    else
        return (std::abs(getEightPiAngle(-radians)) < epsilon);
}

} // namespace shp