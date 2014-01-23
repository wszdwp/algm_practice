/*
原文：
Write a method to compute all permutations of a string

译文：
写一个函数返回一个串的所有排列
*/

#include <iostream>

using namespace std;

typedef vector<string> vs;

vs permu(string s){
	vs result;
	if(s == "" ){
		result.push_back("");
		return result;
	}
	string c = s.substr(0, 1);
	vs res = permu(s.substr(1));
	for(int i = 0; i < res.size(); ++i){
		string t = res[i];
		for(int j = 0; j < t.length(); ++j){
			string u = t;
			u.insert(j, c);
			result.push_back(u);
		}
	}
	return result; //调用result的拷贝构造函数，返回它的一份copy，然后这个局部变量销毁(与基本类型一样)
}

