/*input
2
8
1 1 2 1 1 2 2 2 
*/
/*1
(()(()))
*//*
20
1 2 1 1 2 2 1 2 1 1 2 1 2 2 1 1 2 1 2 2
*/

#include<iostream>
#include<string>
using namespace std;


void bracketto12(string s){
    int n = s.length();
    cout<<n<<endl;
    for (int i = 0; i < n; ++i)
    {
        if(s[i]=='(') cout<<1<<" ";
        else if(s[i]==')') cout<<2<<" ";
    }
    cout<<endl;
}

int main()
{
    int a;
    cout<<"1. to convert string of brackets to good input"<<endl;
    cout<<"2. normal question"<<endl;
    cin>>a;
    if(a==1){
        string s;
        cin>>s;
        // cout<<s<<endl;
        bracketto12(s);
    }
    else{   
        int n; cin>>n;
        int a[n]; 
        for (int i = 0; i < n; ++i)
            cin>>a[i];
    
        int depthCounter=0, maxDepthPos=0, maxDepth=0, startPos=0, endPos=0, length=0, maxLengthPos=0, maxLength=0;
        for (int i = 0; i < n; ++i)
        {
            if(a[i]==1){
                if(depthCounter==0){
                    startPos=i;
                }
                depthCounter++;
                if(depthCounter>maxDepth){
                    maxDepth=depthCounter;
                    maxDepthPos=i;
                }
            }
    
            else if(a[i]==2){
                depthCounter--;
                if(depthCounter==0){
                    endPos=i;
                    length=endPos-startPos+1;//some error might have creepd in here
                    if (length>maxLength){
                        maxLength=length;
                        maxLengthPos = startPos;
                    }
                }
            }
            // debugging
            // for (int j = 0; j < n; ++j)
            // {
            //     if(a[j]==1)cout<<"{";
            //     else cout<<"}";
            // }
            // cout<<endl;
            // for (int j = 0; j < i; ++j)
            // {
            //     cout<<" ";
            // }
            // cout<<"^";
            // cout<<endl<<"depthCounter: "<<depthCounter<<" maxDepth: "<<maxDepth<<" maxDepthPos: "<<maxDepthPos+1<<endl;
            // cout<<"startPos: "<<startPos<<" endPos: "<<endPos<<" length: "<<length<<" maxLength: "<<maxLength<<" maxLengthPos: "<<maxLengthPos+1<<endl;
        }
        maxDepthPos++;
        maxLengthPos++;
        // cout<<"*****"<<endl<<"Answer : "<<" maxDepth: "<<maxDepth<<" maxDepthPos: "<<maxDepthPos<<" maxLength: "<<maxLength<<" maxLengthPos: "<<maxLengthPos<<endl;
        cout<<maxDepth<<" "<<maxDepthPos<<" "<<maxLength<<" "<<maxLengthPos<<endl; 
    }   
    return 0;
}