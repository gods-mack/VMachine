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

	else if(cmd == "sub") {
		fout<<"@SP"<<endl;
		fout<<"A=M-1"<<endl;
		fout<<"D=M"<<endl;
		fout<<"A=A-1"<<endl;
		fout<<"D=M-D"<<endl;
		fout<<"M=D"<<endl;
		fout<<"@SP"<<endl;
		fout<<"M=M-1"<<endl;
	}
}

void writePushPop(string cmd,string arg1,string arg2,ofstream &fout) {


	// C_PUSH
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
		else if(arg1 == "pointer") {
		
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THIS"<<endl;
			fout<<"A=D+A"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M+1"<<endl;

		}
		else if(arg1 == "this") {
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THIS"<<endl;
			fout<<"A=D+M"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M+1"<<endl;
		}
		else if(arg1 == "that") {
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THAT"<<endl;
			fout<<"A=D+M"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M+1"<<endl;
		}
		else if(arg1 == "static") {
			fout<<"@static."<<arg2<<endl;
			fout<<"D=M"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M+1"<<endl;
		}
	}


	else{ // C_POP
		if(arg1 == "LCL"){

			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@LCL"<<endl;
			fout<<"D=D+M"<<endl;

			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;
		}
		else if(arg1 == "pointer") {
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THIS"<<endl;
			fout<<"D=D+A"<<endl;

			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;

		}
		else if(arg1 == "this") {
	
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THIS"<<endl;
			fout<<"D=D+M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;
		}
		else if(arg1 == "that") {
			fout<<"@"<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@THAT"<<endl;
			fout<<"D=D+M"<<endl;

			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;
		}
		else if(arg1 == "static") {

			fout<<"@static."<<arg2<<endl;
			fout<<"D=A"<<endl;
			fout<<"@R13"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"A=M-1"<<endl;
			fout<<"D=M"<<endl;
			fout<<"@R13"<<endl;
			fout<<"A=M"<<endl;
			fout<<"M=D"<<endl;
			fout<<"@SP"<<endl;
			fout<<"M=M-1"<<endl;


		}
	}
}

#endif