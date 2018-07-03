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
	bool *good;
	int pass = 0;
	int f_ele, s_ele;
	for(int a=0;a<T;a++){
		cin >> N;
		score = new pair<int,int>[N];
		good = new bool[N];
		for(int i=0;i<N;i++){
			cin >> f_ele >> s_ele;
			score[i] = make_pair(f_ele,s_ele);
			good[i] = false;
			for(int j=0;j<i;j++){
				if(score[i].first<score[j].first||score[i].second<score[j].score) good[i] = true;
				else good[j] = true;
			}
		}
		pass = 0;
		for(int i=0;i<N;i++){
			int good = 1;
			for(int ii=0;ii<N;ii++){
				if(i==ii) continue;
				if(score[i][0]>score[ii][0]&&score[i][1]>score[ii][1]) good = 0;
			}
			if(good==1) pass++;
		}
		cout << pass << "\n";

		delete [] score;
		delete [] good;
	}

}
