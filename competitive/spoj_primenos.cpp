#include<iostream>
#include<cmath>
using namespace std;

main(){
    long long m,n,j,i;
    int t;
    bool isPrime;
    cin>>t;
    while(t--){
        
        cin>>m>>n;
        for(i=m;i<=n;i++){
            isPrime = true;
            if(i==1) isPrime= false;
            else if(i==2||i==3)  isPrime=true;

            else  {
            for(j=2;j<=sqrt(i);j++){
                if(i%j==0) {isPrime= false;}                                           
            } 
            }
            if(isPrime==true)cout<<i<<endl;
        }

    cout<<endl;
    }
    return 0;
}
