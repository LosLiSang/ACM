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

int n;
struct edge{
    int start;
    int end;
    int cost;
}edge[MAX_INPUT];

bool cmp(struct edge e1, struct edge e2){
    return e1.cost < e2.cost;
}

int pre[MAX_INPUT];

int ufind(int x){
    int r = x;
    while(r != pre[r])
        r = pre[r];
    int itr = x, t;
    while(itr != r){
        t = pre[itr];
        pre[itr] = r;
        itr = t;
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
    while(cin >> n && n){
        int flag;
        int m = n * (n - 1) / 2;
        init(n);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d%d", &(edge[i].start), &(edge[i].end), &(edge[i].cost), &flag);
            if(flag == 1){
                merge(edge[i].start, edge[i].end);
            }
        }
        int cost = 0;
        sort(edge, edge + m, cmp);
        for(int i = 0; i < m; i++){
           if(ufind(edge[i].start) == ufind(edge[i].end)) continue;
           else{
               merge(edge[i].start, edge[i].end);
                cost += edge[i].cost;
           } 
        }
        cout << cost << endl;
    }
    return 0;
}