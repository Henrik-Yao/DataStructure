#include<bits/stdc++.h>  
using namespace std;  
char s[1000],t[1000];  
int Next[1000],sum[1000];  
int main(){  
    cin>>s;  
    cin>>t;  
    int tlen = strlen(t),slen = strlen(s),j = -1,k = 0,count=0;  
    for(int i=0;i<tlen;i++){  
        cin>>Next[i];  
    }  
    while(j<slen){  
        if(k==-1 || s[j] == t[k] || abs(s[j]-t[k])==32){  
            j++;  
            k++;  
        }  
        else k = Next[k];  
        if(k == tlen ){  
            sum[count++] = j-tlen+1;  
            //cout<<j-tlen+1<<endl;  
            int temp = Next[k-1];  
            j = j-Next[k-1]-1;      
            k = temp;  
        }  
    }  
    cout<<count<<endl;  
    for(int i=0;i<count-1;i++){  
        cout<<sum[i]<<endl;  
    }  
    cout<<sum[count-1];  
      
    return 0;  
}  
