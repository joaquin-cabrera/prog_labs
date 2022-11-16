#ifndef B_H
#define B_H

#include <iostream>
#include <stdio.h>
#include "A.h"

using namespace std;

class C;

class B{
    private: 
        A *elementoA;
		C *elementoC;
		int b;
    public:
		B(int b,C *elementoC,A *elementoA);
		int getInt();
		void printInt();
};
#include "C.h"


#endif