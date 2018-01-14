
#include <iostream> 
using namespace std;
void display(int a[],int j)
{
    for (int i=j;i>=0 ;--i)
    {
        cout<<a[i];
    }
}
int main()
{
    int j=0,t;
    cin>>t;
    while(j<t)
    {
        
        int a[180],b=2,m,c,d,carry=0,carry2=0,i;
         a[0]=1;        
         for(int z=1;z<180;z++ )a[z]=0;
         cin>>c;         
        if(c=1){
        	cout<<1;
        }
        	else
        { 
        	for(int ){
        	for(i=0; i<m; i++)
        {
            d=a[i];
            a[i]=(a[i]*b+carry+carry2)%10;
            carry=(d*b/10)%10;
            carry2=d*b/100;
            b++;
        }
     }
        if(carry)
        {
            a[i]=carry;
            i++;
        }
        else if(carry2)
        {
            a[i]=carry;
            a[i+1]=carry2;
            i+=2;
        }
        display(a,i);
     		}
        j++;
        
        cout<<endl;
    }
    return 0;
}

        
