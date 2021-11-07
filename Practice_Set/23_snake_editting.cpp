#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
#define mod 1000000007
#define F first
#define S second
#define ld long double
#define ll long long
#define inf 1e18
#define N 100013

void solve() {
    ll i, j;
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), pre(n);
    for(i=0;i<n;i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    pre[0]=a[0];
    for(i=1;i<n;i++)
        pre[i] = pre[i-1] + a[i];
    while(q--) {
        ll k;
        cin >> k;
        ll end = upper_bound(a.begin(), a.end(), k-1) - a.begin();
        ll ans = n - end;
        ll l=0, mx=end-1, r=end-1, ans1=0;
        while(l <= r) {
            ll mid=(l+r)/2;
            ll req=(mx-mid+1)*k, curr=0;
            if(mid==0)
                curr=pre[mid];
            else
                curr=pre[mx] - pre[mid-1];
            ll less=req-curr;
            if(less <= mid) {
                ans1 = mx-mid+1;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans+ans1<<"\n";
    }
}
int main() { 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for(int j=1; j<=tc; j++) {
        //cout << "Case #" << j << ": ";
        solve();
    }
    return 0;
}