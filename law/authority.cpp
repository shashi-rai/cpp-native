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

#include "authority.h"

namespace law {

Authority::Authority() : name(), establish(), closure(), members() {

}

Authority::Authority(const act::StaffArray& members)
        : name(), establish(), closure(), members(members) {

}

Authority::Authority(std::string name)
        : name(name), establish(), closure(), members() {

}

Authority::Authority(const act::DateTime& closure)
        : name(), establish(), closure(closure), members() {

}

Authority::Authority(const act::DateTime& closure, const act::StaffArray& members)
        : name(), establish(), closure(closure), members(members) {

}

Authority::Authority(std::string name, const act::DateTime& closure)
        : name(name), establish(), closure(closure), members() {

}

Authority::Authority(std::string name, const act::DateTime& closure, const act::StaffArray& members)
        : name(name), establish(), closure(closure), members(members) {

}

Authority::Authority(const act::DateTime& establish, const act::DateTime& closure)
        : name(), establish(establish), closure(closure), members() {

}

Authority::Authority(const act::DateTime& establish, const act::DateTime& closure, const act::StaffArray& members)
        : name(), establish(establish), closure(closure), members(members) {

}

Authority::Authority(std::string name, const act::DateTime& establish, const act::DateTime& closure)
        : name(name), establish(establish), closure(closure), members() {

}

Authority::Authority(std::string name, const act::DateTime& establish, const act::DateTime& closure, const act::StaffArray& members)
        : name(name), establish(establish), closure(closure), members(members) {

}

Authority::~Authority() {

}

bool Authority::operator==(const Authority& peer) const {
    return (name == peer.name)
        && (establish == peer.establish)
        && (closure == peer.closure)
        && (members == peer.members);
}

Authority Authority::operator+(const Authority& peer) const {
    act::StaffArray result(members);
    result.insert(result.end(), peer.members.begin(), peer.members.end());
    return Authority("+", (establish + peer.establish), (closure + peer.closure), result);
}

Authority Authority::operator-(const Authority& peer) const {
    act::StaffArray result(members);
    for (act::StaffArray::const_iterator it = peer.members.begin(); it != peer.members.end(); ++it) {
        act::StaffArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Authority("-", (establish - peer.establish), (closure - peer.closure), result);
}

int Authority::getMemberCount() const {
    return members.size();
}

act::Staff Authority::get(const int index) const {
    act::Staff result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(members.size())) {
        return result;
    }
    return members[index];
}

void Authority::set(const int index, const act::Staff& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(members.size())) {
        // replace existing element
        members[index] = object;
    } else if (index == static_cast<int>(members.size())) {
        // append at end
        members.push_back(object);
    } else {
        // index beyond current size: append at end
        members.push_back(object);
    }
    return;
}

Authority Authority::copy() {
    Authority fresh(name, establish, closure, members);
    return fresh;
}

void Authority::clear() {
    name.clear();
    establish.clear();
    closure.clear();
    members.clear();
    return;
}

std::string Authority::print() {
    std::stringstream result;
	result << "A:"; 
    result << name << ",e:";
    result << establish.print() << ",c:";
    result << closure.print() << ",sz:";
	result << members.size() << "[";
    for (int i = 0; i < members.size(); i++) {
        result << "," << members[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace law