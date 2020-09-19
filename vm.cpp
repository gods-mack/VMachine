
#include<bits/stdc++.h>
#include "intialize.h"
using namespace std;


int main(int argc, char **argv) {


	string in_fname = argv[1];
	string out_fname = "";
	

	ifstream fin;  // input file stream
	ofstream fout; // output file stream
	fin.open(in_fname);

	int ptr = 0;
	// create output file name
	while(in_fname[ptr] != '.'){
		out_fname += in_fname[ptr++];
	}

	out_fname += ".asm";
	fout.open(out_fname);
	register_entry(fout);



	string line;
	while(fin) {

		getline(fin,line); // read line from input file
		cout<<line<<endl;

		// remove comment and blank line
		if(line[0] == '/' or (int)line[0] == 13){
			continue;
		}
		//fout<<line<<endl;
	}

	fin.close();
	fout.close();

}	