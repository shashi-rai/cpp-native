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

#ifndef ACT_PERSON_H
#define ACT_PERSON_H

#include <sstream>
#include <string>
#include <vector>
#include "../gis/address.h"

namespace act {

class Person {
    std::string firstname;
    std::string middlename;
    std::string lastname;
    gis::Address residence;
    gis::Address office;
public:
    // Constructors
    Person();
    Person(std::string name);
    Person(std::string firstname, std::string lastname);
    Person(std::string firstname, std::string middlename, std::string lastname);
    Person(const gis::Address& residence);
    Person(std::string name, const gis::Address& residence);
    Person(const gis::Address& residence, const gis::Address& office);
    Person(std::string name, const gis::Address& residence, const gis::Address& office);
    Person(std::string firstname, std::string middlename, std::string lastname,
        const gis::Address& residence, const gis::Address& office);

    // Destructors
    ~Person();

    // Operator overloading
    bool operator==(const Person& peer) const;

    // Getters
    std::string getFirstName() const { return firstname; }
    std::string getMiddleName() const { return middlename; }
    std::string getLastName() const { return lastname; }
    gis::Address getResidence() const { return residence; }
    gis::Address getOffice() const { return office; }


    // Setters
    void setFirstName(const std::string& name) { this->firstname = name; }
    void setMiddleName(const std::string& name) { this->middlename = name; }
    void setLastName(const std::string& name) { this->lastname = name; }
    void setResidence(const gis::Address& object) { this->residence = object; }
    void setOffice(const gis::Address& object) { this->office = object; }

    // Additional methods
    std::string getName() const;
    void setName(const std::string& fullname);
    virtual Person copy();
    virtual void clear();
    virtual std::string print();
private:
    std::vector<std::string> splitName(const std::string& str, char delimiter);
};

typedef std::vector<Person > PersonArray;

} // namespace act

#endif //ACT_PERSON_H