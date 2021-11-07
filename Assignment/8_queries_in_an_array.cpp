#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<ll>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    while (q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        ll count = 0;
        // l--;
        for (int i = l-1; i < r; i++)
        {
            if (a[i] >= x)
            {
                break;
            }
            count++;
        }
        cout << (r-l+1)-count << endl;
    }
    return 0;
}