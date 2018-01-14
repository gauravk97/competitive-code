/*input
3
3
1 2 3
3
1 4 5
3
2 4 6
*/

// question::
// ideone::
 
#include <bits/stdc++.h>

using namespace std; 


int main() {
	ios::sync_with_stdio(false);	

	long long int ar[10001];

	long long int t, n, sum = 0;
	cin>>t;
	while(t--){
		cin>>n;
		sum = 0;
		for (int i = n; i >= 1; --i)
			cin>>ar[i];
		for (int i = 1; i <= n; ++i)
			sum += (n - 2*i + 1)*ar[i];
 		cout<<sum<<endl;
	}
	
	return 0;
}

/*comments on the ques: >

*/