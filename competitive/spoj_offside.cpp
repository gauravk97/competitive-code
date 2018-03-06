#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, d, temp;
	cin>>a>>d;
	while(a!=0){
		vector<int> dist_a, dist_d;
		for(int i=0; i<a; ++i){
			cin>>temp;
			dist_a.push_back(temp);
		}
		for(int i=0; i<d; ++i){
			cin>>temp;
			dist_d.push_back(temp);
		}		
		sort(dist_a.begin(), dist_a.end());
		sort(dist_d.begin(), dist_d.end());
		// cout<<dist_a[0]<<" "<<dist_d[0]<<" "<<dist_d[1]<<endl;
		// if(dist_a[0]<dist_d[0] && dist_a[0]<dist_d[1])
		// 	cout<<"Y"<<endl;
		if (dist_a[0]<dist_d[1])
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
		
		cin>>a>>d;
	}
	return 0;
}