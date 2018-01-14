/*input
5
140 82
89 134
100 520	
1 201
88 90
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin>>n;int a, b, pa=0, pb=0, difference, min = INT_MAX, max = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		pa+=a;pb+=b;
		difference = pb-pa;
		if(difference<min)min=difference;
		if(difference>max)max=difference;
	}
	if(abs(min)>abs(max))cout<<1<<" "<<abs(min)<<endl;
	else cout<<2<<" "<<abs(max)<<endl;
	return 0;
}