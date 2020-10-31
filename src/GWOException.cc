//  GWOException.cc
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

#include "GWOException.hpp"

struct GWOExceptionDict GWOException::exceptionDict_m[] = {
    {MISSING_BENCHMARK, "Benchmark name is missing"},
    {UNKNOWN_BENCHMARK, "Unknown benchmark name"},
    {MISSING_POPULATION, "Population size is missing"},
    {INVALID_POPULATION, "Invalid population size"},
    {MISSING_ITERATIONS, "Iterations count is missing"},
    {INVALID_ITERATIONS, "Invalid iterations count"},
    {UNKNOWN_ARGUMENT, "Unknown input argument"}
};

GWOException::GWOException (GWOExceptionId exceptionId) {
    exceptionId_m = exceptionId;
}

const char* GWOException::what() const throw() {
    return exceptionDict_m[exceptionId_m].exceptionName;
}
