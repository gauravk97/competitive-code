#include <iostream>
#include <conio>
using namespace std;

int main()
{
	int t,i=0,a,b;
	cin>>t;
	while(i++<t)
	{
		cin>>a>>b;
		if(a==b||a==b+2)
		{
			if(a%2==0&&b%2==0) cout<<a+b<<endl;
			else cout<<a+b-1<<endl; 
		}
		else
			cout<<"No Number"<<endl;
	}

	return 0;
}