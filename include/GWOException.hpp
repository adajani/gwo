//  GWOException.hpp
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

#ifndef __GWO_EXCEPTION_H
    #define __GWO_EXCEPTION_H
    #include <iostream>

    enum GWOExceptionId {
        //Parse arguments
        MISSING_BENCHMARK,
        UNKNOWN_BENCHMARK,
        MISSING_POPULATION,
        INVALID_POPULATION,
        MISSING_ITERATIONS,
        INVALID_ITERATIONS,
        UNKNOWN_ARGUMENT,

    };

    struct GWOExceptionDict {
        unsigned int exceptionId;
        const char *exceptionName;
    };

    class GWOException : public std::exception {
        public:
            GWOException(GWOExceptionId exceptionId);
            const char* what() const throw();
        private:
            GWOExceptionId exceptionId_m;
            static struct GWOExceptionDict exceptionDict_m[];
    };
#endif
