#include<iostream>

using namespace std;
 
main(){
    long long n,t,sum,avg;    
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        sum=0;
            //noOfSteps=0;
        for(int i=0;i<n;++i){           //enter and take sum
            cin>>a[i];
            sum+=a[i];
        }
            //now we need to calc avg. : lol
         avg=sum/n;
         if(sum==avg*n) {
            //  for(int i=0;i<n;++i){
            //   if(a[i]>avg) noOfSteps+=a[i]-avg;
            //}
            cout<<"YES"<<endl;
         }
         else cout<<"NO"<<endl;
    }
    return 0;
}
