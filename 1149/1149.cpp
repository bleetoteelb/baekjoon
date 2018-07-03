#include <iostream>
#include <algorithm>
using namespace std;
/*
Red / Green / Blue
3
26 40 83
49 60 57
13 89 99
*/

int prices[1001][3] = {0,};
int smallest[1001][3] = {0,};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int houses = 0;
	cin >> houses;
	
	for(int i=0;i<houses;i++){
		cin >> prices[i+1][0] >> prices[i+1][1] >> prices[i+1][2];
	}
	smallest[1][0] = prices[1][0];
	smallest[1][1] = prices[1][1];
	smallest[1][2] = prices[1][2];

	for(int i=2;i<houses+1;i++){
		smallest[i][0] = min(smallest[i-1][1],smallest[i-1][2])+prices[i][0];
		smallest[i][1] = min(smallest[i-1][0],smallest[i-1][2])+prices[i][1];
		smallest[i][2] = min(smallest[i-1][0],smallest[i-1][1])+prices[i][2];
	}
	
	cout << min(min(smallest[houses][0],smallest[houses][1]),smallest[houses][2]);
	
	return 0;
}
