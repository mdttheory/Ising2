/*
 * File:   CLattice.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:51 AM
 */

#include "CLattice.h"

#include <iostream>
#include <string>
typedef std::vector<vector<bool> > NestedVector;

//#include "CObject.h"

using namespace std;

CLattice::CLattice(const unsigned short h, const unsigned short w) : CObject() {
    m_height = h;
    m_width = w;

    for(unsigned short i = 0; i<=m_height; i++){
        m_lattice.push_back(vector<bool>());
        for(unsigned short j = 0; j<=m_width; j++){
            m_lattice[i].push_back(false);
        }
    }

    //NestedVector m_lattice(m_height,vector<bool>(m_width, 0));

}

CLattice::~CLattice() {
}

void CLattice::print_all(ostream& out_stream) {
	const string TRUE_CHAR = " ";
	const string FALSE_CHAR = "X";

	for(unsigned short i = 1; i< m_height+1; i++){
		string adjust = "";

		if (i< 10)adjust = " ";
		string newstring = adjust + to_string(i);

		string header("  ");
		if (i==1)
		{
			for(unsigned short j = 1; j<m_width+1; j++){
						if(j<10)header+=" ";
						header+= to_string(j);
						header += " ";
					}
			header += "\n";
			out_stream << header;
		}

		for(unsigned short j = 1; j<m_width+1; j++){
			if(m_lattice[i][j])newstring+= " "+TRUE_CHAR+" ";
			else newstring+= " "+FALSE_CHAR+" ";
		}
		newstring += "\n";
		out_stream << newstring;
	}
	return;
}

