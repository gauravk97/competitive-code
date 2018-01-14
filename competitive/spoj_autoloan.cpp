/*input
3
6800 100 68
2000 510 4
15000 364 48
*/
//5628.0 2197.0 3

//######################################################################
/*
check out ideone ver 2.0 answer of this problem
link:https://ideone.com/CXo4ME
*/



#include <iostream>
#include <cmath>
using namespace std;

double autoloan(double price, double monthlyPayments, int loanTerm){

bool t;
int n ,m=0;
double  b = price, p = monthlyPayments, i, upper=0.2, lower=0, midI;
while(lower<upper){ 
	midI = lower + (upper-lower)/2;
	b=price;
	n=0;
	// cout<<b<<" "<<lower<<" "<<upper<<" "<<midI<<" "<<p<<" "<<loanTerm<<endl;
	while(b>0){

		b += b*midI/12 - p ;
		n++;
		// if(n<10) cout<<"b:"<<b<<endl;
	}
	// cout<<"b: "<<b<<endl;
	// cout<<"n: "<<n<<endl;
	// cout<<"I: "<<midI<<endl;
	
	if(n<=loanTerm)
		lower = midI;
	else if(n>loanTerm)
		upper = midI;
	
	m++;
	if(b==0) break;

	t =fabs(b)<1.0e-09;
	if(t) break;

	}	
	cout<<m<<endl;
return midI*100;

}
int main() {
	

	int t,n;
	double b, p;
	cin>>t;

	while(t--){
		cin>>b>>p>>n;
		cout<<autoloan(b,p,n)<<endl;
		

	}
	return 0;
}

