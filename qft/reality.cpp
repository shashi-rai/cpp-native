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
const float Reality::DEFAULT_FIELD = 1.0f;

Reality::Reality()
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGravityField(DEFAULT_FIELD);
    initializeElectricField(DEFAULT_FIELD);
    initializeMagneticField(DEFAULT_FIELD);
}

Reality::Reality(const Mass& mass)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGravityField(mass);
}

Reality::Reality(const Charge& charge)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeElectricField(charge);
    initializeMagneticField(charge);
}

Reality::Reality(const Colour& colour)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Charge& charge)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGravityField(mass);
    initializeElectricField(charge);
    initializeMagneticField(charge);
}

Reality::Reality(const Charge& charge, const Colour& colour)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeElectricField(charge);
    initializeMagneticField(charge);
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Colour& colour)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGravityField(mass);
    initializeGluonField(colour);
}

Reality::Reality(const Mass& mass, const Charge& charge, const Colour& colour)
        : gravity(), electric(), magnetic(), up(), down(), charm(), strange(), top(), bottom(),
        electron(), electronNeutrino(), muon(), muonNeutrino(), tau(), tauNeutrino(),
        photon(), gluon(), strong(), weak(), higgs() {
    initializeGravityField(mass);
    initializeElectricField(charge);
    initializeMagneticField(charge);
    initializeGluonField(colour);
}

Reality::~Reality() {
    Reality::clear();
}

bool Reality::operator==(const Reality& peer) const {
    return (gravity == peer.gravity) && (electric == peer.electric) && (magnetic == peer.magnetic)
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

std::shared_ptr<qft::Field> Reality::operator()(const Charge& cause) {
    if (electric != nullptr) {
        electric->setRadius(cause.getRadius());
        electric->setAmplitude(cause.getMagnitude());
    } else {
        initializeElectricField(cause);
    }
    return electric;
}

std::shared_ptr<qft::Field> Reality::operator()(const Current& cause) {
    if (magnetic != nullptr) {
        magnetic->setRadius(cause.getCharge().getRadius());
        magnetic->setAmplitude(cause.getLinearTotal());
    } else {
        initializeMagneticField(cause.getCharge());
    }
    return magnetic;
}

std::shared_ptr<qft::Field> Reality::operator()(const Colour& cause) {
    if (gluon != nullptr) {
        gluon->setRadius(cause.getRadius());
        gluon->setAmplitude(cause.getMagnitude());
    } else {
        initializeGluonField(cause);
    }
    return gluon;
}

std::shared_ptr<qft::Field> Reality::operator()(const Mass& cause) {
    if (higgs != nullptr) {
        higgs->setRadius(cause.getRadius());
        higgs->setAmplitude(cause.getMagnitude());
    } else {
        initializeHiggsField(cause);
    }
    return higgs;
}

std::shared_ptr<qft::Field> Reality::operator()(const Momentum& cause) {
    if (gravity != nullptr) {
        gravity->setRadius(cause.getMass().getRadius());
        gravity->setAmplitude(cause.getMass().getMagnitude());
    } else {
        initializeGravityField(cause.getMass());
    }
    return gravity;
}

Reality Reality::copy() const {
    Reality fresh;
    fresh.setGravity(gravity);
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
    gravity->clear(); electric->clear(); magnetic->clear();
    up->clear(); down->clear(); charm->clear(); strange->clear(); top->clear(); bottom->clear();
    electron->clear(); electronNeutrino->clear(); muon->clear(); muonNeutrino->clear(); tau->clear(); tauNeutrino->clear();
    photon->clear(); gluon->clear(); strong->clear(); weak->clear(); higgs->clear();
    return;
}

std::string Reality::print() {
    std::stringstream result;
    result << "ॐ:[" << std::endl;
    if (gravity != nullptr) {
        result << "\t" << gravity->print() << "," << std::endl;
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

void Reality::initializeGravityField(const Mass& mass) {
    gravity = qft::Field::shareable("Gravity"); gravity->setAmplitude(mass);
}

void Reality::initializeElectricField(const Charge& charge) {
    electric = qft::Field::shareable("Electric"); electric->setAmplitude(charge);
}

void Reality::initializeMagneticField(const Charge& charge) {
    magnetic = qft::Field::shareable("Magnetic"); magnetic->setAmplitude(charge);
}

void Reality::initializeUpField(const Colour& colour) {
    up = qft::Field::shareable("Up"); up->setAmplitude(colour);
}

void Reality::initializeDownField(const Colour& colour) {
    down = qft::Field::shareable("Down"); down->setAmplitude(colour);
}

void Reality::initializeCharmField(const Colour& colour) {
    charm = qft::Field::shareable("Charm"); charm->setAmplitude(colour);
}

void Reality::initializeStrangeField(const Colour& colour) {
    strange = qft::Field::shareable("Strange"); strange->setAmplitude(colour);
}

void Reality::initializeTopField(const Colour& colour) {
    top = qft::Field::shareable("Top"); top->setAmplitude(colour);
}

void Reality::initializeBottomField(const Colour& colour) {
    bottom = qft::Field::shareable("Bottom"); bottom->setAmplitude(colour);
}

void Reality::initializeElectronField(const Charge& charge) {
    electron = qft::Field::shareable("Electron"); electron->setAmplitude(charge);
}

void Reality::initializeElectronNeutrinoField(const Charge& charge) {
    electronNeutrino = qft::Field::shareable("Electron Neutrino"); electronNeutrino->setAmplitude(charge);
}

void Reality::initializeMuonField(const Charge& charge) {
    muon = qft::Field::shareable("Muon"); muon->setAmplitude(charge);
}

void Reality::initializeMuonNeutrinoField(const Charge& charge) {
    muonNeutrino = qft::Field::shareable("Muon Neutrino"); muonNeutrino->setAmplitude(charge);
}

void Reality::initializeTauField(const Charge& charge) {
    tau = qft::Field::shareable("Tau"); tau->setAmplitude(charge);
}

void Reality::initializeTauNeutrinoField(const Charge& charge) {
    tauNeutrino = qft::Field::shareable("Tau Neutrino"); tauNeutrino->setAmplitude(charge);
}

void Reality::initializePhotonField(const Mass& mass, const Charge& charge) {
    photon = qft::Field::shareable("Photon"); photon->setAmplitude(charge);
}

void Reality::initializeGluonField(const Colour& colour) {
    gluon = qft::Field::shareable("Gluon"); gluon->setAmplitude(colour);
}

void Reality::initializeStrongField(const Charge& charge) {
    strong = qft::Field::shareable("Strong"); strong->setAmplitude(charge);
}

void Reality::initializeWeakField(const Charge& charge) {
    weak = qft::Field::shareable("Weak"); weak->setAmplitude(charge);
}

void Reality::initializeHiggsField(const Mass& mass) {
    higgs = qft::Field::shareable("Higgs"); higgs->setAmplitude(mass);
}

} // namespace qft