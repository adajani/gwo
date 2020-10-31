//  benchmark.cc
//
//  Author:
//       Ahmad Dajani <eng.adajani@gmail.com>
//
//  Copyright (c) 2020 Ahmad Dajani
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <string>
#include "benchmark.hpp"

Benchmark::Benchmark(const std::string &name,
                     const unsigned int &dimension,
                     Boundaries *boundaries) : name_m(name), dimension_m(dimension), boundaries_m(boundaries) {
}

void Benchmark::setName(const std::string &name) {
    name_m = name;
}

void Benchmark::setDimension(const unsigned int &dimension) {
    dimension_m = dimension;
}

void Benchmark::setBoundaries(Boundaries *boundaries) {
    boundaries_m = boundaries;
}

std::string Benchmark::GetName() {
    return this->name_m;
}

unsigned int Benchmark::GetDimension() {
    return this->dimension_m;
}

Boundaries* Benchmark::getBoundaries() {
    return this->boundaries_m;
}
