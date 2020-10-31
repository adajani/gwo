//  utils.cc
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

#include <algorithm>
#include <iostream>
#include <cstring>
#include "utils.hpp"

// random number between 0 and 1
double Utils::GenerateRandomNumber() {
    static bool init=false;
    if(!init) {
        init = true;
        srand(time(NULL));
    }
    return (double)rand() / RAND_MAX;
}

// create 1D long double array with value zero
double* Utils::Create1DZeroArray(unsigned int columnCount) {
    double *array = new double[columnCount];
    std::fill_n(array, columnCount, 0.0);
    return array;
}

// create 2d long double array, its value is between (0,1) * (ub-lb)+lb
double** Utils::Create2DRandomArray(unsigned int rowCount, unsigned int columnCount, Boundaries boundaries[]) {
    double **array = new double *[rowCount];
    for(register unsigned int y=0; y<rowCount; y++) {
        array[y] = new double[columnCount];

        // randomize data and apply between (lower,upper) bound
        for(register unsigned int x=0; x<columnCount; x++) {
            array[y][x] = boundaries[x].lowerBound + (boundaries[x].upperBound - boundaries[x].lowerBound) * GenerateRandomNumber();
        }
    }
    return array;
}

/*
    Return back the search agents that go beyond the boundaries of the search space
    Given an interval, values outside the interval are clipped to the interval edges.
    For example, if an interval of [0, 1] is specified, values smaller than 0 become 0,
    and values larger than 1 become 1. ... If None, clipping is not performed on lower interval edge.
*/
void Utils::Clip1DArray(double array[], unsigned int columnCount, Boundaries boundaries[]) {
    for(register unsigned int column=0; column<columnCount; column++) {
        double value = array[column];
        if(value < boundaries[column].lowerBound) {
            array[column] = boundaries[column].lowerBound;
        }
        if(value > boundaries[column].upperBound) {
            array[column] = boundaries[column].upperBound;
        }
    }
}
