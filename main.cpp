#include <iostream>
#include <fstream>
#include <string>
#include "hw5.h"
using namespace std;

int main(int argc, char *argv[]){
	char byte;
	ifstream infile;
	infile.open(argv[1]);
	finder fone;
	//int checkSum('GPGSA,A,3,17,06,28,02,24,,,,,,,,3.2,1.7,2.7');
	while(!infile.eof()){
		infile.get(byte);
		
		fone.finder::find(byte);
	}
	}
	
