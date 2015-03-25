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
#include <limits>

using namespace std;
/*
 *
 */
int main(int argc, char** argv) {
	 srand (time(NULL));
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

	if(SimPar->CRIT_MODE){
		float TempCritsAvg;
		for(unsigned short r =0;r<SimPar->CRIT_REPEATS;r++){
			cout << "Repeat: " << r << "/" << SimPar->CRIT_REPEATS << "\n";
			vector<float> mags;
			for(float T = SimPar->MIN_TEMP;T<SimPar->MAX_TEMP;T+=SimPar->TEMP_STEP){
				cout << "Temperature: " << T << endl;
				SimPar->temperature = T;

				CSimulation Simulation(SimPar);
				CLattice lattice(SimPar->HEIGHT,SimPar->WIDTH);
				CObject *lattice2 = &lattice;
				Simulation.addObject(lattice2);

				Simulation.run(pos_stream,mag_stream, SimPar);
				mags.push_back(Simulation.calcMag());

			}
			unsigned short min_sus_idx = 0;//index in terms of mag
			float min_sus = numeric_limits<float>::infinity();
			for(unsigned short i = 1; i<mags.size()-1;i++){
				float new_sus = (mags[i+1]-mags[i-1])/(2*SimPar->TEMP_STEP);
				if(new_sus < min_sus){
					min_sus = new_sus;
					min_sus_idx = i;
				}
			}
			TempCritsAvg+=(SimPar->MIN_TEMP+SimPar->TEMP_STEP*min_sus_idx);
			cout << (SimPar->MIN_TEMP+SimPar->TEMP_STEP*min_sus_idx) << "\n";
		}
		TempCritsAvg/=SimPar->CRIT_REPEATS;
		cout << "Final Average Critical Temp: " << TempCritsAvg << endl;
	}
	else{
		for(float T = SimPar->MIN_TEMP;T<SimPar->MAX_TEMP;T+=SimPar->TEMP_STEP)
		{
			SimPar->temperature = T;
			cout << "Temperature: " << T << endl;

			CSimulation Simulation(SimPar);
			CLattice lattice(SimPar->HEIGHT,SimPar->WIDTH);
			CObject *lattice2 = &lattice;
			Simulation.addObject(lattice2);

			Simulation.run(pos_stream,mag_stream, SimPar);
		}
	}



	delete SimPar;
    return 0;
}
