
#include<bits/stdc++.h>
#include "intialize.h"
#include "parser.h"
#include "translator.h"
using namespace std;



// command type
enum c_type{
	C_ARITHMETIC =   0,
	C_PUSH       =   1,
	C_POP        =   2,
	C_LABLE      =   3,
	C_GOTO       =   4,
	c_IF         =   5,
	C_FUNCTION   =   6,
	C_RETURN     =   7,
	C_CALL       =   8,
};



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
	register_entry(fout); // intialize basic register entry in RAM


	string line;
	while(fin) {

		getline(fin,line); // read line from input file
		
		// remove comment and blank line
		if(line[0] == '/' or (int)line[0] == 13){
			continue;
		}
		else{
			vector<string> cmds;
			cmd_parser(line,cmds);

			
			if(cmds[0] == "push" or cmds[0] == "pop") {
				string arg1 = cmds[1]; 
				string arg2 = cmds[2];

				writePushPop(cmds[0],arg1,arg2,fout);
			}
			else if(cmds[0] == "add" 
					or cmds[0]=="sub" 
					or cmds[0]=="eq" 
					or cmds[0]=="or"
					or cmds[0]=="not"
					or cmds[0]=="gt"
					or cmds[0]=="lt"
					or cmds[0]=="and"
					or cmds[0]=="neg"
				) {
				writeArithmetic(cmds[0],fout);
			}
		}
		
	}

	fin.close();
	fout.close();

}	