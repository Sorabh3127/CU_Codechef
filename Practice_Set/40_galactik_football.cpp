#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

vector <ll> par;
vector <ll> rnk;

void init(ll n)
{
    par.resize(n);
    rnk.resize(n);

    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
}

ll find(ll a)
{
    if (par[a] == a)
        return a;

    par[a] = find(par[a]);
    return par[a];
}

void unio(ll a, ll b)
{
    ll para = find(a);
    ll parb = find(b);

    if (para == parb)
        return;

    if (rnk[para] < rnk[parb])
        par[para] = parb;
    else if (rnk[para] > rnk[parb])
        par[parb] = para;
    else
    {
        par[parb] = para;
        rnk[para] ++;
    }

}


void solve() {

    ll n, m;
    cin >> n >> m;

    init(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        a--;
        b--;

        unio(a, b);
    }

    vector <pair<ll, ll>> cost;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        if (a < 0)
            continue;

        cost.push_back({a, i});
    }

    sort(cost.begin(), cost.end());

    set <ll> st1, st2;

    ll sum = 0;

    debug(cost);

    ll first = 0;

    for (int i = 0; i < cost.size(); i++)
    {
        ll p = find(cost[i].second);

        if (i == 0)
            first = cost[i].first;

        debug(p);

        if (st1.find(p) == st1.end())
        {
            sum += cost[i].first;
            st1.insert(p);
        }

        debug(sum);
    }

    for (int i = 0; i < n; i++)
    {
        st2.insert(find(i));
    }

    if (cost.size() == 0 && st2.size() == 1)
    {
        cout << "0" << endl;
        return;
    }

    debug(st1);
    debug(st2);

    if (st2.size() == st1.size())
    {

        cout << sum - first + (st1.size() - 1) * first << endl;

        // if (st1.size() == 1 && *st1.begin() == *st2.begin())
        //     cout << "0" << endl;
        // else
        // {
        //     auto it1 = st1.begin();
        //     auto it2 = st2.begin();

        //     while (it1 != st1.end() && *it1 == *it2)
        //     {
        //         it1 ++;
        //         it2 ++;
        //     }

        //     if (it1 == st1.end())
        //         cout << sum << endl;
        //     else
        //         cout << "-1" << endl;
        // }
    }
    else
        cout << "-1" << endl;

    return;
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();

    int test = 1;
    //cin >> test;

    for (int i = 1; i <= test; i++)
    {
        solve();
    }
}