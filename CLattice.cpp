/*
 * File:   CLattice.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:51 AM
 */

#include "CLattice.h"

#include <iostream>
#include <string>

using namespace std;

CLattice::CLattice(const unsigned short h, const unsigned short w) : CObject() {
    m_height = h;
    m_width = w;
    // Fill lattice with initial values
    for(unsigned short i = 0; i<=m_height; i++){
        m_lattice.push_back(vector<bool>());
        for(unsigned short j = 0; j<=m_width; j++){
            m_lattice[i].push_back(false);
        }
    }
}

CLattice::~CLattice() {
}

void CLattice::update(float TIMESTEP){
	short y = rand()%m_height;
	short x = rand()%m_width;
	m_lattice[y][x]=!m_lattice[y][x];//flip random bit
	// TODO: Create list of nearest neighbors; unique to a specific lattice object
	// TODO: queue unique to a specific lattice object / resets each timestep? / tuple (x,y) or map single number (1,2,3,4...,N) to x, y?
	//       2N shorts is small; efficient?
	// TODO: Wolff Algorithm:
	/* Choose random site i (done above: x & y)
	 * (1) Study neighbor site j.
	 * 		If s_j = s_i, join site j to cluster with probability p = 1-exp(-2(Beta))
	 * 			Repeat step (1) on j. (until cluster stops growing)
	 * 			Invert cluster (actually do this periodically when it's added to the cluster to save comp time)
	 */
	return;
}

void CLattice::print_all(ostream& out_stream) {
	const string TRUE_CHAR = "1";
	const string FALSE_CHAR = "0";
	const bool labels = false;

	for(unsigned short i = 1; i< m_height+1; i++){
		string newstring = "";
		if(labels){
			string adjust = "";

			if (i< 10)adjust = " ";
			string newstring = adjust + to_string(i);
		}
			string header("  ");
		if (i==1)
		{
			for(unsigned short j = 1; j<m_width+1; j++){
						if(labels){
							if(j<10)header+=" ";
							header+= to_string(j);
							header += " ";
						}
					}
			if(labels){
			header += "\n";
			out_stream << header;
			}
		}
		if(labels){
			for(unsigned short j = 1; j<m_width+1; j++){
				if(m_lattice[i][j])newstring+= " "+TRUE_CHAR+" ";
				else newstring+= " "+FALSE_CHAR+" ";
			}
		}
		else{
			for(unsigned short j = 0; j<m_width; j++){
				if(m_lattice[i-1][j])newstring+= " "+TRUE_CHAR+" ";
				else newstring+= " "+FALSE_CHAR+" ";
			}
		}
		newstring += "\n";
		out_stream << newstring;
	}
	out_stream << "TIME!\n";
	return;
}

