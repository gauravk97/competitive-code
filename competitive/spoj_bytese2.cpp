/*input
1
5
1 7
2 4
6 9
3 8
5 10
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int anArray[n][2], minT=-1, maxT=-1, maxD=-1, numD;
		for (int i = 0; i < n; ++i)
		{
			cin>>anArray[i][0]>>anArray[i][1];
			if(minT == -1 || anArray[i][0]<minT)minT=anArray[i][0];
			if(maxT == -1 || anArray[i][0]>maxT)maxT=anArray[i][1];
		}
		for (int i = minT; i < maxT; ++i)
		{
			numD=0;
			for (int j = 0; j < n; ++j)
			{
				if(anArray[j][0]<=i && anArray[j][1]>=i+1)
					++numD;
			}
			if(maxD == -1 || maxD<numD)maxD=numD;
		}
		cout<<maxD<<endl;
	}
	return 0;
}