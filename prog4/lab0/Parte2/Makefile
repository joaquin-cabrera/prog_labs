
CC = g++ 
OPCIONES = 

principal.o:  C.o B.o A.o Principal.cpp
	$(CC) $(OPCIONES) C.o B.o A.o Principal.cpp -o principal.o 
	
A.o: A.h A.cpp
	$(CC) $(OPCIONES) -c A.cpp -o A.o 

B.o: B.h B.cpp A.o 
	$(CC) $(OPCIONES) -c B.cpp A.o  -o B.o 

C.o: C.h C.cpp A.o B.o
	$(CC) $(OPCIONES) -c C.cpp A.o B.o -o C.o 