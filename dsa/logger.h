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

#ifndef DSA_LOGGER_H
#define DSA_LOGGER_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "../inc/configuration.h"

namespace dsa {

class Logger {
    std::string name;
    cfg::Logging level;
    cfg::CommandLine parameters;
public:
    // Constructors
    Logger();
    Logger(const std::string name);
    Logger(const cfg::Logging level);
    Logger(const cfg::CommandLine& parameters);
    Logger(const std::string name, const cfg::Logging level);
    Logger(const std::string name, const cfg::CommandLine& parameters);
    Logger(const std::string name, const cfg::Logging level, const cfg::CommandLine& parameters);

    // Destructors
    ~Logger();

    // Getters
    std::string getName() const;
    cfg::Logging getLevel() const;
    cfg::CommandLine getParameters() const;

    // Setters
    void setName(const std::string name);
    void setLevel(const cfg::Logging level);
    void setParameters(const cfg::CommandLine& object);

public:
    int main();
    int main(const int argc, char* argv[]);
    int main(const cfg::CommandLine& object);
    std::string getParameter(const int index) const;
    void setParameters(const int argc, char* argv[]);
    std::time_t getCurrent() const;
    std::string getYear(const std::time_t& time) const;
    std::string getDate(const std::time_t& time) const;
    std::string getTime(const std::time_t& time) const;
    std::string getDateTime(const std::time_t& time) const;
    void clear();
    virtual void printStartedMessage() const;
    virtual void printStoppedMessage() const;
    virtual std::string print() const;
    virtual std::string printCopyright() const;
    void log(const std::string message) const;
protected:
    std::string getLogFatal(const std::string message) const;
    std::string getLogError(const std::string message) const;
    std::string getLogWarning(const std::string message) const;
    std::string getLogInfo(const std::string message) const;
    std::string getLogDebug(const std::string message) const;
    std::string getLogTrace(const std::string message) const;
public:
    static const std::string DEFAULT_NAME;
    static const cfg::Logging DEFAULT_LEVEL;
};

} // namespace dsa

#endif //DSA_LOGGER_H