#include "B.h"
#include <stdio.h>

B::B(int b,C *elementoC, A *elementoA){
    this->b = b;
    this->elementoA = elementoA;
    this->elementoC = elementoC;
}

int B::getInt(){
	return b;
}

void B::printInt(){
	cout << b;
}