/*input
10
1
2
3
4
5
6
7
8
9
10
*/
#include <bits/stdc++.h>

using namespace std;
vector<int> ar;
int main()
{
	ios::sync_with_stdio(false);
	int t, n, k, l, a, b; // k = max num/denominator value in a line; l = last(size-1) triangle sum
	ar.push_back(0);
	for (int i = 1; i <= 4501 ; ++i)
	{
		ar.push_back(ar[i-1]+i);
	}
	cin>>t;
	while(t--){
		cin>>n;
		// cout<<"n: "<<n<<endl;
		vector<int>::iterator low = upper_bound(ar.begin(), ar.end(), n);
		if(*(low-1) == n)low--;
		k = low-ar.begin();
		l = *(low-1);
	
		// cout<<"K :"<<k<<" l:"<<l<<endl;
		if(k%2){//odd
			a = k-(n-l-1); b = 1+(n-l-1);	
			// cout<<a<<"/"<<b<<endl;
		}
		else {
			a = 1+(n-l-1); b = k-(n-l-1);
			// cout<<a<<"/"<<b<<endl;
		}
		cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<endl;
	}
	return 0;
}

/* comments on the question :>

*/