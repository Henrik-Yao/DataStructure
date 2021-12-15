#include<iostream>  
#include<queue>  
using namespace std;  
int main(){  
    queue<int> q;  
    int n;  
    cin>>n;  
    for(int i=0;i<n;i++){  
        int t;  
        cin>>t;  
        if(t==1){  
            int d;  
            cin>>d;  
            q.push(d);  
        }  
        else if(t==0){  
            if(q.empty()){  
                cout<<"invalid"<<endl;  
            }  
            else{  
                cout<<q.front()<<endl;  
                q.pop();  
            }  
        }  
    }  
    return 0;  
}  
