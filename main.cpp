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
	while(!infile.eof()){
		infile.get(byte);
		
		fone.finder::find(byte);
	}
	}
	
