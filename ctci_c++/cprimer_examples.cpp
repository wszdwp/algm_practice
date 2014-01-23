#include <iostream>
#include <algorithm>
using namespace std;

enum open_modes{ input = 1, output = 4, append };
void printenum(open_modes om){
	cout << om << endl;
}

int main()
{
	//enum
	open_modes om = input;
	printenum(om);

	//sort
	int ia[6] = { 107, 28, 3, 47, 104, 76 };
	string sa[3] = { "piglet", "eeyore", "pooh" };
	sort( ia, ia+6 );
	sort( sa, sa+3 );

	//two version of new (dynamic memory allocation) 
	int *pint = new int( 1024 );
	//int **test = &pint;
	cout << *pint << endl;
	//cout << test << endl;
	int *pia = new int[ 4 ];
	cout << *pia << endl;
}