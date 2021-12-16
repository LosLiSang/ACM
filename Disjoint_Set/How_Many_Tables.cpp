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

class DisjointSet{
    public:
        int list[MAX_INPUT];
        int C;
        int set_count;
        int find(int x){
            if(list[x] == x) return x;
            list[x] = find(list[x]);
            return list[x];
        }
        bool merge(int a, int b){
            int ha = find(a);
            int hb = find(b);
            if(ha == hb) return false;
            set_count--;
            list[ha] = hb;
            return true;
        }
        void init(int c){
            C = c;
            set_count = c;
            for(int i = 1; i <= c; i++){
                list[i] = i;
            }
        }
        int count(){
            int res = 0;
            int head[C+1];
            // memset(vis, 0, sizeof(vis));
            for(int i = 1; i <= C; i++){
                int t = find(i);
                int flag = 1;
                for(int i = 0; i < res; i++){
                    if(head[i] == t){
                        flag = 0;
                        break;
                    } 
                }
                if(flag) head[res++] = t;
            }
            return res;
        }
};

// int list[MAX_INPUT];
int N;
int C, K;

int main(){
    cin >> N;
    DisjointSet djSet = DisjointSet();
    while(N--){
        cin >> C >> K;
        djSet.init(C);
        int a, b;
        int cnt = C;
        for(int i = 0; i < K; i++){
            cin >> a >> b;
            if(djSet.merge(a, b)){
                cnt--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}