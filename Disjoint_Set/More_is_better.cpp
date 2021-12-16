#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 100010
using namespace std;

int n;

int ulist[MAX_INPUT];
// int ucount[MAX_INPUT];

// void show(){
//     for(int i = 1; i <= 2 * n; i++){
//         cout << ulist[i] << " ";
//     }
//     for(int i = 1; i <= 2 * n; i++){
//         cout << ucount[i] << " ";
//     }
//     cout << endl;
// }

int ufind(int x){
    if(ulist[x] == x) return x;
    ulist[x] = ufind(ulist[x]);
    return ulist[x];
}

void merge(int x, int y){
    int v = ufind(x);
    int w = ufind(y);
    ulist[v] = w;
    // ucount[w] += 1;
    ufind(x);
    ufind(y);
}

void init(){
    for(int i = 1; i <= 2 * n; i++){
        ulist[i] = i;
    }
    // memset(ucount, sizeof(ucount), 0);
}

int main(){
    while(cin >> n){
        init();
        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            merge(a, b);   
            // show();
        }
        int maxt = 0;
        for(int i = 1; i <= 2 * n; i++){
            int t = 0;
            for(int j = 1; j <= 2 * n; j++){
                if(ufind(j) == i) t++;
            }
            maxt = max(t, maxt);
        }
        cout << maxt << endl;
    }
    return 0;
}