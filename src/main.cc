//  main.cc
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

#include <cstdlib> //atexit
#include <iostream> //cerr, cout
#include "argument.hpp"
#include "gwo.hpp"
#include "GWOException.hpp"

Argument *argument = nullptr;
GWO *gwo = nullptr;

void freeMemory() {
    if(argument) {
        delete argument;
        argument = nullptr;
    }
    if(gwo) {
        delete gwo;
        gwo = nullptr;
    }
}

int main(int argc, char **argv) {
    try {
        atexit(freeMemory);
        argument = new Argument(argc, argv);
        argument->Parse();

        gwo = new GWO(argument->GetBenchmark(), argument->GetPopulationSize(), argument->GetIterations());
        (void)gwo->Evaluate(argument->IsDebug());
        
        std::cout << "Result:" << std::endl
                  << gwo << std::endl;

        freeMemory();
    }
    catch (GWOException &e) {
        std::cerr << "Grey wolf optimizer exception : " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
