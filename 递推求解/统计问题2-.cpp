#include<iostream>
using namespace std;
int main()
{
    int c,n;
    int a[21];
    int i;
    
    /*预处理*/
    a[1]=3;
    a[2]=7;
    for(i=3;i<=20;i++)
        a[i]=2*a[i-1]+a[i-2];
 
    cin>>c;
    while(c--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}