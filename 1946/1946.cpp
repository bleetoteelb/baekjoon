#include <iostream>
#include <utility>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T; //test cases <=20
	int N; //application number <=100000
	cin >> T;
	pair<int,int> *score;
	int pass = 0;
	int f_ele, s_ele;
	int last_high = 0;
	for(int a=0;a<T;a++){
		cin >> N;
		score = new pair<int,int>[N+1];
		for(int i=0;i<N;i++){
			cin >> f_ele >> s_ele;
			score[f_ele] = make_pair(f_ele,s_ele);
		}
		last_high = 100001;
		pass = 0;
		for(int i=1;i<N+1;i++){
			if(score[i].second<last_high) {
				pass++;
				last_high = score[i].second;
			}
		}
		cout << pass << "\n";

		delete [] score;
	}

}
