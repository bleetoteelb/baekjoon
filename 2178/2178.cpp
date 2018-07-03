#include <iostream>
using namespace std;

int row,col,smallest=0;
int path[102][102];


int dfs(int (*path_check)[102],int depth,int cur_row,int cur_col);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int path_check[102][102] = {0,};

	for(int i=0;i<102;i++){
		for(int ii=0;ii<102;ii++){
			path[i][ii] = -1;
		}
	}

	cin >> row >> col;
	char temp;
	for(int r=1;r<row+1;r++){
		for(int c=1;c<col+1;c++){
			cin >> temp;
			path[r][c] = int(temp)-48;
			cout << path[r][c];
		}
		cout << "\n";
	}

	dfs(path_check,1,1,1);

	return 0;
}

int dfs(int (*path_check)[102],int depth,int cur_row,int cur_col){
	if(path[cur_row][cur_col]	
	for(int r=1;r<row+1;r++){
		for(int c=1;c<col+1;c++){
			cout << path_check[r][c];
		}
		cout << "\n";
	}
}
