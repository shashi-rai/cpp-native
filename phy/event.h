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

#ifndef PHY_EVENT_H
#define PHY_EVENT_H

#include <string>
#include <vector>
#include "energy.h"
#include "momentum.h"
#include "space.h"
#include "time.h"

namespace phy {

class Event {
    std::string name;
    Space location;
    Time timestamp;
    Momentum impulse;
    Energy change;
public:
    // Constructors
    Event();
    Event(std::string name);
    Event(std::string name, const Space& location, const Time& timestamp,
        const Momentum& impulse, const Energy& action);

    // Destructors
    ~Event();

    // Getters
    std::string getName() const { return name; }
    Space getLocation() const { return location; }
    Time getTimestamp() const { return timestamp; }
    Momentum getImpulse() const { return impulse; }
    Energy getChange() const { return change; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setLocation(const Space& location) { this->location = location; }
    void setTimestamp(const Time& timestamp) { this->timestamp = timestamp; }
    void setImpulse(const Momentum& impulse) { this->impulse = impulse; }
    void setChange(const Energy& action) { this->change = action; }
};

typedef std::vector<Event > EventArray;

} // namespace phy

#endif //PHY_EVENT_H