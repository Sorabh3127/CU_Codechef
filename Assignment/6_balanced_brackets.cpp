#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
int main(){
   int t;
   cin>>t;
   while(t--){
       int n,o=0,e=0;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='(')
	        o++;
	        else
	        e++;
	    }
	    if(o<e) cout<<2*o <<endl;
	    else if(o>e) cout<<2*e <<endl;
	    else if(o==e)cout<<2*o <<endl;
   }
   return 0;
}