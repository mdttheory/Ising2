/*
 * SimulationParametersStruct.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: Mark Wittekind and Drew Murray
 */
#ifndef SIM_PARAMS_UNIQUE
#define SIM_PARAMS_UNIQUE

struct SimulationParameters
{
	const unsigned short WIDTH = 4;
	const unsigned short HEIGHT = 6;
	short MAXTIME = 100;
	float TIMESTEP = 1;
	short MAXTIMESTEPS = short(MAXTIME/TIMESTEP);
};

#endif

