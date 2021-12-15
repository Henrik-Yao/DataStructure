#include<bits/stdc++.h>
using namespace std;

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
}Tree,*LinkTree;

void Insert(Tree* &root,int x){
    if(root==NULL){
        root = (LinkTree)malloc(sizeof(Tree));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        if(x<=root->data) Insert(root->left,x);
        else Insert(root->right,x);
    }
}

void Pre(LinkTree root){
    if(root==NULL) return;
    else {
        cout<<root->data<<" ";
        Pre(root->left);
        Pre(root->right);
    }
}

int main(){
    LinkTree BTree = NULL;
    int n;
    cin>>n;
    while(n!=0){
        Insert(BTree,n);
        cin>>n;
    }
    Pre(BTree);
    return 0;
}
