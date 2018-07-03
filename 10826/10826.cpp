#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);


	int n = 0, f_len=2, s_len=2;
	int *first = new int[2];
	int *second = new int[2];
	cin >> n ;

	if(n == 0) {
		cout << "0\n";
	}else if(n == 1) {
		cout << "1\n";
	}else if (n == 2){
		cout << "1\n";
	}else{
		int pibo[3] = {0,1,0};
		for(int i=2;i<n+1;i++){
			pibo[2] = pibo[1] + pibo[0];
			pibo[0] = pibo[1];
			pibo[1] = pibo[2];
		}
		cout << pibo[2];
	}

	return 0;
}
