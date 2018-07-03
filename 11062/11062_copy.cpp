#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
#include <deque> 
using namespace std;
vector<int> a;  
int cache[1001][1001][2];  
int solve(int l,int r,int turn){
	if (l > r) return 0;  
	int &ret = cache[l][r][turn];  
	if (ret != -1) return ret;  
	ret = 0;  
	if (turn == 1){ // B's turn 
		ret = min(solve(l+1,r,0),solve(l,r-1,0));  
	}else{ // A's turn 
		ret = max(a[l]+solve(l+1,r,1),a[r]+solve(l,r-1,1));  
	}
	return ret;  
}  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);  
	int t; 
	cin >> t; 
	while (t--){
		a.clear();  
		memset(cache,-1,sizeof(cache));  
		int n;  
		cin >> n;  
		for (int i = 0; i < n; i++){
			int no; 
			cin >> no; 
			a.push_back(no); 
		}
		int ans = solve(0,n-1,0); // A starts first 
		cout << ans << endl;   
		for(int i=0;i<n;i++){
			for(int ii=0;ii<n;ii++){
				cout << cache[i][ii][0] << " ";
			}
			cout << "\n";
		}
		cout << "-----------------\n";
		for(int i=0;i<n;i++){
			for(int ii=0;ii<n;ii++){
				cout << cache[i][ii][1] << " ";
			}
			cout << "\n";
		}
	}
	

	return 0;  
}
