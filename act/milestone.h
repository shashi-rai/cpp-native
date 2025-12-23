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

#ifndef ACT_MILESTONE_H
#define ACT_MILESTONE_H

#include <sstream>
#include <string>
#include <vector>
#include "task.h"

namespace act {

class Milestone : public Task {
    TaskArray tasks;
public:
    // Constructors
    Milestone();
    Milestone(std::string name);
    Milestone(std::string name, std::string remarks);
    Milestone(const TaskArray& tasks);
    Milestone(std::string name, const TaskArray& tasks);
    Milestone(std::string name, std::string remarks, const TaskArray& tasks);
    Milestone(const short int status);
    Milestone(const short int status, const TaskArray& tasks);
    Milestone(const short int status, std::string remarks);
    Milestone(const short int status, std::string remarks, const TaskArray& tasks);
    Milestone(std::string name, const long start);
    Milestone(std::string name, const long start, const TaskArray& tasks);
    Milestone(std::string name, const long start, std::string remarks);
    Milestone(std::string name, const long start, std::string remarks, const TaskArray& tasks);
    Milestone(std::string name, const long start, const long stop);
    Milestone(std::string name, const long start, const long stop, const TaskArray& tasks);
    Milestone(std::string name, const long start, const long stop, std::string remarks);
    Milestone(std::string name, const long start, const long stop, std::string remarks, const TaskArray& tasks);
    Milestone(std::string name, const short int status, const long start, const long stop, std::string remarks);
    Milestone(std::string name, const short int status, const long start, const long stop, std::string remarks, const TaskArray& tasks);

    // Destructors
    ~Milestone();

    // Operator overloading
    bool operator==(const Milestone& peer) const;
    Milestone operator+(const Milestone& peer) const;
    Milestone operator-(const Milestone& peer) const;

    // Getters
    TaskArray getTasks() const { return tasks; }

    // Setters
    void setTasks(const TaskArray& objects) { this->tasks = objects; }

    // Additional methods
    int getTaskCount() const;
    Task get(int index) const;
    void set(int index, const Task& object);
    virtual Task copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Milestone > MilestoneArray;

} // namespace act

#endif //ACT_MILESTONE_H