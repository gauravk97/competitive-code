/*input
2 
21 47 
22 47
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long t, a, m;
    cin>>t;
    while(t--){
        cin>>a>>m;
        if((int)pow(a,(m-1)/2) % (int)m == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
