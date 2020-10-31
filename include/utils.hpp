//  utils.hpp
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

#ifndef __UTILS_H
    #define __UTILS_H
    #include "benchmark.hpp"

    class Utils {
        public:
            static double GenerateRandomNumber();
            static double *Create1DZeroArray(unsigned int columnCount);
            static double **Create2DRandomArray(unsigned int rowCount, unsigned int columnCount, Boundaries boundaries[]);
            static void Clip1DArray(double array[], unsigned int columnCount, Boundaries boundaries[]);
    };
#endif
