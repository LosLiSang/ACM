#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include <iomanip>
using namespace std;

struct List{
    double javaBean;
    double money;
    double com;
};


bool cmp(List A, List B){
    return (A.com > B.com);
}


int main(){
    int M;
    int N;
    struct List *list = new List[1000];
    // cout.setf(ios::fixed);
    // cout.precision(3);
    while(cin >> M >> N){
        if(M == -1 && N == -1) break;
        // list = new List[N];
        for(int i = 0; i < N; i++){
            cin >> list[i].javaBean >> list[i].money;
            list[i].com = 1.0 * list[i].javaBean / list[i].money;
        }
        sort(list, list + N, cmp);
        // int i = 0;
        double res = 0, used = 0;
        for(int i = 0; i < N; i++){
            if(used >= M) break;
            if(M > list[i].money + used){
                res += list[i].javaBean;
                used += list[i].money;
            } else {
                res += list[i].com * (M - used);
                break;
            }
            // cout << res << endl;
        }
        // delete list;
        // cout << res << endl;
        // cout << fixed << setprecision(3) << res << endl;
        printf("%.3lf\n", res);
    }

    return 0;
}