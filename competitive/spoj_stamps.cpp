/*input
3
100 6
13 17 42 9 23 57
99 6
13 17 42 9 23 57
1000 3
314 159 265
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool wayToSort(int i, int j){
  return i>j;
}

int func(std::vector<int>& vec,int no){
  int e=0,n=0,k=0;
  for(int i: vec){
    e+=i;
    n++;
    if(e>=no){
      k=1;
      break;}
    }
  if(k==0) n=0;
  return n;
}

 
int main()
{
  int t,no,t1,n;
      
  cin>>t;
  for(int j=1;j<t+1;j++)
    {
    cin>>no>>t1;
    vector<int> v;
    for(int i=0;i<t1;i++){
      cin>>n;
      v.push_back(n);
      }
   //sort this thing in desc order
    sort(v.begin(),v.end(),wayToSort);
    n=func(v,no);

    cout<<"Scenario #"<<j<<":"<<endl;
 
    if(n)cout<<n<<endl;
    else cout<<"impossible"<<endl;
 
 
 
      }
      return 0;
}
 
 
 