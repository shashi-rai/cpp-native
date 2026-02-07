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

#ifndef TEST_PHYSICS_H
#define TEST_PHYSICS_H

#include "../inc/testing.h"
#include "../qft/density.h"

namespace test {

class Physics : protected test::System {

public:
    Physics();
    Physics(const std::string name);
    Physics(const int argc, char* argv[]);
    Physics(const std::string name, const int argc, char* argv[]);
    Physics(const test::CommandLine& object);
    Physics(const std::string name, const test::CommandLine& object);
    ~Physics();
public:
    int run(const test::CommandLine& object);
    void time_concept();
    void velocity_concept();
    void acceleration_concept();
    void charge_concept();
    void current_concept();
    void mass_concept();
    void momentum_concept();
    void temperature_concept();
    void heat_concept();
    void energy_concept();
    void density_concept();
    void force_concept();
    void field_concept();
    void electricity_concept();
    void magnetism_concept();
    void thermal_concept();
    void particle_concept();

public:
    static const std::string DEFAULT_NAME;
};

} // namespace test

#endif //TEST_PHYSICS_H