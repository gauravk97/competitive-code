#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	unsigned long long t, n, k;
	cin>>t;
	while(t--){
		cin>>n;
		k = floor(n*(n+2)*(2*n+1)/8);
		cout<<k<<endl;
	}
	return 0;
}

