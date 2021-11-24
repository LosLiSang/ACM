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

int N;
int res[MAX_INPUT];
int vis[MAX_INPUT];
int count_ = 0;

bool isPrime(int n){
    for(int i = 2; i <= (n / 2) + 1; i++)
        if(n % i == 0) return false;
    return true;
}

void dfs(int step){ 
    // printf("%d %d %d %d %d %d\n", step, res[0], res[1], res[2], res[3], res[4], res[5]);
    if(step == N){
        if(isPrime(res[step-1] + res[step-2]) && isPrime(res[step-1] + res[0])){
            if(res[0] == 1){
                for(int i = 0; i < N - 1; i++)
                    cout << res[i] << " ";
                cout << res[N-1] << endl;
            }
            return;
        }
        else
            return;
    }
    if(step != 0 && !isPrime(res[step-1] + res[step-2])) return;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            vis[i] = 1;
            res[step] = i + 1;
            dfs(step + 1);
            res[step] = 0;
            vis[i] = 0;
        }

    }

}

int main(){
    while(cin >> N){
        // cout << isPrime(6) << endl;
        memset(vis, 0, sizeof(vis));
        count_++;
        cout << "Case " << count_ << ":" << endl;
        dfs(0);
        cout << endl;
    }
    return 0;
}