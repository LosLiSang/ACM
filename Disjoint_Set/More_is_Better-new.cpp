#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 10000005
using namespace std;

int ulist[MAX_INPUT];
int ucount[MAX_INPUT];

int ufind(int x){
    if(ulist[x] == x) return x;
    int t = x;
    // 找根
    while(t != ulist[t]){
        t = ulist[t];
    }
    int k = x, m;
    // 优化
    while(k != t){
        m = k;
        // 遍历
        k = ulist[k];
        // 直接连上根
        ulist[m] = t;
    }
    return t;
}

int merge(int x, int y){
    int tx = ufind(x);
    int ty = ufind(y);
    // tx 的父节点是ty
    // 如果两者的父节点不一致
    if(ty != tx){
        ulist[tx] = ty;
        // ty的节点数要加上tx的节点数
        ucount[ty] += ucount[tx];
    }
    // 返回最大的节点数 
    return ucount[ty];
}

void init(){
    for(int i = 0; i <= MAX_INPUT; i++){
        ulist[i] = i;
        ucount[i] = 1;
    }
    // memset(ucount, 1, sizeof(ucount));
}


int main(){
    int n, maxt = 0;
    while(scanf("%d",&n) != EOF){
        init();
        // 没有盆友组队，应该初始化为1
        maxt = 1;
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            int t = merge(a, b);
            maxt = max(maxt, t);
        }
        // cout << "?";
        cout << maxt << endl;
    }
    return 0;
}