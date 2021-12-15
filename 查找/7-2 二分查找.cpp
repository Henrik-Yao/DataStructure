#include<iostream>  
#include<algorithm>  
using namespace std;  
int main(){  
    int n;  
    while (scanf("%d",&n)!=EOF)  
    {  
        int a[n];  
    for(int i=0;i<n;i++){  
        cin>>a[i];  
    }  
    sort(a,a+n);  
    for(int i=0;i<n-1;i++){  
        cout<<a[i]<<" ";  
    }  
    cout<<a[n-1]<<endl;  
    int m;  
    cin>>m;  
    while(m--){  
        int left=0,right=n-1,mid,x;  
        bool flag = false;    
        cin>>x;  
        while(left<=right){  
            mid=(left+right)/2;  
            if(a[mid]==x){  
                if(m==0){  
                    cout<<mid+1<<endl;  
                }  
                else cout<<mid+1<<" ";  
                flag = true;  
                break;  
            }   
            else if(a[mid]<x) left=mid+1;  
            else right=mid-1;  
        }  
        if(flag==false){  
            if(m==0){  
                cout<<"0"<<endl;  
            }     
            else {  
                cout<<"0 ";  
            }  
        }  
    }  
    }  
      
    return 0;  
}  
