/*input
4
*/

#include <bits/stdc++.h>

using namespace std; 
typedef unsigned long long ull;


int main() {
	ios::sync_with_stdio(false);	
	ull n;
	cin>>n;
	if(n&(n-1))cout<<"NIE"<<endl;
	else cout<<"TAK"<<endl;
	
	

	return 0;
}