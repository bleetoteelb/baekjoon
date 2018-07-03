#include <iostream>
#include <deque>
using namespace std;

deque<int> cards;
deque<int> result;

//turn -> geun = 0 / mung = 1
void get_all(deque<int> test_all,int gm[],int turn){
		cout << turn << " / " << gm[0] << " " << gm[1] << "\n";
	if(test_all.empty()) {
		result.push_back(gm[0]);
	}
	else{
		int temp = test_all.front();
		gm[turn]+=temp;
		test_all.pop_front();
		get_all(test_all,gm,(turn==0)?1:0);
		if(test_all.empty()) return;
		test_all.push_front(temp);
		gm[turn]-=temp;

		temp = test_all.back();
		gm[turn]+=temp;
		test_all.pop_back();
		get_all(test_all,gm,(turn==0)?1:0);
		gm[turn]-=temp;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0, card_num = 0;
	int card = 0, gm[2] = {0,0}, pos = 0;

	cin >> cases;

	for(int i=0;i<cases;i++){
		gm[0] = gm[1] = pos = 0;
		if(!cards.empty()) cards.clear();
		cin >> card_num;
		for(int ii=0;ii<card_num;ii++){
			cin >> card;
			cards.push_back(card);
		}


		deque<int> test_all = cards;
		int gm[2] = {0,0};
		get_all(test_all,gm,0);
		
		int largest = result.front();
		deque<int>::iterator end = result.end();
		for(deque<int>::iterator pos = result.begin(); pos!=end;pos++){
			cout << *pos << " ";
			if (largest < *pos) largest = *pos;
		}
		cout << "\n";
		cout << largest << "\n";
	}
}

