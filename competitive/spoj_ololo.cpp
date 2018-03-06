#include <bits/stdc++.h> 
using namespace std; 
int main() { 
	ios_base::sync_with_stdio(false);
	long long n,k,ans=0; 
	cin>>n; 
	while(n--) { 
		cin>>k; 
		ans^=k; 
 
	} 
	cout<<ans;
	return 0;
	}  