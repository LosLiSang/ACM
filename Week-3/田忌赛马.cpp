#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;

bool cmp(int a, int b){
    return a > b;
}


int main(){
    int tianji[1001];
    int king[1001];
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> tianji[i];
        for(int i = 0; i < n; i++)
            cin >> king[i];
        sort(tianji, tianji + n, cmp);
        sort(king, king + n, cmp);
        int score = 0;
        int t_i = 0, t_j = 0, k_i = 0, k_j = 0;
        int N = n;
        while(N--){
            if(tianji[t_i] > king[k_i]){
                t_i++, k_i++;
                score++;
            }else if(tianji[t_i] < king[k_i]){
                k_i++;
                t_j++;
                score--;
            }else{
                if(tianji[n-1-t_j] > king[n-1-k_j]){
                    score++;
                    t_j++;
                    k_j++;
                // cout << score * 200 << " " << t_j << " "<< k_j << endl;

                    // t_i++;
                    // k_i++;
                }else{
                    if(tianji[n-1-t_j] < king[k_i])
                         score--;                    
                    t_j++;
                    k_i++;
                }
            }

        }
        cout << score * 200 << endl;
    }
    return 0;
}