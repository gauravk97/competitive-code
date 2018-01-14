/*input
6
100
99
98
97
96
2000000000000
*/
#include <bits/stdc++.h>

using namespace std;

unsigned long long int a[4] = {942, 192, 442, 692};

unsigned long long int eights(unsigned long long int n){
	unsigned long long int r1 = n%4, r2 = (n - n%4)/4;
	if(r1 == 0) r2 -= 1;
	return r2*1000+a[r1];
}

int main()
{
	ios::sync_with_stdio(false);
	unsigned long long int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<eights(n)<<endl;
	}	
	return 0;
}
/* comments on the question :>

*/