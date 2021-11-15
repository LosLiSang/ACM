#include<bits/stdc++.h>
using namespace std;
#define max_v 100005
int n;
struct node
{
    double x,y;
}p[max_v];
int a[max_v];
double cmpx(node a,node b)
{
    return a.x<b.x;
}
double cmpy(int a,int b)
{
    return p[a].y<p[b].y;
}
double min_f(double a,double b)
{
    return a<b?a:b;
}
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double slove(int l,int r)
{
    if(r==l+1)
        return dis(p[l],p[r]);
    if(l+2==r)
        return min_f(dis(p[l],p[r]),min_f(dis(p[l],p[l+1]),dis(p[l+1],p[r])));
    int mid=(l+r)>>1;
    double ans=min_f(slove(l,mid),slove(mid+1,r));
    int i,j,cnt=0;
    for( i=l;i<=r;i++)
    {
        if(p[i].x>=p[mid].x-ans&&p[i].x<=p[mid].x+ans)
        {
            a[cnt++]=i;
        }
    }
    sort(a,a+cnt,cmpy);
    for(i=0;i<cnt;i++)
    {
        for(j=i+1;j<cnt;j++)
        {
            if(p[a[j]].y-p[a[i]].y>=ans)
                break;
            ans=min_f(ans,dis(p[a[i]],p[a[j]]));
        }
    }
    return ans;
}
int main()
{
    int i;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmpx);
        printf("%0.2lf\n",slove(0,n-1)/2.0);
    }
    return 0;
}