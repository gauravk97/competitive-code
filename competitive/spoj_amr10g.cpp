/*input
3
3 1
2 5 4
3 2
5 2 4
3 3
2 5 4
*/

// question:: AMR10G
// ideone:: nope
 
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	
	int t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long a[n+1], min = LONG_MAX;
		for (int i = 1; i < n+1; ++i)
		{
			cin>>a[i];
		}
		if (k == 1)
		{
			cout<<0<<endl;
		}
		else
		{
			sort(a+1, a+n+1);
		//n-k+1 times loop , therby iterating through the array
			for (int i = 1; i <= n-k+1; ++i)
			{
				if(min > a[i+k-1] - a[i]){
					min = a[i+k-1] - a[i];
				}
			}
			cout<<min<<endl;
		}
	}
	
	return 0;
}

/*comments on the ques: >
1st one go ! Yippie !
*/