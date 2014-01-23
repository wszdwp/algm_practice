/*
Imagine a robot sitting on the upper left hand corner of an NxN grid. 
The robot can only move in two directions: right and down. 
How many possible paths are there for the robot?
FOLLOW UP
Imagine certain squares are “off limits”, such that the robot can not step on them. 
Design an algorithm to get all possible paths for the robot.

译文：
在一个N*N矩阵的左上角坐着一个机器人，它只能向右运动或向下运动。
那么， 机器人运动到右下角一共有多少种可能的路径？
进一步地，
如果对于其中的一些格子，机器人是不能踏上去的。设计一种算法来获得所有可能的路径。*/

#include <iostream>

using namespace std;

typedef long long ll;
typedef struct point{
    int x, y;
}point;
stack<point> sp;
const int MAXN = 20;
int g[MAXN][MAXN];
point vp[MAXN+MAXN];

ll path(ll m, ll n){
	if(m == 1 || n == 1)	return 1;
	else return path(m-1, n) + path(m, n-1);
}

//consider the unaccessable blocks
//g[i][j] == 1 indicates the accessable cells
bool get_path(int m, int n){
	point p;
	p.x = m; 
	p.y = n;
	if( n == 1 && m == 1)	return true;
	bool suc = false;
	if(m > 1 && g[m-1][n])
		suc = get_path(m-1, n);
	if(!suc && n > 1 && g[m][n-1])
		suc = get_path(m, n-1);
	if(!suc)	sp.pop();
	return suc;
}

void print_paths(int m , int n, int M, int N, int len){
	if(g[m][n] == 0) return;
	point p; p.x = n; p.y = m;
	vp[len++] = p;
	if(m == M && n == N){
		for(int i = 0; i < len; ++i){
			cout << "(" << vp[i].y << ", " << vp[i].x << ")" << " ";
		}
		cout << endl;
	} else {
		print_paths(m, n+1, M, N, len);
		print_paths(m+1, n, M, N, len);
	}
}

int main()
{
	
}