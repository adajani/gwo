//  F7.cc
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
#include "benchmark/f7.hpp"
#include "utils.hpp"

Benchmark* F7::Create() {
    return new F7();
}

F7::F7() : Benchmark()  {
    boundaries_m = new Boundaries[variablesCount_m];
    
    for(register unsigned int variable = 0; variable < variablesCount_m; variable++) {
        boundaries_m[variable] = {.lowerBound = -1.28, .upperBound = 1.28};
    }

    Benchmark::setName("F7");
    Benchmark::setDimension(variablesCount_m);
    Benchmark::setBoundaries(boundaries_m);            
}

F7::~F7() {
    delete boundaries_m;
}

double F7::fitness(double x[]) {
    double sum = 0;
    for(register unsigned int variable=0; variable<variablesCount_m; variable++){
        sum += (double)variable * pow(x[variable], 4.0) + Utils::GenerateRandomNumber();
    }
    return sum;    
}
