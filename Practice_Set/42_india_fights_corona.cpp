#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define f(n) for(ll i=0;i<n;i++)
#define pb push_back
#define iPair pair<ll, pair<ll,ll>>
#define en '\n'
#define yes cout<<"Yes"<<en;
#define no cout<<"No"<<en;
typedef long long ll;
typedef long double ld;
ld PI=2*acos(0.0);
int main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        ll n,m,k,a,b,x,c;cin>>n>>m>>k;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > >pq;
        vector<ll> distance(n+1,1e18);
        vector<bool> visited(n+1,0);
        f(k)
        {
            cin>>x>>c;
            pq.push({c,x});
            distance[x]=c;
        }
        vector<pair<ll,ll>> edges[n+10];
        f(m)
        {
            cin>>a>>b>>c;
            edges[a].push_back({b,c});
            edges[b].push_back({a,c});
        }
        while(pq.size()){
            ll ver = pq.top().second;
            pq.pop();
            if(visited[ver])
                continue;
            visited[ver] = 1;
            for(auto it:edges[ver]){
                if(distance[ver] + it.second < distance[it.first])
                {
                    distance[it.first] = distance[ver] + it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
        rep(i,1,n+1)
            cout<<distance[i]<<" ";
        cout<<en;
    }
    return 0;
}


