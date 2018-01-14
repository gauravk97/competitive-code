#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

struct dual {
	long long l, r;
	};

int main() {
	int n, m;
	long long distance=0;
	cin>>n;
	dual chess[n];
	for(int i =0; i< n ; ++i)
		cin>>chess[i].l>>chess[i].r;
	cin>>m;
	dual pro[m];
	for(int i =0; i< m ; ++i)
		cin>>pro[i].l>>pro[i].r;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			long long a = pro[j].l-chess[i].r, b = pro[i].r-chess[i].l;
			// cout<<chess[i].l<<" "<<chess[i].r<<" "<<pro[j].l<<" "<<pro[j].r<<" "<<a<<" "<<b<<endl;
			if(min(a,b)>0)distance=max(distance,min(a,b));
			// cout<<distance<<endl;;
		}
	}
	cout<<distance<<endl;
	return 0;
}