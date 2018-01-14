#include<iostream>

using namespace std;
 
main(){
    long long n,t,sum,tmp;    
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for(int i=0;i<n;++i){           //enter and take sum
            cin>>tmp;
            sum=(sum+tmp)%n;
        }
            //now we need to calc avg. : lol
         if(!sum) {
            cout<<"YES"<<endl;
         }
         else cout<<"NO"<<endl;
    }
    return 0;
}
