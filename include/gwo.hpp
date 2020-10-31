//  gwo.hpp
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

#ifndef __GWO_H
    #define __GWO_H
    #include "utils.hpp"
    #include "benchmark.hpp"

    class GWO {
        private:
            double executionTime_m = 0;
            Benchmark *benchmark_m;
            unsigned int searchAgentsCount_m;
            unsigned int maximumIterations_m;
            Boundaries *boundaries_m;
            unsigned int dimension_m;

            //initialize alpha, beta, and delta_pos
            double *alphaPosition_m;
            double alphaScore_m;
            double *betaPosition_m;
            double betaScore_m;
            double *deltaPosition_m;
            double deltaScore_m;

            //Initialize the positions of search agents
            double **positions_m;
            double *convergenceCurve_m;

            void calculateFitness();
            void updateWolves(double a);

        public:
            GWO(Benchmark *benchmark, unsigned int searchAgentsCount, 
                unsigned int maximumIterations);
            ~GWO();
            double *Evaluate(bool debug=false);
            double *GetAlphaPosition();
            double GetAlphaScore();
            double *GetBetaPosition();
            double GetBetaScore();
            double *GetDeltaPosition();
            double GetDeltaScore();
            double GetExecutionTime();
            friend std::ostream& operator << (std::ostream& os, const GWO *gwo);
    };
#endif
