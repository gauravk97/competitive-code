#include <bits/stdc++.h>
typedef unsigned long long u64;
#define M 1000000007
using namespace std;

u64 sumpro(u64 n){
	u64 sum = 0, prim = 0, sec = 0, hi, lo, i;
	for ( i = 1; i*i <= n; ++i)
	{
		hi = n/i; lo = n/(i+1);
		prim = (  ( (hi*(hi+1)/2) - (lo*(lo+1)/2) )%M * (i%M)  )%M;
		if(hi == i) sec = 0;
		else sec =  ((hi%M)*(i%M))%M;
		sum = ((sum%M) +(prim%M) + (sec%M))%M;
	}
	return sum;

} 

int main()
{
	ios::sync_with_stdio(false);
	u64 t, n = 0, count = 0, c, d;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<sumpro(n)<<endl;
	}
	return 0;
}

