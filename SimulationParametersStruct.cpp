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
	const unsigned short WIDTH = 100;
	const unsigned short HEIGHT = 100;
	unsigned short MAXTIME = 3000;
	float TIMESTEP = 1;
	unsigned short MAXTIMESTEPS = short(MAXTIME/TIMESTEP);
	float COUPLING_CONSTANT = 1;
	float temperature = 2;
	float BOLTZMAN_CONSTANT = 1;
	unsigned short PRINT_FREQ = 50000;
	float MIN_TEMP = 1;
	float MAX_TEMP = 4;
	float TEMP_STEP = .05;
	bool CRIT_MODE = true;
	unsigned short CRIT_REPEATS = 10;
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

