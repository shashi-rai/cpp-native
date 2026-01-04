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

#include "data.h"

namespace bit {

Data::Data()
        : name(), bytes() {

}

Data::Data(const BinaryArray& bytes)
        : name(), bytes(bytes) {

}

Data::Data(std::string name)
        : name(name), bytes() {

}

Data::Data(std::string name, const BinaryArray& bytes)
        : name(name), bytes(bytes) {

}

Data::~Data() {

}

bool Data::operator==(const Data& peer) const {
    return (name == peer.name) && (bytes == peer.bytes);
}

Data Data::operator+(const Data& peer) const {
    BinaryArray result(bytes);
    result.insert(result.end(), peer.bytes.begin(), peer.bytes.end());
    return Data("+", result);
}

Data Data::operator-(const Data& peer) const {
    BinaryArray result(bytes);
    for (BinaryArray::const_iterator it = peer.bytes.begin(); it != peer.bytes.end(); ++it) {
        BinaryArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Data("-", result);
}

int Data::getByteCount() const {
    return bytes.size();
}

Binary Data::get(const int index) const {
    Binary result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(bytes.size())) {
        return result;
    }
    return bytes[index];
}

void Data::set(const int index, const Binary& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(bytes.size())) {
        // replace existing element
        bytes[index] = object;
    } else if (index == static_cast<int>(bytes.size())) {
        // append at end
        bytes.push_back(object);
    } else {
        // index beyond current size: append at end
        bytes.push_back(object);
    }
    return;
}

Data Data::copy() {
    Data fresh(getName(), bytes);
    return fresh;
}

void Data::clear() {
    name.clear();
    bytes.clear();
    return;
}

std::string Data::print() {
    std::stringstream result;
    result << "[d:";
	result << name << ",sz:";
	result << bytes.size() << "}[";
    for (int i = 0; i < bytes.size(); i++) {
        result << "," << bytes[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace bit