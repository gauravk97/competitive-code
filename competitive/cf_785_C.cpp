/*input
10 3
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	double l = 1, r = 100, mid = l+(r-l)/2;
	while( abs(l-r)>0.1 ){
		cout<<"l : "<<l<<" r : "<<r<<endl;
		if( mid*(mid+1)/2 < n-m ){l = mid;}
		else{ r= mid;}
		mid = (l+r)/2;
	}
	cout<<mid<<" "<<floor(mid)+m<<endl;
	return 0;
}

void naive_solution(){
	int n, m, sum, i=1;
	cin>>n>>m;
	sum=n;
	// cout<<n<<m<<sum<<endl;
	while(sum>0){
		sum+=m;
		sum=(sum>n)?n:sum;
		sum-=i;cout<<sum<<" "<<i<<endl;
		i+=1;
		// cout<<sum<<endl;
	}
	cout<<"finally : "<<sum<<endl;
}