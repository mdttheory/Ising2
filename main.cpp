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
#include <string.h>

using namespace std;
/*
 *
 */
int main(int argc, char** argv) {
	 srand (time(NULL));
	//output stream for debugging
	streambuf * buf;
	ofstream of;
	char tofile[100] = "data/raw_positions.txt";
	if (false){
		//set to cout
		buf = cout.rdbuf();
	}
	else{
		//set to filename
		of.open("data/raw_positions.txt");
		buf = of.rdbuf();
	}


	ostream debug_stream(buf);
	//TODO allow for outputting to file
	//TODO allow for command line parameters

	SimulationParameters* SimPar = new SimulationParameters();
	CSimulation Simulation(SimPar);
	Simulation.run(debug_stream, SimPar);



	delete SimPar;
    return 0;
}
