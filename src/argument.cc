//  argument.cc
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

#include <cstring> //strcasecmp
#include <cstdlib> //exit
#include <iostream> //cout
#include "argument.hpp"
#include "GWOException.hpp"
#include "benchmarkFactory.hpp"

Argument::Argument(int argc, char **argv) {
    argc_m = argc;
    argv_m = argv;
    populationSize_m = 30;
    iterations_m = 500;
    benchmark_m = nullptr;
    debug_m = false;
}

Argument::~Argument() {
    delete benchmark_m;
}

void Argument::ShowUsage() {
    std::cout << "./gwo -name [-population_size] [-iterations] [-debug]"<< std::endl
              << "where:" << std::endl
              << "    -name               [required]    Benchmark name: F1, F2, F3, F4, F5, F6, F7" << std::endl
              << "    -population_size    [optinal ]    integer >= 0, default(" << populationSize_m << ")" << std::endl
              << "    -iterations         [optinal ]    integer >= 0, defualt(" << iterations_m << ")" << std::endl
              << "    -debug              [optinal ]    show debugging info, defualt(" << (debug_m ? "true" : "false") << ")" << std::endl;
    exit(EXIT_SUCCESS);
}

void Argument::Parse() {
    if(argc_m < 2) {
        ShowUsage();
    }

    for(register int index=1; index<argc_m; index++) {
        if(strcasecmp(argv_m[index],"-name") == 0) {
            index += 1;
            char *name=argv_m[index];
            if(name == NULL) {
                throw GWOException(MISSING_BENCHMARK);
            } 
            benchmark_m = BenchmarkFactory::Get()->CreateBenchmark(name);
            if(benchmark_m == nullptr) {
                throw GWOException(UNKNOWN_BENCHMARK);
            }
        } else if(strcasecmp(argv_m[index],"-population_size")==0) {
            index += 1;
            char *size=argv_m[index];
            if(size == NULL) {
                throw GWOException(MISSING_POPULATION);
            }
            populationSize_m = atoi(size);
            if(populationSize_m < 0 ) {
                throw GWOException(INVALID_POPULATION);
            }
        } else if(strcasecmp(argv_m[index],"-iterations")==0) {
            index += 1;
            char *itr=argv_m[index];
            if(itr == NULL) {
                throw GWOException(MISSING_ITERATIONS);
            }
            iterations_m = atoi(itr);
            if(iterations_m < 0 ) {
                throw GWOException(INVALID_ITERATIONS);
            }
        } else if(strcasecmp(argv_m[index],"-debug")==0) {
            debug_m = true;
        } else {
            throw GWOException(UNKNOWN_ARGUMENT);
        }
    }
}

unsigned int Argument::GetPopulationSize() {
    return populationSize_m;
}

unsigned int Argument::GetIterations() {
    return iterations_m;
}

Benchmark *Argument::GetBenchmark() {
    return benchmark_m;
}

bool Argument::IsDebug() {
    return debug_m;
}
