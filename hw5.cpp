#include "hw5.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <ctype.h>
GPSfinder::GPSfinder(){
	//to_find = c;
	this->state = None;
}

GPSfinder::~GPSfinder(){}

void GPSfinder::checksumcheck(char x){
	this->check = this->check ^ (x);

}

void GPSfinder::FindByte(char byte)
{
	if(this->state == None)
	{
		if(byte == '$')
		{
			this->state = found_start;
		}
	}
	else if (this->state == found_start)
	{
		GPSfinder::checksumcheck(byte);
		this->type += byte;

		if(this->type == "GPGGA" || this->type == "GPGSA" || this->type == "GPGSV" || this->type == "GPRMC")
		{
			this->final_type = this->type;
			this->type.clear();
			this->state = found_type;
		}
		else if(byte == ',')
		{
			this->state = None;
			this->type.clear();
			this->check = 0;
			this->final_type.clear();
		}
	}
	else if(this->state == found_type)
	{
		if(byte == '*')
		{
			this->final_data = this->data;
			this->data.clear();
			this->state = found_data;
		}
		else if(byte == '$')
		{
			this->data.clear();
			this->type.clear();
			this->check = 0;
			this->state = found_start;
		}
		else
		{
			this->data += byte;
			GPSfinder::checksumcheck(byte);
		}
	}
	else if(this->state == found_data)
	{
		if(this->num == 1)
		{
			this->checksum += byte;
			this->final_checksum = this->checksum;
			this->checksum.clear();
			this->state = None;
			this->num = 0;
			GPSfinder::CheckandPrint();
		}
		else 
		{
			this->checksum += byte;
			this->num++;
		}
	}
}


void GPSfinder::CheckandPrint()
{
	stringstream ss;
	ss << hex << int(this->check);
	string output = ss.str();
	transform(output.begin(), output.end(), output.begin(), ::toupper);

	if(this->final_checksum == output)
	{
		cout << "Message type: " << this->final_type << endl;
		cout << "Message data: " << this->final_type << this->final_data << endl;
		cout << "Message checksum: " << this->final_checksum << endl << endl;
		this->final_checksum.clear();
		this->final_type.clear();
		this->final_data.clear();
		this->check = 0;
		this->state = None;
	}
	else
	{
		this->final_checksum.clear();
		this->final_type.clear();
		this->final_data.clear();
		this->check = 0;
		this->checksum.clear();
		this->type.clear();
		this->data.clear();
		this->state = None;
	}
}
	
		
