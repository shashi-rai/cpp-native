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

#ifndef DOC_DOCUMENT_H
#define DOC_DOCUMENT_H

#include <sstream>
#include <string>
#include <vector>
#include "chapter.h"
#include "../act/datetime.h"

namespace doc {

class Document {
    std::string name;
    act::DateTime created;
    act::DateTime expired;
    ChapterArray chapters;
public:
    // Constructors
    Document();
    Document(const ChapterArray& chapters);
    Document(std::string name);
    Document(std::string name, const ChapterArray& chapters);
    Document(const act::DateTime& expired);
    Document(const act::DateTime& expired, const ChapterArray& chapters);
    Document(std::string name, const act::DateTime& expired);
    Document(std::string name, const act::DateTime& expired, const ChapterArray& chapters);
    Document(const act::DateTime& created, const act::DateTime& expired);
    Document(const act::DateTime& created, const act::DateTime& expired, const ChapterArray& chapters);
    Document(std::string name, const act::DateTime& created, const act::DateTime& expired);
    Document(std::string name, const act::DateTime& created, const act::DateTime& expired, const ChapterArray& chapters);

    // Destructors
    ~Document();

    // Operator overloading
    bool operator==(const Document& peer) const;
    Document operator+(const Document& peer) const;
    Document operator-(const Document& peer) const;

    // Access operator
    Chapter operator()(const int x) { return chapters[x]; }
    const Chapter operator()(const int x) const { return chapters[x]; }

    // Getters
    std::string getName() const { return name; }
    act::DateTime getCreated() const { return created; }
    act::DateTime getExpired() const { return expired; }
    ChapterArray getChapters() const { return chapters; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setCreated(const act::DateTime& timestamp) { this->created = timestamp; }
    void setExpired(const act::DateTime& timestamp) { this->expired = timestamp; }
    void setChapters(const ChapterArray& articles) { this->chapters = articles; }

    // Additional methods
    int getChapterCount() const;
    Chapter get(const int index) const;
    void set(const int index, const Chapter& object);
    virtual Document copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Document > DocumentArray;

} // namespace doc

#endif //DOC_DOCUMENT_H