#include <iostream>

using namespace std;

void setzero(int a[][4], int n) {
	int row[] = {0, 0, 0, 0}; 
	int col[] = {0, 0, 0, 0};

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] == 0 ) {
				row[i] = 1;
				col[j] = 1;
			}

	for(int i = 0; i < n; i++) {
		if (row[i] == 1) {
			for(int j = 0; j < n; j++)
				a[i][j] = 0;
		}

		if (col[i] == 1) {
			for(int j = 0; j < n; j++)
				a[j][i] = 0;
		}

	}
}

int main()
{
	int a[4][4] = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 0, 12},
        {13, 14, 15, 16}
    };

    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    setzero(a, 4);
	for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}