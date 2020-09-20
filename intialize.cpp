
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
	fout<<"M=D"<<"\n"; // point SP reg. to mem location 256 in RAM
	
	fout<<"@300"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@LCL"<<"\n";
	fout<<"M=D"<<"\n"; // point LCL reg. to mem location 300 in RAM
	
	fout<<"@400"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@ARG"<<"\n";
	fout<<"M=D"<<"\n";
	
	fout<<"@3000"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@THIS"<<"\n";
	fout<<"M=D"<<"\n";
	
	fout<<"@3010"<<"\n";
	fout<<"D=A"<<"\n";
	fout<<"@THAT"<<"\n";
	fout<<"M=D"<<"\n";

}