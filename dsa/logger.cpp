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

#include "logger.h"

namespace dsa {

const std::string Logger::DEFAULT_NAME = "Logger";
const cfg::Logging Logger::DEFAULT_LEVEL = (cfg::Level) 4;

Logger::Logger()
        : name(DEFAULT_NAME), level(DEFAULT_LEVEL), parameters() {

}

Logger::Logger(const std::string name)
        : name(name), level(DEFAULT_LEVEL), parameters() {

}

Logger::Logger(const cfg::Logging level)
        : name(DEFAULT_NAME), level(level), parameters() {

}

Logger::Logger(const cfg::CommandLine& parameters)
        : name(DEFAULT_NAME), level(DEFAULT_LEVEL), parameters(parameters) {

}

Logger::Logger(const std::string name, const cfg::Logging level)
        : name(name), level(level), parameters() {

}

Logger::Logger(const std::string name, const cfg::CommandLine& parameters)
        : name(name), level(DEFAULT_LEVEL), parameters(parameters) {

}

Logger::Logger(const std::string name, const cfg::Logging level, const cfg::CommandLine& parameters)
        : name(name), level(level), parameters(parameters) {

}

Logger::~Logger() {

}

std::string Logger::getName() const {
    return name;
}

cfg::Logging Logger::getLevel() const {
    return level;
}

cfg::CommandLine Logger::getParameters() const {
    return parameters;
}

void Logger::setLevel(const cfg::Logging level) {
    this->level = level;
}

void Logger::setName(const std::string name) {
    this->name = name;
}

void Logger::setParameters(const cfg::CommandLine& object) {
    this->parameters = object;
}

int Logger::main() {
    return main(Logger::getParameters());
}

int Logger::main(const int argc, char* argv[]) {
    Logger::setParameters(argc, argv);
    return main(Logger::getParameters());
}

int Logger::main(const cfg::CommandLine& object) {
    Logger::printStartedMessage();

    Logger::printStoppedMessage();
    return 0;
}

std::string Logger::getParameter(const int index) const {
    std::string result;
    if (index >= 0) {
        if (index < this->parameters.size()) {
            result = this->parameters[index];
        }
    }
    return result;
}

void Logger::setParameters(const int argc, char* argv[]) {
    for (int index = 0; index < argc; index++) {
        this->parameters.push_back(argv[index]);
    }
}

std::time_t Logger::getCurrent() const {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t result = std::chrono::system_clock::to_time_t(now);
    return result;
}

std::string Logger::getYear(const std::time_t& time) const {
    char buffer[80]; std::tm ltm = *std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y", &ltm); 
    std::string result(buffer);
    return result;
}

std::string Logger::getDate(const std::time_t& time) const {
    char buffer[80]; std::tm ltm = *std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "[%Y-%m-%d]", &ltm); 
    std::string result(buffer);
    return result;
}

std::string Logger::getTime(const std::time_t& time) const {
    char buffer[80]; std::tm ltm = *std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S]", &ltm); 
    std::string result(buffer);
    return result;
}

std::string Logger::getDateTime(const std::time_t& time) const {
    char buffer[80]; std::tm tm_buf = {};
    std::tm* tm_ptr = std::localtime(&time);
    if (tm_ptr) {
        tm_buf = *tm_ptr;
    }
    std::strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", &tm_buf);
    std::string result(buffer);
    return result;
}

void Logger::clear() {
    this->name.clear();
    this->parameters.clear();
}

void Logger::printStartedMessage() const {
    std::cout << this->printCopyright() << std::endl;
    std::cout << this->name << " starting" << std::endl;
}

void Logger::printStoppedMessage() const {
    std::cout << this->name << " finished" << std::endl << std::endl;
}

std::string Logger::print() const {
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

std::string Logger::printCopyright() const {
    std::stringstream result;
    result << "Consciousness Programming Platform";
    result << " Release 1.00" << std::endl;
    result << "Copyright © 2018-";
    result << this->getYear(this->getCurrent());
    result << " by ";
    result << "Bhojpur Consulting Private Limited, Bihar, India" << std::endl;
    result << "All rights reserved. https:://www.bhojpur-consulting.com";
    result << std::endl;
	return result.str();
}

void Logger::log(const std::string message) const {
    std::stringstream result;
    if (this->level < 1) {
        // do not log anything
    } else if (this->level < 2) {
        result << getLogFatal(message);
    } else if (this->level < 3) {
        result << getLogError(message);
    } else if (this->level < 4) {
        result << getLogWarning(message);
    } else if (this->level < 5) {
        result << getLogInfo(message);
    } else if (this->level < 6) {
        result << getLogDebug(message);
    } else if (this->level < 7) {
        result << getLogTrace(message);
    }
	std::cout << result.str();
}

std::string Logger::getLogFatal(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << ":F:";
    result << message;
    result << std::endl;
	return result.str();
}

std::string Logger::getLogError(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << ":E:";
    result << message;
    result << std::endl;
	return result.str();
}

std::string Logger::getLogWarning(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << ":W:";
    result << message;
    result << std::endl;
	return result.str();
}

std::string Logger::getLogInfo(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << ":I:";
    result << message;
    result << std::endl;
	return result.str();
}

std::string Logger::getLogDebug(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << "D:";
    result << message;
    result << std::endl;
	return result.str();
}

std::string Logger::getLogTrace(const std::string message) const {
    std::stringstream result;
    result << (this->getDateTime(this->getCurrent()));
    result << ":";
    result << name;
    result << ":T:";
    result << message;
    result << std::endl;
	return result.str();
}

} // namespace dsa