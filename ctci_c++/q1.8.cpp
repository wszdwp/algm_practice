#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) {
	//unsigned int pos;
	//pos = s1.find(s2);

	//cout << pos << endl;
	//cout << string::npos << endl;
	//if (pos != string::npos)
	if(s1.find(s2))
		return true;
	else
		return false;
}

bool isRotation(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	if (s1.length() < 0 || s2.length() < 0)
		return false;
	return isSubstring(s1 + s1, s2);
}


int main() 
{
	string str1 = "erbottlewat";
	string str2 = "waterbottle";

	string s1 = "apple";
    string s2 = "pleap";
    
	
	cout << ((isRotation(str1, str2)) ? "true" : "false")<< endl; 
	cout << ((isRotation(s1, s2)) ? "true" : "false")<< endl; 
}