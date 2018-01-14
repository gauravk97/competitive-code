#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	// your code goes here
	long long t, sq, large = 0, lPrimeFactor = 2;
	cin>>t;
	sq = sqrt(t)+10;
	int isPrime[sq];
	memset(isPrime, 1, sizeof isPrime);
	// cout<<ar[100]<<" "<<sq;
	// isPrime[0]=1;
	// isPrime[1]=1;
	for(long long i = 2; i < sq; ++i){
		if(isPrime[i]){
			for(long long j = i; j<sq; j+=i){
				isPrime[j]=0;
			}
			// cout<<i<<endl;
			if(large<i)large = i;
			if(lPrimeFactor<i && t%i==0)lPrimeFactor=i;
		}
	}
	cout<<"large : "<<large<<endl;
	cout<<"lPF : "<<lPrimeFactor<<endl;
	return 0;
	
}