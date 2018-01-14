/*input
1
2 2
-1 1
*/
// 3 5
// -1 -1 4 5 -1
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long DP(long long ar[], long long n1, long long k1){
	cout<<n1<<" "<<k1<<endl;
	long long result = 0, temp ;
	if(n1<0 || k1<0) return 0;
	for(long long i = 1; i < k1+1; ++i){
		if(ar[i]>0){ 
			temp = DP(ar, n1-1, k1-1);
			if(result!=0) result = min( result, ar[i]+temp);
			else result = ar[i]+temp;
		}
	}
	cout<<n1<<" "<<k1<<" "<<result<<endl;
	return result;
}

int main() {
	long long t;
	cin>>t;
	cout<<t<<endl;
	for (long long i = 0; i < t; ++i)
	{
		cin>>n>>k;
		// cout<<n<<k;
		long long ar[k+1];
		for (long long j = 1; j < k+1; ++j)
		{
			cin>>ar[j];
		}
		cout<<DP(ar, n, k)<<endl;

	}
	return 0;
}