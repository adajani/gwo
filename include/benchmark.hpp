//  benchmark.hpp
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

#ifndef __BENCHMARK_HPP
    #define __BENCHMARK_HPP
    #include <string>

    typedef struct {
        double lowerBound, upperBound;
    } Boundaries;

    class Benchmark {
        private:
            std::string name_m;
            unsigned int dimension_m;
            Boundaries *boundaries_m = nullptr;
        public:
            Benchmark(const std::string &name, const unsigned int &dimension, Boundaries *boundaries);
            Benchmark() = default;
            virtual ~Benchmark() = default;
            std::string GetName();
            unsigned int GetDimension();
            Boundaries *getBoundaries();
            void setName(const std::string &name);
            void setDimension(const unsigned int &dimension);
            void setBoundaries(Boundaries *boundaries);
            virtual double fitness(double x[]) = 0;
    };
#endif
