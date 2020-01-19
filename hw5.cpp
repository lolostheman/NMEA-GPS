#include "hw5.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

finder::finder(){
	//to_find = c;
	State = None;
}
/////////////////////////////////////////////////////////////
finder::~finder(){}

int i=0; //the interation of the type value

/////////////////////////////////////////////////////////////
string finder::checkSum(const std::string& a){
	string temp = a;
	int result;
	char x = a[0];
	result = (int)x;
	

	for(int i = 0; i<temp.size();i++){
		char y = a[i+1];
		result ^= (int)y;
	}
	char hex[50];
	
	sprintf(hex, "%X", result);
	string print;
	cout<<"logan";
	print[0] = hex[0];
	print[1] = hex[1];
	return print;
}
///////////////////////////////////////////////////////////////////
void finder::find(char c){
	//cout<<"test";
	this->to_find = c;
	if(State == None && to_find == sign){
		State = Found_Sign;
		
	}
	else if(State == Found_Sign){
			if((to_find == types1[i] || to_find == types2[i] || 
				to_find == types3[i] || to_find == types4[i])&&(to_find != ',')){
					type += to_find;
					i++;
			}
			else if(type == types1 || type == types2 || type == types3 || type == types4){
				State = Found_Type;
				i=0;
				//result += type;
				//type = "";
				//cout<<"Message type:"<<result<<endl;
				data += type;
				data += to_find;
				
			}
	}else if(State == Found_Type){
			if(to_find != star){
				data += to_find;
			}
			else if(to_find == star){
				State = Found_Star;
				//result += data;
				//data = "";
				//cout<<"Message data:"<<data<<endl;
				//int test = checkSum(result);      //checksum
				//cout<< std::hex << test;
				//result = "";				
			}
	}else if(State == Found_Star){
			if(to_find != sign){
			checksum += to_find;
				if(checksum.length()==2){
					//result +=checksum;
					//char hexadecimal[20];
					//sprintf(hexadecimal, "%X", checkSum(data));
					//cout<<"XXXXX"<<hexadecimal;
					//checksum = "";
					State = None;
					done = true;
					//cout<<"Message checksum:"<<result<<endl<<endl;
					
				}
			}
			/*else if(to_find == sign){
				result +=checksum;
				checksum = "";
				State = Found_Sign;
				cout<<"Message checksum:"<<result<<endl<<endl;
				this->result = "";
				
			}*/
		}
		//cout<<checksum<<" and "<<checkSum(data)<<endl;
		if(done == true){
		cout<< "Message type:"<< type<<endl;
			cout<< "Message Data:" << data<<endl;
		cout<< "Message checksum:"<<checksum<<endl;
			checksum = "";
			type = "";
			data = "";
			done = false;
		}
	}
				
			
		
		
