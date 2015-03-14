/*
 * File:   CObject.h
 * Author: Mark Wittekind and Drew Murray
 *
 * Created on March 6, 2015, 11:53 AM
 */

#ifndef COBJECT_H
#define	COBJECT_H
#include <fstream>
#include <streambuf>
#include <iostream>
using namespace std;

class CObject {
public:
    CObject();
    virtual ~CObject();
    virtual void update(float TIMESTEP);
    virtual void print_all(ostream& out_stream);
private:

};

#endif	/* COBJECT_H */