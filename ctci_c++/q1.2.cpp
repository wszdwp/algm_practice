#include <iostream>

using namespace std;

void revstr(char *);
void swap(char *, char *);

int main()
{
	char test1[] = "abcdefg";
	revstr(test1);

	cout <<  test1<< endl;
}

void revstr(char *str) {
	char *hd = str;
	char *ed = str;

	while(*ed) {
		ed++;
	}
	ed--;

	while(hd < ed) {
		swap(*hd, *ed);
		hd++;
		ed--;
	}
}

void swap1(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char &a, char &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}