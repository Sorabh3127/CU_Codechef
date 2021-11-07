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
       int n,sum=0,sumo=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   for(int i=0;i<n;i++)
	   {
	       if(i%2==0)
	       {
	           sum+=a[i];
	       }
	       else
	       {
	           sumo+=a[i];
	       }
	       
	   }
	   if(sum>sumo)
	   cout<<sum<<endl;
	   else
	   cout<<sumo<<endl;

   }
   return 0;
}