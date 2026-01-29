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

#include <sstream>
#include <vector>

namespace gis {

class Location {
    double latitude;
    double longitude;
    double altitude;
    long updated;       // timestamp
public:
    // Constructors
    Location();
    Location(const double latitude, const double longitude);
    Location(const double latitude, const double longitude, const long timestamp);
    Location(const double latitude, const double longitude, const double altitude, const long updated);

    // Destructors
    ~Location();

    // Operator overloading
    bool operator==(const Location& peer) const;
    Location operator+(const Location& peer) const;
    Location operator-(const Location& peer) const;

    // Getters
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    double getAltitude() const { return altitude; }
    long getUpdated() const { return updated; }

    // Setters
    void setLatitude(const double value) { this->latitude = value; }
    void setLongitude(const double value) { this->longitude = value; }
    void setAltitude(const double value) { this->altitude = value; }
    void setUpdated(const long timestamp) { this->updated = timestamp; }

    // Additional methods
    virtual Location copy();
    virtual void clear();
    virtual std::string print();

public:
    static const double DEFAULT_VALUE;
    static const long DEFAULT_TIME;
};

typedef std::vector<Location > LocationArray;

} // namespace gis

#endif //GIS_LOCATION_H