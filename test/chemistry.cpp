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

#include "chemistry.h"

namespace test {

const std::string Chemistry::DEFAULT_NAME = "Chemistry";

Chemistry::Chemistry()
        : test::System(DEFAULT_NAME) {

}

Chemistry::Chemistry(const std::string name)
        : test::System(name) {

}

Chemistry::Chemistry(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Chemistry::Chemistry(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Chemistry::Chemistry(const test::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Chemistry::Chemistry(const std::string name, const test::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Chemistry::~Chemistry() {

}

int Chemistry::run() {
    return run(test::System::getParameters());
}

int Chemistry::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Chemistry::run(const test::CommandLine& object) {
    test::System::printStartedMessage();
    test::System::printStoppedMessage();
    return 0;
}

void Chemistry::nucleus_concept() {

}

void Chemistry::orbital_concept() {

}

void Chemistry::atom_concept() {

}

void Chemistry::molecule_concept() {

}

} // namespace test