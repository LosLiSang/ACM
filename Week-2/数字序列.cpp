#include<iostream>
#include<math.h>
using namespace std;

// void print(int *list){
//     int len = sizeof(list) / sizeof(int);
//     cout << len;
//     int size = len;
//     while(len--){
//         cout << " " << list[size - len + 1];
//     }
// }

int main(){
    int n, A, B;
    int *list;
    while(cin >> A >> B >> n){
        if (A == 0 && B == 0 && n == 0) break;
        bool flag = true;
        int n_1 = 1, n_2 = 1, count = 0;
        do{
            int temp = n_2;
            n_2 = n_1;
            n_1 = (n_1 * A + temp * B) % 7;
            count++; 
            if(count + 2 == n){
                cout << n_1 << endl;
                flag = false;
            }
        }while(n_1 != 1 || n_2 != 1);
        // cout << count << endl;
        if(flag){
            list = new int[count];
            list[1] = 1, list[2] = 1, n_1 = 1, n_2 = 1;
            int i = 3;
            do{
                // if(count + 1 == n) break;
                list[i % count] = (n_1 * A + n_2 * B) % 7;
                n_2 = n_1;
                n_1 = list[i % count];
                i++;
                // cout << n_1 << " " << n_2 << endl;
            }while(n_1 != 1 || n_2 != 1);
            cout << list[n % count] << endl;
        }
    }
    return 0;
}



// int main(){
//     long long n, A, B;
//     int *list;
//     while(cin >> A >> B >> n){
//         if (A == 0 && B == 0 && n == 0) break;
        
//         int n_1 = 1, n_2 = 1, count = 0;
//         // do{
//         //     int temp = n_2;
//         //     n_2 = n_1;
//         //     n_1 = (n_1 * A + temp * B) % 7;
//         //     count++; 
//         // }while(n_1 != 1 || n_2 != 1);
//         // cout << count << endl;
//         list = new int[1000];
//         list[1] = 1, list[2] = 1, n_1 = 1, n_2 = 1;
//         int i = 3;
//         do{
//             // if(count + 1 == n) break;
//             list[i] = (n_1 * A + n_2 * B) % 7;
//             n_2 = n_1;
//             n_1 = list[i];
//             i++;
//             // cout << n_1 << " " << n_2 << endl;
//         }while(n_1 != 1 || n_2 != 1);
//         i = i - 3;
//         list[0] = list[i];
//         // cout << i <<endl;
//         // print(list);
//         cout << list[n % i] << endl;
//     }
//     return 0;
    
// }