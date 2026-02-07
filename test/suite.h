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

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "../inc/testing.h"
#include "mathematics.h"
#include "physics.h"
#include "chemistry.h"
#include "biology.h"
#include "consciousness.h"

namespace test {

class Suite : protected test::System {
    Mathematics mathematics;
    Physics physics;
    Chemistry chemistry;
    Biology biology;
    Consciousness consciousness;
public:
    Suite();
    Suite(const std::string name);
    Suite(const int argc, char* argv[]);
    Suite(const test::CommandLine& object);
    ~Suite();
public:
    int main();
    int main(const int argc, char* argv[]);
    int main(const test::CommandLine& object);
    void mathematics_concept(const test::CommandLine& parameters);
    void physics_concept(const test::CommandLine& parameters);
    void chemistry_concept(const test::CommandLine& parameters);
    void biology_concept(const test::CommandLine& parameters);
    void consciousness_concept(const test::CommandLine& parameters);

public:
    static const std::string DEFAULT_NAME;
};

} // namespace test

#endif //TEST_SUITE_H