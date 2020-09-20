#ifndef _PARSER_H
#define _PARSER_H


//vector<string> cmds;  // 3 commands


void cmd_parser(string line, vector<string> &cmds) {
//	cout<<"line "<<line<<" "<<line.length()<<endl;

	
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

	cout<<"#commands\n";


	
}



#endif