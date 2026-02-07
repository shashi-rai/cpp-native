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

#include "biology.h"

namespace test {

const std::string Biology::DEFAULT_NAME = "Biology";

Biology::Biology()
        : test::System(DEFAULT_NAME) {

}

Biology::Biology(const std::string name)
        : test::System(name) {

}

Biology::Biology(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Biology::Biology(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Biology::Biology(const test::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Biology::Biology(const std::string name, const test::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Biology::~Biology() {

}

int Biology::run() {
    return run(test::System::getParameters());
}

int Biology::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Biology::run(const test::CommandLine& object) {
    test::System::printStartedMessage();
    test::System::printStoppedMessage();
    return 0;
}

void Biology::protein_concept() {

}

void Biology::rna_concept() {

}

void Biology::dna_concept() {

}

void Biology::membrane_concept() {

}

void Biology::cell_concept() {

}

} // namespace test