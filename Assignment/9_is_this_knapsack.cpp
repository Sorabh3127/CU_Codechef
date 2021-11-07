#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
ll answer(vi a,ll n,ll c,ll k){
   ll start=0,end=0;
   ll sum=0,ans=0;   
   while(start<n&&end<n){
      if(sum<k){
         sum+=a[end];
         end++;
      }
      else if(sum>c){
         sum-=a[start];
         start++;
      }
      else{
         ans=max(ans,end-start);
         sum+=a[end];
         end++;
      }
   }
   while(start<n){
      if(sum>=k&&sum<=c){
         ans=max(ans,end-start);
         break;
      }
      sum-=a[start];
      start++;
   }
   return ans;
}
int main(){
   ll t;
   cin>>t;
   while(t--){
      ll n,c,k;
      cin>>n>>c>>k;
      vi a(n);
      rep(i,0,n){
         cin>>a[i];
      }
      cout<<answer(a,n,c,k)<<endl;
   }
   return 0;
}