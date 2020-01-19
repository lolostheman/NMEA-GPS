#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum states {None, found_start, found_type, found_data, found_checksum};

class GPSfinder {

	private:
		enum states state;
		string type, data,, checksum, final_type, final_data, final_checksum;
		char check = 0;
		
	public:
		GPSfinder();
		~GPSfinder();

		void FindByte(char byte);
		void CheckandPrint();
		void checksumcheck(char x);
};
