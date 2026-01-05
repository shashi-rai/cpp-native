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

#include "chapter.h"

namespace doc {

Chapter::Chapter()
        : name(), sections() {

}

Chapter::Chapter(const SectionArray& sections)
        : name(), sections(sections) {

}

Chapter::Chapter(std::string name)
        : name(name), sections() {

}

Chapter::Chapter(std::string name, const SectionArray& sections)
        : name(name), sections(sections) {

}

Chapter::~Chapter() {

}

bool Chapter::operator==(const Chapter& peer) const {
    return (name == peer.name) && (sections == peer.sections);
}

Chapter Chapter::operator+(const Chapter& peer) const {
    SectionArray result(sections);
    result.insert(result.end(), peer.sections.begin(), peer.sections.end());
    return Chapter("+", result);
}

Chapter Chapter::operator-(const Chapter& peer) const {
    SectionArray result(sections);
    for (SectionArray::const_iterator it = peer.sections.begin(); it != peer.sections.end(); ++it) {
        SectionArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Chapter("-", result);
}

int Chapter::getSectionCount() const {
    return sections.size();
}

Section Chapter::get(const int index) const {
    Section result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(sections.size())) {
        return result;
    }
    return sections[index];
}

void Chapter::set(const int index, const Section& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(sections.size())) {
        // replace existing element
        sections[index] = object;
    } else if (index == static_cast<int>(sections.size())) {
        // append at end
        sections.push_back(object);
    } else {
        // index beyond current size: append at end
        sections.push_back(object);
    }
    return;
}

Chapter Chapter::copy() {
    Chapter fresh(getName(), sections);
    return fresh;
}

void Chapter::clear() {
    name.clear();
    sections.clear();
    return;
}

std::string Chapter::print() {
    std::stringstream result;
    result << "ch:";
	result << name << ",sz:";
	result << sections.size() << "[";
    for (int i = 0; i < sections.size(); i++) {
        result << "," << sections[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace doc