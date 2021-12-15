#include<iostream>  
#include<queue>  
using namespace std;  
int main(){  
    queue<int> one;  
    queue<int> two;  
    int n,count=0;  
    cin>>n;  
    for(int i=0;i<n;i++){  
        int t;  
        cin>>t;  
        if(t%2==1){  
            one.push(t);  
        }else{  
            two.push(t);  
        }  
    }  
    while(!one.empty()||!two.empty()){  
        for(int i=0;i<2;i++){  
            if(!one.empty()){  
                if(count==n-1){  
                    cout<<one.front();  
                    one.pop();  
                }else{  
                    cout<<one.front()<<" ";  
                    one.pop();  
                    count++;  
                }  
            }  
        }  
        if(!two.empty()){  
            if(count==n-1){  
                cout<<two.front();  
                two.pop();  
            }else{  
                cout<<two.front()<<" ";  
                two.pop();  
                count++;  
            }  
        }  
    }  
    return 0;  
}  
