#include<stdio.h>
#include<iostream>
using namespace std;
 struct Node{
 	char data;
 	int next;
 }node[100001];

 int main(){
 	int head,n;
 	cin>>head>>n;
 	int addr;
 	for(int i=0;i<n;i++){
 		cin>>addr;
		cin>>node[addr].data>>node[addr].next;
	}
	addr=head;
    int sum[100]={0};
	for(int i=0;i<n;i++){
		int temp = node[addr].data;
        sum[temp]++;
        addr=node[addr].next;
	}
	double number;
    for(char j='A';j<='Z';j++){
		int temp = j;
		if(sum[temp]!=0){
			number = (sum[temp]*1.0/n)*100;
			printf("%c %.2lf%%\n",j,number);
		}
	}
 }

