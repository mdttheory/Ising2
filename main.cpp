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
	 cout << "Hello2\n";
	//output stream for position
	streambuf * pos_buf;
	ofstream pos_of;
	streambuf * mag_buf;
	ofstream mag_of;
	if (false){
		//set to cout
		pos_buf = cout.rdbuf();
		mag_buf = cout.rdbuf();
	}
	else{
		//set to filename
		pos_of.open("data/raw_positions.txt");
		pos_buf = pos_of.rdbuf();
		mag_of.open("data/mag.txt");
		mag_buf = mag_of.rdbuf();
	}


	ostream pos_stream(pos_buf);
	ostream mag_stream(mag_buf);
	//TODO allow for outputting to file
	//TODO allow for command line parameters

	SimulationParameters* SimPar = new SimulationParameters();
	for(float T = SimPar->MIN_TEMP;T<SimPar->MAX_TEMP;T+=SimPar->TEMP_STEP)
	{
		SimPar->temperature = T;
		cout << "Temperature: " << T << endl;
		CSimulation Simulation(SimPar);
		Simulation.run(pos_stream,mag_stream, SimPar);
	}



	delete SimPar;
    return 0;
}
