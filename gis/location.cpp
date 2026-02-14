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

#include "location.h"

namespace gis {

const long Location::DEFAULT_TIME = 0L;

Location::Location()
        : phy::Position(), updated(Location::DEFAULT_TIME) {

}

Location::Location(const long updated)
        : phy::Position(), updated(updated) {

}

Location::Location(const double latitude, const double longitude)
    : phy::Position(latitude, longitude), updated(Location::DEFAULT_TIME) {

}

Location::Location(const double latitude, const double longitude, const long updated)
    : phy::Position(latitude, longitude), updated(updated) {

}

Location::Location(const double latitude, const double longitude, const double altitude, const long updated)
    : phy::Position(latitude, longitude, altitude), updated(updated) {

}

Location::~Location() {

}

bool Location::operator==(const Location& peer) const {
    return (static_cast<const phy::Position&>(*this) == static_cast<const phy::Position&>(peer))
        && (updated == peer.updated);
}

bool Location::operator<(const Location& peer) const {
    Location self = *this; bool result = false;   
    if (static_cast<const phy::Position&>(*this) < static_cast<const phy::Position&>(peer)) {
        result = true;
    }
    if (updated < peer.updated) {
        result = true;
    }
    return result;
}

bool Location::operator>(const Location& peer) const {
    Location self = *this; bool result = false;
    if (static_cast<const phy::Position&>(*this) > static_cast<const phy::Position&>(peer)) {
        result = true;
    }
    if (updated > peer.updated) {
        result = true;
    }
    return result;
}

bool Location::operator<=(const Location& peer) const {
    Location self = *this;
    return (self < peer) || (self == peer);
}

bool Location::operator>=(const Location& peer) const {
    Location self = *this;
    return (self > peer) || (self == peer);
}

Location Location::operator+(const Location& peer) const {
    phy::Position self = *this, other = peer, position = (self + other);
    return Location(position.getX(), position.getY(), position.getZ(), (updated + peer.updated));
}

Location Location::operator-(const Location& peer) const {
    phy::Position self = *this, other = peer, position = (self - other);
    return Location(position.getX(), position.getY(), position.getZ(), (updated - peer.updated));
}

Location Location::operator*(const Location& peer) const {
    phy::Position self = *this, other = peer, position = (self * other);
    return Location(position.getX(), position.getY(), position.getZ(), (updated * peer.updated));
}

Location Location::operator/(const Location& peer) const {
    phy::Position self = *this, other = peer, position = (self / other);
    return Location(position.getX(), position.getY(), position.getZ(), (updated / peer.updated));
}

Location Location::operator%(const Location& peer) const {
    phy::Position self = *this, other = peer, position = (self % other);
    return Location(position.getX(), position.getY(), position.getZ(), (updated % peer.updated));
}

double Location::getLatitude() const {
    return phy::Position::getX();
}

void Location::setLatitude(const double latitude) {
    phy::Position::setX(latitude);
}

double Location::getLongitude() const {
    return phy::Position::getY();
}

void Location::setLongitude(const double longitude) {
    phy::Position::setY(longitude);
}

double Location::getAltitude() const {
    return phy::Position::getZ();
}

void Location::setAltitude(const double altitude) {
    phy::Position::setZ(altitude);
}

Location Location::getOffset(long double shiftLatitude, long double shiftLongitude) {
    double fraction_lat = (shiftLatitude / Location::getEarthEquatorialRadius());
    double fraction_long = (shiftLongitude / (Location::getEarthEquatorialRadius() * std::cos(M_PI * this->getLatitude() / phy::Position::DEGREE_QUADRANT_2)));
    double latitude_offset = this->getLatitude() + fraction_lat * phy::Position::DEGREE_QUADRANT_2 / M_PI;
    double longitude_offset = this->getLongitude() + fraction_long * phy::Position::DEGREE_QUADRANT_2 / M_PI;
    return Location(latitude_offset, longitude_offset);
}

long double Location::getDistance(long double fromLatitude, long double fromLongitude) {
    return Location::getHaversine(this->getLatitude(), this->getLongitude(), fromLatitude, fromLongitude);
}

Location Location::copy() {
    Location fresh(phy::Position::getX(), phy::Position::getY(), phy::Position::getZ(), this->updated);
    return fresh;
}

void Location::clear() {
    phy::Position::clear();
    updated = Location::DEFAULT_TIME;
    return;
}

std::string Location::print() const {
    std::stringstream result;
    result << "(";
    result << printCoordinate() << ",";
    result << printUpdateTime();
    result << ")";
	return result.str();
}

std::string Location::printCoordinate() const {
    std::stringstream result;
    result << "lat:";
    result << phy::Position::getX() << ",long:";
    result << phy::Position::getY() << ",alt:";
    result << phy::Position::getZ();
	return result.str();
}

std::string Location::printUpdateTime() const {
    std::stringstream result;
    result << "upd:";
    result << updated;
	return result.str();
}

const long double Location::getEarthEquatorialRadius() {
    return 6378137.0;
}

const long double Location::getEarthPolarRadius() {
    return 6356752.0;
}

const long double Location::getEarthMeanRadius() {
    return 6371.0;
}

const long double Location::getHaversine(
        const long double latA, const long double longA, 
        const long double latB, const long double longB) {
    long double latX = phy::Position::toRadians(latA), longX = phy::Position::toRadians(longA);
    long double latY = phy::Position::toRadians(latB), longY = phy::Position::toRadians(longB);
    long double difference_latitude = (latY - latX), difference_longitude = (longY - longX);

    long double result = std::pow(std::sin(difference_latitude / 2), 2)
        + std::cos(latX) * std::cos(latY) * std::pow(sin(difference_longitude / 2), 2);
    result = 2 * std::asin(std::sqrt(result));
    return (result * Location::getEarthMeanRadius());       // distance in Kilometer
}

} // namespace gis
