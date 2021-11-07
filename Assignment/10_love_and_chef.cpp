#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define ln '\n'

bool check_work(vector<ll> &v, ll k, ll max_Work)
{
    ll previous_Work = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (previous_Work > k || previous_Work > max_Work)
            return false;
        ll rem = max_Work - previous_Work;
        previous_Work = max(v[i] - rem, 0ll);
    }
    return (previous_Work == 0);
}

pair<ll, ll> minimum_maximum(vector<ll> &v)
{
    pair<ll, ll> result = make_pair(LONG_MAX, LONG_MIN);
    for (auto el : v)
    {
        result.first = min(result.first, el);
        result.second = max(result.second, el);
    }
    return result;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    std::vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    pair<ll, ll> range = minimum_maximum(v);

    ll l = range.first, r = range.second;
    ll ans = r;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check_work(v, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << ln;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll test_cases = 1;

    cin >> test_cases;
    while (test_cases--)
        solve();
    return 0;
}