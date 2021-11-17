#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t,n,m,i,j;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        cin>>m;
        vector<ll>v(m);
        for(i=0; i<m; i++){
            cin>>v[i];
        }
        queue<ll>q;
        for(i=0; i<n; i++){
            if(s[i]=='1'){
                q.push(i);
            }
        }
        ll ans=0;
        map<ll,ll>mp;
        for(i=0; i<m; i++){
            
            ll id = v[i]-1;
            mp[id]++;
            
            ll c = q.size();
            while(c>0){
                
                ll top = q.front();
                q.pop();
                
                if(mp[top]==0 && s[top-1] =='0' ){
                    q.push(top-1);
                    s[top-1]='1';
                }
                if(mp[top+1]==0 && s[top+1]=='0'){
                    q.push(top+1);
                    s[top+1]='1';
                }
                
                c--;
            }
        }
        //cout<<s<<" < == s \n";
        for(i=0; i<n; i++){
            if(s[i]=='1' ){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}