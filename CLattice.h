/*
 * File:   CLattice.h
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:51 AM
 */

#ifndef CLATTICE_H
#define	CLATTICE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "SimulationParametersStruct.cpp"

#include "CObject.h"

using namespace std;

class CLattice : public CObject{
public:
    CLattice(const unsigned short h, const unsigned short w);
    ~CLattice();
    void print_all(ostream& out_stream);
    void update(SimulationParameters* SimPar);
private:
    vector<vector<bool> > m_lattice;
    unsigned short m_height;
    unsigned short m_width;
    queue<vector<unsigned short>> m_queue;

};

#endif	/* CLATTICE_H */
