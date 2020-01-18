#include "hw5.h"
#include <iostream>

using namespace std;

finder::finder(){
	//to_find = c;
	State = None;
}
finder::~finder(){}
int i=0; //the interation of the type value
//bool tempsign = false;

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
				result += type;
				type = "";
				cout<<"Message type:"<<result<<endl;
				result += to_find;
				//result = "";
			}
	}else if(State == Found_Type){
			if(to_find != star){
				data += to_find;
			}
			else if(to_find == star){
				State = Found_Star;
				result += data;
				data = "";
				cout<<"Message data:"<<result<<endl;
				result = "";				
			}
	}else if(State == Found_Star){
			if(to_find != sign){
			checksum += to_find;
				if(checksum.length()==2){
					result +=checksum;
					checksum = "";
					State = None;
					cout<<"Message checksum:"<<result<<endl<<endl;
					this->result = "";
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
	}
				
			
		
		
