#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
int main(){
   ll t;
   cin>>t;
   while(t--){
       string s;
       cin>>s;
       stack<char> st;
       for(ll i=0;i<s.length();i++){
           if(st.empty()||st.top()!=s[i]){
               st.push(s[i]);
           }else{
               st.pop();
           }
       }
       cout<<st.size()<<endl;
   }
   return 0;
}