#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define vi vector<int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
bool sortbysec(pair<int, int> &a, pair<int, int> &b)
{
   return (a.first < b.first);
}
int main()
{
      int n, m;
      cin >> n >> m;
      vector<pair<int, int>> v1;
      vector<pair<int, int>> v2;

      for (int i = 0; i < n; i++)
      {
         int a, b;
         cin >> a >> b;
         v1.pb(make_pair(a, b));
      }
      for (int i = 0; i < m; i++)
      {
         int a, b;
         cin >> a >> b;
         v2.pb(make_pair(a, b));
      }
      sort(v1.begin(), v1.end(), sortbysec);
      sort(v2.begin(), v2.end(), sortbysec);
      int i1 = 0, i2 = 0, ans = 0;
      while (1)
      {
         if (v1[i1].second < v2[i2].first || v2[i2].second < v1[i1].first)
         {
            if (v1[i1].second < v2[i2].first)
               i1++;
            else
               i2++;
         }
         else
         {
            int maxi = max(v1[i1].first, v2[i2].first);
            int mini = min(v1[i1].second, v2[i2].second);
            ans += abs(maxi - mini);
            if (v1[i1].second == v2[i2].second)
            {
               i1++;
               i2++;
            }
            else if (v1[i1].second < v2[i2].second)
               i1++;
            else
               i2++;
         }
         if (i1 == n || i2 == m)
            break;
      }
      cout << ans<<endl;
   return 0;
}