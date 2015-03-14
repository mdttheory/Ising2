/*
 * File:   main.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 5, 2015, 6:03 PM
 */

#include <cstdlib>
#include "SimulationParametersStruct.cpp"
#include "CSimulation.h"
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>

using namespace std;



/*
 *
 */
int main(int argc, char** argv) {

	//output stream for debugging
	streambuf * buf;
	buf = cout.rdbuf();
	ostream debug_stream(buf);
	//TODO allow for outputting to file
	//TODO allow for command line parameters

	SimulationParameters* SimPar = new SimulationParameters();
	CSimulation Simulation(SimPar);
	Simulation.run(debug_stream);



	delete SimPar;
    return 0;
}
