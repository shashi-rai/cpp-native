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

#include "contract.h"

namespace act {

Contract::Contract() : Task(), order(), milestones() {

}

Contract::Contract(std::string name)
        : Task(name), order(), milestones() {

}

Contract::Contract(std::string name, const Order& order)
        : Task(name), order(order), milestones() {

}

Contract::Contract(std::string name, std::string remarks)
        : Task(name, remarks), order(), milestones() {

}

Contract::Contract(const MilestoneArray& milestones)
        : Task(), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const MilestoneArray& milestones)
        : Task(name), order(), milestones(milestones) {

}

Contract::Contract(std::string name, std::string remarks,
        const MilestoneArray& milestones)
        : Task(name, remarks), order(), milestones(milestones) {

}

Contract::Contract(const short int status)
        : Task(status), order(), milestones() {

}

Contract::Contract(const short int status, const MilestoneArray& milestones)
        : Task(status), order(), milestones(milestones) {

}

Contract::Contract(const short int status, std::string remarks)
        : Task(status, remarks), order(), milestones() {

}

Contract::Contract(const short int status, std::string remarks,
        const MilestoneArray& milestones)
        : Task(status, remarks), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const long start)
        : Task(name, start), order(), milestones() {

}

Contract::Contract(std::string name, const long start, const MilestoneArray& milestones)
        : Task(name, start), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const long start, std::string remarks)
        : Task(name, start, remarks), order(), milestones() {

}

Contract::Contract(std::string name, const long start, std::string remarks,
        const MilestoneArray& milestones)
        : Task(name, start, remarks), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const long start, const long stop)
        : Task(name, start, stop), order(), milestones() {

}

Contract::Contract(std::string name, const long start, const long stop,
        const MilestoneArray& milestones)
        : Task(name, start, stop), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const long start, const long stop,
        std::string remarks)
        : Task(name, start, stop, remarks), order(), milestones() {

}

Contract::Contract(std::string name, const long start, const long stop,
        std::string remarks, const MilestoneArray& milestones)
        : Task(name, start, stop, remarks), order(), milestones(milestones) {

}

Contract::Contract(std::string name, const short int status,
        const long start, const long stop, std::string remarks)
        : Task(name, status, start, stop, remarks), order(), milestones() {

}

Contract::Contract(std::string name, const short int status,
        const long start, const long stop, std::string remarks, const MilestoneArray& milestones)
        : Task(name, status, start, stop, remarks), order(), milestones(milestones) {

}

Contract::~Contract() {

}

bool Contract::operator==(const Contract& peer) const {
    return (static_cast<const Task&>(*this) == static_cast<const Task&>(peer))
        && (order == peer.order) && (milestones == peer.milestones);
}

Contract Contract::operator+(const Contract& peer) const {
    MilestoneArray result(milestones);
    result.insert(result.end(), peer.milestones.begin(), peer.milestones.end());
    return Contract("+", result);
}

Contract Contract::operator-(const Contract& peer) const {
    MilestoneArray result(milestones);
    for (MilestoneArray::const_iterator it = peer.milestones.begin(); it != peer.milestones.end(); ++it) {
        MilestoneArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Contract("-", result);
}

int Contract::getMilestoneCount() const {
    return milestones.size();
}

Milestone Contract::get(int index) const {
    Milestone result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(milestones.size())) {
        return result;
    }
    return milestones[index];
}

void Contract::set(int index, const Milestone& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(milestones.size())) {
        // replace existing element
        milestones[index] = object;
    } else if (index == static_cast<int>(milestones.size())) {
        // append at end
        milestones.push_back(object);
    } else {
        // index beyond current size: append at end
        milestones.push_back(object);
    }
    return;
}

Task Contract::copy() {
    Contract fresh(getName(), getStatus(),
            getStart().getValue(), getStop().getValue(), getRemarks(), this->milestones);
    return fresh;
}

void Contract::clear() {
    Task::clear();
    milestones.clear();
    return;
}

std::string Contract::print() {
    std::stringstream result;
    result << "{C:";
	result << Task::print() << ",sz:";
	result << milestones.size() << "}";
	return result.str();
}

} // namespace act