/*
 * File:   CSimulation.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:33 AM
 */

#include "CSimulation.h"
#include "CObject.h"

CSimulation::CSimulation() {
	m_timestep = 0;
}


CSimulation::~CSimulation() {
}

void CSimulation::update(){
        for (vector<CObject>::iterator it = objects.begin(); it != objects.end(); it++){
           (*it).update();
        }
    }
