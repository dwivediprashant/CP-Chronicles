//https://codeforces.com/contest/1997/submission/355939588

// Short Problem Statement:
// Given a string having characters (,),_ . At every odd place we have the character '_'.
// We need to place either '(' or ')' in place of '_' such that the string becomes valid 
// parentheses and the sum between the pairs () is minimized.

// Approach:
// We take a variable cnt and a stack.
// We use a greedy approach as whenever we see a ')' we try to pair it up with the nearest '('.
// We use stack to store the indices at which character is '('.
// We use cnt to identify the character that to be placed at '_' position.
// if cnt is 0 and charater is '_' we place '(' and increment cnt. And push the ind to stack.
// if character is '_' or ')' and decrement cnt. And pop the stack and cal the dist.
// if character is '(' and increment cnt. And push ind to stack.
// Everytime we calc distance, we add it to the variable ans and finally return ans.

// Time Complexity: O(n).
// Space Complexity: O(n).


#include<bits/stdc++.h>
using namespace std;

int f(int n,string &s){
    int cnt=0;
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(cnt==0 && s[i]=='_'){
                cnt++;
                st.push(i);
            }else if(s[i]=='_' || s[i]==')'){
                cnt--;
                ans += (i-st.top());
                st.pop();
            }else{
                cnt++;
                st.push(i);
            }
        }
        return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        cout<<f(n,s)<<endl;
    }
}



