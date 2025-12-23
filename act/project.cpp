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

#include "project.h"

namespace act {

Project::Project() : Task(), manager(), contracts() {

}

Project::Project(const Staff& manager) : Task(), manager(), contracts() {

}

Project::Project(std::string name) : Task(name), manager(), contracts() {

}

Project::Project(std::string name, std::string remarks)
        : Task(name, remarks), manager(), contracts() {

}

Project::Project(const ContractArray& contracts)
        : Task(), manager(), contracts(contracts) {

}

Project::Project(std::string name, const ContractArray& contracts)
        : Task(name), manager(), contracts(contracts) {

}

Project::Project(std::string name, std::string remarks,
        const ContractArray& contracts)
        : Task(name, remarks), manager(), contracts(contracts) {

}

Project::Project(const short int status)
        : Task(status), manager(), contracts() {

}

Project::Project(const short int status, const ContractArray& contracts)
        : Task(status), manager(), contracts(contracts) {

}

Project::Project(const short int status, std::string remarks)
        : Task(status, remarks), manager(), contracts() {

}

Project::Project(const short int status, std::string remarks,
        const ContractArray& contracts)
        : Task(status, remarks), manager(), contracts(contracts) {

}

Project::Project(std::string name, const long start)
        : Task(name, start), manager(), contracts() {

}

Project::Project(std::string name, const long start, const ContractArray& contracts)
        : Task(name, start), manager(), contracts(contracts) {

}

Project::Project(std::string name, const long start, std::string remarks)
        : Task(name, start, remarks), manager(), contracts() {

}

Project::Project(std::string name, const long start, std::string remarks,
        const ContractArray& contracts)
        : Task(name, start, remarks), manager(), contracts(contracts) {

}

Project::Project(std::string name, const long start, const long stop)
        : Task(name, start, stop), manager(), contracts() {

}

Project::Project(std::string name, const long start, const long stop,
        const ContractArray& contracts)
        : Task(name, start, stop), manager(), contracts(contracts) {

}

Project::Project(std::string name, const long start, const long stop,
        std::string remarks)
        : Task(name, start, stop, remarks), manager(), contracts() {

}

Project::Project(std::string name, const long start, const long stop,
        std::string remarks, const ContractArray& contracts)
        : Task(name, start, stop, remarks), manager(), contracts(contracts) {

}

Project::Project(std::string name, const short int status,
        const long start, const long stop, std::string remarks)
        : Task(name, status, start, stop, remarks), manager(), contracts() {

}

Project::Project(std::string name, const short int status,
        const long start, const long stop, std::string remarks, const ContractArray& contracts)
        : Task(name, status, start, stop, remarks), manager(), contracts(contracts) {

}

Project::~Project() {

}

bool Project::operator==(const Project& peer) const {
    return (static_cast<const Task&>(*this) == static_cast<const Task&>(peer))
        && (manager == peer.manager) && (contracts == peer.contracts);
}

Project Project::operator+(const Project& peer) const {
    ContractArray result(contracts);
    result.insert(result.end(), peer.contracts.begin(), peer.contracts.end());
    return Project("+", result);
}

Project Project::operator-(const Project& peer) const {
    ContractArray result(contracts);
    for (ContractArray::const_iterator it = peer.contracts.begin(); it != peer.contracts.end(); ++it) {
        ContractArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Project("-", result);
}

int Project::getContractCount() const {
    return contracts.size();
}

Contract Project::get(int index) const {
    Contract result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(contracts.size())) {
        return result;
    }
    return contracts[index];
}

void Project::set(int index, const Contract& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(contracts.size())) {
        // replace existing element
        contracts[index] = object;
    } else if (index == static_cast<int>(contracts.size())) {
        // append at end
        contracts.push_back(object);
    } else {
        // index beyond current size: append at end
        contracts.push_back(object);
    }
    return;
}

Task Project::copy() {
    Project fresh(getName(), getStatus(),
            getStart().getValue(), getStop().getValue(), getRemarks(), this->contracts);
    return fresh;
}

void Project::clear() {
    Task::clear();
    contracts.clear();
    return;
}

std::string Project::print() {
    std::stringstream result;
    result << "{P:";
	result << Task::print() << ",sz:";
	result << contracts.size() << "}";
	return result.str();
}

} // namespace act