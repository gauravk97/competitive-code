/*input
49 21
21 49
16 18
4 6
1 2
20187 981981
0 0
*/

// question::
// ideone::
 
#include <iostream>

using namespace std;
typedef unsigned long long u64;

u64 gcd(u64 small, u64 large){
	u64 res;
	if (small == 0)
		return large;
	if (large%small == 0)
		res = small;
	else
		res = gcd(large%small, small);
	return res;
}

int main() {
	ios::sync_with_stdio(false);	

	u64 t, n, g;
	cin>>t>>n;
	while(t!=0 && n!=0)
	{
		g = gcd(t,n);
		u64 u = t * n; 
		// cout<<g<<endl;1690740
		cout<<((u/g)/g)<<endl;
		cin>>t>>n;
	}


	return 0;
}

/*comments on the ques: >

*/