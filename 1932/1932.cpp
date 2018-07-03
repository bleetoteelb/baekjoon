#include <iostream>
#include <algorithm>
using namespace std;


int tri[500][500] = {0,};
int large[500][500] = {0,};

int get_max(int f,int t){
	if(f==t) return large[t][t];
	return max(large[t][f],get_max(f+1,t));
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int size = 0;
	cin >> size;
//	cout << "size " <<size << "\n";
	for(int i=0;i<size;i++){
		for(int ii=0;ii<i+1;ii++){
			cin >> tri[i][ii];
//			cout << tri[i][ii] << " ";
		}
//		cout << "\n";
	}

	large[0][0] = tri[0][0];

	for(int i=1;i<size;i++){
		for(int ii=0;ii<i+1;ii++){
			if(ii==0){
				large[i][ii] = tri[i][ii]+large[i-1][ii];
			}else if(ii==i){
				large[i][ii] = tri[i][ii]+large[i-1][ii-1];
			}else{
				large[i][ii] = max(large[i-1][ii-1],large[i-1][ii])+tri[i][ii];
			}
		}
	}
/*
	for(int i=1;i<size;i++){
		for(int ii=0;ii<i+1;ii++){
			cout << large[i][ii] << " ";
		}
		cout << "\n";
	}
*/	
	cout << get_max(0,size-1) << "\n";
}
