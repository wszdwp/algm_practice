#include <iostream>
#include <cstring>
using namespace std;

bool dupcheck(string);

int main()
{
	string test1 = "abcsdefgaa";
	string test2 = "asdfghjkl;";
	bool result;
	result = dupcheck(test1);
	cout << "result of test1: " << result<< endl;
	result = dupcheck(test2);
	cout << "result of test2: " << result << endl;
}

bool dupcheck(string s) {
	bool asci[256];
	memset(asci, 0, 256);
	for(int i = 0; i < s.length(); i++) {
		int index = (int)s[i];
		if(asci[index])
			return false;
		else
			asci[index] = true;
	}
	return true;
}

bool dupcheck2(string s) {
	int chk[8];
	memset(chk, 0, sizeof(chk));
	for(int i = 0; i < s.length(); i++) {
		int pos = (int)s[i] / 32;
		int offset = (int)s[i] % 32 - 1;
		//cout << pos << ",";
		//cout << offset << endl;
		if (chk[pos] & (1 << offset))
			return false;
		else
			chk[pos] |= (1 << offset);
	}
	return true;
}