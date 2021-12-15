#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main(){
	char s[500];
	stack<char> st;
	cin>>s;
	string flag = "True";
	int len = strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
			st.push(s[i]);
		else{
			st.pop();
		} 
	}
	if(!st.empty())flag="False";
	cout<<flag;
}
