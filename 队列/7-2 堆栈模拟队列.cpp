#include<iostream>  
#include<stack>  
#include<queue>  
using namespace std;  
int main(){  
    stack<int> s1;  
    stack<int> s2;  
    int n1,n2,item;  
    cin>>n1>>n2;  
    if(n1>n2){  
        int t = n1;  
        n1 = n2;  
        n2 = t;  
    }  
    char c;  
    cin>>c;  
    while(c!='T'){  
        if(c=='A'){  
            cin>>item;  
            if(s1.size()==n1&&s2.size()>0)cout<<"ERROR:Full"<<endl;  
            else if(s1.size()<n1){  
                s1.push(item);  
            }  
            else if(s1.size()==n1&&s2.size()==0){  
                while(!s1.empty()){  
                    s2.push(s1.top());  
                    s1.pop();  
                }  
                s1.push(item);  
            }  
        }  
        else if(c=='D'){  
           if(!s2.empty()){  
               cout<<s2.top()<<endl;  
               s2.pop();  
           }  
           else if(s2.empty()&&!s1.empty()){  
               while(!s1.empty()){  
                    s2.push(s1.top());  
                    s1.pop();  
                }  
                cout<<s2.top()<<endl;  
                s2.pop();  
            }  
            else if(s1.empty()&&s2.empty())cout<<"ERROR:Empty"<<endl;  
        }  
        cin>>c;  
    }  
  
  
    return 0;  
}  
