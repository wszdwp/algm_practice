#include <iostream>
#include <cstring>

using namespace std;

long long fibon(int n){
	if(n < 0) return -1;
	if( n < 2)
		return n;
	else
		return fibon(n - 1) + fibon(n - 2);
}

long long fibon2(int n){
	if(n < 0) return -1;
	const int N = n + 1;
	long long fib[N];
	memset(fib, 0, sizeof(fib));
	if(n < 0) return -1;
	if( n == 0 || n == 1)
		return n;

	fib[0] = 0; 
	fib[1] = 1;
	for(int i = 2; i <= n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	return fib[n];
}

int main(){
	int n = 30;

	cout << "fibon1 = " << fibon(n) << endl;
	cout << "fibon2 = " << fibon2(n) << endl;
}