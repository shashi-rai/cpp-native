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

#include "address.h"

namespace gis {

const std::string Address::DEFAULT_VALUE = "";

Address::Address() : room(), unit(), floor(), building(), plot(), survey(),
        street(), village(), town(), postbox(), postoffice(), policestation(),
        city(), district(), division(), province(), country(), pincode() {
    setLocation(nullptr);
}

Address::Address(Location* location): room(), unit(), floor(), building(), plot(),
        survey(), street(), village(), town(), postbox(), postoffice(), policestation(),
        city(), district(), division(), province(), country(), pincode() {
    setLocation(location);
}

Address::Address(std::string pincode): room(), unit(), floor(), building(), plot(),
        survey(), street(), village(), town(), postbox(), postoffice(), policestation(),
        city(), district(), division(), province(), country(), pincode(pincode) {
    setLocation(nullptr);
}

Address::~Address() {

}

bool Address::operator==(const Address& peer) const {
    return (location == peer.location)
        && (room == peer.room)
        && (unit == peer.unit)
        && (floor == peer.floor)
        && (building == peer.building)
        && (plot == peer.plot)
        && (survey == peer.survey)
        && (street == peer.street)
        && (village == peer.village)
        && (town == peer.town)
        && (postbox == peer.postbox)
        && (postoffice == peer.postoffice)
        && (policestation == peer.policestation)
        && (city == peer.city)
        && (district == peer.district)
        && (division == peer.division)
        && (province == peer.province)
        && (country == peer.country)
        && (pincode == peer.pincode);
}

bool Address::isLocated() const {
    return location != nullptr;
}

Address Address::copy() {
    Address fresh(location);
    return fresh;
}

void Address::clear() {
    setLocation(nullptr);
    setRoom(DEFAULT_VALUE);
    setUnit(DEFAULT_VALUE);
    setFloor(DEFAULT_VALUE);
    setBuilding(DEFAULT_VALUE);
    setPlot(DEFAULT_VALUE);
    setSurvey(DEFAULT_VALUE);
    setStreet(DEFAULT_VALUE);
    setVillage(DEFAULT_VALUE);
    setTown(DEFAULT_VALUE);
    setPostBox(DEFAULT_VALUE);
    setPostOffice(DEFAULT_VALUE);
    setPoliceStation(DEFAULT_VALUE);
    setCity(DEFAULT_VALUE);
    setDistrict(DEFAULT_VALUE);
    setDivision(DEFAULT_VALUE);
    setProvince(DEFAULT_VALUE);
    setCountry(DEFAULT_VALUE);
    setPinCode(DEFAULT_VALUE);
    return;
}

std::string Address::print() {
    std::stringstream result;
    result << "{loc:";
    result << (location != nullptr ? location->print() : DEFAULT_VALUE);
    result << ",r:";
    result << room << ",u:";
    result << unit << ",flr:";
    result << floor << ",bldg:";
    result << building << ",pl:";
    result << plot << ",sv:";
    result << survey << ",st:";
    result << street << ",vill:";
    result << village << ",tw:";
    result << town << ",pb:";
    result << postbox << ",po:";
    result << postoffice << ",ps:";
    result << policestation << ",c:";
    result << city << ",dist:";
    result << district << ",div:";
    result << division << ",prov:";
    result << province << ",co:";
    result << country << ",pin:";
    result << pincode << "}";
	return result.str();
}

} // namespace gis