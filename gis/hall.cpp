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

#include "hall.h"

namespace gis {

Hall::Hall()
        : Indoor(), racks() {

}

Hall::Hall(const RackArray& racks)
        : Indoor(), racks() {

}

Hall::Hall(const std::string room)
        : Indoor(room), racks() {

}

Hall::Hall(const std::string room, const std::string unit)
        : Indoor(room, unit), racks() {

}

Hall::Hall(const std::string room, const std::string unit, const std::string floor)
        : Indoor(room, unit, floor), racks() {

}

Hall::Hall(const std::string room, const RackArray& racks)
        : Indoor(room), racks(racks) {

}

Hall::Hall(const std::string room, const std::string unit, const RackArray& racks)
        : Indoor(room, unit), racks(racks) {

}

Hall::Hall(const std::string room, const std::string unit, const std::string floor, const RackArray& racks)
        : Indoor(room, unit, floor), racks(racks) {

}

Hall::~Hall() {

}

bool Hall::operator==(const Hall& peer) const {
    return (static_cast<const Indoor&>(*this) == static_cast<const Indoor&>(peer))
        && (racks == peer.racks);
}

Hall Hall::operator+(const Hall& peer) const {
    RackArray result(racks);
    result.insert(result.end(), peer.racks.begin(), peer.racks.end());
    return Hall("+", result);
}

Hall Hall::operator-(const Hall& peer) const {
    RackArray result(racks);
    for (RackArray::const_iterator it = peer.racks.begin(); it != peer.racks.end(); ++it) {
        RackArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Hall("-", result);
}

int Hall::getRackCount() const {
    return racks.size();
}

Rack Hall::get(const int index) const {
    Rack result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(racks.size())) {
        return result;
    }
    return racks[index];
}

void Hall::set(const int index, const Rack& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(racks.size())) {
        // replace existing element
        racks[index] = object;
    } else if (index == static_cast<int>(racks.size())) {
        // append at end
        racks.push_back(object);
    } else {
        // index beyond current size: append at end
        racks.push_back(object);
    }
    return;
}

Hall Hall::copy() {
    Hall fresh(Indoor::getRoom(), Indoor::getUnit(), Indoor::getFloor(), this->racks);
    return fresh;
}

void Hall::clear() {
    Indoor::clear();
    racks.clear();
    return;
}

std::string Hall::print() const {
    std::stringstream result;
    result << Indoor::print();
    result << printRacks();
	return result.str();
}

std::string Hall::printRacks() const {
    std::stringstream result; int size = racks.size();
    if (size > 0) {
        result << ",sz:";
	    result << racks.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << racks[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace gis