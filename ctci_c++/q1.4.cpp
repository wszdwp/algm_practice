#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isAnagram(string , string);
bool isAnagram2(string , string);


int main()
{
	string s1, s2, s3, s4;
	s1 = "det";
	s2 = "ted";
	s3 = "deddt";
	s4= "tedss";
	
	cout << "Expected(true): " << ((isAnagram(s1, s2)==1) ? "true" : "false" )<< endl;
	cout << "Expected(true): " << ((isAnagram2(s1, s2)==1) ? "true" : "false" )<< endl;

	cout << "Expected(false): " << ((isAnagram(s3, s4)==1) ? "true" : "false" )<< endl;
	cout << "Expected(false): " << ((isAnagram2(s3, s4)==1) ? "true" : "false" )<< endl;

}

bool isAnagram(string s1, string s2) {
	if( s1.length() != s2.length())
		return false;
	if( s1 == "" | s2 == "")
		return false;

	sort(&s1[0], &s1[0] + s1.length());
	sort(&s2[0], &s2[0] + s2.length());

	if (s1 == s2)
		return true;
	else
		return false;
}

bool isAnagram2(string s1, string s2) {
	if( s1.length() != s2.length())
		return false;
	if( s1 == "" | s2 == "")
		return false;

	int len = s1.length(); 
	int check[256];
	memset(check, 0, sizeof(check));
	//cout << sizeof(check) <<endl;
	for(int i = 0; i < len; i++) {
		++check[s1[i]];
		cout << (int)s1[i] << ",";
		--check[s2[i]];
		//cout << s2[i];
		//cout << (int)s2[i] << ",";

	}	
	//cout << check[256] << endl;
	for(int i = 0; i < 256; ++i) {
		//cout << check[i];
		if(check[i] != 0)
			return false; 
	}

	return true;
}