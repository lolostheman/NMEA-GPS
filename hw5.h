#include <string>

using namespace std;

enum find_states(None, Found_Sign, Found_Type, Found_Star, Found_Checksum);
const string types1 = "GPGGA";
const string types2 = "GPGSA";
const string types3 = "GPGSV";
const string types4 = "GPRMC";

class finder
{
	private:
		enum find_states State;
		char to_find;
		//string type1,type2,type3,type4;
		string result;
		string type;
		string data;
		string checksum;
		
	public:
		finder(char);
		~finder();
		bool find();
	};
