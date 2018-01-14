#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
 
vector<long long> primes;
 
bool isPrime(long long n){
	bool b = 1;
	for(long long i = 0; i < primes.size(); ++i){
		// cout<<primes[i]<<endl;
		if(n!=primes[i] && n%primes[i]==0){
			b = 0;
			break;
		}
	}
	return b;
}
 
int main() {
	long long n, largest = 0, sq;
	cin>>n;
	sq = sqrt(n)+10;
	// cout<<sq<<"  fdsf"<<endl;
	int ar[sq];
	for(long long i = 0; i < sq; ++i){
		ar[i]=1;
	}	
	for(long long i =2; i < sq; ++i ){
		if(ar[i]){
			for(long long j = i*i; j < sq; j+=i){
				ar[j]=0;
			}
			primes.push_back(i);
		}
	}
	cout<<"no"<<endl;
	// for(int i = 2; i < sq; ++i){
		// cout<<ar[i]<<endl;
	// }	
	cout<<"you"<<endl;
	// for(int i = 0; i<primes.size(); ++i){
		// cout<<primes[i]<<endl;
	// }
	// cout<<"mk"<<endl;
	for(long long i=2; i <= (int)sqrt(n); ++i){
		// cout<<"i : "<<i<<endl;
		if(n%i==0){
			long long k = n/i;
			// cout<<i<<" "<<k<<endl;
			// cout<<endl;
			// cout<<"isPrime() : "<<isPrime(i)<<" :"<<isPrime(k)<<endl;
			if(isPrime(i) && largest<i )largest = i;
			
			if(isPrime(k) && largest<k )largest = k;
			// cout<<"larg : "<<largest<<endl;
		}
	}
	cout<<"b : "<<largest<<endl;
 
	// cout<<isPrime(67)<<endl;
	return 0;
}