#include<iostream>  
#include<queue>  
#include<malloc.h>
using namespace std;  
  
typedef struct node{  
    char data;  
    struct node *L;  
    struct node *R;  
}Node,*LinkNode;  
  
queue<LinkNode> Q;  
  
LinkNode Init(){  
    char temp;  
    cin>>temp;  
    if(temp=='@') return NULL;  
    LinkNode T = (LinkNode)malloc(sizeof(Node));  
    T->data = temp;  
    T->L = Init();  
    T->R = Init();  
    return T;  
}  
  
void level(LinkNode T){  
    queue<LinkNode> Q;  
    if(T==NULL) return;  
    Q.push(T);  
    while(!Q.empty()){  
        LinkNode temp = Q.front();  
        Q.pop();  
        cout<<temp->data;  
        if(temp->L!=NULL){  
            Q.push(temp->L);  
        }  
        if(temp->R!=NULL){  
            Q.push(temp->R);  
        }  
    }  
}  
  
int main(){  
    int n;  
    cin>>n;  
    while(n--){  
        LinkNode T = Init();  
        level(T);  
        cout<<endl;  
    }  
    return 0;  
}  
