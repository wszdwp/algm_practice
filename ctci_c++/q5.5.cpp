#include <iostream>
using namespace std;


int cvtAtoB(int a, int b){
	int count = 0;
	for(int i = a ^ b; i != 0; i = i >> 1){
		count += i & 1;
	}
	return count;		
}

int main(){
	int a = 31, b = 14;
	cout << cvtAtoB(a, b) << endl;
	//cout << ((-1) >> 4);
	cout << ~(1 << 31) ;
}