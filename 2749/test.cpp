#include <stdio.h>
using namespace std;

int main(){

	long long pibo[3] = {5,8,0};
	for(long long i=7;i<100000000;i++){
		pibo[2] = (pibo[1] + pibo[0])%1000000;
		pibo[0] = pibo[1];
		pibo[1] = pibo[2];
		if (pibo[0]==1 && pibo[1]==1) {
			printf("here! %lli\n",i);
			break;
		}
	}
	return 0;
}
