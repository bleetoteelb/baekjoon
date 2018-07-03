#include <iostream>
#include <deque>
using namespace std;

deque<int> window;
deque<int> index;

void empty_deal(int number,int in){
	window.push_back(number);
	index.push_back(in);
//		cout << window.front() << " " << window.back() << endl;
	cout << window.front();
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0, L = 0;
	cin >> N >> L;

	int number = 0;

	for(int i=0;i<N;i++){
		cin >> number;
		if(i!=0){cout << " ";}
		if(window.empty()){ empty_deal(number,i); }
		else{
			if(index.front() <= i-L){
				window.pop_front();
				index.pop_front();
			}
			if(window.empty()){ empty_deal(number,i);}
			else{
				while(1){
					if(!window.empty&&window.back()>=number){
//		cout << "here " << window.front() << " " << window.back() << endl;
						window.pop_back();
						index.pop_back();
					}else break;
				}
				empty_deal(number,i);
//		cout << window.front() << " " << window.back() << endl;
			}
		}
/*		deque<int>::iterator begin = window.begin();
		deque<int>::iterator end = window.end();
		for(;begin!=end;begin++){
			cout << *begin << " ";
		}
		cout << endl;*/
	}
	cout << "\n";
	return 0;
}
