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

#include "self.h"

namespace con {

Self::Self()
        : Memory(), observers() {

}

Self::Self(const ObserverArray& observers)
        : Memory(), observers(observers) {

}

Self::Self(const Stimulus& stimulus)
        : Memory(stimulus), observers() {

}

Self::Self(const Stimulus& stimulus, const ObserverArray& observers)
        : Memory(stimulus), observers(observers) {

}

Self::Self(const Feedback& feedback)
        : Memory(feedback), observers() {

}

Self::Self(const Feedback& feedback, const ObserverArray& observers)
        : Memory(feedback), observers(observers) {

}

Self::Self(const Response& response)
        : Memory(response), observers() {

}

Self::Self(const Response& response, const ObserverArray& observers)
        : Memory(response), observers(observers) {

}

Self::Self(const Stimulus& stimulus, const Response& response)
        : Memory(stimulus, response), observers() {

}

Self::Self(const Stimulus& stimulus, const Response& response, const ObserverArray& observers)
        : Memory(stimulus, response), observers(observers) {

}

Self::Self(const Feedback& feedback, const Response& response)
        : Memory(feedback, response), observers() {

}

Self::Self(const Feedback& feedback, const Response& response, const ObserverArray& observers)
        : Memory(feedback, response), observers(observers) {

}

Self::Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Memory(stimulus, feedback, response), observers() {

}

Self::Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const ObserverArray& observers)
        : Memory(stimulus, feedback, response), observers(observers) {

}

Self::Self(const std::string name)
        : Memory(name), observers() {

}

Self::Self(const std::string name, const ObserverArray& observers)
        : Memory(name), observers(observers) {

}

Self::Self(const std::string name, const Stimulus& stimulus)
        : Memory(name, stimulus), observers() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const ObserverArray& observers)
        : Memory(name, stimulus), observers(observers) {

}

Self::Self(const std::string name, const Feedback& feedback)
        : Memory(name, feedback), observers() {

}

Self::Self(const std::string name, const Feedback& feedback, const ObserverArray& observers)
        : Memory(name, feedback), observers(observers) {

}

Self::Self(const std::string name, const Response& response)
        : Memory(name, response), observers() {

}

Self::Self(const std::string name, const Response& response, const ObserverArray& observers)
        : Memory(name, response), observers(observers) {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Response& response)
        : Memory(name, stimulus, response), observers() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Response& response,
        const ObserverArray& observers)
        : Memory(name, stimulus, response), observers(observers) {

}

Self::Self(const std::string name, const Feedback& feedback, const Response& response)
        : Memory(name, feedback, response), observers() {

}

Self::Self(const std::string name, const Feedback& feedback, const Response& response,
        const ObserverArray& observers)
        : Memory(name, feedback, response), observers(observers) {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Memory(name, stimulus, feedback, response), observers() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const ObserverArray& observers)
        : Memory(name, stimulus, feedback, response), observers(observers) {

}

Self::~Self() {

}

bool Self::operator==(const Self& peer) const {
    return (static_cast<const Memory&>(*this) == static_cast<const Memory&>(peer))
        && (observers == peer.observers);
}

Self Self::operator+(const Self& peer) const {
    Memory self = *this, other = peer, memory = (self + other);
    ObserverArray result(observers);
    result.insert(result.end(), peer.observers.begin(), peer.observers.end());
    return Self("+", memory.getStimulus(), memory.getFeedback(), memory.getResponse(), result);
}

Self Self::operator-(const Self& peer) const {
    Memory self = *this, other = peer, memory = (self - other);
    ObserverArray result(observers);
    for (ObserverArray::const_iterator it = peer.observers.begin(); it != peer.observers.end(); ++it) {
        ObserverArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Self("-", memory.getStimulus(), memory.getFeedback(), memory.getResponse(), result);
}

std::string Self::getName() const {
    return Memory::getName();
}

void Self::setName(const std::string name) {
    Memory::setName(name);
}

Stimulus Self::getStimulus() const {
    return Memory::getStimulus();
}

void Self::setStimulus(const Stimulus& input) {
    Memory::setStimulus(input);
}

Feedback Self::getFeedback() const {
    return Memory::getFeedback();
}

void Self::setFeedback(const Feedback& modifier) {
    Memory::setFeedback(modifier);
}

Response Self::getResponse() const {
    return Memory::getResponse();
}

void Self::setResponse(const Response& output) {
    Memory::setResponse(output);
}

bool Self::isAware(const std::string word) const {
    return Memory::isAware(word);
}

shp::Signal Self::getBehaviour(const Stimulus& stimulus) const {
    Response response = Memory::getLearning(stimulus);
    return response.getOutput();
}

shp::Signal Self::getBehaviour(const Feedback& feedback) const {
    Response response = Memory::getLearning(feedback);
    return response.getOutput();
}

void Self::setBehaviour(const std::string word, const Stimulus& stimulus, const Response& response) {
    Memory::setLearning(word, stimulus, response);
}

void Self::setBehaviour(const std::string word, const Feedback& feedback, const Response& response) {
    Memory::setLearning(word, feedback, response);
}

int Self::getObserverCount() const {
    return observers.size();
}

Observer Self::getObserver(const int index) const {
    Observer result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(observers.size())) {
        return result;
    }
    return observers[index];
}

void Self::setObserver(const int index, const Observer& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(observers.size())) {
        // replace existing element
        observers[index] = object;
    } else if (index == static_cast<int>(observers.size())) {
        // append at end
        observers.push_back(object);
    } else {
        // index beyond current size: append at end
        observers.push_back(object);
    }
    return;
}

Self Self::copy() {
    Self fresh(Memory::getName(),
        Memory::getStimulus(), Memory::getFeedback(), Memory::getResponse(), this->observers);
    return fresh;
}

void Self::clear() {
    Memory::clear();
    observers.clear();
    return;
}

std::string Self::print() const {
    std::stringstream result;
	result << Memory::print();
    result << printObservers();
	return result.str();
}

std::string Self::printObservers() const {
    std::stringstream result; int size = observers.size();
    if (size > 0) {
        result << ",sz:";
	    result << observers.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << observers[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con