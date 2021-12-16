#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 110
using namespace std;

struct e{
    int start;
    int end;
    int cost;
}edge[MAX_INPUT * MAX_INPUT];

bool cmp(struct e e1, struct e e2){
    return e1.cost < e2.cost;
}

int n, m;
int map[MAX_INPUT][MAX_INPUT];
int ulist[MAX_INPUT];

int find(int x){
    return ulist[x];
}

void merge(int x, int y){
    int a = max(ulist[x], ulist[y]);
    int b = min(ulist[y], ulist[x]);
    for(int i = 1; i <= n; i++){
        if(ulist[i] == a) ulist[i] = b;
    }
}

void init_(int n){
    for(int i = 0; i <= n; i++){
        ulist[i] = i;
    }
}

int main(){
    while(cin >> n){
        int cost = 0;
        int cnt = 0;
        init_(n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> map[i][j];
                if(j < i) {
                    edge[cnt].cost = map[i][j];
                    edge[cnt].start = j;
                    edge[cnt].end = i;
                    cnt++;
                }                 
            }
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            merge(a, b);
        }
        sort(edge, edge + cnt, cmp);
        for(int i = 0; i < cnt; i++){
            if(find(edge[i].start) == find(edge[i].end)){
                continue;
            }else{
                merge(edge[i].start, edge[i].end);
                cost += edge[i].cost;
            }
        }
        cout << cost << endl;
    }

    return 0;
}