#include "A.h"
#include "B.h"
#include "C.h"

int main(){
	A* A1;
	B* B1;
	C* C1;
	A1 = new A(1,B1,C1);
	B1 = new B(1,C1,A1);
	C1 = new C(1,B1,A1);
	A1->printInt();
	B1->printInt();
	C1->printInt();
}