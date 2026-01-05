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

#ifndef DOC_SECTION_H
#define DOC_SECTION_H

#include <sstream>
#include <string>
#include <vector>
#include "page.h"

namespace doc {

class Section {
    std::string name;
    PageArray pages;
public:
    // Constructors
    Section();
    Section(const PageArray& pages);
    Section(std::string name);
    Section(std::string name, const PageArray& pages);

    // Destructors
    ~Section();

    // Operator overloading
    bool operator==(const Section& peer) const;
    Section operator+(const Section& peer) const;
    Section operator-(const Section& peer) const;

    // Access operator
    Page operator()(const int x) { return pages[x]; }
    const Page operator()(const int x) const { return pages[x]; }

    // Getters
    std::string getName() const { return name; }
    PageArray getPages() const { return pages; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setPages(const PageArray& data) { this->pages = data; }

    // Additional methods
    int getPageCount() const;
    Page get(const int index) const;
    void set(const int index, const Page& object);
    virtual Section copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Section > SectionArray;

} // namespace doc

#endif //DOC_SECTION_H