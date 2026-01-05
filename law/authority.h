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

#ifndef LAW_AUTHORITY_H
#define LAW_AUTHORITY_H

#include <sstream>
#include <string>
#include <vector>
#include "../act/datetime.h"
#include "../act/staff.h"

namespace law {

class Authority {
    std::string name;
    act::DateTime establish;
    act::DateTime closure;
    act::StaffArray members;
public:
    // Constructors
    Authority();
    Authority(const act::StaffArray& members);
    Authority(std::string name);
    Authority(const act::DateTime& closure);
    Authority(const act::DateTime& closure, const act::StaffArray& members);
    Authority(std::string name, const act::DateTime& closure);
    Authority(std::string name, const act::DateTime& closure, const act::StaffArray& members);
    Authority(const act::DateTime& establish, const act::DateTime& closure);
    Authority(const act::DateTime& establish, const act::DateTime& closure, const act::StaffArray& members);
    Authority(std::string name, const act::DateTime& establish, const act::DateTime& closure);
    Authority(std::string name, const act::DateTime& establish, const act::DateTime& closure, const act::StaffArray& members);

    // Destructors
    ~Authority();

    // Operator overloading
    bool operator==(const Authority& peer) const;
    Authority operator+(const Authority& peer) const;
    Authority operator-(const Authority& peer) const;

    // Getters
    std::string getName() const { return name; }
    act::DateTime getEstablish() const { return establish; }
    act::DateTime getClosure() const { return closure; }
    act::StaffArray getMembers() const { return members; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setEstablish(const act::DateTime& timestamp) { this->establish = timestamp; }
    void setClosure(const act::DateTime& timestamp) { this->closure = timestamp; }
    void setMembers(const act::StaffArray& persons) { this->members = persons; }

    // Additional methods
    int getMemberCount() const;
    act::Staff get(const int index) const;
    void set(const int index, const act::Staff& object);
    virtual Authority copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Authority > AuthorityArray;

} // namespace law

#endif //LAW_AUTHORITY_H