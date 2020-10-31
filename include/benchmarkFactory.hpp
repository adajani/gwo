//  benchmarkFactory.hpp
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

#ifndef __BENCHMARK_FACTORY_HPP
    #define __BENCHMARK_FACTORY_HPP
    #include <map>
    #include "benchmark.hpp"

    typedef Benchmark* (*BenchmarkCreateMethod)(void); 

    class BenchmarkFactory {
        private:
            BenchmarkFactory();
            BenchmarkFactory(const BenchmarkFactory &) = default;
            BenchmarkFactory &operator=(const BenchmarkFactory &);
            std::map<std::string, BenchmarkCreateMethod> factoryMap_m;
        public:
            ~BenchmarkFactory();
            static BenchmarkFactory *Get();
            void Register(const std::string &benchmarkName, BenchmarkCreateMethod benchmarkCreateMethod);
            Benchmark *CreateBenchmark(const std::string &benchmarkName);
    };
#endif
