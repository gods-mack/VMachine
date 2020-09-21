#ifndef _PARSER_H
#define _PARSER_H


int i_par = 0; // current command number

void cmd_parser(string line, vector<string> &cmds) {


	
	string tmp = "";
	for(int i = 0; i < (int)line.length()-1;i++) {
		if(line[i] != ' ' ){
			tmp += line[i];
		}
		else{
			cmds.push_back(tmp);
			tmp = "";
		}
	}
	cmds.push_back(tmp);

	i_par++; // inc. command var


	
}




#endif