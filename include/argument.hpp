//  argument.hpp
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

#ifndef __ARGUMENT_H
    #define __ARGUMENT_H
    #include "benchmark.hpp"

    class Argument {
        private:
            int argc_m;
            char **argv_m;
            unsigned int populationSize_m;
            unsigned int iterations_m;
            Benchmark *benchmark_m;
            bool debug_m;
            void ShowUsage();
        public:
            Argument(int argc, char **argv);
            ~Argument();
            void Parse();
            unsigned int GetPopulationSize();
            unsigned int GetIterations();
            Benchmark *GetBenchmark();
            bool IsDebug();
    };
#endif
