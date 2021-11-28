#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1010, MOD = 1000000007;
typedef pair<ll, ll> pt;


ll GCD(ll a, ll b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

ll c3(ll a, ll b) {
    return (a + b - 1) / b;
}

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        int x = a.second - a.first + 1, y = b.second - b.first + 1;
        if (x == y)return a.first < b.first;
        return x > y;
    }
};


int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
int dis[100009];
bool vis[100009];

//bool valid(int x, int y) {
//    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
//}

void solve() {
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("window.in", "r", stdin);
#endif
    string s;
    cin >> s;

    int n = s.size();

    map<char, vector<int>> tmp;


    for (int i = 0; i < n; ++i) {
        tmp[s[i]].push_back(i);
    }

    queue<int> q;//index
    q.push(0);
    dis[0] = 0;
    vis[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int x = cur - 1, x2 = cur + 1;

        for (int i = 0; i < tmp[s[cur]].size(); ++i) {
            if (!vis[tmp[s[cur]][i]]) {
                vis[tmp[s[cur]][i]] = true;
                dis[tmp[s[cur]][i]] = dis[cur] + 1;
                q.push(tmp[s[cur]][i]);
            }
        }
        tmp[s[cur]].clear();

        if (x2 < n) {
            if (!vis[x2]) {
                vis[x2] = true;
                q.push(x2);
                dis[x2] = dis[cur] + 1;
            }
        }
        if (x >= 0) {
            if (!vis[x]) {
                vis[x] = true;
                q.push(x);
                dis[x] = dis[cur] + 1;
            }
        }

    }

    cout << dis[n - 1] << "\n";
    return 0;
}