#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
int maxEvenSubarray(vi a, int N)
{
    int ans = 0;
    int count = 0;
     for (int i = 0; i < N; i++) {
        if (a[i] % 2 == 0) {
            count++;
            ans = max(ans, count);
        }
        else {
            count = 0;
        }
    }
     ans = max(ans, count);
    return ans;
}
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
        cout<<maxEvenSubarray(a,n)<<endl;
   }
   return 0;
}