#include<iostream>  
#include<malloc.h> 
using namespace std;  
  
typedef struct node{  
    char data;  
    struct node *L;  
    struct node *R;  
}Node,*LinkNode;  
  
LinkNode Init(){  
    char temp;  
    cin>>temp;  
    if(temp=='#') return NULL;  
    LinkNode T = (LinkNode)malloc(sizeof(Node));  
    T->data = temp;  
    T->L = Init();  
    T->R = Init();  
    return T;  
}  
  
void PreOrder(LinkNode T){  
    if(T){  
        cout<<T->data;  
        PreOrder(T->L);  
        PreOrder(T->R);  
    }  
}  
  
void MiddleOreder(LinkNode T){  
    if(T){  
        MiddleOreder(T->L);  
        cout<<T->data;  
        MiddleOreder(T->R);  
    }  
}  
  
void PostOrder(LinkNode T){  
    if(T){  
        PostOrder(T->L);  
        PostOrder(T->R);  
        cout<<T->data;  
    }  
}  
  
int Leaf(LinkNode T){  
    if(T==NULL) return 0;  
    else if(T->L==NULL&&T->R==NULL) return 1;  
    else return Leaf(T->L)+Leaf(T->R);  
}  
  
int main(){  
    LinkNode T = Init();  
    if(!T){  
        cout<<Leaf(T);  
        return 0;  
    }  
    PreOrder(T);  
    cout<<endl;  
    MiddleOreder(T);  
    cout<<endl;  
    PostOrder(T);  
    cout<<endl;  
    cout<<Leaf(T);  
    return 0;  
} 
