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

#include "mathematics.h"

namespace test {

const std::string Mathematics::DEFAULT_NAME = "Mathematics";

Mathematics::Mathematics()
        : test::System(DEFAULT_NAME) {

}

Mathematics::Mathematics(const std::string name)
        : test::System(name) {

}

Mathematics::Mathematics(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const test::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Mathematics::Mathematics(const std::string name, const test::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Mathematics::~Mathematics() {

}

int Mathematics::run() {
    return run(test::System::getParameters());
}

int Mathematics::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Mathematics::run(const test::CommandLine& object) {
    test::System::printStartedMessage();
    test::System::printStoppedMessage();
    return 0;
}

void Mathematics::quantity_concept() {

}

void Mathematics::direction_concept() {

}

void Mathematics::angular_concept() {

}

void Mathematics::signal_concept() {

}

void Mathematics::distance_concept() {

}

void Mathematics::area_concept() {

}

void Mathematics::volume_concept() {

}

void Mathematics::medium_concept() {

}

void Mathematics::temporal_concept() {

}

void Mathematics::frequency_concept() {

}

void Mathematics::potential_concept() {

}

void Mathematics::confinement_concept() {

}

} // namespace test