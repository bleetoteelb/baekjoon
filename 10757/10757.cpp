#include <iostream>
#include <deque>
#include <sstream>
#include <string.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

	string temp;
	getline(cin,temp);
	istringstream iss(temp);
	string a,b;

	iss >> a >> b;

	int f_length = a.length();
	int s_length = b.length();
	int sum_len = f_length > s_length ? f_length+1 : s_length+1;

	char * first = new char [f_length+1];
	char * second = new char [s_length+1];


	strcpy(first,a.c_str());
	strcpy(second,b.c_str());

	int * first_int = new int [f_length];
	int * second_int = new int [s_length];
	int * sum_int = new int [sum_len];

	for(int i=0;i<sum_len;i++) sum_int[i]=0;
	for(int i=0;i<f_length;i++){
		first_int[i] = int(first[i])-48;
	}
	for(int i=0;i<s_length;i++){
		second_int[i] = int(second[i])-48;
	}
	for(int f=f_length-1,s=s_length-1,i=sum_len-1;;f--,s--,i--){
		if(f<0){
			for(;s>=0;s--,i--){
				if(second_int[s]+sum_int[i]>=10){
					sum_int[i-1] += 1;
					sum_int[i] += second_int[s]-10;
				}else sum_int[i] += second_int[s];
			}
			break;
		}else if(s<0){
			for(;f>=0;f--,i--){
				if(first_int[f]+sum_int[i]>=10){
					sum_int[i-1] += 1;
					sum_int[i] += first_int[f]-10;
				}else sum_int[i] += first_int[f];
			}
			break;
		}
		if(first_int[f]+second_int[s]+sum_int[i]>=10){
			sum_int[i-1] += 1;
			sum_int[i] += first_int[f] + second_int[s] - 10;
		}else sum_int[i] += first_int[f] + second_int[s];
	}

	for(int k=0;k<sum_len;k++){
		if(k==0&&sum_int[0]==0) continue;
		cout << sum_int[k];
	}
	cout << "\n";

	delete[] first;
	delete[] second;
	delete[] first_int;
	delete[] second_int;
	delete[] sum_int;
}
