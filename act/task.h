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

#ifndef ACT_TASK_H
#define ACT_TASK_H

#include <sstream>
#include <string>
#include <vector>
#include "price.h"
#include "datetime.h"

namespace act {

class Task {
    std::string name;
    DateTime start;
    DateTime stop;
    short int status;
    std::string remarks;
public:
    // Constructors
    Task();
    Task(const short int status);
    Task(const short int status, std::string remarks);
    Task(std::string name);
    Task(std::string name, std::string remarks);
    Task(std::string name, const long start);
    Task(std::string name, const long start, std::string remarks);
    Task(std::string name, const long start, const long stop);
    Task(std::string name, const long start, const long stop, std::string remarks);
    Task(std::string name, const short int status, const long start, const long stop, std::string remarks);

    // Destructors
    ~Task();

    // Operator overloading
    bool operator==(const Task& peer) const;
    Task operator+(const Task& peer) const;
    Task operator-(const Task& peer) const;

    // Getters
    std::string getName() const { return name; }
    DateTime getStart() const { return start; }
    DateTime getStop() const { return stop; }
    short int getStatus() const { return status; }
    std::string getRemarks() const { return remarks; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setStart(const DateTime& date) { this->start = date; }
    void setStop(const DateTime& date) { this->stop = date; }
    void setStatus(const short int code) { this->status = code; }
    void setRemarks(const std::string& description) { this->remarks = description; }

    // Additional methods
    virtual Task copy();
    virtual void clear();
    virtual std::string print();

public:
    static const short int DEFAULT_STATUS;
};

typedef std::vector<Task > TaskArray;

} // namespace act

#endif //ACT_TASK_H