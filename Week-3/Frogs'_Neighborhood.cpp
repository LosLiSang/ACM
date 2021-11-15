#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int T;

struct data{
    int id;
    int count;
    int all;
    int i;
    int neibor[21];
}list[21];

bool cmp(struct data d1, struct data d2){
    return d1.count > d2.count;
}

bool cmp_id(struct data d1, struct data d2){
    return d1.id < d2.id;
}


int main(){
    cin >> T;
    int N;
    while(T--){
        cin >> N;
        int sum = 0;
        for(int i = 0; i < N; i++){
            cin >> list[i].count;
            list[i].all = list[i].count;
            list[i].id = i + 1;
            sum += list[i].count;
            list[i].i = 0;
            for(int j = 0; j < 21; j++){
                list[i].neibor[j] = 1000;
            }
        }
        if(sum & 1) {
            cout << "NO" << endl << endl;
            continue;
        }
        sort(list, list + N, cmp);
        // for(int i = 0; i < N; i++){
        //     cout << list[i].count  << " ";
        // }
        int count = N;
        for(int i = 0; i < N; i++){
            if(list[i].count == 0) count--;
        }
        while(count && count > list[0].count){
            for(int i = 0; i < list[0].count; i++){
                list[i+1].count -= 1;
                if(list[i+1].count == 0) count -= 1;
                list[i+1].neibor[list[i+1].i++] = list[0].id;
                list[0].neibor[list[0].i++] = list[i+1].id;
            }
            // sort(list[0].neibor, list[0].neibor + list[0].all);
            list[0].count = 0;
            count -= 1;
            sort(list, list + N, cmp);



            // for(int i = 0; i < N; i++){
            //     int k = 0;
            //     for(int j = 0; j < N; j++){
            //         if(list[i].neibor[k] == j + 1){
            //             cout << 1 << " ";
            //             k++;
            //         }else{
            //             cout << 0 << " ";
            //         }
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            // cout << count << endl;
        }
        // for(int i = 0; i < N; i++){
        //     cout << list[i].id << " " << list[i].all << " " << list[i].itr;
        //     cout << endl;
        // }
        if(count != 0) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            sort(list, list + N, cmp_id);
            for(int i = 0; i < N; i++){
                int k = 0;
                sort(list[i].neibor, list[i].neibor + list[i].all);
                for(int j = 0; j < N; j++){
                    if(list[i].neibor[k] == j + 1){
                        cout << 1 << " ";
                        k++;
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
