/*
 * File:   CLattice.cpp
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:51 AM
 */

#include "CLattice.h"

#include <iostream>
#include <string>
#include <math.h>

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

void CLattice::update(SimulationParameters* SimPar){

	unsigned short y = rand()%m_height;
	unsigned short x = rand()%m_width;
	bool old_spin = m_lattice[y][x];
	if(m_lattice[y][x]==old_spin &&
						float(rand())/float(RAND_MAX)>
						(1-exp(-2.0*SimPar->COUPLING_CONSTANT/
						(SimPar->BOLTZMAN_CONSTANT*SimPar->TEMPERATURE)))){
		m_lattice[y][x] = !old_spin;
		vector<unsigned short> temp = {y,x};
		m_queue.push(temp);
		while (!m_queue.empty())
		{
			y = m_queue.front()[0];
			x = m_queue.front()[1];
			m_queue.pop();
			unsigned short newy, newx;
			for(short i = 0; i<4;i++)
			{
				switch(i){
				case 0:
					newy = y;
					if(x==0)newx=m_width-1;
					else newx = x-1;
					break;
				case 1:
					newy = y;
					newx = (x+1)%m_width;
					break;
				case 2:
					if(y==0)newy=m_height-1;
					else newy = y-1;
					newx = x;
					break;
				case 3:
					newy = (y+1)%m_height;
					newx = x;
					break;
				}
				if(m_lattice[newy][newx]==old_spin &&
						float(rand())/float(RAND_MAX)>
						(1-exp(-2.0*SimPar->COUPLING_CONSTANT/
						(SimPar->BOLTZMAN_CONSTANT*SimPar->TEMPERATURE))))
				{
					m_lattice[newy][newx]=!old_spin;
					temp.clear();
					temp.push_back(newy);
					temp.push_back(newx);
					m_queue.push(temp);
				}
			}

		}

	}
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

