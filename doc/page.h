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

#ifndef DOC_PAGE_H
#define DOC_PAGE_H

#include <sstream>
#include <string>
#include <vector>
#include "clause.h"

namespace doc {

class Page {
    std::string name;
    ClauseArray clauses;
public:
    // Constructors
    Page();
    Page(const ClauseArray& clauses);
    Page(std::string name);
    Page(std::string name, const ClauseArray& clauses);

    // Destructors
    ~Page();

    // Operator overloading
    bool operator==(const Page& peer) const;
    Page operator+(const Page& peer) const;
    Page operator-(const Page& peer) const;

    // Access operator
    Clause operator()(const int x) { return clauses[x]; }
    const Clause operator()(const int x) const { return clauses[x]; }

    // Getters
    std::string getName() const { return name; }
    ClauseArray getClauses() const { return clauses; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setClauses(const ClauseArray& paragraphs) { this->clauses = paragraphs; }

    // Additional methods
    int getClauseCount() const;
    Clause get(const int index) const;
    void set(const int index, const Clause& object);
    virtual Page copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Page > PageArray;

} // namespace doc

#endif //DOC_PAGE_H