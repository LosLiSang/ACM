#include<iostream>
// #include<math.h>
#include<algorithm>
using namespace std;


bool cmp(int a, int b){
    return a > b;
}
int T;

int main(){
    cin >> T;
    int list[1000];
    while(T--){
        int n;
        cin >> n; 
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> list[i];
            sum += list[i] % 2;
        }
        if(sum & 1){
            cout << "no" << endl;
            return 0;
        }
        sort(list, list + n, cmp);
        int i = 0, not_zero = n;
        do{ 
            if(not_zero - 1 < list[i]){
                cout << "no" << endl;
                return 0;
            }
            for(int j = 0; j < list[0]; j++){
                if(list[j + 1] == 1) not_zero -= 1;
                list[j + 1] -= 1;
            }
            list[0] = 0;
            sort(list, list + n, cmp);
            not_zero--;
            // n = not_zero;
            // i++;
            // for(int itr = 0; itr < n; itr++){
            //     cout << list[itr] << " ";
            // }
            // // cout << not_zero << endl;
            // cout << endl;
        }while(not_zero > 0);
    }
    cout << "yes" << endl;
    return 0;
}