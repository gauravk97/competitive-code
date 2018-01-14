#include <bits/stdc++.h>

using namespace std;

void function(){
	int ar[10000] = {0}, mark[100000] = {0},j=0;
	for (int i = 2; i < 100000; ++i)
	{
		if(mark[i]==0){
			ar[j] = i;
			
			j++;
			for (int k = 2*i; k < 100000; k+=i)
			{
				mark[k] = 1; 
			}
			
		}
	}

// cout<<"now mark";
for (int i = 0; i < 100000; ++i)
	{
	cout<<ar[i]<<" ";
	if(ar[i]==0){cout<<i; break;
	}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	function();

	return 0;
}
