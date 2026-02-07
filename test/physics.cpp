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

#include "physics.h"

namespace test {

const std::string Physics::DEFAULT_NAME = "Physics";

Physics::Physics()
        : test::System(DEFAULT_NAME) {

}

Physics::Physics(const std::string name)
        : test::System(name) {

}

Physics::Physics(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Physics::Physics(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Physics::Physics(const test::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Physics::Physics(const std::string name, const test::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Physics::~Physics() {

}

int Physics::run() {
    return run(test::System::getParameters());
}

int Physics::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Physics::run(const test::CommandLine& object) {
    test::System::printStartedMessage();
    test::System::setParameters(object);
    density_concept();
    test::System::printStoppedMessage();
    return 0;
}

void Physics::time_concept() {

}

void Physics::velocity_concept() {

}

void Physics::acceleration_concept() {

}

void Physics::charge_concept() {

}

void Physics::current_concept() {

}

void Physics::mass_concept() {

}

void Physics::momentum_concept() {

}

void Physics::temperature_concept() {

}

void Physics::heat_concept() {

}

void Physics::energy_concept() {

}

void Physics::density_concept() {
    for (int i=0; i < 3; i++) {
        shp::Signal intrinsic(1.1f);
        qft::Density a("M", 2.0f, 0, "C");
        intrinsic.setOrientation(shp::Direction::DEGREE_001 * i); a.setThermalFactor(intrinsic);
        a.setParameterThreshold(i+1);
        std::cout << a.print()
            << " S: " << a.getScalarFlux().print()
            << " V: " << a.getVectorFlux().print()
            << " A: " << a.getScalarThermalDrift().print()
            << " D: " << a.getScalarThermalTotal().print()
            << " A: " << a.getThermalFieldDrift().print()
            << " D: " << a.getThermalFieldTotal().print()
            << std::endl;
    }
}

void Physics::force_concept() {

}

void Physics::field_concept() {

}

void Physics::electricity_concept() {

}

void Physics::magnetism_concept() {

}

void Physics::thermal_concept() {

}

void Physics::particle_concept() {

}

} // namespace test