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

	CLattice lattice(SimPar->WIDTH,SimPar->HEIGHT);
	CObject* lattice2 = &lattice;
	m_objects.push_back(lattice2);




}


CSimulation::~CSimulation() {
}

void CSimulation::run(ostream& debug_stream){
			for (vector<CObject*>::iterator it = m_objects.begin(); it != m_objects.end(); it++){
			   (*it)->update(m_simPar->TIMESTEP);
			   (*it)->print_all(debug_stream);
			}


		return;
    }
