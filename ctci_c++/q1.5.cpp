#include <iostream>
#include <cstring>

using namespace std;

char* rep(char *s);

int main() 
{
    const int len = 100;
    char s[] = "I am tony.";
    cout << rep(s) <<endl;
    //cout << c << endl;
    //rep(c);
    //cout << c << endl;
    return 0;
}

char* rep(char *s) {
	if(s == NULL) return NULL;
    int len = strlen(s);
    if(len == 0) return NULL;
    
	int count = 0;
	for(int i = 0; i < len; i++)
		if (s[i] == ' ')
			count++;

	int len2 = len + 2*count + 1;
	char *c = new char[len2];
	int index = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == ' ') {
			c[index] = '%';
			c[index + 1] = '2';
			c[index + 2] = '0';
			index += 3;
		} else {
			c[index] = s[i];
			index++;
		}

	} 
	c[index] = '\0';
	return c;
}

