#include <iostream>
using namespace std;

int main() {
	long long int a=0, sum=0,i,t;
	char b;
	cin>>t;
	while(t--){
	cin>>a;
	i=0;
	b='0'
	cout<<a<<"  check 1  "<<"also i: "<<i<<endl;//check1
	sum=a;
	
	while(b!='='){
		if(i%2==0){
		cin>>b;
	cout<<b<<"  check 2  "<<"also i: "<<i<<endl;//check2
		++i;			
		}	
		else if(i%2!=0){
			cin>>a;
	cout<<a<<"  check 3  "<<"also i: "<<i<<endl;//check1
			++i;
			
			switch(b){
			case '+':
				sum+=a;
				break;
			case '-':
				sum-=a;
				break;
			case '*':
				sum*=a;
				break;
			case '/':
				sum /=a;
				break;
			}
		}
	cout<<sum<<"  check 4  "<<"also i: "<<i<<endl;//check4

	}
	cout<<sum<<endl;

}

	return 0;
}