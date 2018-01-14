/*input
2
3 5
3 6
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n], b[n];
    double sum_=0, largest=0, second_l=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        sum_+=a[i];
    }
    // cout<<sum_<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin>>b[i];
        if (largest<b[i])
        {
            second_l = largest;
            largest = b[i];
        }
        else if (second_l<b[i])
        {
            second_l = b[i];
        }
    }
    // cout<<largest<<" "<<second_l<<endl;
    if(sum_<=largest+second_l)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}