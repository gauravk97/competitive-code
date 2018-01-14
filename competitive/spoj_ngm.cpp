/*input
15
*/
#include <bits/stdc++.h>

using namespace std;

void ngm(int t){
	int lastDig = t%10;
	if(lastDig){
		cout<<1<<endl<<lastDig<<endl;
	}
	else{
		cout<<2<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);	
	int t;
	while(cin>>t){
		ngm(t);
	}
	return 0;
}
