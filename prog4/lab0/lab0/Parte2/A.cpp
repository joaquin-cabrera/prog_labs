#include "A.h"
#include <stdio.h>

A::A(int a,B *elementoB,C *elementoC){
    this->a = a;
    this->elementoB = elementoB;
    this->elementoC = elementoC;
}

int A::getInt(){
	return a;
}

void A::printInt(){
	cout << a;
}