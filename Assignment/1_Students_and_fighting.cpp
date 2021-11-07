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
       int n;
       cin>>n;
       vi a(n);
       rep(i,0,n){
           cin>>a[i];
       }
       int mx=*max_element(a.begin(),a.end());
       int c=0;
       for(int i=0;i<n;i++){
           if(a[i]==mx){
               c++;
           }
       }
       if(c>1){
           cout<<"fight:("<<endl;
       }else{
           cout<<"peace:)"<<endl;
       }
   }
   return 0;
}