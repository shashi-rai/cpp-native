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

#ifndef ACT_CONTRACT_H
#define ACT_CONTRACT_H

#include <sstream>
#include <string>
#include <vector>
#include "datetime.h"
#include "milestone.h"
#include "order.h"

namespace act {

class Contract : public Task {
    Order order;
    MilestoneArray milestones;
public:
    // Constructors
    Contract();
    Contract(std::string name);
    Contract(std::string name, const Order& order);
    Contract(std::string name, std::string remarks);
    Contract(const MilestoneArray& milestones);
    Contract(std::string name, const MilestoneArray& milestones);
    Contract(std::string name, std::string remarks, const MilestoneArray& milestones);
    Contract(const short int status);
    Contract(const short int status, const MilestoneArray& milestones);
    Contract(const short int status, std::string remarks);
    Contract(const short int status, std::string remarks, const MilestoneArray& milestones);
    Contract(std::string name, const long start);
    Contract(std::string name, const long start, const MilestoneArray& milestones);
    Contract(std::string name, const long start, std::string remarks);
    Contract(std::string name, const long start, std::string remarks, const MilestoneArray& milestones);
    Contract(std::string name, const long start, const long stop);
    Contract(std::string name, const long start, const long stop, const MilestoneArray& milestones);
    Contract(std::string name, const long start, const long stop, std::string remarks);
    Contract(std::string name, const long start, const long stop, std::string remarks, const MilestoneArray& milestones);
    Contract(std::string name, const short int status, const long start, const long stop, std::string remarks);
    Contract(std::string name, const short int status, const long start, const long stop, std::string remarks, const MilestoneArray& milestones);

    // Destructors
    ~Contract();

    // Operator overloading
    bool operator==(const Contract& peer) const;
    Contract operator+(const Contract& peer) const;
    Contract operator-(const Contract& peer) const;

    // Getters
    Order getOrder() const { return order; }
    MilestoneArray getMilestones() const { return milestones; }

    // Setters
    void setOrder(const Order& object) { this->order = object; }
    void setMilestones(const MilestoneArray& objects) { this->milestones = objects; }

    // Additional methods
    int getMilestoneCount() const;
    Milestone get(int index) const;
    void set(int index, const Milestone& object);
    virtual Task copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Contract > ContractArray;

} // namespace act

#endif //ACT_CONTRACT_H