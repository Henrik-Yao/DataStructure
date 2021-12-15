#include<iostream>  
#include<stack>  
using namespace std;  
int main(){  
    int n,k;  
    cin>>n>>k;  
    stack<int> result;  
    char num[6]= {'A','B','C','D','E','F'};  
    while(n){  
        int t = n%k;  
        result.push(t);  
        n /= k;  
    }  
    while(!result.empty()){  
        if(k==2||k==8){  
            int t = result.top();  
            cout<<t;  
            result.pop();  
        }  
        if(k==16){  
            int t = result.top();  
            if(t>9){  
                cout<<num[t-10];  
            }  
            else{  
                cout<<t;  
            }  
            result.pop();  
        }  
    }  
    cout<<endl;  
}  
