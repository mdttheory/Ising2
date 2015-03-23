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
	const unsigned short WIDTH = 30;
	const unsigned short HEIGHT = 30;
	unsigned short MAXTIME = 15;
	float TIMESTEP = 1;
	unsigned short MAXTIMESTEPS = short(MAXTIME/TIMESTEP);
	float COUPLING_CONSTANT = 1;
	float TEMPERATURE = 2;
	float BOLTZMAN_CONSTANT = 1;
	unsigned short PRINT_FREQ = 1;
	//TODO magnetization vs temp
	// T critical
	// Susceptibility (d<m>/dT)
	// Internal Energy
	// Heat capacity (dE/dT)
	// Critical exponents:
	// 		log(X) vs log(T)
	// 		log(mag) vs log(T)
};

#endif

