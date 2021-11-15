// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     while(n-- > 0){
//         int count;
//         cin >> count;
//         int max = 0, temp;
//         long long all = 0;
//         while(count-- > 0){
//             cin >> temp;
//             if (temp > max){
//                 all += max;
//                 max = temp;
//             }
//             else all += temp;
//         }
//         if (max - 1 <= all)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
 
int Arr[1000200];
 
int main()
{
	int t;
	int n;
	int val, biggest;
	long long rest;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d",&n);
		biggest = 0;
		rest = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&val);
			if(val > biggest)
			{
				biggest = val;
			}
			else
			{
				rest += val;
			}
		}
		if(biggest - 1 <= rest)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}