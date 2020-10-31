//  f5.cc
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
#include "benchmark/f5.hpp"

Benchmark* F5::Create() {
    return new F5();
}

F5::F5() : Benchmark()  {
    boundaries_m = new Boundaries[variablesCount_m];
    
    for(register unsigned int variable = 0; variable < variablesCount_m; variable++) {
        boundaries_m[variable] = {.lowerBound = -30.0, .upperBound = 30.0};
    }

    Benchmark::setName("F5");
    Benchmark::setDimension(variablesCount_m);
    Benchmark::setBoundaries(boundaries_m);            
}

F5::~F5() {
    delete boundaries_m;
}

double F5::fitness(double x[]) {
    double sum = 0;
    
    for(register unsigned int variable=0; variable<variablesCount_m - 1; variable++) {
        sum += (100 * pow(x[variable+1] - pow(x[variable], 2.0), 2.0)) + pow(x[variable]-1.0, 2.0);
    }

    return sum;
}
