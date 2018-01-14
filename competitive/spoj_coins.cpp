/*input
100
12
2
*/
#include <bits/stdc++.h>

using namespace std; 

map<long long int, long long int> value;

long long int exchange(long long int n){

    long long int res = n;
    if(n == 0) return 0;

    if(value.find(n) != value.end())
       	return value[n];


    else
        value[n] = max(n, exchange(n/2) + exchange(n/3) + exchange(n/4));
    return value[n];
}

int main() {
    ios::sync_with_stdio(false);    

    long long int t, n;
    while(cin>>t){
        cout<<exchange(t)<<endl;
    }

    return 0;
}