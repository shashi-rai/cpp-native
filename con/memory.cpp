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

#include "memory.h"

namespace con {

Memory::Memory()
        : Strategy(), activators() {

}

Memory::Memory(const StrategyMap& objects)
        : Strategy(), activators() {
    setActivators(objects);
}

Memory::Memory(const Stimulus& stimulus)
        : Strategy(stimulus), activators() {

}

Memory::Memory(const Stimulus& stimulus, const StrategyMap& objects)
        : Strategy(stimulus), activators() {
    setActivators(objects);
}

Memory::Memory(const Feedback& feedback)
        : Strategy(feedback), activators() {

}

Memory::Memory(const Feedback& feedback, const StrategyMap& objects)
        : Strategy(feedback), activators() {
    setActivators(objects);
}

Memory::Memory(const Response& response)
        : Strategy(response), activators() {

}

Memory::Memory(const Response& response, const StrategyMap& objects)
        : Strategy(response), activators() {
    setActivators(objects);
}

Memory::Memory(const Stimulus& stimulus, const Response& response)
        : Strategy(stimulus, response), activators() {

}

Memory::Memory(const Feedback& feedback, const Response& response)
        : Strategy(feedback, response), activators() {

}

Memory::Memory(const Stimulus& stimulus, const Response& response, const StrategyMap& objects)
        : Strategy(stimulus, response), activators() {
    setActivators(objects);
}

Memory::Memory(const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Strategy(stimulus, feedback, response), activators() {

}

Memory::Memory(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StrategyMap& objects)
        : Strategy(stimulus, feedback, response), activators() {
    setActivators(objects);
}

Memory::Memory(const std::string name)
        : Strategy(name), activators() {

}

Memory::Memory(const std::string name, const StrategyMap& objects)
        : Strategy(name), activators() {
    setActivators(objects);
}

Memory::Memory(const std::string name, const Stimulus& stimulus)
        : Strategy(name, stimulus), activators() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const StrategyMap& objects)
        : Strategy(name, stimulus), activators() {
    setActivators(objects);
}

Memory::Memory(const std::string name, const Feedback& feedback)
        : Strategy(name, feedback), activators() {

}

Memory::Memory(const std::string name, const Feedback& feedback, const StrategyMap& objects)
        : Strategy(name, feedback), activators() {
    setActivators(objects);
}

Memory::Memory(const std::string name, const Response& response)
        : Strategy(name, response), activators() {

}

Memory::Memory(const std::string name, const Response& response, const StrategyMap& objects)
        : Strategy(name, response), activators() {
    setActivators(objects);
}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Response& response)
        : Strategy(name, stimulus, response), activators() {

}

Memory::Memory(const std::string name, const Feedback& feedback, const Response& response)
        : Strategy(name, feedback, response), activators() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Strategy(name, stimulus, feedback, response), activators() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StrategyMap& objects)
        : Strategy(name, stimulus, feedback, response), activators() {
    setActivators(objects);
}

Memory::~Memory() {

}

bool Memory::operator==(const Memory& peer) const {
    return (static_cast<const Strategy&>(*this) == static_cast<const Strategy&>(peer))
        && (activators == peer.activators);
}

Memory Memory::operator+(const Memory& peer) const {
    StrategyMap result(activators);
    result.insert(peer.activators.begin(), peer.activators.end());
    return Memory("+", result);
}

Memory Memory::operator-(const Memory& peer) const {
    StrategyMap result(activators);
    for (StrategyMap::const_iterator it = peer.activators.begin(); it != peer.activators.end(); ++it) {
        StrategyMap::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Memory("-", result);
}

StrategyMap Memory::getActivators() const {
    return activators;
}

void Memory::setActivators(const StrategyMap& objects) {
    for (StrategyMap::const_iterator it = objects.begin(); it != objects.end(); ++it) {
        this->activators[it->first] = it->second;
    }
}

std::string Memory::getName() const {
    return Strategy::getName();
}

void Memory::setName(const std::string name) {
    Strategy::setName(name);
}

Stimulus Memory::getStimulus() const {
    return Strategy::getStimulus();
}

void Memory::setStimulus(const Stimulus& input) {
    Strategy::setStimulus(input);
}

Feedback Memory::getFeedback() const {
    return Strategy::getFeedback();
}

void Memory::setFeedback(const Feedback& modifier) {
    Strategy::setFeedback(modifier);
}

Response Memory::getResponse() const {
    return Strategy::getResponse();
}

void Memory::setResponse(const Response& output) {
    Strategy::setResponse(output);
}

bool Memory::isAware(const std::string word) const {
    bool result = false;
    for (StrategyMap::const_iterator it = activators.begin(); it != activators.end(); ++it) {
        if (it->first == word) {
            result = true;
            break;
        }
    }
    return result;
}

Response Memory::getLearning(const std::string word) const {
    Response result;
    for (StrategyMap::const_iterator it = activators.begin(); it != activators.end(); ++it) {
        if (it->first == word) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

Response Memory::getLearning(const Stimulus& stimulus) const {
    Response result;
    for (StrategyMap::const_iterator it = activators.begin(); it != activators.end(); ++it) {
        if (it->second.getStimulus().getName() == stimulus.getName()) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

Response Memory::getLearning(const Feedback& feedback) const {
    Response result;
    for (StrategyMap::const_iterator it = activators.begin(); it != activators.end(); ++it) {
        if (it->second.getFeedback().getName() == feedback.getName()) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

void Memory::setLearning(const std::string word,
        const Stimulus& stimulus, const Response& response) {
    activators[word] = Strategy(stimulus, response);
}

void Memory::setLearning(const std::string word,
        const Feedback& feedback, const Response& response) {
    activators[word] = Strategy(feedback, response);
}

void Memory::setLearning(const std::string word,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response) {
    activators[word] = Strategy(stimulus, feedback, response);
}

int Memory::getActivatorCount() const {
    return activators.size();
}

Strategy Memory::getActivator(const std::string word) const {
    return activators.find(word)->second;
}

void Memory::setActivator(const std::string word, const Strategy& object) {
    activators[word] = object;
}

Memory Memory::copy() {
    Memory fresh(Strategy::getName(), this->activators);
    return fresh;
}

void Memory::clear() {
    Strategy::clear();
    activators.clear();
    return;
}

std::string Memory::print() const {
    std::stringstream result;
	result << Strategy::print();
    result << printActivators();
	return result.str();
}

std::string Memory::printRadians() const {
    std::stringstream result;
	result << Strategy::printRadians();
    result << printActivators();
	return result.str();
}

std::string Memory::printActivators() const {
    std::stringstream result; int size = activators.size();
    if (size > 0) {
        result << ",sz:";
	    result << activators.size();
        result << std::endl << "{";
        for (StrategyMap::const_iterator it = activators.begin(); it != activators.end(); ++it) {
            result << "\t" << (*it).second.print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con