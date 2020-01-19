#include "hw5.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

GPSfinder::GPSfinder(){
	//to_find = c;
	state = None;
}

finder::~finder(){}

void GPSfinder::checksumcheck(char x){
	check = check ^ (x);

}

void GPSfinder::FindByte(char byte)
{
	if(state == None)
	{
		if(byte == '$')
		{
			state =  found_start;
		}
	}
	else if (state == found_start)
	{
		GPSfinder::checksumcheck(byte);
		type += byte;

		if(type == "GPGGA" || type == "GPGSA" || type == "GPGSV" || type == "GPRMC")
		{
			final_type = type;
			type.clear();
			state = found_type;
		}
		else if(byte == ',')
		{
			state = None;
			type.clear();
			check = 0;
			final_type.clear();
		}
	}
	else if(state == found_type)
	{
		if(byte == '*')
		{
			final_data = data;
			data.clear();
			state = found_data;
		}
		else if(byte == '$')
		{
			data.clear();
			type.clear();
			check = 0;
	char byte
			state = found_start;
		}
		else
		{
			data += byte;
			GPSfinder::checksumcheck(byte);
		}
	}
	else if(state == found_data)
	{
		if(num == 1)
		{
			checksum += byte;
			final_checksum = checksum;
			checksum.clear();
			state = None;
			num = 0;
			CheckandPrint();
		}
		else 
		{
			checksum += byte;
			num++;
		}
	}
}


void GPSfinder::CheckandPrint()
{
	stringstream ss;
	ss << hex << int(check);
	string output = ss.str();
	transform(output.begin(), output.end(), output.begin(), toupper);

	if(final_checksum == output)
	{
		cout << "Message type: " << final_type << endl;
		cout << "Message data: " << final_type << final_data << endl;
		cout << "Message checksum: " << final_checksum << endl << endl;
		final_checksum.clear();
		final_type.clear();
		final_data.clear();
		check = 0;
		state = None;
	}
	else
	{
		final_checksum.clear();
		final_type.clear();
		final_data.clear();
		check = 0;
		checksum.clear();
		type.clear();
		data.clear();
		state = None;
	}
}
	
			
