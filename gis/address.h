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

#ifndef GIS_ADDRESS_H
#define GIS_ADDRESS_H

#include <string>
#include <vector>
#include "location.h"

namespace gis {

class Address {
    Location* location;
    std::string room;
    std::string unit;
    std::string floor;
    std::string building;
    std::string plot;
    std::string survey;
    std::string street;
    std::string village;
    std::string town;
    std::string postbox;
    std::string postoffice;
    std::string policestation;
    std::string city;
    std::string district;
    std::string division;
    std::string province;
    std::string country;
    std::string pincode;
public:
    // Constructors
    Address();
    Address(Location* location);
    Address(std::string pincode);

    // Destructors
    ~Address();

    // Operator overloading
    bool operator==(const Address& peer) const;

    // Getters
    Location* getLocation() const { return location; }
    std::string getRoom() const { return room; }
    std::string getUnit() const { return unit; }
    std::string getFloor() const { return floor; }
    std::string getBuilding() const { return building; }
    std::string getPlot() const { return plot; }
    std::string getSurvey() const { return survey; }
    std::string getStreet() const { return street; }
    std::string getVillage() const { return village; }
    std::string getTown() const { return town; }
    std::string getPostBox() const { return postbox; }
    std::string getPostOffice() const { return postoffice; }
    std::string getPoliceStation() const { return policestation; }
    std::string getCity() const { return city; }
    std::string getDistrict() const { return district; }
    std::string getDivision() const { return division; }
    std::string getProvince() const { return province; }
    std::string getCountry() const { return country; }
    std::string getPinCode() const { return pincode; }

    // Setters
    void setLocation(Location* value) { this->location = value; }
    void setRoom(const std::string& name) { this->room = name; }
    void setUnit(const std::string& name) { this->unit = name; }
    void setFloor(const std::string& name) { this->floor = name; }
    void setBuilding(const std::string& name) { this->building = name; }
    void setPlot(const std::string& name) { this->plot = name; }
    void setSurvey(const std::string& name) { this->survey = name; }
    void setStreet(const std::string& name) { this->street = name; }
    void setVillage(const std::string& name) { this->village = name; }
    void setTown(const std::string& name) { this->town = name; }
    void setPostBox(const std::string& number) { this->postbox = number; }
    void setPostOffice(const std::string& name) { this->postoffice = name; }
    void setPoliceStation(const std::string& name) { this->policestation = name; }
    void setCity(const std::string& name) { this->city = name; }
    void setDistrict(const std::string& name) { this->district = name; }
    void setDivision(const std::string& name) { this->division = name; }
    void setProvince(const std::string& name) { this->province = name; }
    void setCountry(const std::string& name) { this->country = name; }
    void setPinCode(const std::string& number) { this->pincode = number; }

    // Additional methods
    bool isLocated() const;
    virtual Address copy();
    virtual void clear();
    virtual std::string print();

public:
    static const std::string DEFAULT_VALUE;
};

typedef std::vector<Address > AddressArray;

} // namespace gis

#endif //GIS_ADDRESS_H