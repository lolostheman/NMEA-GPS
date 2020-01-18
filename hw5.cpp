#include "hw5.h"

using namespace std;

finder::finder(char c){
	to_find = c;
	State = None;
}
finder::~finder(){}
int i=0; //the interation of the type value
bool finder:find(){
	
	if(State == None && to_find == "$"){
		State = Found_Sign;
		result += to_find;
	}
	else if(State == Found_Sign){
			if(to_find == types1[i] || to_find == types2[i] || 
				to_find == types3[i] || to_find == types4[i]){
					type += to_find;
					i++;
			}
			else if(type == types1 || type == types2 || type == types3 || type == types4){
				State = Found_Type;
				result += type;
			}
	}else if(State == Found_Type){
			if(to_find != "*"){
				data += to_find;
			}
			else if(to_find == "*"){
				State = Found_Star
				data += to_find;
				result += data;
			}
	}else if(State == Found_Star){
			if(to_find != "$"){
			checksum += to_find;
			}
			else if(to_find == "$"){
				result +=checksum;
				
			
		
		
