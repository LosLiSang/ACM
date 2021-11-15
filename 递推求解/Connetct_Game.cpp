#include<iostream>
#include<string.h>
using namespace std;
int a[104][100];//保存卡特兰数
int b[100];//卡特兰数的位数
void catalan() //求卡特兰数模板
{
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for(i = 2; i <= 100; i++)
    {
        for(j = 0; j < len; j++) //乘法
        a[i][j] = a[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(j = 0; j < len; j++) //处理相乘结果
        {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry) //进位处理
        {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(j = len-1; j >= 0; j--) //除法
        {
            temp = carry*10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!a[i][len-1]) //高位零处理
            len--;
        b[i] = len;
    }
}
int main()
{
	int n,i,j;
	catalan();
	while(cin>>n)
	{
		if(n==-1) break;
		for(i=b[n]-1;i>=0;i--)
			cout<<a[n][i];
		cout<<endl;
	}
	return 0;
}