/*input

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, ans, no, ma;
	for (int i = 2; i < 1001; ++i)
	{
	t=i;
	if(t%2!=0)ans=1;
	else{
		for (int m = 1; m < 1001; ++m){
			no = t*m+1;
			// cout<<" no "<<no<<endl;
			for (int j = 2; j < sqrt(no); ++j){
				
				if (no%j==0)
				{	

					ans = j;
					break;
				}
			}
		}

	}
	cout<<ans<<endl;;
	}
	return 0;
}