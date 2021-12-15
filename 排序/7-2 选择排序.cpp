#include<iostream>  
using namespace std;  
int main()  
{  
    int n;  
    cin>>n;  
    int a[n];  
    for(int i=0;i<n;i++){  
        cin>>a[i];  
    }  
    for(int i=0;i<n;i++){  
        int index=i;  
        for(int j=i;j<n;j++){  
            if(a[index]>a[j])index=j;  
        }  
        int temp=a[index];  
        a[index]=a[i];  
        a[i]=temp;  
        if(i==n-1){  
            cout<<"sorted array: ";  
            for(int j=0;j<n;j++){  
                cout<<a[j]<<" ";  
            }  
              
        }  
        else{  
            cout<<"step "<<i+1<<": ";  
            for(int j=0;j<n;j++){  
                cout<<a[j]<<" ";  
            }  
            cout<<endl;  
        }  
    }  
    return 0;  
}  
