#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	char cro[101];
	int count=0;
	for(int i=0;i<101;i++) cro[i]='0';
	cin >> cro;
	for(int i=0;i<100;i++){
		if(cro[i]!='\0'){
			if(cro[i]=='c'){
				if(cro[i+1]=='='||cro[i+1]=='-'||i==99){
					count++;i++;
				}else count++;
			}else if(cro[i]=='d'){
				if(i==99){
					count++;i++;
				}else if(cro[i+1]=='z'){
					if(i+1==99){
						count+=2;i++;
					}else if(cro[i+2]=='='){
						count++;i+=2;
					}
				}else if(cro[i+1]=='-'){
					count++;i++;
				}else count++;
			}else if(cro[i]=='l'||cro[i]=='n'){
				if(cro[i+1]=='j'||i==99){
					count++;i++;
				}else count++;
			}else if(cro[i]=='s'||cro[i]=='z'){
				if(cro[i+1]=='='||i==99){
					count++;i++;
				}else count++;
			}else {
				count++;
			}
		}else{break;}
	}
	cout << count << '\n';
}
