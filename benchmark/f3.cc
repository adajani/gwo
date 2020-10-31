//  f3.cc
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
#include "benchmark/f3.hpp"

Benchmark* F3::Create() {
    return new F3();
}

F3::F3() : Benchmark()  {
    boundaries_m = new Boundaries[variablesCount_m];
    
    for(register unsigned int variable = 0; variable < variablesCount_m; variable++) {
        boundaries_m[variable] = {.lowerBound = -100.0, .upperBound = 100.0};
    }

    Benchmark::setName("F3");
    Benchmark::setDimension(variablesCount_m);
    Benchmark::setBoundaries(boundaries_m);            
}

F3::~F3() {
    delete boundaries_m;
}

double F3::fitness(double x[]) {
    double outerSum = 0;
    double innerSum = 0;
    for(register unsigned int variable=0; variable<variablesCount_m; variable++){
        innerSum = 0;
        for(register unsigned int i=0; i<=variable; i++) {
            innerSum += x[i];
        }
        outerSum += pow(innerSum, 2.0);
    }
    return outerSum;
}
