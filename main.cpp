#include <iostream>
#include <fstream>
#include <string>
#include "hw5.h"
using namespace std;

int main(int argc, char *argv[]){
	GPSfinder GPS;
	char byte;
	ifstream infile;
	infile.open(argv[1]);
	while(!infile.eof())
	{
		infile.get(byte);
		GPS.FindByte(byte);
	}
	infile.close();
}
///////////////////////////////////////////////////////////////////

