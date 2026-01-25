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

#ifndef QFT_REALITY_H
#define QFT_REALITY_H

#include "colour.h"
#include "current.h"
#include "field.h"
#include "momentum.h"

namespace qft {

class Reality {
    // Generic Fields
    std::shared_ptr<qft::Field> gravity;
    std::shared_ptr<qft::Field> electric;
    std::shared_ptr<qft::Field> magnetic;

    // Quark Fields
    std::shared_ptr<qft::Field> up;
    std::shared_ptr<qft::Field> down;
    std::shared_ptr<qft::Field> charm;
    std::shared_ptr<qft::Field> strange;
    std::shared_ptr<qft::Field> top;
    std::shared_ptr<qft::Field> bottom;

    // Lepton Fields
    std::shared_ptr<qft::Field> electron;
    std::shared_ptr<qft::Field> electronNeutrino;
    std::shared_ptr<qft::Field> muon;
    std::shared_ptr<qft::Field> muonNeutrino;
    std::shared_ptr<qft::Field> tau;
    std::shared_ptr<qft::Field> tauNeutrino;

    // Guage Boson Fields
    std::shared_ptr<qft::Field> photon;
    std::shared_ptr<qft::Field> gluon;
    std::shared_ptr<qft::Field> strong;
    std::shared_ptr<qft::Field> weak;

    // Higgs Boson Field
    std::shared_ptr<qft::Field> higgs;
public:
    // Constructors
    Reality();
    Reality(const Mass& mass);
    Reality(const Charge& charge);
    Reality(const Colour& colour);
    Reality(const Mass& mass, const Charge& charge);
    Reality(const Charge& charge, const Colour& colour);
    Reality(const Mass& mass, const Colour& colour);
    Reality(const Mass& mass, const Charge& charge, const Colour& colour);

    // Destructors
    ~Reality();

    // Operator overloading
    bool operator==(const Reality& peer) const;
    std::shared_ptr<qft::Field> operator()(const Charge& cause);
    std::shared_ptr<qft::Field> operator()(const Current& cause);
    std::shared_ptr<qft::Field> operator()(const Colour& cause);
    std::shared_ptr<qft::Field> operator()(const Mass& cause);
    std::shared_ptr<qft::Field> operator()(const Momentum& cause);

    // Getters
    std::shared_ptr<qft::Field> getGravity() const { return gravity; }
    std::shared_ptr<qft::Field> getElectric() const { return electric; }
    std::shared_ptr<qft::Field> getMagnetic() const { return magnetic; }
    std::shared_ptr<qft::Field> getUp() const { return up; }
    std::shared_ptr<qft::Field> getDown() const { return down; }
    std::shared_ptr<qft::Field> getCharm() const { return charm; }
    std::shared_ptr<qft::Field> getStrange() const { return strange; }
    std::shared_ptr<qft::Field> getTop() const { return top; }
    std::shared_ptr<qft::Field> getBottom() const { return bottom; }
    std::shared_ptr<qft::Field> getElectron() const { return electron; }
    std::shared_ptr<qft::Field> getElectronNeutrino() const { return electronNeutrino; }
    std::shared_ptr<qft::Field> getMuon() const { return muon; }
    std::shared_ptr<qft::Field> getMuonNeutrino() const { return muonNeutrino; }
    std::shared_ptr<qft::Field> getTau() const { return tau; }
    std::shared_ptr<qft::Field> getTauNeutrino() const { return tauNeutrino; }
    std::shared_ptr<qft::Field> getPhoton() const { return photon; }
    std::shared_ptr<qft::Field> getGluon() const { return gluon; }
    std::shared_ptr<qft::Field> getStrong() const { return strong; }
    std::shared_ptr<qft::Field> getWeak() const { return weak; }
    std::shared_ptr<qft::Field> getHiggs() const { return higgs; }

    // Setters
    void setGravity(const std::shared_ptr<qft::Field> field) { this->gravity = field; }
    void setElectric(const std::shared_ptr<qft::Field> field) { this->electric = field; }
    void setMagnetic(const std::shared_ptr<qft::Field> field) { this->magnetic = field; }
    void setUp(const std::shared_ptr<qft::Field> field) { this->up = field; }
    void setDown(const std::shared_ptr<qft::Field> field) { this->bottom = field; }
    void setCharm(const std::shared_ptr<qft::Field> field) { this->charm = field; }
    void setStrange(const std::shared_ptr<qft::Field> field) { this->strange = field; }
    void setTop(const std::shared_ptr<qft::Field> field) { this->top = field; }
    void setBottom(const std::shared_ptr<qft::Field> field) { this->bottom = field; }
    void setElectron(const std::shared_ptr<qft::Field> field) { this->electron = field; }
    void setElectronNeutrino(const std::shared_ptr<qft::Field> field) { this->electronNeutrino = field; }
    void setMuon(const std::shared_ptr<qft::Field> field) { this->muon = field; }
    void setMuonNeutrino(const std::shared_ptr<qft::Field> field) { this->muonNeutrino = field; }
    void setTau(const std::shared_ptr<qft::Field> field) { this->tau = field; }
    void setTauNeutrino(const std::shared_ptr<qft::Field> field) { this->tauNeutrino = field; }
    void setPhoton(const std::shared_ptr<qft::Field> field) { this->photon = field; }
    void setGluon(const std::shared_ptr<qft::Field> field) { this->gluon = field; }
    void setStrong(const std::shared_ptr<qft::Field> field) { this->strong = field; }
    void setWeak(const std::shared_ptr<qft::Field> field) { this->weak = field; }
    void setHiggs(const std::shared_ptr<qft::Field> field) { this->higgs = field; }

    // Additional methods
    virtual Reality copy() const;
    virtual void clear();
    virtual std::string print();

private:
    void initializeGravityField(const Mass& mass);
    void initializeElectricField(const Charge& charge);
    void initializeMagneticField(const Charge& charge);
    void initializeUpField(const Colour& colour);
    void initializeDownField(const Colour& colour);
    void initializeCharmField(const Colour& colour);
    void initializeStrangeField(const Colour& colour);
    void initializeTopField(const Colour& colour);
    void initializeBottomField(const Colour& colour);
    void initializeElectronField(const Charge& charge);
    void initializeElectronNeutrinoField(const Charge& charge);
    void initializeMuonField(const Charge& charge);
    void initializeMuonNeutrinoField(const Charge& charge);
    void initializeTauField(const Charge& charge);
    void initializeTauNeutrinoField(const Charge& charge);
    void initializePhotonField(const Mass& mass, const Charge& charge);
    void initializeGluonField(const Colour& colour);
    void initializeStrongField(const Charge& charge);
    void initializeWeakField(const Charge& charge);
    void initializeHiggsField(const Mass& mass);
public:
    static const float DEFAULT_VALUE;
    static const float DEFAULT_FIELD;
};

typedef std::vector<Reality > RealityArray;

} // namespace qft

#endif //QFT_REALITY_H