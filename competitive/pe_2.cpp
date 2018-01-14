#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long i = 0, j = 1, sum=0;
	for(long long l =0; l<(long long)(4e6);){
		l = j + i;
		i = j;
		j = l;
		if(l<(long long)(4e6) && l%2==0)
			sum+=l;
		cout<<l<<endl;
	}
	cout<<"  l:"<<sum<<endl;
	return 0;
}