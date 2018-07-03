#include <stdio.h>
using namespace std;

int main(){

	long long n = 0;
	scanf("%lli",&n);
	n = n%1500000;
	if(n == 1) {
		printf("1\n");
	}else if (n == 2){
		printf("1\n");
	}else{
		long long pibo[3] = {0,1,0};
		for(int i=2;i<n+1;i++){
			pibo[2] = (pibo[1] + pibo[0])%1000000;
			pibo[0] = pibo[1];
			pibo[1] = pibo[2];
		}
		printf("%lli\n",pibo[2]);
	}

	return 0;
}
