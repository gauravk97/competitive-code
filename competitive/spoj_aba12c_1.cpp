/*input
1
5 5
1 2 3 4 5*/
// 3 5
// -1 -1 4 5 -1
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long DP(long long ar[], long long n1, long long k1){
	long long result = INT_MAX ;
	if(n1<0 || k1<0) return INT_MAX;
	for(long long i = 1; i < k+1; ++i){
		// if(ar[i]>0) result = min( result, DP(ar, n1-1, k-1));
	}
	return 0;
}

int main() {
	long long t;
	cin>>t;
	for (long long i = 0; i < t; ++i)
	{
		cin>>n>>k;
		long long ar[k+1];
		for (long long j = 1; j < k+1; ++j)
		{
			cin>>ar[j];
		}
		cout<<0<<endl;//DP(ar, n, k)<<endl;

	}
	return 0;
}