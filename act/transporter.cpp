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

#include "transporter.h"

namespace act {

Transporter::Transporter() : Party(), vehicles() {

}

Transporter::Transporter(std::string name)
        : Party(name), vehicles() {

}

Transporter::Transporter(const VehicleArray& vehicles)
        : Party(), vehicles(vehicles) {

}

Transporter::Transporter(std::string name, const VehicleArray& vehicles)
        : Party(name), vehicles(vehicles) {

}

Transporter::~Transporter() {

}

bool Transporter::operator==(const Transporter& peer) const {
    return (static_cast<const Party&>(*this) == static_cast<const Party&>(peer))
        && (vehicles == peer.vehicles);
}

Transporter Transporter::operator+(const Transporter& peer) const {
    VehicleArray result(vehicles);
    result.insert(result.end(), peer.vehicles.begin(), peer.vehicles.end());
    return Transporter("+", result);
}

Transporter Transporter::operator-(const Transporter& peer) const {
    VehicleArray result(vehicles);
    for (VehicleArray::const_iterator it = peer.vehicles.begin(); it != peer.vehicles.end(); ++it) {
        VehicleArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Transporter("-", result);
}

int Transporter::getVehicleCount() const {
    return vehicles.size();
}

Vehicle Transporter::get(int index) const {
    Vehicle result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(vehicles.size())) {
        return result;
    }
    return vehicles[index];
}

void Transporter::set(int index, const Vehicle& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(vehicles.size())) {
        // replace existing element
        vehicles[index] = object;
    } else if (index == static_cast<int>(vehicles.size())) {
        // append at end
        vehicles.push_back(object);
    } else {
        // index beyond current size: append at end
        vehicles.push_back(object);
    }
    return;
}

Party Transporter::copy() {
    Transporter fresh(getName(), vehicles);
    return fresh;
}

void Transporter::clear() {
    Party::clear();
    vehicles.clear();
    return;
}

std::string Transporter::print() {
    std::stringstream result;
    result << Party::print() << ",sz:";
    result << vehicles.size();
	return result.str();
}

} // namespace act