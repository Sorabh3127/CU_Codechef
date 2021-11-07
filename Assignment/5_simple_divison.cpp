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
	   int n,x,y;
	   cin>>n>>x>>y;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int count=0;
		for(int i=0;i<n;i++){
			if(a[i]<=x&&a[i]%y==0){
				count++;
			}
		}
		cout<<count<<endl;
   }
   return 0;
}