/*原文：

Write a method that returns all subsets of a set.

译文：

写一个函数返回一个集合中的所有子集。
*/

#include <iostream>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
vvi get_subsets(int a[], int n){
	vvi subsets;
	int max = 1 << n;
	for(int i = 0; i < max; ++i){
		vi subset;
		int idx = 0;
		int j = i;
		while(j > 0){
			if(j & 1) {
				subset.push_back(a[idx]);
			}
			j >> 1;
			++idx;
		}
		subsets.push_back(subset);
	}
	return subsets;
}

//method2 recurrsion

vvi get_subsets2(int a[], int idx, int n){
	vvi subsets;
	if(idx == n){
		vi subset;
		subsets.push_back(subset);
	}
	else{
		vvi rsubsets = get_subsets2(a, idx + 1, n);
		int v = a[idx];
		for(int i = 0; i < rsubsets.size(); ++i){
			vi subset = rsubsets[i];
			subsets.push_back(subset);
			subset.push_back(v);
			subsets.push_back(subset);
		}
	}
	return subsets;
}

int main()
{
	
}