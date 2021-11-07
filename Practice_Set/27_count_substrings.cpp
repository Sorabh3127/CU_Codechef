#include<bits/stdc++.h>
#define pb push_back
#define mod  998244353
#define ll long long 
using namespace std;

int main(){ 
   int t;
   cin>>t;
   while(t--){
       string s;
       ll n,k,q;
       cin>>n>>k>>q;  
       cin>>s;
       int count0=0,count1=0;
       ll far[n+1];
       int j=0;
      
       for(int i=1;i<=n;i++){
           while(j<=n && count0<=k && count1<=k){
               j+=1;
               
               if(j>n)
               break;
               
               if(s[j-1]=='1')
               count1++;
               else
               count0++;
           }
           far[i]=j;
           if(s[i-1]=='0') count0--;
           else count1--;
        }
         ll sumfar[n+1];
        sumfar[0]=0;
        for(int i=1;i<=n;i++)
        sumfar[i]=sumfar[i-1]+far[i];
        
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            ll k1=l-1,k2=r+1;
            while(k2-k1>1){
                ll km=k1+k2;
                km/=2;
                
                if(far[km]<=r)
                k1=km;
                else
                k2=km;
            }
            
            ll ans=sumfar[k1]-sumfar[l-1]+(r-k1)*(r+1)-(r*(r+1))/2+(l*(l-1))/2;
            cout<<ans<<endl;
        }
    }
}