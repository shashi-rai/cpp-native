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

#include "observer.h"

namespace con {

Observer::Observer()
        : Behaviour(), stimulations() {

}

Observer::Observer(const StimulusArray& stimulations)
        : Behaviour(), stimulations(stimulations) {

}

Observer::Observer(const std::string name)
        : Behaviour(name), stimulations() {

}

Observer::Observer(const std::string name, const StimulusArray& stimulations)
        : Behaviour(name), stimulations(stimulations) {

}

Observer::~Observer() {

}

bool Observer::operator==(const Observer& peer) const {
    return (static_cast<const Behaviour&>(*this) == static_cast<const Behaviour&>(peer))
        && (stimulations == peer.stimulations);
}

Observer Observer::operator+(const Observer& peer) const {
    Behaviour self = *this, other = peer, memory = (self + other);
    StimulusArray result(stimulations);
    result.insert(result.end(), peer.stimulations.begin(), peer.stimulations.end());
    return Observer("+", result);
}

Observer Observer::operator-(const Observer& peer) const {
    Behaviour self = *this, other = peer, memory = (self - other);
    StimulusArray result(stimulations);
    for (StimulusArray::const_iterator it = peer.stimulations.begin(); it != peer.stimulations.end(); ++it) {
        StimulusArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Observer("-", result);
}

int Observer::getStimulationCount() const {
    return stimulations.size();
}

Stimulus Observer::getStimulation(const int index) const {
    Stimulus result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(stimulations.size())) {
        return result;
    }
    return stimulations[index];
}

void Observer::setStimulation(const int index, const Stimulus& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(stimulations.size())) {
        // replace existing element
        stimulations[index] = object;
    } else if (index == static_cast<int>(stimulations.size())) {
        // append at end
        stimulations.push_back(object);
    } else {
        // index beyond current size: append at end
        stimulations.push_back(object);
    }
    return;
}

std::string Observer::getName() const {
    return Behaviour::getName();
}

void Observer::setName(const std::string name) {
    Behaviour::setName(name);
}

void Observer::setTemporalDelay(const shp::Temporal& time) {
    Behaviour::setDelay(time.getMagnitude(), time.getScaling(), time.getUnit());
}

float Observer::getTemporalDelay() const {
    return Behaviour::getDelay();
}

void Observer::setTemporalDelay(const float value) {
    Behaviour::setDelay(value);
}

void Observer::setTemporalDelay(const float value, const short int scale) {
    Behaviour::setDelay(value, scale);
}

void Observer::setTemporalDelay(const float value, const short int scale, const std::string unit) {
    Behaviour::setDelay(value, scale, unit);
}

void Observer::setTemporalDelay(const float value, const short int scale, const shp::Unit& unit) {
    Behaviour::setDelay(value, scale, unit);
}

short int Observer::getTemporalScaling() const {
    return Behaviour::getScaling();
}

void Observer::setTemporalScaling(const short int factor) {
    Behaviour::setScaling(factor);
}

shp::Unit Observer::getTemporalUnit() const {
    return Behaviour::getUnit();
}

void Observer::setTemporalUnit(const shp::Unit& object) {
    Behaviour::setUnit(object);
}

Observer Observer::copy() {
    Observer fresh(Behaviour::getName(), this->stimulations);
    return fresh;
}

void Observer::clear() {
    Behaviour::clear();
    stimulations.clear();
    return;
}

std::string Observer::print() const {
    std::stringstream result;
	result << Behaviour::print();
    result << printStimulations();
	return result.str();
}

std::string Observer::printStimulations() const {
    std::stringstream result; int size = stimulations.size();
    if (size > 0) {
        result << ",sz:";
	    result << stimulations.size();
        result << std::endl << "{";
        for (int i = 0; i < size; i++) {
            result << "\t" << stimulations[i].print() << std::endl;
        }
        result << "}";
    }
	return result.str();
}

} // namespace con