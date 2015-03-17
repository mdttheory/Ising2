/*
 * File:   CSimulation.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:33 AM
 */

#include "CSimulation.h"
#include "CObject.h"
#include "SimulationParametersStruct.cpp"

CSimulation::CSimulation(SimulationParameters *SimPar) {

	m_simPar = SimPar;
	CLattice lattice(SimPar->WIDTH,SimPar->HEIGHT);
	CObject* lattice2 = &lattice;
	m_objects.push_back(lattice2);

}


CSimulation::~CSimulation() {
}

void CSimulation::run(ostream& debug_stream, SimulationParameters *SimPar){


	//mystery line to allow virtual functions to work as they should (this variable is never used)
	CLattice uselessvariable(SimPar->WIDTH,SimPar->HEIGHT);

	for(short t = 0; t<SimPar->MAXTIMESTEPS;t++)
	{

		cout << "ran time" << t << endl;
		for (vector<CObject*>::iterator it = m_objects.begin(); it != m_objects.end(); it++){
			(*it)->update(m_simPar->TIMESTEP);
			cout << "ran time2" << t << endl;
		}
		for (vector<CObject*>::iterator it2 = m_objects.begin(); it2 != m_objects.end(); it2++){
			(*it2)->print_all(debug_stream);
		}
	}
		return;
    }
