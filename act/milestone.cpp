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

#include "milestone.h"

namespace act {

Milestone::Milestone() : Task(), tasks() {

}

Milestone::Milestone(std::string name) : Task(name), tasks() {

}

Milestone::Milestone(std::string name, std::string remarks)
        : Task(name, remarks), tasks() {

}

Milestone::Milestone(const TaskArray& tasks)
        : Task(), tasks(tasks) {

}

Milestone::Milestone(std::string name, const TaskArray& tasks)
        : Task(name), tasks(tasks) {

}

Milestone::Milestone(std::string name, std::string remarks,
        const TaskArray& tasks)
        : Task(name, remarks), tasks(tasks) {

}

Milestone::Milestone(const short int status)
        : Task(status), tasks() {

}

Milestone::Milestone(const short int status, const TaskArray& tasks)
        : Task(status), tasks(tasks) {

}

Milestone::Milestone(const short int status, std::string remarks)
        : Task(status, remarks), tasks() {

}

Milestone::Milestone(const short int status, std::string remarks,
        const TaskArray& tasks)
        : Task(status, remarks), tasks(tasks) {

}

Milestone::Milestone(std::string name, const long start)
        : Task(name, start), tasks() {

}

Milestone::Milestone(std::string name, const long start, const TaskArray& tasks)
        : Task(name, start), tasks(tasks) {

}

Milestone::Milestone(std::string name, const long start, std::string remarks)
        : Task(name, start, remarks), tasks() {

}

Milestone::Milestone(std::string name, const long start, std::string remarks,
        const TaskArray& tasks)
        : Task(name, start, remarks), tasks(tasks) {

}

Milestone::Milestone(std::string name, const long start, const long stop)
        : Task(name, start, stop), tasks() {

}

Milestone::Milestone(std::string name, const long start, const long stop,
        const TaskArray& tasks)
        : Task(name, start, stop), tasks(tasks) {

}

Milestone::Milestone(std::string name, const long start, const long stop,
        std::string remarks)
        : Task(name, start, stop, remarks), tasks() {

}

Milestone::Milestone(std::string name, const long start, const long stop,
        std::string remarks, const TaskArray& tasks)
        : Task(name, start, stop, remarks), tasks(tasks) {

}

Milestone::Milestone(std::string name, const short int status,
        const long start, const long stop, std::string remarks)
        : Task(name, status, start, stop, remarks), tasks() {

}

Milestone::Milestone(std::string name, const short int status,
        const long start, const long stop, std::string remarks, const TaskArray& tasks)
        : Task(name, status, start, stop, remarks), tasks(tasks) {

}

Milestone::~Milestone() {

}

bool Milestone::operator==(const Milestone& peer) const {
    return (static_cast<const Task&>(*this) == static_cast<const Task&>(peer))
        && (tasks == peer.tasks);
}

Milestone Milestone::operator+(const Milestone& peer) const {
    TaskArray result(tasks);
    result.insert(result.end(), peer.tasks.begin(), peer.tasks.end());
    return Milestone("+", result);
}

Milestone Milestone::operator-(const Milestone& peer) const {
    TaskArray result(tasks);
    for (TaskArray::const_iterator it = peer.tasks.begin(); it != peer.tasks.end(); ++it) {
        TaskArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Milestone("-", result);
}

int Milestone::getTaskCount() const {
    return tasks.size();
}

Task Milestone::get(int index) const {
    Task result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(tasks.size())) {
        return result;
    }
    return tasks[index];
}

void Milestone::set(int index, const Task& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(tasks.size())) {
        // replace existing element
        tasks[index] = object;
    } else if (index == static_cast<int>(tasks.size())) {
        // append at end
        tasks.push_back(object);
    } else {
        // index beyond current size: append at end
        tasks.push_back(object);
    }
    return;
}

Task Milestone::copy() {
    Milestone fresh(getName(), getStatus(),
            getStart().getValue(), getStop().getValue(), getRemarks(), this->tasks);
    return fresh;
}

void Milestone::clear() {
    Task::clear();
    tasks.clear();
    return;
}

std::string Milestone::print() {
    std::stringstream result;
    result << "{M:";
	result << Task::print() << ",sz:";
	result << tasks.size() << "}";
	return result.str();
}

} // namespace act