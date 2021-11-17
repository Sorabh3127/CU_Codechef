
#include<bits/stdc++.h>
using namespace std;

//@Himanshu_nobee

#define f(i,s,e) for(long long i=s;i<e;i++)
#define endl "\n"
#define ll long long

int t;
int main()
{
    //@Himanshu_nobee
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //@Himanshu_nobee
        ll n,m;
        cin>>n>>m;
        ll a[n]; f(i,0,n) cin>>a[i];
        sort(a,a+n);
        int i=0;
        int j=n-1;
        queue<ll> q;
        while(m--)
        {
            int x;
            cin>>x;
            ll ans ;
            for (;i<x;i++)
            {
                if(j>=0&&(q.empty()||a[j]>=q.front())){
                    ans = a[j];j--;
                }
                else {
                    ans=q.front();
                    q.pop();
                }
                q.push(ans/2);
            }
            cout<<ans<<endl;
        }
    }

