#include<iostream>

using namespace std;
 
main(){
    int n,sum,avg,noOfSteps;    
    cin>>n;
    while(n!=-1){
    
        int a[n];
        sum=0;
        noOfSteps=0;
        for(int i=0;i<n;++i){ //enter and take sum
            cin>>a[i];
            sum+=a[i];
        }
         //now we need to calc avg. : lol
         avg=sum/n;
         if(sum==avg*n) {
            for(int i=0;i<n;++i){
                if(a[i]>avg) noOfSteps+=a[i]-avg;
            }
            cout<<noOfSteps<<endl;
         }
         else cout<<-1<<endl;
         cin>>n;
    }
    return 0;
}
