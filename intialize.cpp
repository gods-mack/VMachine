
#include<bits/stdc++.h>
#include "intialize.h"
using namespace std;


// basic register entry in RAM
// e.g SP and some GPR
// LCL, ARG
void register_entry(ofstream &fout) {

	fout<<"@256"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@SP"<<"\n";
	fout<<"M=D"<<"\n";
	fout<<"@300"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@LCL"<<"\n";
	fout<<"M=D"<<"\n";


}