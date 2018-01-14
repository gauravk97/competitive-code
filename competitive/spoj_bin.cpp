#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	string s;

	int i=0,n=8,num=n;
	
	for(i=0;i<=log2(num);++i){
		cout<<n<<" "<<i<<endl;
		if(n%2==0) s[i]='0';
		else s[i]='1';
		cout<<s[i]<<endl;
		n/=2;
	}
	cout<<s.length();
	
	
	return 0;
}