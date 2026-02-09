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

#ifndef TEST_FINANCE_H
#define TEST_FINANCE_H

#include "../inc/testing.h"

namespace test {

class Finance : protected cfg::System {

public:
    Finance();
    Finance(const std::string name);
    Finance(const int argc, char* argv[]);
    Finance(const std::string name, const int argc, char* argv[]);
    Finance(const cfg::CommandLine& object);
    Finance(const std::string name, const cfg::CommandLine& object);
    ~Finance();
public:
    int run();
    int run(const int argc, char* argv[]);
    int run(const cfg::CommandLine& object);
    void wealth_concept();

public:
    static const std::string DEFAULT_NAME;
};

} // namespace test

#endif //TEST_FINANCE_H