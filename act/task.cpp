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

#include "task.h"

namespace act {

const short int Task::DEFAULT_STATUS = 0;

Task::Task()
        : name(), start(), stop(), status(DEFAULT_STATUS), remarks() {

}

Task::Task(const short int status)
        : name(), start(), stop(), status(DEFAULT_STATUS), remarks() {

}

Task::Task(const short int status, std::string remarks)
        : name(), start(), stop(), status(DEFAULT_STATUS), remarks(remarks) {

}

Task::Task(std::string name)
        : name(name), start(), stop(), status(DEFAULT_STATUS), remarks() {

}

Task::Task(std::string name, std::string remarks)
        : name(name), start(), stop(), status(DEFAULT_STATUS), remarks(remarks) {

}

Task::Task(std::string name, const long start, std::string remarks)
        : name(name), start(start), stop(), status(DEFAULT_STATUS), remarks(remarks) {

}

Task::Task(std::string name, const long start, const long stop)
        : name(name), start(start), stop(stop), status(DEFAULT_STATUS), remarks() {

}

Task::Task(std::string name, const long start, const long stop, std::string remarks)
        : name(name), start(start), stop(stop), status(DEFAULT_STATUS), remarks(remarks) {

}

Task::Task(std::string name, const short int status,
        const long start, const long stop, std::string remarks)
        : name(name), start(start), stop(stop), status(status), remarks(remarks) {

}

Task::~Task() {

}

bool Task::operator==(const Task& peer) const {
    return (name == peer.name) && (status == peer.status)
        && (start == peer.start) && (stop == peer.stop)
        && (remarks == peer.remarks);
}

Task Task::operator+(const Task& peer) const {
    return Task("+", (start + peer.start).getValue(), (start + peer.start).getValue());
}

Task Task::operator-(const Task& peer) const {
    return Task("-", (start - peer.start).getValue(), (start - peer.start).getValue());
}

Task Task::copy() {
    Task fresh(name, start.getValue(), stop.getValue(), status, remarks);
    return fresh;
}

void Task::clear() {
    name = remarks = "";
    start.clear();
    stop.clear();
    status = DEFAULT_STATUS;
    return;
}

std::string Task::print() {
    std::stringstream result;
    result << name << ",";
    result << start.print() << ",";
    result << stop.print() << ",";
	result << status << ",";
    result << remarks;
	return result.str();
}

} // namespace act