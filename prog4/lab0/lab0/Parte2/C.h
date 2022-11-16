#ifndef C_H
#define C_H

#include <iostream>
#include <stdio.h>
#include "B.h"
#include "A.h"

using namespace std;

class C{
    private: 
        B *elementoB;
		A *elementoA;
		int c;
    public:
		C(int c,B *elementoB,A *elementoA);
		int getInt();
		void printInt();
};

#endif