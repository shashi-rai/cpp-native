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

#ifndef ACT_DEPOT_H
#define ACT_DEPOT_H

#include <sstream>
#include <string>
#include <vector>
#include "document.h"
#include "warehouse.h"

namespace act {

class Depot : public Warehouse {
    Inventory exports;
    Inventory imports;
    Document license;
public:
    // Constructors
    Depot();
    Depot(std::string name);
    Depot(const Inventory& exports);
    Depot(const Inventory& imports, const Inventory& exports);
    Depot(std::string name, const Inventory& exports);
    Depot(std::string name, const Inventory& imports, const Inventory& exports);
    Depot(const gis::Address& address);
    Depot(const Inventory& exports, const gis::Address& address);
    Depot(const Inventory& imports, const Inventory& exports, const gis::Address& address);
    Depot(std::string name, const gis::Address& address);
    Depot(std::string name, const Inventory& exports, const gis::Address& address);
    Depot(std::string name, const Inventory& imports, const Inventory& exports, const gis::Address& address);

    // Destructors
    ~Depot();

    // Operator overloading
    bool operator==(const Depot& peer) const;

    // Getters
    Inventory getExports() const { return exports; }
    Inventory getImports() const { return imports; }
    Document getLicense() const { return license; }

    // Setters
    void setMaterial(const Inventory& items) { this->exports = items; }
    void setWorking(const Inventory& items) { this->imports = items; }
    void setLicense(const Document& certificate) { this->license = certificate; }

    // Additional methods
    virtual Branch copy();
    virtual void clear();
    virtual std::string print();
};

typedef std::vector<Depot > DepotArray;

} // namespace act

#endif //ACT_DEPOT_H