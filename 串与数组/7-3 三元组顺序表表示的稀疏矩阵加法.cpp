#include<bits/stdc++.h>
using namespace std;
struct mydata
{
    int x;
    int y;
    int value;
}temp[100];
bool cmp(mydata a,mydata b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
bool add(mydata temp[],mydata one,int t){
    for(int i=0;i<t;i++){
        if(temp[i].x==one.x && temp[i].y==one.y){
            temp[i].value+=one.value;
            return true;
        }
    }
    return false;
}

int main(){
    int m,n,t1,t2,count=0;
    cin>>m>>n>>t1>>t2;
    for(int i=0;i<t1;i++){
        cin>>temp[i].x>>temp[i].y>>temp[i].value;
    }
    mydata one;
    for(int i=0;i<t2;i++){
        cin>>one.x>>one.y>>one.value;
        bool result = add(temp,one,t1);
        if(!result){
            temp[t1++]=one;
        }
    }
    sort(temp,temp+t1,cmp);
    for(int i=0;i<t1;i++){
        if(temp[i].value!=0){
            count++;
        }
    }
    cout<<m<<" "<<n<<" "<<count<<endl;
    for(int i=0;i<t1;i++){
        if(temp[i].value!=0){
            cout<<temp[i].x<<" "<<temp[i].y<<" "<<temp[i].value<<endl;
        }
    }
    return 0;
} 
