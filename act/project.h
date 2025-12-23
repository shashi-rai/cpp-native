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

#ifndef ACT_PROJECT_H
#define ACT_PROJECT_H

#include <sstream>
#include <string>
#include <vector>
#include "contract.h"
#include "staff.h"
#include "task.h"

namespace act {

class Project : public Task {
    Staff manager;
    ContractArray contracts;
public:
    // Constructors
    Project();
    Project(const Staff& manager);
    Project(std::string name);
    Project(std::string name, std::string remarks);
    Project(const ContractArray& contracts);
    Project(std::string name, const ContractArray& contracts);
    Project(std::string name, std::string remarks, const ContractArray& contracts);
    Project(const short int status);
    Project(const short int status, const ContractArray& contracts);
    Project(const short int status, std::string remarks);
    Project(const short int status, std::string remarks, const ContractArray& contracts);
    Project(std::string name, const long start);
    Project(std::string name, const long start, const ContractArray& contracts);
    Project(std::string name, const long start, std::string remarks);
    Project(std::string name, const long start, std::string remarks, const ContractArray& contracts);
    Project(std::string name, const long start, const long stop);
    Project(std::string name, const long start, const long stop, const ContractArray& contracts);
    Project(std::string name, const long start, const long stop, std::string remarks);
    Project(std::string name, const long start, const long stop, std::string remarks, const ContractArray& contracts);
    Project(std::string name, const short int status, const long start, const long stop, std::string remarks);
    Project(std::string name, const short int status, const long start, const long stop, std::string remarks, const ContractArray& contracts);

    // Destructors
    ~Project();

    // Operator overloading
    bool operator==(const Project& peer) const;
    Project operator+(const Project& peer) const;
    Project operator-(const Project& peer) const;

    // Getters
    Staff getManager() const { return manager; }
    ContractArray getContracts() const { return contracts; }

    // Setters
    void setManager(const Staff& person) { this->manager = person; }
    void setContacts(const ContractArray& objects) { this->contracts = objects; }

    // Additional methods
    int getContractCount() const;
    Contract get(int index) const;
    void set(int index, const Contract& object);
    virtual Task copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Project > ProjectArray;

} // namespace act

#endif //ACT_PROJECT_H