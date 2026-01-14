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

#include "nucleus.h"
#include "../qft/field.h"

namespace che {

const int Nucleus::PROTON_MIN_LIMIT = 1;
const int Nucleus::PROTON_MAX_LIMIT = 118;
const int Nucleus::NEUTRON_MAX_LIMIT = 176;

const std::string Nucleus::UNKNOWN = "Unknown Atom";
const std::string Nucleus::ELEMENT_SYMBOL[] = {
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
	"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
	"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",
	"Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
	"I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
	"Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt",
	"Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa",
	"U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf",
	"Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

const std::string Nucleus::ELEMENT_NAME[] = {
	"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
	"Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon",
	"Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium",
	"Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel",
	"Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine",
	"Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
	"Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver",
	"Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium",
	"Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium",
	"Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium",
	"Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
	"Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
	"Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium",
	"Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium",
	"Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
	"Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
	"Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium",
	"Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine",
	"Oganesson",
};

Nucleus::Nucleus()
        : symbol(""), proton(0), neutron(0), energy() {
	initialize();
}

Nucleus::Nucleus(std::string symbol)
        : symbol(symbol), proton(0), neutron(0), energy() {
	initialize();
}

Nucleus::Nucleus(const short int proton)
        : symbol(getSymbol(proton)), proton(proton), neutron(proton), energy() {
	initialize();
}

Nucleus::Nucleus(const short int proton, const short int neutron)
        : symbol(getSymbol(proton)), proton(proton), neutron(neutron), energy() {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton)
        : symbol(symbol), proton(proton), neutron(proton), energy() {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton, const short int neutron)
        : symbol(symbol), proton(proton), neutron(neutron), energy() {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton, const short int neutron,
        qft::Mass& mass)
        : symbol(symbol), proton(proton), neutron(neutron), energy(mass) {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton, const short int neutron,
        qft::Charge& charge)
        : symbol(symbol), proton(proton), neutron(neutron), energy(charge) {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton, const short int neutron,
        qft::Mass& mass, qft::Charge& charge)
        : symbol(symbol), proton(proton), neutron(neutron), energy(mass, charge) {
	initialize();
}

Nucleus::Nucleus(std::string symbol, const short int proton, const short int neutron,
        qft::Energy& energy)
        : symbol(symbol), proton(proton), neutron(neutron), energy(energy) {
	initialize();
}

Nucleus::~Nucleus() {
	setElectric(nullptr);
	setGravity(nullptr);
}

bool Nucleus::operator==(const Nucleus& peer) const {
    return (symbol == peer.symbol)
		&& (proton == peer.proton)
		&& (neutron == peer.neutron)
		&& (energy == peer.energy);
}

Nucleus Nucleus::operator+(const Nucleus& peer) const {
	qft::Energy total = (energy + peer.energy);
    return Nucleus("+", (proton + peer.proton),
		(neutron + peer.neutron), total);
}

Nucleus Nucleus::operator-(const Nucleus& peer) const {
	qft::Energy total = (energy + peer.energy);
    return Nucleus("-", (proton - peer.proton),
		(neutron - peer.neutron), total);
}

const std::string Nucleus::getSymbol(short int number) {
	return (number > 0 && number <= PROTON_MAX_LIMIT) ? ELEMENT_SYMBOL[number-1] : UNKNOWN;
}

const std::string Nucleus::getName(short int number) {
	return (number > 0 && number <= PROTON_MAX_LIMIT) ? ELEMENT_NAME[number-1] : UNKNOWN;
}

std::string Nucleus::getElementName() const {
	return (proton > 0 && proton <= PROTON_MAX_LIMIT) ? ELEMENT_NAME[proton-1] : UNKNOWN;
}

std::shared_ptr<qft::Field> Nucleus::getElectric() const {
	return energy.getChargeField();
}

void Nucleus::setElectric(std::shared_ptr<qft::Field> address) {
	energy.setChargeField(address);
}

std::shared_ptr<qft::Field> Nucleus::getGravity() const {
	return energy.getMassField();
}

void Nucleus::setGravity(std::shared_ptr<qft::Field> address) {
	energy.setMassField(address);
}

Nucleus Nucleus::copy() {
    Nucleus fresh(getSymbol(), proton, neutron, energy);
	return fresh;
}

void Nucleus::clear() {
	symbol.clear();
	proton = neutron = 0;
	energy.clear();
    return;
}

std::string Nucleus::print() {
    std::stringstream result;
	result << symbol << ",p:";
	result << proton << ",n:";
	result << neutron << ",";
	result << energy.print();
	return result.str();
}

void Nucleus::initialize() {
    setGravity(qft::Field::shareable("G"));
	std::shared_ptr<qft::Field> mfield = getGravity();
	float nuclear_mass = ((qft::Mass::PROTON * proton) + (qft::Mass::NEUTRON * neutron));
    mfield->setMagnitude(nuclear_mass, qft::Mass::ATOMIC_SCALE);

    setElectric(qft::Field::shareable("E"));
	std::shared_ptr<qft::Field> efield = getElectric();
    efield->setMagnitude((qft::Charge::PROTON * proton), qft::Charge::ATOMIC_SCALE);
}

} // namespace che