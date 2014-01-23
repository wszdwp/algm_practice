/*
原文：
Given an infinite number of quarters 
(25 cents), dimes (10 cents), 
nickels (5 cents) and pennies (1 cent), 
write code to calculate the number of ways of representing n cents.
译文：
我们有25分，10分，5分和1分的硬币无限个。写一个函数计算组成n分的方式有几种？
*/
#include <iostream>
using namespace std;

int make_change(int n, int denom){
	int next_denom = 0;
	switch(denom){
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}
	int ways = 0;
	for(int i = 0; i*denom <= n; ++i){
		ways += make_change(n - i*denom, next_denom);
	}
	return ways;
}

//way2
int sum_n(int sum, int c, int n){
	int ways = 0;
	if(sum <= n){
		if(sum == n)	return 1;
		if(c >= 25)
			ways += sum_n(sum+25, 25, n);
		if(c >= 10)
			ways += sum_n(sum+10, 10, n);
		if(c >= 5)
			ways += sum_n(sum+5, 5, n);
		if(c >= 1)
			ways += sum_n(sum+1, 1, n);
	}
	return ways;
}

//way interative
int findchange(int n){
	int count = 0;
	for (int i = 0; i <= n / 25; i++){
		for (int j = 0; j <= n / 10; j++){
			for (int k = 0; k <= n / 5; k++){
				//for (int l = 0; l <= n; l++){
					int v = i * 25 + j * 10 + k * 5; //+ l;
								if (v<=n)	count++;
								else if( v > n) {
									break;
								}
				//}
			}
		}
	}	
	return count;				
}

int main(){
	int n = 10;
    //sumN(0, 25, n);
    //cout<<cnt<<endl;
    cout<<make_change(n, 25)<<endl;
    cout<<sum_n(0, 25, n)<<endl;
    cout<<findchange(n)<<endl;
    return 0;

}