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

#include "section.h"

namespace doc {

Section::Section()
        : name(), pages() {

}

Section::Section(const PageArray& pages)
        : name(), pages(pages) {

}

Section::Section(std::string name)
        : name(name), pages() {

}

Section::Section(std::string name, const PageArray& pages)
        : name(name), pages(pages) {

}

Section::~Section() {

}

bool Section::operator==(const Section& peer) const {
    return (name == peer.name) && (pages == peer.pages);
}

Section Section::operator+(const Section& peer) const {
    PageArray result(pages);
    result.insert(result.end(), peer.pages.begin(), peer.pages.end());
    return Section("+", result);
}

Section Section::operator-(const Section& peer) const {
    PageArray result(pages);
    for (PageArray::const_iterator it = peer.pages.begin(); it != peer.pages.end(); ++it) {
        PageArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Section("-", result);
}

int Section::getPageCount() const {
    return pages.size();
}

Page Section::get(const int index) const {
    Page result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(pages.size())) {
        return result;
    }
    return pages[index];
}

void Section::set(const int index, const Page& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(pages.size())) {
        // replace existing element
        pages[index] = object;
    } else if (index == static_cast<int>(pages.size())) {
        // append at end
        pages.push_back(object);
    } else {
        // index beyond current size: append at end
        pages.push_back(object);
    }
    return;
}

Section Section::copy() {
    Section fresh(getName(), pages);
    return fresh;
}

void Section::clear() {
    name.clear();
    pages.clear();
    return;
}

std::string Section::print() {
    std::stringstream result;
    result << "s:";
	result << name << ",sz:";
	result << pages.size() << "[";
    for (int i = 0; i < pages.size(); i++) {
        result << "," << pages[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace doc