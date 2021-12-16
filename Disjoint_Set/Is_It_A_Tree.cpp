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

int ulist[MAX_INPUT];

void show(){
    for(int i = 1; i <= 8; i++){
        printf("%d ", ulist[i]);
    }
    printf("\n");
}

int ufind(int x){
    if(ulist[x] == -1){
        ulist[x] = x;
        return x;
    }
    if(ulist[x] == x) return x;
    return ufind(ulist[x]);
}

bool merge(int a, int b){
    int x = ufind(a);
    int y = ufind(b);
    // printf("%d %d %d %d\n", a, b, x, y);
    if(x == y) return false;
    // a是子节点，而b是父节点
    if(b == y && a != x) return false;
    ulist[a] = b;
    return true;
}

void init(){
    memset(ulist, -1, sizeof(ulist));
}

int main(){
    init();
    int x, y;
    int cnt = 1;
    int maxn = 0;
    int flag = 1;
    while(cin >> x >> y){
        if(x < 0 && y < 0) return 0;
        if(x == 0 && y == 0){
            if(flag){
                printf("Case %d is a tree.\n", cnt);
            }else{
                printf("Case %d is not a tree.\n", cnt);
            }
            init();
            maxn = 0;
            flag = 1;
            cnt++;
            continue;
        }
        maxn = max(x, maxn);
        maxn = max(y, maxn);
        if(!merge(y, x)){
            flag = 0;
        }
        // show();
    }
    return 0;
}