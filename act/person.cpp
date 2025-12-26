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

#include "person.h"

namespace act {

Person::Person()
        : firstname(), middlename(), lastname(), residence(), office() {

}

Person::Person(std::string name) : residence(), office() {
    setName(name);
}

Person::Person(std::string firstname, std::string lastname)
        : firstname(firstname), middlename(), lastname(lastname), residence(), office() {

}

Person::Person(std::string firstname, std::string middlename, std::string lastname)
        : firstname(firstname), middlename(middlename), lastname(lastname), residence(), office() {

}

Person::Person(const gis::Address& residence)
        : firstname(), middlename(), lastname(), residence(residence), office() {

}

Person::Person(std::string name, const gis::Address& residence)
        : residence(residence), office() {
    setName(name);
}

Person::Person(const gis::Address& residence, const gis::Address& office)
        : firstname(), middlename(), lastname(), residence(residence), office(office) {

}

Person::Person(std::string name, const gis::Address& residence, const gis::Address& office)
        : residence(residence), office(office) {
    setName(name);
}

Person::Person(std::string firstname, std::string middlename, std::string lastname,
        const gis::Address& residence, const gis::Address& office)
        : firstname(firstname), middlename(), lastname(lastname),
        residence(residence), office(office) {

}

Person::~Person() {

}

bool Person::operator==(const Person& peer) const {
    return (firstname == peer.firstname)
        && (middlename == peer.middlename)
        && (lastname == peer.lastname)
        && (residence == peer.residence)
        && (office == peer.office);
}

std::string Person::getName() const {
    std::stringstream result;
    result << firstname << " ";
    result << middlename << " ";
    result << lastname ;
	return result.str();
}

void Person::setName(const std::string& fullname) {
    char delimiter = ' ';
    std::vector<std::string> names = splitName(fullname, delimiter);
    if (names.size() > 2) {
        lastname = names[2];
    }
    if (names.size() > 1) {
        middlename = names[1];
    }
    if (names.size() > 0) {
        firstname = names[0];
    }
}

Person Person::copy() {
    Person fresh(firstname, middlename, lastname, residence, office);
    return fresh;
}

void Person::clear() {
    firstname = middlename = lastname = "";
    residence.clear();
    office.clear();
    return;
}

std::string Person::print() {
    std::stringstream result;
    result << this->getName() << ",";
	return result.str();
}

std::vector<std::string> Person::splitName(const std::string& str, char delimiter) {
    std::vector<std::string> tokens; std::string token;
    std::stringstream ss(str);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

} // namespace act