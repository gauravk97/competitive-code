#include <bits/stdc++.h>

using namespace std;

int isBeenum(int n);

int main(){
    int n;
    cin>>n;
    while(n!=-1){
        if(isBeenum(n)){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
        cin>>n;
    }
}

int isBeenum(int n){
    if(n%2){
        n--;
        if(n%3==0){
            n /=3;
            n = 4*n+1;
            t = sqrt(n);
            if(t*t==n){
                if(t%2)
                    return 1;
            }
        }
    }
    return 0;
    // int t = 1;
    // for(int i =0; t <= n; ++i){
    //  t+=i*6;
    //  if(t==n)
    //      return 1;
    // }
    // return 0;
}