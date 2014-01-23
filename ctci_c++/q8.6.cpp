#include <iostream>
using namespace std;

enum color{
	red, yellow, blue, green
};
//recurrsion way
bool paint_fill(color **screen, int m, int n, int x, int y, color c){
	if(x<0 || x>=m || y<0 || y>=n)	return false;
	if(screen[x][y] == c) return false;
	else{
		screen[x][y] = c;
		paint_fill(screen, m, n, x-1, y, c);
		paint_fill(screen, m, n, x+1, y, c);
		paint_fill(screen, m, n, x, y-1, c);
		paint_fill(screen, m, n, x, y+1, c);
	}
	return true;
}

//iterative way



int main(){

}