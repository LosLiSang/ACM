#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n;

long long a[100];
long long b[100];

bool cmp(long long a, long long b){
    return a < b;
}


int main(){
    int n;
    while(cin >> n && n){
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n, cmp);
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(b, b+n, cmp);
        int a_score = 0, b_score = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]) a_score += 2;
            else if(a[i] < b[i]) b_score += 2;
            else{
                a_score += 1;
                b_score += 1;
            }
        }
        cout << a_score << " vs " << b_score << endl;
    }

    
    return 0;
}