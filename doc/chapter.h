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

#ifndef DOC_CHAPTER_H
#define DOC_CHAPTER_H

#include <sstream>
#include <string>
#include <vector>
#include "section.h"

namespace doc {

class Chapter {
    std::string name;
    SectionArray sections;
public:
    // Constructors
    Chapter();
    Chapter(const SectionArray& sections);
    Chapter(std::string name);
    Chapter(std::string name, const SectionArray& sections);

    // Destructors
    ~Chapter();

    // Operator overloading
    bool operator==(const Chapter& peer) const;
    Chapter operator+(const Chapter& peer) const;
    Chapter operator-(const Chapter& peer) const;

    // Access operator
    Section operator()(const int x) { return sections[x]; }
    const Section operator()(const int x) const { return sections[x]; }

    // Getters
    std::string getName() const { return name; }
    SectionArray getSections() const { return sections; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setSections(const SectionArray& segments) { this->sections = segments; }

    // Additional methods
    int getSectionCount() const;
    Section get(const int index) const;
    void set(const int index, const Section& object);
    virtual Chapter copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Chapter > ChapterArray;

} // namespace doc

#endif //DOC_CHAPTER_H