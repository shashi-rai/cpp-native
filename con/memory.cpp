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
        : Pattern(), patterns() {

}

Memory::Memory(const PatternMap& objects)
        : Pattern() {
    setPatterns(objects);
}

Memory::Memory(const Stimulus& stimulus)
        : Pattern(stimulus), patterns() {

}

Memory::Memory(const Stimulus& stimulus, const PatternMap& objects)
        : Pattern(stimulus) {
    setPatterns(objects);
}

Memory::Memory(const Response& response)
        : Pattern(response), patterns() {

}

Memory::Memory(const Response& response, const PatternMap& objects)
        : Pattern(response) {
    setPatterns(objects);
}

Memory::Memory(const Stimulus& stimulus, const Response& response)
        : Pattern(stimulus, response), patterns() {

}

Memory::Memory(const Stimulus& stimulus, const Response& response, const PatternMap& objects)
        : Pattern(stimulus, response) {
    setPatterns(objects);
}

Memory::Memory(const std::string name)
        : Pattern(name), patterns() {

}

Memory::Memory(const std::string name, const PatternMap& objects)
        : Pattern(name) {
    setPatterns(objects);
}

Memory::Memory(const std::string name, const Stimulus& stimulus)
        : Pattern(name, stimulus), patterns() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const PatternMap& objects)
        : Pattern(name, stimulus) {
    setPatterns(objects);
}

Memory::Memory(const std::string name, const Response& response)
        : Pattern(name, response), patterns() {

}

Memory::Memory(const std::string name, const Response& response, const PatternMap& objects)
        : Pattern(name, response) {
    setPatterns(objects);
}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Response& response)
        : Pattern(name, stimulus, response), patterns() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Response& response,
        const PatternMap& objects)
        : Pattern(name, stimulus, response) {
    setPatterns(objects);
}

Memory::~Memory() {

}

bool Memory::operator==(const Memory& peer) const {
    return (static_cast<const Pattern&>(*this) == static_cast<const Pattern&>(peer))
        && (patterns == peer.patterns);
}

Memory Memory::operator+(const Memory& peer) const {
    PatternMap result(patterns);
    result.insert(peer.patterns.begin(), peer.patterns.end());
    return Memory("+", result);
}

Memory Memory::operator-(const Memory& peer) const {
    PatternMap result(patterns);
    for (PatternMap::const_iterator it = peer.patterns.begin(); it != peer.patterns.end(); ++it) {
        PatternMap::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Memory("-", result);
}

PatternMap Memory::getPatterns() const {
    return patterns;
}

void Memory::setPatterns(const PatternMap& objects) {
    for (PatternMap::const_iterator it = objects.begin(); it != objects.end(); ++it) {
        this->patterns[it->first] = it->second;
    }
}

std::string Memory::getName() const {
    return Behaviour::getName();
}

void Memory::setName(const std::string name) {
    Behaviour::setName(name);
}

Stimulus Memory::getStimulus() const {
    return Pattern::getStimulus();
}

void Memory::setStimulus(const Stimulus& input) {
    Pattern::setStimulus(input);
}

Response Memory::getResponse() const {
    return Pattern::getResponse();
}

void Memory::setResponse(const Response& output) {
    Pattern::setResponse(output);
}

bool Memory::isAware(const Stimulus& stimulus) const {
    bool result = false;
    for (PatternMap::const_iterator it = patterns.begin(); it != patterns.end(); ++it) {
        if (it->first == stimulus.getName()) {
            result = true;
            break;
        }
    }
    return result;
}

Response Memory::getLearning(const Stimulus& stimulus) const {
    Response result;
    for (PatternMap::const_iterator it = patterns.begin(); it != patterns.end(); ++it) {
        if (it->first == stimulus.getName()) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

void Memory::setLearning(const Stimulus& stimulus, const Response& response) {
    patterns[stimulus.getName()] = Pattern(stimulus, response);
}

int Memory::getPatternCount() const {
    return patterns.size();
}

Pattern Memory::get(const std::string key) const {
    return patterns.find(key)->second;
}

void Memory::set(const std::string key, const Pattern& object) {
    patterns[object.getName()] = object;
}

Memory Memory::copy() const {
    Memory fresh(this->getName(), this->patterns);
    return fresh;
}

void Memory::clear() {
    Pattern::clear();
    patterns.clear();
    return;
}

std::string Memory::print() const {
    std::stringstream result;
	result << Pattern::print();
    result << printPatterns();
	return result.str();
}

std::string Memory::printPatterns() const {
    std::stringstream result; int size = patterns.size();
    if (size > 0) {
        result << ",sz:";
	    result << patterns.size();
        result << std::endl << "{";
        for (PatternMap::const_iterator it = patterns.begin(); it != patterns.end(); ++it) {
            result << "\t" << (*it).second.print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con