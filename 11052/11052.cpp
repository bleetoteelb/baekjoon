#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int b_count = 0; // bread number <= 1000
	cin >> b_count; 
	int *price = new int[b_count+1]; // bread set price <= 10000
	int *memo = new int[b_count+1];
 	for(int i=0;i<b_count+1;i++){
		price[i] = 0;
		memo[i] = 0;
	}
	for(int i=1;i<b_count+1;i++){
		cin >> price[i];
	}

	for(int i=1;i<b_count+1;i++){
		for(int ii=1;ii<i+1;ii++){
			int temp = memo[i-ii]+price[ii];
			memo[i] = (memo[i] > temp) ? memo[i] : temp;
		}
	}
	cout << memo[b_count] << '\n';
}
