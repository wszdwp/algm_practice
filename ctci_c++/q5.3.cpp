/**
原文：
Given an integer, print the next smallest and next largest number that have the same number of 1 bits in their binary representation.

译文：
给定一个整数x，找出另外两个整数，这两个整数的二进制表示中1的个数和x相同， 其中一个是比x大的数中最小的，另一个是比x小的数中最大的。

解答
对于这道题，我们先完成一个最朴素最直接的版本，以保证其正确性。 这个版本可以作为其它版本的验证工具。
什么方法是最直接的呢？给定一个数x，计算出它的二进制表示中1的个数为num， 然后x不断加1并计算其二进制表示中1的个数，当它再次等于num时， 就找到了比x大且二进制表示中1的个数相同的最小的数。类似地， 可以找到比x小且二进制表示中1的个数相同的最大的数，只不过x变为不断减1而已。
*/
#include <iostream>
#include <cstring>
using namespace std;

int ans[2] = {0, 0};

void findMinMax(int a){
	int count_one = 0;
	memset(ans, 0, sizeof(ans));
	while(a) {
		a >> 1;
		if( a & 1) ++count_one;
	}
	ans[0] = 1 << count_one;
	ans[1] = 1 >> count_one;
	
}
int count_one(int x){
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}

int next1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //011.., none satisify
    x |= 1;
    x <<= bit; // wtf, x<<32 != 0,so use next line to make x=0
    if(bit == 32) x = 0; // for 11100..00
    int num1 = count_one(xx) - count_one(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}
int previous1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //100..11, none satisify
    x -= 1;
    x <<= bit;
    if(bit == 32) x = 0;
    int num1 = count_one(xx) - count_one(x);
    x >>= bit;
    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
    x <<= bit;
    return x;
}

int main(){
    int a = -976756;//(1<<31)+(1<<29);//-8737776;
    
    findMinMax(a);
    cout << "Min = " << ans[0] << " Max = " << ans[1] << endl;
    cout<<"next=" << next1(a)<<" Min="<<previous1(a)<<endl; // very slow
    
    return 0;
}