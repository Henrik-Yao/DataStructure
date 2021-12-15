#include<bits/stdc++.h>  
using namespace std;  
struct mydata  
{  
    int x;  
    int y;  
    int value;  
};  
bool cmp(mydata a,mydata b){  
    if(a.y!=b.y) return a.y<b.y;  
    else return a.x<b.x;  
}  
int main(){  
    mydata temp[100];  
    int m,n,t;  
    cin>>m>>n>>t;  
    for(int i=0;i<t;i++){  
        cin>>temp[i].x>>temp[i].y>>temp[i].value;  
    }  
    sort(temp,temp+t,cmp);  
    for(int i=0;i<t;i++){  
        cout<<temp[i].y<<" "<<temp[i].x<<" "<<temp[i].value<<endl;  
    }  
    return 0;  
}  
