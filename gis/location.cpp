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

const double Location::DEFAULT_VALUE = 0.0;
const long Location::DEFAULT_TIME = 0L;

Location::Location()
        : latitude(DEFAULT_VALUE), longitude(DEFAULT_VALUE), altitude(DEFAULT_VALUE),
        updated(DEFAULT_TIME) {

}

Location::Location(double latitude, double longitude)
    : latitude(latitude), longitude(longitude), altitude(DEFAULT_VALUE),
    updated(DEFAULT_TIME) {

}

Location::Location(double latitude, double longitude, long updated)
    : latitude(latitude), longitude(longitude), altitude(DEFAULT_VALUE),
    updated(updated) {

}

Location::Location(double latitude, double longitude, double altitude, long updated)
    : latitude(latitude), longitude(longitude), altitude(altitude), updated(updated) {

}

Location::~Location() {

}

bool Location::operator==(const Location& peer) const {
    return (latitude == peer.latitude)
        && (longitude == peer.longitude)
        && (altitude == peer.altitude)
        && (updated == peer.updated);
}

Location Location::operator+(const Location& peer) const {
    return Location((latitude + peer.latitude), (longitude + peer.longitude),
        (altitude + peer.altitude), (updated + peer.updated));
}

Location Location::operator-(const Location& peer) const {
    return Location((latitude - peer.latitude), (longitude - peer.longitude),
        (altitude - peer.altitude), (updated - peer.updated));
}

Location Location::copy() {
    Location fresh(latitude, longitude, altitude, updated);
    return fresh;
}

void Location::clear() {
    latitude = longitude = altitude = DEFAULT_VALUE;
    updated = 0L;
    return;
}

std::string Location::print() {
    std::stringstream result;
    result << "(lat:";
    result << latitude << ",long:";
    result << longitude << ",alt:";
    result << altitude << ",upd:";
    result << updated << ")";
	return result.str();
}

} // namespace gis
