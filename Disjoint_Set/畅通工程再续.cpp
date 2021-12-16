#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10010
using namespace std;

int n, m;
struct ipt{
    int x;
    int y;
}ipts[MAX_INPUT];

struct edge{
    int start;
    int end;
    double cost;
}edge[MAX_INPUT];

bool cmp(struct edge e1, struct edge e2){
    return e1.cost < e2.cost;
}

int pre[MAX_INPUT];

int ufind(int x){

    int r = x;
    while(r != pre[r])
        r = pre[r];
    int i = x, j;
    while(i != r){
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

bool merge(int x, int y){
    int tx = ufind(x);
    int ty = ufind(y);
    if(tx == ty) return false;
    pre[tx] = ty;
    return true;
}

void init(int n){
    for(int i = 1; i <= n; i++){
        pre[i] = i;
    }
}


int main(){
    // 
    int n, m;
    cin >> n;
    while(n--){
        // 多少个村庄
        cin >> m;
        init(m);
        // int count = 0;
        // 输入
        int count = 0;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &(ipts[i].x), &(ipts[i].y));
            for(int j = 1; j < i; j++){
                edge[count].start = i;
                edge[count].end = j;
                edge[count].cost = sqrt(pow(ipts[i].x - ipts[j].x, 2) + pow(ipts[i].y - ipts[j].y, 2));
                count++;
            }
            // edge[i].end = sqrt(edge[i].start * edge[i].start + edge[i].end)
        }
        double cost = 0;
        sort(edge, edge + m * (m - 1) / 2, cmp);
        for(int i = 0; i < m * (m - 1) / 2; i++){
            if(ufind(edge[i].start) == ufind(edge[i].end) || edge[i].cost < 10 || edge[i].cost > 1000) 
                continue;
            else{
                merge(edge[i].start, edge[i].end);
                cost += edge[i].cost;
           }
        }
        int flag = true;
        for(int i = 1; i <= m; i++){
            int x = ufind(1);
            if(x != ufind(i)) flag = false; 
        }
        if(flag)
            printf("%.1f\n", cost * 100);
        else
            cout << "oh!" << endl;
    }
    return 0;
}