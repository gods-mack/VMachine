
output: vm.o intialize.o
	g++ vm.o intialize.o -o output

vm.o: vm.cpp 
	g++ -c vm.cpp

intialize.o: intialize.cpp intialize.h
	g++ -c intialize.cpp

clean:
	rm *.o output			