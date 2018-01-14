/*input
1
5 2
1
2
4
8
9
*/

#include <iostream>
using namespace std;

int main() {
	int aggrCow(int ar[], int noOfSheds, int noOfCows);

	long int t, n, c;
	cin>>t;
	while(t--){
		cin>>n>>c;
		int ar[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
		}
		//sort the fuckin' array
		//call the aggrcow function
		cout<<aggrCow(ar,n,c);

	}
	return 0;
}


int aggrCow(int ar[], int noOfSheds, int noOfCows){
	int lo = 1, hi = ar[noOfSheds-1]-ar[0], distance, sum, cows;
	
	while(lo<hi){
	cout<<"lo  :"<<lo<<endl;
	cout<<"hi :"<<hi<<endl;
	distance = lo+ (hi- lo +1)/2;
	cout<<"dis:   "<<distance<<endl;;
	sum =0;
	cows =1;
	for (int i = 1; i < noOfSheds; ++i)
		{
		if(ar[i]-ar[i-1]+sum >= distance) {
			cows++;
			sum = 0;
			}
		else {
			sum += ar[i]-ar[i-1];
		}	
	}
	cout<<"cows :  "<<cows<<endl;
	if(cows>=noOfCows){ lo = distance; }//shit shit shit
	else if(cows< noOfCows) { hi = distance - 1; }
	else cout<<"error ifelse";

	}
	return lo;
}