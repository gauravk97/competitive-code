#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ApGp(int ar[]){
	int d;
	if(2*ar[1]==((ar[0]+ar[2])))
	{
 	d=1;
 	ar[3]=2*ar[2]-ar[1];
 	}
 	else if(ar[1]==((int)sqrt(ar[0]*ar[2])))
 	{
 		d=2;
 		ar[3]=ar[2]*ar[2]/ar[1];
 	}
 	return d;
}


int main (){
	int t[4],d;
	cin>>t[0]>>t[1]>>t[2];
	while(t[0]||t[1]||t[2]){




		d= ApGp(t);
		if(d==1) cout<<"AP "<<t[3]<<endl;
		else cout<<"GP "<<t[3]<<endl;
		cin>>t[0]>>t[1]>>t[2];
	}


	return 0;

}
