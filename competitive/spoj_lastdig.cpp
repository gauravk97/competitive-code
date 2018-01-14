#include <iostream>
using namespace std;
int ar[][4]={{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{0,5,0,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
int main()
{
	int t,i=0,a;
    long int b;
	cin>>t;
	while(i++<t)
	{
	    cin>>a>>b;
	    if(b==0) cout<<1<<"\n";
	    else cout<<ar[a%10][b%4]<<"\n";

	}

	return 0;
}
