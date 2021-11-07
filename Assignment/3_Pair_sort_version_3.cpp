#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<ll>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
bool sortbysec(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.second == b.second)
    {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
    return (a.second > b.second);
}
int main()
{
    ll n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vi b(n);
    rep(i, 0, n)
    {
        cin >> b[i];
    }
    vector<pair<ll, ll>> p;
    rep(i, 0, n)
    {
        p.push_back(make_pair(a[i], b[i]));
    }
    sort(p.begin(), p.end(), sortbysec);
    //    sort(p.begin(),p.end());
    rep(i, 0, n)
    {
        cout << p[i].first << " " << p[i].second << " ";
    }
    cout << endl;
    return 0;
}