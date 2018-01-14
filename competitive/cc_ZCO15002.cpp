/*input
3 1 
3 2 4
*/

#include <bits/stdc++.h>

using namespace std;

void naive_approach(int n, int k, vector<int> a);

void approach_1(int n, int k, vector<int> a);

void approach_binary(int n, int k, vector<int> a);

int main()
{
    // ios::sync_with_stdio(false);
    int n, k, temp; cin>>n>>k;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        cin>>temp;
        a.push_back(temp);
    }
    // naive_approach(n, k, a);
    sort(a.begin(), a.end());
    approach_1(n, k, a);
    return 0;
}

void naive_approach(int n, int k, vector<int> a){
    int variations=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i ; ++j){
            if(((a[i]-a[j])>=k) || ((a[i]-a[j])*(-1)>=k)){
                variations++;
            }
            // cout<<a[i]<<" "<<a[j]<<" "<<abs(a[i]-a[j])<<endl;
        }
    }
    cout<<variations<<endl;
}

void approach_1(int n, int k, vector<int> a){
    int variations=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; (j<i) && ((a[i]-a[j])>=k); ++j){
            variations++;
        }
    }
    cout<<variations<<endl;
}


void approach_binary(int n, int k, vector<int> a){
    int variations=0;
    
}