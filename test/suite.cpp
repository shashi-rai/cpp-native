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

#include "suite.h"

namespace test {

const std::string Suite::DEFAULT_NAME = "Sanity Test";

Suite::Suite()
        : cfg::System(DEFAULT_NAME),
        mathematics(), physics(), chemistry(), biology(), consciousness() {

}

Suite::Suite(const std::string name)
        : cfg::System(name),
        mathematics(), physics(), chemistry(), biology(), consciousness() {

}

Suite::Suite(const int argc, char* argv[])
        : cfg::System(DEFAULT_NAME),
        mathematics(), physics(), chemistry(), biology(), consciousness() {
    cfg::System::setParameters(argc, argv);
}

Suite::Suite(const cfg::CommandLine& object)
        : cfg::System(DEFAULT_NAME),
        mathematics(), physics(), chemistry(), biology(), consciousness() {
    cfg::System::setParameters(object);
}

Suite::~Suite() {

}

int Suite::main() {
    return main(cfg::System::getParameters());
}

int Suite::main(const int argc, char* argv[]) {
    cfg::System::setParameters(argc, argv);
    return main(cfg::System::getParameters());
}

int Suite::main(const cfg::CommandLine& object) {
    cfg::System::printStartedMessage();
    mathematics_concept(object);
    physics_concept(object);
    chemistry_concept(object);
    biology_concept(object);
    consciousness_concept(object);
    cfg::System::printStoppedMessage();
    return 0;
}

void Suite::mathematics_concept(const cfg::CommandLine& parameters) {
    cfg::CommandLine cmdline = parameters;
    mathematics.run(cmdline);
}

void Suite::physics_concept(const cfg::CommandLine& parameters) {
    cfg::CommandLine cmdline = parameters;
    physics.run(cmdline);
}

void Suite::chemistry_concept(const cfg::CommandLine& parameters) {
    cfg::CommandLine cmdline = parameters;
    chemistry.run(cmdline);
}

void Suite::biology_concept(const cfg::CommandLine& parameters) {
    cfg::CommandLine cmdline = parameters;
    biology.run(cmdline);
}

void Suite::consciousness_concept(const cfg::CommandLine& parameters) {
    cfg::CommandLine cmdline = parameters;
    consciousness.run(cmdline);
}

} // namespace test