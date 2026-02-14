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

#ifndef GIS_LOCATION_H
#define GIS_LOCATION_H

#include "../phy/position.h"

namespace gis {

/*
 * x = Latitude
 * y = Longitude
 * z = Altitude
 */
class Location : private phy::Position {
    long updated;       // timestamp
public:
    // Constructors
    Location();
    Location(const long updated);
    Location(const double latitude, const double longitude);
    Location(const double latitude, const double longitude, const long timestamp);
    Location(const double latitude, const double longitude, const double altitude, const long updated);

    // Destructors
    ~Location();

    // Operator overloading
    bool operator==(const Location& peer) const;
    bool operator<(const Location& peer) const;
    bool operator>(const Location& peer) const;
    bool operator<=(const Location& peer) const;
    bool operator>=(const Location& peer) const;
    Location operator+(const Location& peer) const;
    Location operator-(const Location& peer) const;
    Location operator*(const Location& peer) const;
    Location operator/(const Location& peer) const;
    Location operator%(const Location& peer) const;

    // Getters
    long getUpdated() const { return updated; }

    // Setters
    void setUpdated(const long timestamp) { this->updated = timestamp; }

    // Additional methods
    double getLatitude() const;
    void setLatitude(const double latitude);
    double getLongitude() const;
    void setLongitude(const double longitude);
    double getAltitude() const;
    void setAltitude(const double altitude);
    Location getOffset(const long double shiftLatitude, const long double shiftLongitude);
    long double getDistance(const long double fromLatitude, const long double fromLongitude);
    Location copy();
    virtual void clear();
    virtual std::string print() const;
    virtual std::string printCoordinate() const;
    virtual std::string printUpdateTime() const;

private:
    static const long double getEarthEquatorialRadius();    // in Meter
    static const long double getEarthPolarRadius();         // in Meter
    static const long double getEarthMeanRadius();          // in Kilometer
    static const long double getHaversine(
        const long double latA, const long double longA,
        const long double latB, const long double longB);
public:
    static const long DEFAULT_TIME;
};

typedef std::vector<Location > LocationArray;

} // namespace gis

#endif //GIS_LOCATION_H