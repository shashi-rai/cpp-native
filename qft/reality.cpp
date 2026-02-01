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

#include "reality.h"

namespace qft {

const float Reality::DEFAULT_VALUE = 0.0f;
const float Reality::DEFAULT_TICKS = 1.0f;
const float Reality::DEFAULT_FIELD = 1.0f;

Reality::Reality()
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGravityField(DEFAULT_FIELD);
    initializeThermalField(DEFAULT_FIELD);
    initializeDiffusionField(DEFAULT_FIELD);
    initializeElectricField(DEFAULT_FIELD);
    initializeMagneticField(DEFAULT_FIELD);
}

Reality::Reality(const Mass& mass)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGravityField(mass);
}

Reality::Reality(const Charge& charge)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeElectricField(charge);
    initializeMagneticField(charge);
}

Reality::Reality(const Colour& colour)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Charge& charge)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGravityField(mass);
    initializeElectricField(charge);
    initializeMagneticField(charge);
}

Reality::Reality(const Charge& charge, const Colour& colour)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeElectricField(charge);
    initializeMagneticField(charge);
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Colour& colour)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGravityField(mass);
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Charge& charge, const Colour& colour)
        : clock(), gravity(), thermal(), diffusion(), electric(), magnetic(),
        up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeTimeDomain();
    initializeGravityField(mass);
    initializeElectricField(charge);
    initializeMagneticField(charge);
    initializeGluonField(colour);
}

Reality::~Reality() {
    Reality::clear();
}

bool Reality::operator==(const Reality& peer) const {
    return (clock == peer.clock)
        // Generic Fields
        && (gravity == peer.gravity) && (thermal == peer.thermal) && (diffusion == peer.diffusion)
        && (electric == peer.electric) && (magnetic == peer.magnetic)
        // Quark Fields
        && (up == peer.up) && (down == peer.down)
        && (charm == peer.charm) && (strange == peer.strange)
        && (top == peer.top) && (bottom == peer.bottom)
        // Lepton Fields
        && (electron == peer.electron) && (electronNeutrino == peer.electronNeutrino)
        && (muon == peer.muon) && (muonNeutrino == peer.muonNeutrino)
        && (tau == peer.tau) && (tauNeutrino == peer.tauNeutrino)
        // Guage Boson Fields
        && (photon == peer.photon) && (gluon == peer.gluon) && (strong == peer.strong) && (weak == peer.weak)
        // Higgs Boson Field
        && (higgs == peer.higgs);
}

std::shared_ptr<qft::Field> Reality::operator()(const Temperature& cause) {
    if (thermal != nullptr) {
        thermal->setRadius(cause.getFieldRadius());
        thermal->setTemporalChange(cause.getMagnitude());
    } else {
        initializeThermalField(cause);
    }
    return electric;
}

std::shared_ptr<qft::Field> Reality::operator()(const Heat& cause) {
    if (diffusion != nullptr) {
        shp::Signal total = cause.getThermalFlow();
        diffusion->setRadius(cause.getTemperature().getFieldRadius());
        diffusion->setTemporalChange(total.getMagnitude());
    } else {
        initializeDiffusionField(cause.getTemperature());
    }
    return diffusion;
}

std::shared_ptr<qft::Field> Reality::operator()(const Charge& cause) {
    if (electric != nullptr) {
        electric->setRadius(cause.getFieldRadius());
        electric->setTemporalChange(cause.getMagnitude());
    } else {
        initializeElectricField(cause);
    }
    return electric;
}

std::shared_ptr<qft::Field> Reality::operator()(const Current& cause) {
    if (magnetic != nullptr) {
        shp::Signal total = cause.getChargeFlow();
        magnetic->setRadius(cause.getCharge().getFieldRadius());
        magnetic->setTemporalChange(total.getMagnitude());
    } else {
        initializeMagneticField(cause.getCharge());
    }
    return magnetic;
}

std::shared_ptr<qft::Field> Reality::operator()(const Colour& cause) {
    if (gluon != nullptr) {
        gluon->setRadius(cause.getFieldRadius());
        gluon->setTemporalChange(cause.getMagnitude());
    } else {
        initializeGluonField(cause);
    }
    return gluon;
}

std::shared_ptr<qft::Field> Reality::operator()(const Mass& cause) {
    if (higgs != nullptr) {
        higgs->setRadius(cause.getFieldRadius());
        higgs->setTemporalChange(cause.getMagnitude());
    } else {
        initializeHiggsField(cause);
    }
    return higgs;
}

std::shared_ptr<qft::Field> Reality::operator()(const Momentum& cause) {
    if (gravity != nullptr) {
        gravity->setRadius(cause.getMass().getFieldRadius());
        gravity->setTemporalChange(cause.getMass().getMagnitude());
    } else {
        initializeGravityField(cause.getMass());
    }
    return gravity;
}

Reality Reality::copy() const {
    Reality fresh;
    fresh.setClock(clock);
    fresh.setGravity(gravity);
    fresh.setThermal(thermal);
    fresh.setDiffusion(diffusion);
    fresh.setElectric(electric);
    fresh.setMagnetic(magnetic);
    fresh.setUp(up);
    fresh.setDown(down);
    fresh.setCharm(charm);
    fresh.setStrange(strange);
    fresh.setTop(top);
    fresh.setBottom(bottom);
    fresh.setElectron(electron);
    fresh.setElectronNeutrino(electronNeutrino);
    fresh.setMuon(muon);
    fresh.setMuonNeutrino(muonNeutrino);
    fresh.setTau(tau);
    fresh.setTauNeutrino(tauNeutrino);
    fresh.setPhoton(photon);
    fresh.setGluon(gluon);
    fresh.setStrong(strong);
    fresh.setWeak(weak);
    fresh.setHiggs(higgs);
    return fresh;
}

void Reality::clear() {
    clock->clear(), gravity->clear(); thermal->clear(), diffusion->clear(), electric->clear(); magnetic->clear();
    up->clear(); down->clear(); charm->clear(); strange->clear(); top->clear(); bottom->clear();
    electron->clear(); electronNeutrino->clear(); muon->clear(); muonNeutrino->clear(); tau->clear(); tauNeutrino->clear();
    photon->clear(); gluon->clear(); strong->clear(); weak->clear(); higgs->clear();
    return;
}

std::string Reality::print() {
    std::stringstream result;
    result << "ॐ:[" << std::endl;
    if (clock != nullptr) {
        result << "\t" << clock->print() << "," << std::endl;
    }
    if (gravity != nullptr) {
        result << "\t" << gravity->print() << "," << std::endl;
    }
    if (thermal != nullptr) {
        result << "\t" << thermal->print() << "," << std::endl;
    }
    if (diffusion != nullptr) {
        result << "\t" << diffusion->print() << "," << std::endl;
    }
    if (electric != nullptr) {
        result << "\t" << electric->print() << "," << std::endl;
    }
    if (magnetic != nullptr) {
        result << "\t" << magnetic->print() << "," << std::endl;
    }
    if (up != nullptr) {
        result << "\t" << up->print() << "," << std::endl;
    }
    if (down != nullptr) {
        result << "\t" << down->print() << "," << std::endl;
    }
    if (charm != nullptr) {
        result << "\t" << charm->print() << "," << std::endl;
    }
    if (strange != nullptr) {
        result << "\t" << strange->print() << "," << std::endl;
    }
    if (top != nullptr) {
        result << "\t" << top->print() << "," << std::endl;
    }
    if (bottom != nullptr) {
        result << "\t" << bottom->print() << "," << std::endl;
    }
    if (electron != nullptr) {
        result << "\t" << electron->print() << "," << std::endl;
    }
    if (electronNeutrino != nullptr) {
        result << "\t" << electronNeutrino->print() << "," << std::endl;
    }
    if (muon != nullptr) {
        result << "\t" << muon->print() << "," << std::endl;
    }
    if (muonNeutrino != nullptr) {
        result << "\t" << muonNeutrino->print() << "," << std::endl;
    }
    if (tau != nullptr) {
        result << "\t" << tau->print() << "," << std::endl;
    }
    if (tauNeutrino != nullptr) {
        result << "\t" << tauNeutrino->print() << "," << std::endl;
    }
    if (photon != nullptr) {
        result << "\t" << photon->print() << "," << std::endl;
    }
    if (gluon != nullptr) {
        result << "\t" << gluon->print() << "," << std::endl;
    }
    if (strong != nullptr) {
        result << "\t" << strong->print() << "," << std::endl;
    }
    if (weak != nullptr) {
        result << "\t" << weak->print() << "," << std::endl;
    }
    if (higgs != nullptr) {
        result << "\t" << higgs->print() << "," << std::endl;
    }
    result << "]" << std::endl;
	return result.str();
}

void Reality::initializeTimeDomain() {
    clock = qft::Time::shareable("Time", DEFAULT_TICKS, shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeGravityField(const Mass& mass) {
    gravity = qft::Field::shareable("Gravity", mass.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeThermalField(const Temperature& temperature) {
    gravity = qft::Field::shareable("Thermal", temperature.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeDiffusionField(const Temperature& temperature) {
    gravity = qft::Field::shareable("Diffusion", temperature.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeElectricField(const Charge& charge) {
    electric = qft::Field::shareable("Electric", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeMagneticField(const Charge& charge) {
    magnetic = qft::Field::shareable("Magnetic", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeUpField(const Colour& colour) {
    up = qft::Field::shareable("Up", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeDownField(const Colour& colour) {
    down = qft::Field::shareable("Down", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeCharmField(const Colour& colour) {
    charm = qft::Field::shareable("Charm", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeStrangeField(const Colour& colour) {
    strange = qft::Field::shareable("Strange", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeTopField(const Colour& colour) {
    top = qft::Field::shareable("Top", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeBottomField(const Colour& colour) {
    bottom = qft::Field::shareable("Bottom", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeElectronField(const Charge& charge) {
    electron = qft::Field::shareable("Electron", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeElectronNeutrinoField(const Charge& charge) {
    electronNeutrino = qft::Field::shareable("Electron Neutrino", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeMuonField(const Charge& charge) {
    muon = qft::Field::shareable("Muon", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeMuonNeutrinoField(const Charge& charge) {
    muonNeutrino = qft::Field::shareable("Muon Neutrino", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeTauField(const Charge& charge) {
    tau = qft::Field::shareable("Tau", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeTauNeutrinoField(const Charge& charge) {
    tauNeutrino = qft::Field::shareable("Tau Neutrino", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializePhotonField(const Mass& mass, const Charge& charge) {
    photon = qft::Field::shareable("Photon", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeGluonField(const Colour& colour) {
    gluon = qft::Field::shareable("Gluon", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeStrongField(const Colour& colour) {
    strong = qft::Field::shareable("Strong", colour.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeWeakField(const Charge& charge) {
    weak = qft::Field::shareable("Weak", charge.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

void Reality::initializeHiggsField(const Mass& mass) {
    higgs = qft::Field::shareable("Higgs", mass.getMagnitude(), shp::Quantity::DEFAULT_SCALE);
}

} // namespace qft