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
        : test::System(DEFAULT_NAME) {

}

Mathematics::Mathematics(const std::string name)
        : test::System(name) {

}

Mathematics::Mathematics(const int argc, char* argv[])
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const std::string name, const int argc, char* argv[])
        : test::System(name) {
    test::System::setParameters(argc, argv);
}

Mathematics::Mathematics(const cfg::CommandLine& object)
        : test::System(DEFAULT_NAME) {
    test::System::setParameters(object);
}

Mathematics::Mathematics(const std::string name, const cfg::CommandLine& object)
        : test::System(name) {
    test::System::setParameters(object);
}

Mathematics::~Mathematics() {

}

int Mathematics::run() {
    return run(test::System::getParameters());
}

int Mathematics::run(const int argc, char* argv[]) {
    test::System::setParameters(argc, argv);
    return run(test::System::getParameters());
}

int Mathematics::run(const cfg::CommandLine& object) {
    test::System::printStartedMessage();
    quantity_concept();
    direction_concept();
    angular_concept();
    signal_concept();
    distance_concept();
    area_concept();
    volume_concept();
    test::System::printStoppedMessage();
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
        shp::Azimuth(shp::Direction::DEGREE_030),
        shp::Polar(shp::Direction::DEGREE_030));
    shp::Distance d2(3.0f, scale, unit,
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
}

void Mathematics::area_concept() {
    shp::Area a1(3.0f, 0), a2(4.0f, 0);
    a1.setLength(11.0f); a1.setBreadth(11.0f);
    a2.setLength(12.0f); a2.setBreadth(12.0f);
    std::cout << a1.print() << " " << a1.getScalarTotal().print() << " " << a1.getVectorTotal().print() << std::endl;
    std::cout << a2.print() << " " << a2.getScalarTotal().print() << " " << a2.getVectorTotal().print() << std::endl;
    std::cout << (a1+a2).print() << " " << (a1+a2).getScalarTotal().print() << " " << (a1+a2).getVectorTotal().print() << std::endl;
    std::cout << (a1-a2).print() << " " << (a1-a2).getScalarTotal().print() << " " << (a1-a2).getVectorTotal().print() << std::endl;
    std::cout << (a1*a2).print() << " " << (a1*a2).getScalarTotal().print() << " " << (a1*a2).getVectorTotal().print() << std::endl;
    std::cout << (a1/a2).print() << " " << (a1/a2).getScalarTotal().print() << " " << (a1/a2).getVectorTotal().print() << std::endl;
    std::cout << (a1%a2).print() << " " << (a1%a2).getScalarTotal().print() << " " << (a1%a2).getVectorTotal().print() << std::endl;
    std::cout << std::endl;
}

void Mathematics::volume_concept() {
    shp::Volume v1(3.0f, 0), v2(4.0f, 0);
    v1.setLength(11.0f); v1.setBreadth(11.0f); v1.setHeight(11.0f);
    v2.setLength(12.0f); v2.setBreadth(12.0f); v2.setHeight(12.0f);
    std::cout << v1.print() << " " << v1.getScalarTotal().print() << " " << v1.getVectorTotal().print() << std::endl;
    std::cout << v2.print() << " " << v2.getScalarTotal().print() << " " << v2.getVectorTotal().print() << std::endl;
    std::cout << (v1+v2).print() << " " << (v1+v2).getScalarTotal().print() << " " << (v1+v2).getVectorTotal().print() << std::endl;
    std::cout << (v1-v2).print() << " " << (v1-v2).getScalarTotal().print() << " " << (v1-v2).getVectorTotal().print() << std::endl;
    std::cout << (v1*v2).print() << " " << (v1*v2).getScalarTotal().print() << " " << (v1*v2).getVectorTotal().print() << std::endl;
    std::cout << (v1/v2).print() << " " << (v1/v2).getScalarTotal().print() << " " << (v1/v2).getVectorTotal().print() << std::endl;
    std::cout << (v1%v2).print() << " " << (v1%v2).getScalarTotal().print() << " " << (v1%v2).getVectorTotal().print() << std::endl;
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