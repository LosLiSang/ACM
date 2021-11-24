#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char s[10][10];
    int q[10][10];
    int a,b,c;
    while(cin>>a>>b)
    {
        memset(q,0,sizeof(q));
        if(a==0&&b==0)
            break;
        cin>>c;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                cin>>s[i][j];
        int i=0,j=c-1,step=0,flag=0;
        while((i>=0&&i<=a-1)&&(j>=0&&j<=b-1))
        {
            if(q[i][j]!=0)
            {
                int s=q[i][j]-1;
                cout<<s<<" step(s) before a loop of "<<step-s<<" step(s)"<<endl;
                flag=1;
                break;
            }
            char ch=s[i][j];
            q[i][j]=step+1;
            if(ch=='N')
            {
                i--;
                step++;
            }
            else if(ch=='S')
            {
                i++;
                step++;
            }
            else if(ch=='E')
            {
                j++;
                step++;
            }
            else
            {
                j--;
                step++;
            }
        }
        if(flag==0)
        cout<<step<<" step(s) to exit"<<endl;
    }
    return 0;
}