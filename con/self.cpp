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
        : Memory(), sensors() {

}

Self::Self(const StimulusArray& sensors)
        : Memory(), sensors(sensors) {

}

Self::Self(const Stimulus& stimulus)
        : Memory(stimulus), sensors() {

}

Self::Self(const Stimulus& stimulus, const StimulusArray& sensors)
        : Memory(stimulus), sensors(sensors) {

}

Self::Self(const Feedback& feedback)
        : Memory(feedback), sensors() {

}

Self::Self(const Feedback& feedback, const StimulusArray& sensors)
        : Memory(feedback), sensors(sensors) {

}

Self::Self(const Response& response)
        : Memory(response), sensors() {

}

Self::Self(const Response& response, const StimulusArray& sensors)
        : Memory(response), sensors(sensors) {

}

Self::Self(const Stimulus& stimulus, const Response& response)
        : Memory(stimulus, response), sensors() {

}

Self::Self(const Stimulus& stimulus, const Response& response, const StimulusArray& sensors)
        : Memory(stimulus, response), sensors(sensors) {

}

Self::Self(const Feedback& feedback, const Response& response)
        : Memory(feedback, response), sensors() {

}

Self::Self(const Feedback& feedback, const Response& response, const StimulusArray& sensors)
        : Memory(feedback, response), sensors(sensors) {

}

Self::Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Memory(stimulus, feedback, response), sensors() {

}

Self::Self(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusArray& sensors)
        : Memory(stimulus, feedback, response), sensors(sensors) {

}

Self::Self(const std::string name)
        : Memory(name), sensors() {

}

Self::Self(const std::string name, const StimulusArray& sensors)
        : Memory(name), sensors(sensors) {

}

Self::Self(const std::string name, const Stimulus& stimulus)
        : Memory(name, stimulus), sensors() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const StimulusArray& sensors)
        : Memory(name, stimulus), sensors(sensors) {

}

Self::Self(const std::string name, const Feedback& feedback)
        : Memory(name, feedback), sensors() {

}

Self::Self(const std::string name, const Feedback& feedback, const StimulusArray& sensors)
        : Memory(name, feedback), sensors(sensors) {

}

Self::Self(const std::string name, const Response& response)
        : Memory(name, response), sensors() {

}

Self::Self(const std::string name, const Response& response, const StimulusArray& sensors)
        : Memory(name, response), sensors(sensors) {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Response& response)
        : Memory(name, stimulus, response), sensors() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Response& response,
        const StimulusArray& sensors)
        : Memory(name, stimulus, response), sensors(sensors) {

}

Self::Self(const std::string name, const Feedback& feedback, const Response& response)
        : Memory(name, feedback, response), sensors() {

}

Self::Self(const std::string name, const Feedback& feedback, const Response& response,
        const StimulusArray& sensors)
        : Memory(name, feedback, response), sensors(sensors) {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Memory(name, stimulus, feedback, response), sensors() {

}

Self::Self(const std::string name, const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusArray& sensors)
        : Memory(name, stimulus, feedback, response), sensors(sensors) {

}

Self::~Self() {

}

bool Self::operator==(const Self& peer) const {
    return (static_cast<const Memory&>(*this) == static_cast<const Memory&>(peer))
        && (sensors == peer.sensors);
}

Self Self::operator+(const Self& peer) const {
    Memory self = *this, other = peer, memory = (self + other);
    StimulusArray result(sensors);
    result.insert(result.end(), peer.sensors.begin(), peer.sensors.end());
    return Self("+", memory.getStimulus(), memory.getResponse(), result);
}

Self Self::operator-(const Self& peer) const {
    Memory self = *this, other = peer, memory = (self - other);
    StimulusArray result(sensors);
    for (StimulusArray::const_iterator it = peer.sensors.begin(); it != peer.sensors.end(); ++it) {
        StimulusArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Self("-", memory.getStimulus(), memory.getResponse(), result);
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

int Self::getSensorCount() const {
    return sensors.size();
}

Stimulus Self::getSensor(const int index) const {
    Stimulus result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(sensors.size())) {
        return result;
    }
    return sensors[index];
}

void Self::setSensor(const int index, const Stimulus& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(sensors.size())) {
        // replace existing element
        sensors[index] = object;
    } else if (index == static_cast<int>(sensors.size())) {
        // append at end
        sensors.push_back(object);
    } else {
        // index beyond current size: append at end
        sensors.push_back(object);
    }
    return;
}

Self Self::copy() const {
    Self fresh(Memory::getName(),
        Memory::getStimulus(), Memory::getFeedback(), Memory::getResponse(), this->sensors);
    return fresh;
}

void Self::clear() {
    Memory::clear();
    sensors.clear();
    return;
}

std::string Self::print() const {
    std::stringstream result;
	result << Memory::print();
    result << printSensors();
	return result.str();
}

std::string Self::printSensors() const {
    std::stringstream result; int size = sensors.size();
    if (size > 0) {
        result << ",sz:";
	    result << sensors.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << sensors[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con