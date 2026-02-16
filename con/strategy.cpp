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

#include "strategy.h"

namespace con {

Strategy::Strategy()
        : Pattern(), stimulators(), modulators() {

}

Strategy::Strategy(const StimulusMap& stimulii)
        : Pattern(), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Stimulus& stimulus)
        : Pattern(stimulus), stimulators(), modulators() {

}

Strategy::Strategy(const Stimulus& stimulus, const StimulusMap& stimulii)
        : Pattern(stimulus), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Stimulus& stimulus,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(stimulus), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Feedback& feedback)
        : Pattern(feedback), stimulators(), modulators() {

}

Strategy::Strategy(const Feedback& feedback, const StimulusMap& stimulii)
        : Pattern(feedback), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(feedback), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Response& response)
        : Pattern(response), stimulators(), modulators() {

}

Strategy::Strategy(const Response& response, const StimulusMap& stimulii)
        : Pattern(response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback)
        : Pattern(stimulus, feedback), stimulators(), modulators() {

}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii)
        : Pattern(stimulus, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(stimulus, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Feedback& feedback, const Response& response)
        : Pattern(feedback, response), stimulators(), modulators() {

}

Strategy::Strategy(const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Stimulus& stimulus, const Response& response)
        : Pattern(stimulus, response), stimulators(), modulators() {

}

Strategy::Strategy(const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(stimulus, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(stimulus, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Pattern(stimulus, feedback, response), stimulators(), modulators() {

}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(stimulus, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(stimulus, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name)
        : Pattern(name), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const StimulusMap& stimulii)
        : Pattern(name), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus)
        : Pattern(name, stimulus), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Stimulus& stimulus,
        const StimulusMap& stimulii)
        : Pattern(name, stimulus), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, stimulus), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Feedback& feedback)
        : Pattern(name, feedback), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Feedback& feedback,
        const StimulusMap& stimulii)
        : Pattern(name, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Response& response)
        : Pattern(name, response), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(name, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback)
        : Pattern(name, stimulus, feedback), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii)
        : Pattern(name, stimulus, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Feedback& feedback,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, stimulus, feedback), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Feedback& feedback, const Response& response)
        : Pattern(name, feedback, response), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(name, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Response& response)
        : Pattern(name, stimulus, response), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(name, stimulus, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name, const Stimulus& stimulus, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, stimulus, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::Strategy(const std::string name,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response)
        : Pattern(name, stimulus, feedback, response), stimulators(), modulators() {

}

Strategy::Strategy(const std::string name,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii)
        : Pattern(name, stimulus, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
}

Strategy::Strategy(const std::string name,
        const Stimulus& stimulus, const Feedback& feedback, const Response& response,
        const StimulusMap& stimulii, const FeedbackMap& modifiers)
        : Pattern(name, stimulus, feedback, response), stimulators(), modulators() {
    setStimulators(stimulii);
    setModulators(modifiers);
}

Strategy::~Strategy() {

}

bool Strategy::operator==(const Strategy& peer) const {
    return (static_cast<const Pattern&>(*this) == static_cast<const Pattern&>(peer))
        && (stimulators == peer.stimulators) && (modulators == peer.modulators);
}

Strategy Strategy::operator+(const Strategy& peer) const {
    StimulusMap stimulii(stimulators); FeedbackMap modifiers(modulators);
    stimulii.insert(peer.stimulators.begin(), peer.stimulators.end());
    modifiers.insert(peer.modulators.begin(), peer.modulators.end());
    return Strategy("+", stimulii, modifiers);
}

Strategy Strategy::operator-(const Strategy& peer) const {
    StimulusMap stimulii(stimulators); FeedbackMap modifiers(modulators);
    for (StimulusMap::const_iterator it = peer.stimulators.begin(); it != peer.stimulators.end(); ++it) {
        StimulusMap::iterator found = std::find(stimulii.begin(), stimulii.end(), *it);
        if (found != stimulii.end()) {
            stimulii.erase(found);
        }
    }
    for (FeedbackMap::const_iterator it = peer.modulators.begin(); it != peer.modulators.end(); ++it) {
        FeedbackMap::iterator found = std::find(modifiers.begin(), modifiers.end(), *it);
        if (found != modifiers.end()) {
            modifiers.erase(found);
        }
    }
    return Strategy("-", stimulii, modifiers);
}

StimulusMap Strategy::getStimulators() const {
    return stimulators;
}

FeedbackMap Strategy::getModulators() const {
    return modulators;
}

void Strategy::setStimulators(const StimulusMap& stimulii) {
    for (StimulusMap::const_iterator it = stimulii.begin(); it != stimulii.end(); ++it) {
        this->stimulators[it->first] = it->second;
    }
}

void Strategy::setModulators(const FeedbackMap& modifiers) {
    for (FeedbackMap::const_iterator it = modifiers.begin(); it != modifiers.end(); ++it) {
        this->modulators[it->first] = it->second;
    }
}

std::string Strategy::getName() const {
    return Pattern::getName();
}

void Strategy::setName(const std::string name) {
    Pattern::setName(name);
}

Stimulus Strategy::getStimulus() const {
    return Pattern::getStimulus();
}

void Strategy::setStimulus(const Stimulus& input) {
    Pattern::setStimulus(input);
}

Feedback Strategy::getFeedback() const {
    return Pattern::getFeedback();
}

void Strategy::setFeedback(const Feedback& modifier) {
    Pattern::setFeedback(modifier);
}

Response Strategy::getResponse() const {
    return Pattern::getResponse();
}

void Strategy::setResponse(const Response& output) {
    Pattern::setResponse(output);
}

bool Strategy::isAware(const Stimulus& stimulus) const {
    bool result = false;
    for (StimulusMap::const_iterator it = stimulators.begin(); it != stimulators.end(); ++it) {
        if (it->first == stimulus.getName()) {
            result = true;
            break;
        }
    }
    return result;
}

Response Strategy::getLearning(const Stimulus& stimulus) const {
    Response result;
    for (StimulusMap::const_iterator it = stimulators.begin(); it != stimulators.end(); ++it) {
        if (it->first == stimulus.getName()) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

void Strategy::setLearning(const Stimulus& stimulus, const Response& response) {
    stimulators[stimulus.getName()] = Pattern(stimulus, response);
}

bool Strategy::isAware(const Feedback& feedback) const {
    bool result = false;
    for (FeedbackMap::const_iterator it = modulators.begin(); it != modulators.end(); ++it) {
        if (it->first == feedback.getName()) {
            result = true;
            break;
        }
    }
    return result;
}

Response Strategy::getLearning(const Feedback& feedback) const {
    Response result;
    for (FeedbackMap::const_iterator it = modulators.begin(); it != modulators.end(); ++it) {
        if (it->first == feedback.getName()) {
            result = it->second.getResponse();
            break;
        }
    }
    return result;
}

void Strategy::setLearning(const Feedback& feedback, const Response& response) {
    modulators[feedback.getName()] = Pattern(feedback, response);
}

int Strategy::getStimulusCount() const {
    return stimulators.size();
}

Pattern Strategy::getStimulus(const std::string key) const {
    return stimulators.find(key)->second;
}

void Strategy::setStimulus(const std::string key, const Pattern& object) {
    stimulators[object.getName()] = object;
}

int Strategy::getFeedbackCount() const {
    return modulators.size();
}

Pattern Strategy::getFeedback(const std::string key) const {
    return modulators.find(key)->second;
}

void Strategy::setFeedback(const std::string key, const Pattern& object) {
    modulators[object.getName()] = object;
}

Strategy Strategy::copy() {
    Strategy fresh(Pattern::getName(), this->stimulators);
    return fresh;
}

void Strategy::clear() {
    Pattern::clear();
    stimulators.clear();
    return;
}

std::string Strategy::print() const {
    std::stringstream result;
	result << Pattern::print();
    result << printSimulators();
    result << printModulators();
	return result.str();
}

std::string Strategy::printSimulators() const {
    std::stringstream result; int size = stimulators.size();
    if (size > 0) {
        result << ",sz:";
	    result << stimulators.size();
        result << std::endl << "{";
        for (StimulusMap::const_iterator it = stimulators.begin(); it != stimulators.end(); ++it) {
            result << "\t" << (*it).second.print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

std::string Strategy::printModulators() const {
    std::stringstream result; int size = modulators.size();
    if (size > 0) {
        result << ",sz:";
	    result << modulators.size();
        result << std::endl << "{";
        for (FeedbackMap::const_iterator it = modulators.begin(); it != modulators.end(); ++it) {
            result << "\t" << (*it).second.print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con