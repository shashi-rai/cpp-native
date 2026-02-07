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

#include "consciousness.h"

namespace test {

const std::string Consciousness::DEFAULT_NAME = "Consciousness";

Consciousness::Consciousness()
        : test::System(DEFAULT_NAME) {

}

Consciousness::Consciousness(const std::string name)
        : test::System(name) {

}

Consciousness::Consciousness(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Consciousness::Consciousness(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Consciousness::Consciousness(const cfg::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Consciousness::Consciousness(const std::string name, const cfg::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Consciousness::~Consciousness() {

}

int Consciousness::run() {
    return run(test::System::getParameters());
}

int Consciousness::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Consciousness::run(const cfg::CommandLine& object) {
    test::System::printStartedMessage();
    simple_training();
    test::System::printStoppedMessage();
    return 0;
}

void Consciousness::simple_training() {
    con::Self self("M");
    self.setBehaviour(con::Stimulus("A", 5), con::Response("B", 3));
    shp::Signal output = self.getBehaviour(con::Stimulus("A"));
    std::cout << output.print() << std::endl;
}

} // namespace test