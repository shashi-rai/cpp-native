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

#include "../inc/testing.h"

namespace cfg {

System::System()
        : name(), parameters() {

}

System::System(const cfg::CommandLine& parameters)
        : name(), parameters(parameters) {

}

System::System(const std::string name)
        : name(name), parameters() {

}

System::System(const std::string name, const cfg::CommandLine& parameters)
        : name(name), parameters(parameters) {

}

System::~System() {

}

std::string System::getName() const {
    return name;
}

cfg::CommandLine System::getParameters() const {
    return parameters;
}

void System::setName(const std::string name) {
    this->name = name;
}

void System::setParameters(const cfg::CommandLine& object) {
    this->parameters = object;
}

std::string System::getParameter(const int index) const {
    std::string result;
    if (index >= 0) {
        if (index < this->parameters.size()) {
            result = this->parameters[index];
        }
    }
    return result;
}

void System::setParameters(const int argc, char* argv[]) {
    for (int index = 0; index < argc; index++) {
        this->parameters.push_back(argv[index]);
    }
}

void System::clear() {
    this->name.clear();
    this->parameters.clear();
}

void System::printStartedMessage() const {
    std::cout << this->name << " suite starting" << std::endl;
}

void System::printStoppedMessage() const {
    std::cout << this->name << " suite finished" << std::endl << std::endl;
}

std::string System::print() const {
    std::stringstream result; int size = this->parameters.size();
    if (size > 0) {
        result << std::endl << "{";
        for (int index = 0; index < size; index++) {
            result << "\t" << this->parameters[index] << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace cfg