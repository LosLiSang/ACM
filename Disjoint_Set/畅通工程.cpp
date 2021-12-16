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

int N, M;

int list[MAX_INPUT];

int ufind(int x){
    int t = x;
    while(t != list[t])
        t = list[t];
    int itr = x, r = x;
    while(itr != list[itr]){
        r = itr;
        itr = list[itr];
        list[r] = t;
    }
    return t;
}

bool merge(int x, int y){
    int tx = ufind(x);
    int ty = ufind(y);
    if(tx == ty) return false;
    list[tx] = ty;
    return true;
}

void init(int n){
    for(int i = 1; i <= n; i++)
        list[i] = i;
}

int main(){
    while(cin >> N && N){
        cin >> M;
        init(N);
        int a, b;
        int cnt = N-1;
        for(int i = 0; i < M; i++){
            scanf("%d%d", &a, &b);
            if(merge(a, b)){
                cnt--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}