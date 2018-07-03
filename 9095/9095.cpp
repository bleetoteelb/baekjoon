#include <iostream>
using namespace std;
int memo[100] = {0,};
int pos = 0;
int recur(int num_count[]){
	int check_dup = num_count[0]*61+num_count[1]*41+num_count[2];
	for(int i=0;i<pos;i++) {if(memo[i]==check_dup) return 0;}
	memo[pos++] = check_dup;
	int count = 0;
	int each[] = {num_count[0],num_count[1],num_count[2]};
	int fact[] = {1,1,1,1};
	bool first = true;
	for(int i=1;i<num_count[0]+1;i++) fact[0] = i*fact[0];
	for(int i=1;i<num_count[1]+1;i++) fact[1] = i*fact[1];
	for(int i=1;i<num_count[2]+1;i++) fact[2] = i*fact[2];
	for(int i=1;i<num_count[0]+num_count[1]+num_count[2]+1;i++) fact[3] = i*fact[3];
	count += fact[3]/(fact[0]*fact[1]*fact[2]);

	if(num_count[2]-2>=0){
		each[1]+=1;
		each[2]-=2;
		count += recur(each);
		each[1]-=1;
		each[2]+=2;
	}
	if(num_count[2]-3>=0){
		each[0]+=1;
		each[2]-=3;
		count += recur(each);
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int cases;
	int number;
	cin >> cases;

	for(int i=0;i<cases;i++){
		cin >> number;
		for(int ii =0;ii<100;ii++) memo[ii] = 0;
		pos = 0;
		int each[] = {0,0,number};
		cout << recur(each) << '\n';
		
	}
}
