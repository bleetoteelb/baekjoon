#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    int N,M; // 1<=N,M<=300
    int K; // 1<=K<=10000
    int i,j,x,y; // i<=x, j<=y

    cin >> N >> M;
    int arr[301][301] = {0,};
    int memo[301][301] = {0,};
    for(int a=1;a<N+1;a++){
        for(int b=1;b<M+1;b++){
            cin >> arr[a][b];
            memo[a][b] = memo[a][b-1]+arr[a][b];
        }
    }

    cin >> K;
    for(int a=0;a<K;a++){
        cin >> i >> j >> x >> y;
        int sum = 0;
        for(int b=i;b<x+1;b++){
            sum += memo[b][y]-memo[b][j-1];
        }
        cout << sum << '\n';
    }
}

