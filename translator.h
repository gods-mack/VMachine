#ifndef _TRANSLATOR_H
#define _TRANSLATOR_H


void writeArithmetic(string cmd, ofstream &fout) {

	if(cmd == "add") {
		fout<<"@SP"<<endl;
		fout<<"A=M-1"<<endl;
		fout<<"D=M"<<endl;
		fout<<"A=A-1"<<endl;
		fout<<"D=D+M"<<endl;
		fout<<"M=D"<<endl;
		fout<<"@SP"<<endl;
		fout<<"M=M-1"<<endl;
	}
}

void writePushPop(string cmd,string arg1,string arg2,ofstream &fout) {


	if(cmd == "push") {

		if(arg1 == "constant") {
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M+1"<<endl;

		}
	}
	else{ // pop
		if(arg1 == "LCL"){
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@LCL"<<endl;
			fout<<"D=D+M"<<endl;
			fout<<"@13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;
		}
	}
}

#endif