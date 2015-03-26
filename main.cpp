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

unsigned int calc_timesteps(SimulationParameters *SimPar)
{
	unsigned int t = 1;
	t *= SimPar->HEIGHT;
	t *= SimPar->WIDTH;
	t *= SimPar->temperature;
	t /= 2;
	return t;
}

int main(int argc, char** argv) {
	 srand (time(NULL));
	//output stream for position
	streambuf * pos_buf;
	ofstream pos_of;
	streambuf * mag_buf;
	ofstream mag_of;
	streambuf * en_buf;
	ofstream en_of;
	if (false){
		//set to cout
		pos_buf = cout.rdbuf();
		mag_buf = cout.rdbuf();
		en_buf = cout.rdbuf();
	}
	else{
		//set to filename
		pos_of.open("data/raw_positions.txt");
		pos_buf = pos_of.rdbuf();
		mag_of.open("data/mag.txt");
		mag_buf = mag_of.rdbuf();
		en_of.open("data/energy.txt");
		en_buf = en_of.rdbuf();
	}


	ostream pos_stream(pos_buf);
	ostream mag_stream(mag_buf);
	ostream en_stream(en_buf);
	//TODO allow for outputting to file
	//TODO allow for command line parameters


	SimulationParameters* SimPar = new SimulationParameters();

	if(SimPar->CRIT_MODE){
		float TempCritsAvg;
		for(unsigned short r =0;r<SimPar->CRIT_REPEATS;r++){
			cout << "\nRepeat: " << r << "/" << SimPar->CRIT_REPEATS << "\n";
			vector<float> mags;
			for(float T = SimPar->MIN_TEMP;T<SimPar->MAX_TEMP;T+=SimPar->TEMP_STEP){
				cout << "Temperature: " << T << endl;
				SimPar->temperature = T;

				SimPar->MAXTIMESTEPS=calc_timesteps(SimPar);
				cout << "MAXTIMESTEPS = " << SimPar->MAXTIMESTEPS << "\n";
				CSimulation Simulation(SimPar);
				CLattice lattice(SimPar->HEIGHT,SimPar->WIDTH, SimPar->COUPLING_CONSTANT);
				CObject *lattice2 = &lattice;
				Simulation.addObject(lattice2);

				Simulation.run(pos_stream,mag_stream, SimPar);
				mags.push_back(Simulation.calcMag());
				//cout << "Final Energy: " << Simulation.calcEnergy() << "\n";

			}

			//calculate crit temp
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
			cout << "\nTemperature: " << T << endl;
			en_stream << T << "\n";

			SimPar->MAXTIMESTEPS=calc_timesteps(SimPar);
			cout << "MAXTIMESTEPS = " << SimPar->MAXTIMESTEPS << "\n";
			CSimulation Simulation(SimPar);
			CLattice lattice(SimPar->HEIGHT,SimPar->WIDTH, SimPar->COUPLING_CONSTANT);
			CObject *lattice2 = &lattice;
			Simulation.addObject(lattice2);

			Simulation.run(pos_stream,mag_stream, SimPar);
			float energy = Simulation.calcEnergy();
			cout << "Final Energy: " << energy << "\n";
			en_stream << energy << "\n";
		}
	}



	delete SimPar;
    return 0;
}
