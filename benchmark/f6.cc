//  f6.cc
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

#include <cmath> //pow
#include "benchmark/f6.hpp"

Benchmark* F6::Create() {
    return new F6();
}

F6::F6() : Benchmark()  {
    boundaries_m = new Boundaries[variablesCount_m];
    
    for(register unsigned int variable = 0; variable < variablesCount_m; variable++) {
        boundaries_m[variable] = {.lowerBound = -100.0, .upperBound = 100.0};
    }

    Benchmark::setName("F6");
    Benchmark::setDimension(variablesCount_m);
    Benchmark::setBoundaries(boundaries_m);            
}

F6::~F6() {
    delete boundaries_m;
}

double F6::fitness(double x[]) {
    double sum = 0;
    for(register unsigned int variable=0; variable<variablesCount_m; variable++){
        sum += pow(std::abs(x[variable] + 0.5), 2.0);
    }
    return sum;
}
