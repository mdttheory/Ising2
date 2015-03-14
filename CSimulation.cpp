/*
 * File:   CSimulation.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:33 AM
 */

#include "CSimulation.h"
#include "CObject.h"
#include "CLattice.h"
#include "SimulationParametersStruct.cpp"

CSimulation::CSimulation(SimulationParameters *SimPar) {

	m_simPar = SimPar;

	vector<CObject> objects;
	CLattice lattice(SimPar->WIDTH,SimPar->HEIGHT);
	objects.push_back(lattice);




}


CSimulation::~CSimulation() {
}

void CSimulation::run(ostream& debug_stream){

			for (vector<CObject>::iterator it = objects.begin(); it != objects.end(); it++){
			   (*it).update(m_simPar->TIMESTEP);
			   (*it).print_all(debug_stream);
			}


		return;
    }
