#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int dum = 0;
	for(int i = 1; i<1000; ++i){
		if(i%3 == 0)dum+=i;
		else if(i%5 == 0)dum+=i;
	}
	cout<<dum<<endl;
	return 0;
}