/*input
4
10 1 2 3 4 5 1 2 3 4 5
6 10 3 2 5 7 8
7 7 7 7 7 7 7 7
40 94 40 49 65 21 21 106 80 92 81 679 4 61  
6 237 12 72 74 29 95 265 35 47 1 61 397
52 72 37 51 1 81 45 435 7 36 57 86 81 72 
*/

#include <iostream>
using namespace std;


int badNei(int seq[],int n){

	int S[n], flag[n], max=0;
	
	for (int i = 0; i < n; ++i)
	{S[i]=0;
	flag[i]=0;}
	flag[0]=1;

	for (int i = 0; i < n; ++i)
	{
		S[i]=seq[i];
		for (int j = 0; j < i-1; ++j)
		{	if(flag[j]==1 && (i==n-1) ) break;
			if(S[j]+seq[i]>S[i])
			{
				S[i] = S[j] + seq[i]; 
				if(flag[j]==1)flag[i]=1;
			}	
			//cout<<i<<" "<<j<<" "<<S[i]<<" "<<S[j]<<" "<<seq[i]<<" "<<flag[i]<<endl;
		}

		if(max<S[i])max = S[i];

	}

	return max;
}

int badNei2(int seq[],int n){
	int ans1 = badNei(seq,n), temp=0, ans2;
	
	for (int i = 0,j=n-1; i < n/2; --j,++i)
	{
		temp = seq[i];
		seq[i] = seq[n-1-i];
		seq[n-1-i] = temp;		
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	 code cout<<seq[i]<<" ";
	// }
	// cout<<endl;
	ans2 = badNei(seq,n);
	// cout<<ans1<<" "<<ans2<<endl;
	if(ans2>ans1) return ans2;
	else return ans1;
}

int main() {
	

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int ar[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
		}

		cout<<badNei2(ar,n)<<endl;
	}
	return 0;
}
//