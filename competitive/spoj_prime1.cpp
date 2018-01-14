/*input
1
100 200
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

main(){
    vector<int> prime;
    int t,cap;
    long long m,n,i,j;
    bool isPrime;
    cin>>t;
    prime.push_back(2);
    vector<int>::iterator p;
    while(t--){
    
    
    
    
        cin>>m>>n;
        for(i=3;i<=sqrt(n);i+=2){
            isPrime=true;
            cap=sqrt(i)+1;
             //loop for listing primes till sqrt(n)
            for(p=prime.begin();p!=prime.end();p++){
                if(*p>=cap) break; 
                if(i% *p==0) {
                    isPrime= false;
                    break;
                     }                                           
            }
            if(isPrime)prime.push_back(i);
        }
    
        for(j=m;j<=n;j++){
            isPrime=true;
            if(j==1) isPrime=false;
            cap=sqrt(j)+1;
        
            for(p=prime.begin();p!=prime.end();p++){
                if(*p>= cap) break;
                if(j% *p==0){isPrime= false;
                break;}
            }
            if(isPrime) cout<<j<<endl;
        }


    }
    return 0;
}
