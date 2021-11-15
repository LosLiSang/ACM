#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int T;

struct node{
    int score;
    int day;
    bool done = false;
};

bool cmp(struct node a, struct node b){
    if(a.day == b.day) return a.score < b.score;
    else return a.day < b.day; 
}

int main(){
    cin >> T;
    struct node list[1000];
    int res, sum, N;
    while(T--){
        sum = 0;
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> list[i].day;
        for(int i = 0; i < N; i++){
            cin >> list[i].score;
            sum += list[i].score;
            list[i].done = false;
        }

        sort(list, list + N, cmp);
        int now = list[N-1].day;
        // cout << list[0].score << endl;
        // cout << list[1].score << endl;
        // cout << list[2].score << endl;
        res = 0;
        while(now){
            int max = -1, max_i = 0;
            for(int i = N-1; list[i].day >= now; i--){
                if(list[i].done == false && max < list[i].score) {
                    max = list[i].score;
                    max_i = i;
                }
            }
            if(max != -1){
                // cout << max << " " << max_i << endl;
                list[max_i].done = true;
                res += max;
            }
            now--;
        }
        cout << sum - res << endl;
    }
    return 0;
}