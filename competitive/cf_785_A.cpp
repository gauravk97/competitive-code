#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int nF(char a){
	if(a=='I')return 20;
	else if(a=='C')return 6;
	else if(a=='T')return 4;
	else if(a=='D')return 12;
	else if(a=='O')return 8;
	}
 
int main() {
 
	long long n, sum=0;
	cin>>n;
	string str;
	for(int i = 0; i < n; ++i){
		cin>>str;
		sum+=nF(str[0]);
 
	}
	cout<<sum<<endl;
	// your code goes here
	return 0;
}