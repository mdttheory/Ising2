/*
 * File:   CObject.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:53 AM
 */

#include "CObject.h"

CObject::CObject() {
}


CObject::~CObject() {
}

void CObject::update(SimulationParameters* SimPar){
    cout << "Called CObject update (bad)\n";
	return;
}

void CObject::print_all(ostream& pos_stream, ostream& mag_stream){
    cout << "Called CObject print_all (bad)\n";
	return;
}

