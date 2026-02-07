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

#ifndef INC_TESTING_H
#define INC_TESTING_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace test {

typedef std::vector<std::string > CommandLine;

class System {
    std::string name;
    CommandLine parameters;
public:
    System();
    System(const CommandLine& parameters);
    System(const std::string name);
    System(const std::string name, const CommandLine& parameters);
    ~System();

    // Getters
    std::string getName() const;
    CommandLine getParameters() const;

    // Setters
    void setName(const std::string name);
    void setParameters(const CommandLine& object);

public:
    std::string getParameter(const int index) const;
    void setParameters(const int argc, char* argv[]);
    void clear();
    void printStartedMessage() const;
    void printStoppedMessage() const;
    std::string print() const;
};

} // namespace test

#endif //INC_TESTING_H