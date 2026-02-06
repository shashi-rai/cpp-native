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

Memory::Memory(const PatternArray& patterns)
        : Pattern(), patterns(patterns) {

}

Memory::Memory(const Stimulus& stimulus)
        : Pattern(stimulus), patterns() {

}

Memory::Memory(const Stimulus& stimulus, const PatternArray& patterns)
        : Pattern(stimulus), patterns(patterns) {

}

Memory::Memory(const Response& response)
        : Pattern(response), patterns() {

}

Memory::Memory(const Response& response, const PatternArray& patterns)
        : Pattern(response), patterns(patterns) {

}

Memory::Memory(const Stimulus& stimulus, const Response& response)
        : Pattern(stimulus, response), patterns() {

}

Memory::Memory(const Stimulus& stimulus, const Response& response, const PatternArray& patterns)
        : Pattern(stimulus, response), patterns(patterns) {

}

Memory::Memory(const std::string name)
        : Pattern(name), patterns() {

}

Memory::Memory(const std::string name, const PatternArray& patterns)
        : Pattern(name), patterns(patterns) {

}

Memory::Memory(const std::string name, const Stimulus& stimulus)
        : Pattern(name, stimulus), patterns() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const PatternArray& patterns)
        : Pattern(name, stimulus), patterns(patterns) {

}

Memory::Memory(const std::string name, const Response& response)
        : Pattern(name, response), patterns() {

}

Memory::Memory(const std::string name, const Response& response, const PatternArray& patterns)
        : Pattern(name, response), patterns(patterns) {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Response& response)
        : Pattern(name, stimulus, response), patterns() {

}

Memory::Memory(const std::string name, const Stimulus& stimulus, const Response& response,
        const PatternArray& patterns)
        : Pattern(name, stimulus, response), patterns(patterns) {

}

Memory::~Memory() {

}

bool Memory::operator==(const Memory& peer) const {
    return (static_cast<const Pattern&>(*this) == static_cast<const Pattern&>(peer))
        && (patterns == peer.patterns);
}

Memory Memory::operator+(const Memory& peer) const {
    PatternArray result(patterns);
    result.insert(result.end(), peer.patterns.begin(), peer.patterns.end());
    return Memory("+", result);
}

Memory Memory::operator-(const Memory& peer) const {
    PatternArray result(patterns);
    for (PatternArray::const_iterator it = peer.patterns.begin(); it != peer.patterns.end(); ++it) {
        PatternArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Memory("-", result);
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

int Memory::getPatternCount() const {
    return patterns.size();
}

Pattern Memory::get(const int index) const {
    Pattern result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(patterns.size())) {
        return result;
    }
    return patterns[index];
}

void Memory::set(const int index, const Pattern& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(patterns.size())) {
        // replace existing element
        patterns[index] = object;
    } else if (index == static_cast<int>(patterns.size())) {
        // append at end
        patterns.push_back(object);
    } else {
        // index beyond current size: append at end
        patterns.push_back(object);
    }
    return;
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
        for (int i = 0; i < size; i++) {
            result << "\t" << patterns[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con