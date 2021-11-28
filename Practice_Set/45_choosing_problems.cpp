#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;

ld ori[300001];
ld a[300001];
ld s[300001];
int n;

void calcs()
{
    s[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
}

ld sum(int l, int r)
{
    if (l == 0)
        return s[r];
    else
        return s[r] - s[l - 1];
}

const ld eps = 1e-8;

struct PBDS
{
    tree<pair<ld, int>, null_type, less<pair<ld, int>>, rb_tree_tag, tree_order_statistics_node_update> t;
    int timer;

    PBDS() { timer = 0; }
    void insert(ld x)
    {
        t.insert(mp(x, timer));
        timer++;
    }

    int lower(ld x)
    {
        return t.order_of_key(mp(x, -1));
    }

    void del(ld x) //make sure x exists
    {
        pair<ld, int> tmp = (*t.find_by_order(lower(x)));
        t.erase(tmp);
    }

    int higher(ld x)
    {
        int tmp = lower(x);
        return (int(t.size()) - tmp);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    ll k;
    cin >> n >> l >> r >> k;
    for (int i = 0; i < n; i++)
        cin >> ori[i];
    ld lo = 0;
    ld hi = ld(1e9);
    while (hi - lo > eps)
    {
        ld mid = (lo + hi) * ld(0.5);
        for (int i = 0; i < n; i++)
        {
            a[i] = ori[i] - mid;
        }
        calcs();
        /*
    for(int i = 0; i < n; i++)
    {
      cerr<<a[i]<<' ';
    }
    cerr<<'\n';
    for(int i = 0; i < n; i++)
    {
      cerr<<s[i]<<' ';
    }
    cerr<<'\n';
    */
        PBDS t;
        t.insert(0);
        ll cnt = 0; //count subsegments <= mid
        for (int i = l - 1; i < n; i++)
        {
            if (i >= r)
            {
                if (i > r)
                    t.del(s[i - r - 1]);
                else
                    t.del(ld(0));
            }
            //cerr<<i<<' '<<t.t.size()<<'\n';
            cnt += t.higher(s[i]);
            t.insert(s[i - l + 1]);
            //cerr<<i<<' '<<cnt<<'\n';
        }
        //cerr<<fixed<<setprecision(12)<<mid<<' '<<cnt<<'\n';
        if (cnt >= k)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    cout << fixed << setprecision(12) << hi << '\n';
}