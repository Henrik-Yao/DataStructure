#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Node{
    int number;
    struct Node *next;
}Node,*LinkList;

int main(){
    LinkList tail = (LinkList)malloc(sizeof(Node));
    tail->next = NULL;
    int n;
    scanf("%d",&n);
    while (n!=-1)
    {
        LinkList link = (LinkList)malloc(sizeof(Node));
        link->number = n;
        link->next = tail;
        tail = link;
        scanf("%d",&n);
    }
    while(tail&&tail->next!=nullptr)
    {
        printf("%d ",tail->number);
        tail=tail->next;
    }
    printf("\n");
    return 0;
}
