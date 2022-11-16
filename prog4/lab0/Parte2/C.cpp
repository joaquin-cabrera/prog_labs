#include "C.h"
#include <stdio.h>

C::C(int c,B *elementoB,A *elementoA){
    this->c = c;
    this->elementoB = elementoB;
    this->elementoA = elementoA;
}

int C::getInt(){
	return c;
}

void C::printInt(){
	cout << c;
}