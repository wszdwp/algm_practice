#include <iostream>
#include <cstring>

using namespace std;

string removeDuplicate(string s);
void removeDuplicate2(char s[]);

int main() 
{
	char test1[] = "aaaaaaaaaabbbbbbbbbcccccccdddeeefffggg";
	string test2 = "abababcdbbc";
	//string result = removeDuplicate(test1);
	removeDuplicate2(test1);
	cout << "after remove duplicate: " << removeDuplicate(test2) << endl;
	cout << "after remove duplicate: " << test1 << endl;
}

void removeDuplicate1(char s[]){
	int len = strlen(s);

	if(len < 2)
		return;
	int index = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] != '\0') {
			s[index++] = s[i];	//put the first non '\0' char to a continuous char string;
			for(int j = i + 1; j < len; j++) {
				if(s[j] == s[i])
					s[j] = '\0';
			}
		}
	}
	s[index] = '\0';
}	

string removeDuplicate(string s) {
	int len = s.length();
	if(len < 2) return s;
	string str = "";
	for (int i = 0; i < len; i++) {
		if(s[i] != '\0') {
			str += s[i];
			for(int j = i + 1; j < len; j++){
				if(s[j] == s[i])
					s[j] = '\0';
			}
		}
	}

	return str;

}

void removeDuplicate2(char s[]) {
	int len = strlen(s);
	bool accii[256];
	memset(accii, 0, sizeof(accii));

	if (len < 2) return;
	int index = 0;
	for(int i = 0; i < len; i++) {
		if (!accii[(int)s[i]]) {
			s[index++] = s[i];
			accii[(int)s[i]] = true;
		}
	}
	s[index] = '\0';

}
