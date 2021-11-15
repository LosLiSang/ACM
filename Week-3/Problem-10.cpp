#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//由于要排序，需要用结构体保存节点的 下标
typedef struct node{
	int index;
	int f; //邻居个数
}Node;
//比较函数。从大到小排序
bool cmp(const Node n1,const Node n2){
	return n1.f > n2.f;
}
//打印图
void print_map(int arr[10][10],int m){
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if(j)
				cout <<  " "<<arr[i][j] ;
			else
				cout <<arr[i][j];
		}
		cout << endl;
	}
}
Node nodes[10];
int map[10][10];
 
int main(){
	int n,m;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		memset(map,0,sizeof(map)); //初始化为0
		for(int i=0; i<m;i++){
			scanf("%d",&nodes[i].f);
			nodes[i].index = i;
		}
		int flag = 0;//是否可以构成图
		for(int i=0; i<m; i++){
			if(flag)
				break;
			sort(nodes+i,nodes+m, cmp); //循环排序
			for(int j=0; j<nodes[i].f; j++){ //后面的依次减1
				nodes[i+j+1].f --;
				if(nodes[i+j+1].f < 0){
					flag = 1;
					break;
				}
				map[nodes[i].index][nodes[i+j+1].index] = 1; //同时更新图
				map[nodes[i+j+1].index][nodes[i].index] = 1; //对称更新
			}
 
		}
		if(flag)
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			print_map(map,m);
		}
		cout << endl;
 
	}
	return 0;
}