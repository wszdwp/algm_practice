/**
*	BFS Graph
*	graph
*		nodes: 0 , 1, 2, 3, 4, 5, 6, 7, 8, 9
*		0 ---2---6---7---9					0  1  2  3  4  5  6  7  8  9
*		 \			/					0	      1  1   
*		  \		   /					1            1           1  1 
*			3-----1-----8				2   1                 1
*			 \							3   1  1           1
*			  \							4                  1
*			   5-----4					5			 1  1 
*										6         1
*										7      1                       1
*										8      1
*										9                        1
*
*/


#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 10;
bool g[maxn][maxn], visited[maxn];

void init(){
	memset(g, false, sizeof(g));
	memset(visited, false, sizeof(visited));
	//
	g[0][2] = g[0][3] = true;
	g[1][3] = g[1][7] =g[1][8] = true;
	g[2][0] = g[2][6] = true;
	g[3][0] = g[3][1] =g[3][5] = true;
	g[4][5] = true;
	g[5][3] = g[5][4] = true;
	g[6][2] = true;
	g[7][1] = g[7][9] = true;
	g[8][1] = true;
	g[9][7] = true;
}

void print(bool g[][maxn]){
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void BFS(bool g[][maxn], int src){
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		cout << t << " ";
		for(int i = 0; i < maxn; i++){
			if(g[t][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
}

int main(){
	init();
	//test the initilization
	print(g);
	BFS(g, 0);
	init();
	BFS(g, 1);
	init();
	BFS(g, 9);
	init();
	BFS(g, 5);

}