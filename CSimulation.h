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
using namespace std;

class CSimulation {
public:
    CSimulation();
    virtual ~CSimulation();

    void SetTimestep(float timestep) {
        m_timestep = timestep;
    }

    float GetTimestep() const {
        return m_timestep;
    }

    void update();


private:
    float m_timestep;
    vector<CObject> objects;

};

#endif	/* CSIMULATION_H */
