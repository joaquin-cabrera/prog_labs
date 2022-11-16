#ifndef A_H
#define A_H

#include <iostream>
#include <stdio.h>

using namespace std;

class B;
class C;

class A{
    private: 
        B *elementoB;
		C *elementoC;
		int a;
    public:
		A(int a,B *elementoB,C *elementoC);
		int getInt();
		void printInt();
};

#include "B.h"
#include "C.h"


#endif