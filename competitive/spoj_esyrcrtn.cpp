#include <bits/stdc++.h>

using namespace std;

int pfun(int a){
	int n = a%6, result;
	switch(n){
		case 0: result = -2;
			break;
		case 1: result = 1;
			break;
		case 2: result = 3;
			break;
		case 3: result = 2;
			break;
		case 4: result = -1;
			break;
		case 5: result = -3;
			break;
	}
	return result;
}

int fun(int a){
	if(a == 1)return 1;
	else if(a==2)return 4;
	else if(a>2) return pfun(a-1)+3;
}

int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	cin>>t;
	while(t--){

		cin>>n;
		// cout<<n<<" :: > "<<fun(n)<<endl;
		cout<<fun(n)<<endl;
		//n++;
	}
	return 0;
}