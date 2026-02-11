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

#include "mathematics.h"

namespace test {

const std::string Mathematics::DEFAULT_NAME = "Mathematics";

Mathematics::Mathematics()
        : cfg::System(DEFAULT_NAME) {

}

Mathematics::Mathematics(const std::string name)
        : cfg::System(name) {

}

Mathematics::Mathematics(const int argc, char* argv[])
        : cfg::System(DEFAULT_NAME) {
    cfg::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const std::string name, const int argc, char* argv[])
        : cfg::System(name) {
    cfg::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const cfg::CommandLine& object)
        : cfg::System(DEFAULT_NAME) {
    cfg::System::setParameters(object);
}

Mathematics::Mathematics(const std::string name, const cfg::CommandLine& object)
        : cfg::System(name) {
    cfg::System::setParameters(object);
}

Mathematics::~Mathematics() {

}

int Mathematics::run() {
    return run(cfg::System::getParameters());
}

int Mathematics::run(const int argc, char* argv[]) {
    cfg::System::setParameters(argc, argv);
    return run(cfg::System::getParameters());
}

int Mathematics::run(const cfg::CommandLine& object) {
    cfg::System::printStartedMessage();
    quantity_concept();
    direction_concept();
    angular_concept();
    signal_concept();
    distance_concept();
    area_concept();
    volume_concept();
    cfg::System::printStoppedMessage();
    return 0;
}

void Mathematics::quantity_concept() {
    std::string unit = "kg"; short int scale = 0;
    shp::Quantity q1(3.0f, scale, unit);
    std::cout << q1.print() << std::endl;
    shp::Quantity q2(4.0f, scale, unit);
    std::cout << q2.print() << std::endl;
    std::cout << (q1+q2).print() << std::endl;
    std::cout << (q1-q2).print() << std::endl;
    std::cout << (q1*q2).print() << std::endl;
    std::cout << (q1/q2).print() << std::endl;
    std::cout << (q1%q2).print() << std::endl;
    std::cout << std::endl;
}

void Mathematics::direction_concept() {
    for (int i=0; i < 5; i++) {
        shp::Direction d(shp::Direction::DEGREE_001 * i);
        std::cout << d.print() << " " << d.printRadians() << " " << d.printEuler() << std::endl;
    }
    std::cout << std::endl;
}

void Mathematics::angular_concept() {
    std::string unit = "m"; short int scale = 0;
    shp::Angular a1(5.0f, scale, unit,
        shp::Azimuth(shp::Direction::DEGREE_030),
        shp::Polar(shp::Direction::DEGREE_030));
    shp::Angular a2(3.0f, scale, unit,
        shp::Azimuth(shp::Direction::DEGREE_045),
        shp::Polar(shp::Direction::DEGREE_045));
    std::cout << "A1: " << a1.print() << std::endl << "A2: " << a2.print() << std::endl
        << "\ta1 + a2: " << (a1+a2).print() << std::endl
        << "\ta1 - a2: " << (a1-a2).print() << std::endl
        << "\ta1 * a2: " << (a1*a2).print() << std::endl
        << "\ta1 / a2: " << (a1/a2).print() << std::endl
        << "\ta1 % a2: " << (a1%a2).print() << std::endl
        << std::endl;
    for (int i=0; i < 4; i++) {
        a1.setStressFactor(shp::Direction::DEGREE_001 * i);
        a1.setDopplerShift(shp::Direction::DEGREE_005 * i);
        shp::Distance position(i, 1);
        std::cout << "A1: " << a1.print() << std::endl
            << "Stress: " << a1.getStressFactor().print()
            << " Doppler: " << a1.getDopplerShift().print()
            << " X1: " << a1.getLinearX(position).print()
            << " Y1: " << a1.getLinearY(position).print()
            << " Z1: " << a1.getLinearZ(position).print()
            << std::endl << std::endl;;
    }
    std::cout << std::endl;
}

void Mathematics::signal_concept() {
    std::string unit = "m"; short int scale = 0;
    shp::Signal q1(shp::Intrinsic(shp::Direction::DEGREE_001 * 30), 5.0f, scale, unit);
    for (int i=0; i < 6; i++) {
        shp::Signal q2(shp::Intrinsic(shp::Direction::DEGREE_030 * i), 3.0f, scale, unit);
        std::cout << "Q1: " << q1.print() << " Q2: " << q2.print() << " Amp: " << q2.getAmplitude()
            << std::endl
            << "\tDot: " << q2.getDotProduct(q1).print()
            << "\tCross: " << q2.getCrossProduct(q1).print()
            << std::endl
            << "\tq1 + q2: " << (q1+q2).print() << std::endl
            << "\tq1 - q2: " << (q1-q2).print() << std::endl
            << "\tq1 * q2: " << (q1*q2).print() << std::endl
            << "\tq1 / q2: " << (q1/q2).print() << std::endl
            << "\tq1 % q2: " << (q1%q2).print() << std::endl
            << std::endl;
    }
    std::cout << std::endl;
}

void Mathematics::distance_concept() {
    std::string unit = "m"; short int scale = 0;
    shp::Distance d1(5.0f, scale, unit,
        shp::Intrinsic(shp::Direction::DEGREE_001 * 0),
        shp::Azimuth(shp::Direction::DEGREE_030),
        shp::Polar(shp::Direction::DEGREE_030));
    shp::Distance d2(3.0f, scale, unit,
        shp::Intrinsic(shp::Direction::DEGREE_001 * 0),
        shp::Azimuth(shp::Direction::DEGREE_045),
        shp::Polar(shp::Direction::DEGREE_045));
    std::cout << "D1: " << d1.print() << std::endl << "D2: " << d2.print() << std::endl
        << "\td1 + d2: " << (d1+d2).print() << std::endl
        << "\td1 - d2: " << (d1-d2).print() << std::endl
        << "\td1 * d2: " << (d1*d2).print() << std::endl
        << "\td1 / d2: " << (d1/d2).print() << std::endl
        << "\td1 % d2: " << (d1%d2).print() << std::endl
        << std::endl;
    for (int i=0; i < 4; i++) {
        shp::Intrinsic elevation(shp::Direction::DEGREE_001 * 0);
        shp::Distance position(i, 1); d1.setChangeIntrinsic(1.0f);
        std::cout << "Ampl: " << d1.getAmplitude() << " D: " << d1.print() << std::endl
            << "R1: " << d1.getRadial().print()
            << " X1: " << d1.getRadialX(elevation).print()
            << " Y1: " << d1.getRadialY(elevation).print()
            << " Z1: " << d1.getRadialZ(elevation).print()
            << std::endl << std::endl;
    }
    std::cout << std::endl;

    for (int i=0; i < 5; i++) {
        shp::Intrinsic elevation(shp::Direction::DEGREE_001 * 0);
        shp::Azimuth azimuth(shp::Direction::DEGREE_001 * i);
        shp::Polar polar(shp::Direction::DEGREE_001 * i);
        shp::Distance dA(5.0f, scale, unit,
            shp::Intrinsic(shp::Direction::DEGREE_001 * 0),
            shp::Azimuth(shp::Direction::DEGREE_001 * 0),
            shp::Polar(shp::Direction::DEGREE_001 * 0));
        shp::Distance dB(1.0f, scale, unit,
            shp::Intrinsic(shp::Direction::DEGREE_001 * 0),
            shp::Azimuth(shp::Direction::DEGREE_001 * 0),
            shp::Polar(shp::Direction::DEGREE_001 * 0));    
        std::cout
            << "dB: " << dB.print() << " Xp: " << dA(dB, azimuth, polar).print()
            << std::endl
            << "xL: " << dA.getLinear(dB, elevation).print()
            << " xD: " << dA.getLinearDivergence(dB, elevation).print()
            << " xC: " << dA.getLinearConvergence(dB, elevation).print()
            << std::endl
            << "yP: " << dA.getPlanar(dB, elevation).print()
            << " yD: " << dA.getPlanarDivergence(dB, azimuth).print()
            << " yC: " << dA.getPlanarConvergence(dB, azimuth).print()
            << std::endl
            << "zO: " << dA.getOrthogonal(dB, elevation).print()
            << " zD: " << dA.getOrthogonalDivergence(dB, polar).print()
            << " zC: " << dA.getOrthogonalConvergence(dB, polar).print()
            << std::endl << std::endl;
    }
    std::cout << std::endl;
}

void Mathematics::area_concept() {
    shp::Area a1(30.0f, 0), a2(40.0f, 0);
    a1.setLength(3.0f); a1.setLengthPhase(shp::Direction::DEGREE_000);
    a1.setBreadth(3.0f); a1.setBreadthPhase(shp::Direction::DEGREE_000);
    std::cout << "a1: " << a1.print() << std::endl
        << "\t" << a1.getScalar().print() << " " << a1.getRotation().print()
        << " " << a1.getAligned().print() << " " << a1.getNormal().print() << std::endl;
    a2.setLength(4.0f); a2.setLengthPhase(shp::Direction::DEGREE_000);
    a2.setBreadth(4.0f); a2.setBreadthPhase(shp::Direction::DEGREE_000);
    std::cout << "a2: " << a2.print() << std::endl
        << "\t" << a2.getScalar().print() << " " << a2.getRotation().print()
        << " " << a2.getAligned().print() << " " << a2.getNormal().print() << std::endl;
    std::cout << "a1+a2: " << (a1+a2).print() << std::endl
        << "\t" << (a1+a2).getScalar().print() << " " << (a1+a2).getRotation().print()
        << " " << (a1+a2).getAligned().print() << " " << (a1+a2).getNormal().print() << std::endl;
    std::cout << "a1-a2: " << (a1-a2).print() << std::endl
        << "\t" << (a1-a2).getScalar().print() << " " << (a1-a2).getRotation().print()
        << " " << (a1-a2).getAligned().print() << " " << (a1-a2).getNormal().print() << std::endl;
    std::cout << "a1*a2: " << (a1*a2).print() << std::endl
        << "\t" << (a1*a2).getScalar().print() << " " << (a1*a2).getRotation().print()
        << " " << (a1*a2).getAligned().print() << " " << (a1*a2).getNormal().print() << std::endl;
    std::cout << "a1/a2: " << (a1/a2).print() << std::endl
        << "\t" << (a1/a2).getScalar().print() << " " << (a1/a2).getRotation().print()
        << " " << (a1/a2).getAligned().print() << " " << (a1/a2).getNormal().print() << std::endl;
    std::cout << "a1%a2: " << (a1%a2).print() << std::endl
        << "\t" << (a1%a2).getScalar().print() << " " << (a1%a2).getRotation().print()
        << " " << (a1%a2).getAligned().print() << " " << (a1%a2).getNormal().print() << std::endl;
    std::cout << std::endl;
}

void Mathematics::volume_concept() {
    shp::Volume v1(30.0f, 0), v2(40.0f, 0);
    v1.setLength(3.0f); v1.setLengthPhase(shp::Direction::DEGREE_000);
    v1.setBreadth(4.0f); v1.setBreadthPhase(shp::Direction::DEGREE_000);
    v1.setHeight(5.0f); v1.setHeightPhase(shp::Direction::DEGREE_000);
    v2.setLength(3.0f); v2.setLengthPhase(shp::Direction::DEGREE_000);
    v2.setBreadth(4.0f); v2.setBreadthPhase(shp::Direction::DEGREE_000);
    v2.setHeight(5.0f); v2.setHeightPhase(shp::Direction::DEGREE_000);
    std::cout << v1.print() << std::endl
        << " " << v1.getScalar().print() << " " << v1.getFlux().print()
        << " " << v1.getSurfaceTension().print() << " " << v1.getSurfaceCurrent().print()
        << " " << v1.getMobility().print() << " " << v1.getCurvature().print() << std::endl;
    std::cout << v2.print() << std::endl
        << " " << v2.getScalar().print() << " " << v2.getFlux().print()
        << " " << v2.getSurfaceTension().print() << " " << v2.getSurfaceCurrent().print()
        << " " << v2.getMobility().print() << " " << v2.getCurvature().print() << std::endl;
    std::cout << "v1+v2: " << (v1+v2).print() << std::endl
        << "\t" << (v1+v2).getScalar().print() << " " << (v1+v2).getFlux().print()
        << " " << (v1+v2).getSurfaceTension().print() << " " << (v1+v2).getSurfaceCurrent().print()
        << " " << (v1+v2).getMobility().print() << " " << (v1+v2).getCurvature().print() << std::endl;
    std::cout << "v1-v2: " << (v1-v2).print() << std::endl
        << "\t" << (v1-v2).getScalar().print() << " " << (v1-v2).getFlux().print()
        << " " << (v1-v2).getSurfaceTension().print() << " " << (v1-v2).getSurfaceCurrent().print()
        << " " << (v1-v2).getMobility().print() << " " << (v1-v2).getCurvature().print() << std::endl;
    std::cout << "v1*v2: " << (v1*v2).print() << std::endl
        << "\t" << (v1*v2).getScalar().print() << " " << (v1*v2).getFlux().print()
        << " " << (v1*v2).getSurfaceTension().print() << " " << (v1*v2).getSurfaceCurrent().print()
        << " " << (v1*v2).getMobility().print() << " " << (v1*v2).getCurvature().print() << std::endl;
    std::cout << "v1/v2: " << (v1/v2).print() << std::endl
        << "\t" << (v1/v2).getScalar().print() << " " << (v1/v2).getFlux().print()
        << " " << (v1/v2).getSurfaceTension().print() << " " << (v1/v2).getSurfaceCurrent().print()
        << " " << (v1/v2).getMobility().print() << " " << (v1/v2).getCurvature().print() << std::endl;
    std::cout << "v1%v2: " << (v1%v2).print() << std::endl
        << "\t" << (v1%v2).getScalar().print() << " " << (v1%v2).getFlux().print()
        << " " << (v1%v2).getSurfaceTension().print() << " " << (v1%v2).getSurfaceCurrent().print()
        << " " << (v1%v2).getMobility().print() << " " << (v1%v2).getCurvature().print() << std::endl;
    std::cout << std::endl;
}

void Mathematics::medium_concept() {

}

void Mathematics::temporal_concept() {

}

void Mathematics::frequency_concept() {

}

void Mathematics::potential_concept() {

}

void Mathematics::confinement_concept() {

}

} // namespace test