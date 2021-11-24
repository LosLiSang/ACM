#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#define MAX 0x3f3f3f3f
#define MIN INT16_MIN
#define MAX_INPUT 30
using namespace std;

long long target;
string L;
int vis[MAX_INPUT];
int res[5];
long long common;
bool flag = 0;

void dfs(int step){
    // cout << common << " " << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " " 
    //     << res[4] << " " << step << endl;
    if(common == target && step == 6) flag = 1;
    if(step > 5) return;
    if(flag) return;
    for(int i = 0; i < L.length(); i++){
        if(!vis[i]){
            vis[i] = 1;
            res[step - 1] = L[i] + 1 - 'A';
            common += pow(-1, step+1) * pow(res[step - 1], step);
            dfs(step + 1);
            if(flag) return;
            common -= pow(-1, step+1) * pow(res[step - 1], step);
            res[step - 1] = 0;
            vis[i] = 0;
        }
    }
}

int main(){
    while(cin >> target >> L && (target || L != "END")){
        // sort(L, L+L.length());
        memset(vis, 0, sizeof(vis));
        common = 0;
        flag = 0;
        dfs(1);
        if(flag){
            for(int i = 0; i < 5; i++)
                cout << char(res[i] - 1 + int('A'));
            cout << endl;
        }else cout << "NO" << endl;
    }

    return 0;
}