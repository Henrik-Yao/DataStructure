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

LinkTree FindMax(LinkTree root){
    if(root==NULL) return NULL;
    if(root->right!=NULL) return FindMax(root->right);
    return root;
}

LinkTree FindMin(LinkTree root){
    if(root==NULL) return NULL;
    if(root->left!=NULL) return FindMin(root->left);
    return root;
}

LinkTree Remove(int x,Tree* &root){
    if(root==NULL) return NULL;
    if(x<root->data) root->left=Remove(x,root->left);
    else if(x>root->data) root->right=Remove(x,root->right);
    else if (root->left!=NULL)
    {
        root->data=FindMax(root->left)->data;
        root->left=Remove(root->data,root->left);
    }
    else if(root->right!=NULL){
        root->data=FindMin(root->right)->data;
        root->right=Remove(root->data,root->right);
    }
    else root = NULL;
    return root;
}

int main(){
    LinkTree BTree = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Insert(BTree,x);
    }
    int m;
    cin>>m;
    int count=n-m;
    while(m--){
        int x;
        cin>>x;
        Remove(x,BTree);
    }
    queue<LinkTree> Q;
    Q.push(BTree);
    while (!Q.empty())
    {
        LinkTree temp = Q.front();
        if(temp->left!=NULL)Q.push(temp->left);
        if(temp->right!=NULL)Q.push(temp->right);
        Q.pop();
        if(count==1)cout<<temp->data;
        else {
            cout<<temp->data<<" ";
            count--;
        }
    }
    cout<<endl;
    

    return 0;
}
