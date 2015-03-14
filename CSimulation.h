/*
 * File:   CSimulation.h
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:33 AM
 */

#ifndef CSIMULATION_H
#define	CSIMULATION_H
#include <vector>
#include "CObject.h"
#include "SimulationParametersStruct.cpp"
using namespace std;


class CSimulation {
public:
    CSimulation(SimulationParameters *SimPar);
    virtual ~CSimulation();

    void run(ostream& debug_stream);


private:
    SimulationParameters* m_simPar;
    vector<CObject> objects;

};

#endif	/* CSIMULATION_H */
