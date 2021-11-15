#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int C;

struct data{
    int price;
    int weight;
    int all;
} list[1001];


bool cmp(struct data d1, struct data d2){
    return d1.price < d2.price;
}

int main(){
    cin >> C;
    double money;
    int n;
    while(C--){
        cin >> money >> n;
        for(int i = 0; i < n; i++){
            cin >> list[i].price >> list[i].weight;
            list[i].all = list[i].price * list[i].weight;
        }
        sort(list, list+n, cmp);
        double res = 0, used = 0;
        for(int i = 0; i < n; i++){
            if(money <= used) break;
            if(money >= used + list[i].all){
                used += list[i].all;
                res += list[i].weight;
            }else{
                res += (money - used) / list[i].price;
                used = money;
            }

        }
        printf("%.2lf\n", res);
        // printf("%.2lf\n", res);
    }
    return 0;
}