/*input
10
1 1 3 0 0 0 2 1 0 3
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        b[i]=1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ( j >= i - a[i])
            {
                b[j]=0;
            }   
        }
    }
    int count=0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i]==1)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}