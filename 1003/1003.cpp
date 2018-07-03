#include <iostream>
using namespace std;

int main(){
	int cases = 0;

	cin >> cases;
	int  num = 0;
	// output is 0's count, 1's count
	for(int i=0;i<cases;i++){
		cin >> num;

		if(num == 0){
			cout << "1 0"<< endl;
			continue;
		}else if(num == 1){
			cout << "0 1"<< endl;
			continue;
		}

		int tmp_count0[2] = {1,0};
		int tmp_count1[2] = {0,1};
		int tmp_num = 0;
		for(int ii=2;ii<=num;ii++){
			tmp_num = tmp_count0[1];
			tmp_count0[1] = tmp_count0[0] + tmp_count0[1];
			tmp_count0[0] = tmp_num;
			tmp_num = tmp_count1[1];
			tmp_count1[1] = tmp_count1[0] + tmp_count1[1];
			tmp_count1[0] = tmp_num;
		}
		cout << tmp_count0[1] << " " << tmp_count1[1] << endl;
	}
}
