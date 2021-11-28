#include<bits/stdc++.h>
using namespace std;

#define ipair pair<long long int,long long int>

long long int M=100000000000000;
long long  int dijk (int st, int end, vector<pair<int, int> > G[], int n) {

    vector<long long int> values(n,M);
	vector<bool> isInMst(n,0);
	priority_queue< ipair, vector< ipair >, greater< ipair > > pq;
	pq.push(make_pair(0,0));
	values[0]=0;
	long long int ans=0,temp,store,store2,i;
	while(!pq.empty())
	{

		temp=pq.top().second;
		if(temp==end)
		break;
		pq.pop();
		isInMst[temp]=true;
		for(i=0;i<G[temp].size();i++)
		{
			store=G[temp][i].first;
			store2=G[temp][i].second;
			if(isInMst[store]==false&&values[store]>store2+values[temp])
			{
				values[store]=store2+values[temp];
				pq.push(make_pair(values[store],store));
			}
		}
	}
	if(values[end]==100000000000000)
	values[end]=-1;
	return values[end];
}

int main()
{
    int t, n, m, i, j, x, y;
    cin >> n >> m;
    vector<int> h(n + 1), c(n + 1);
    vector<pair<int, int> > G[2 * n + 2];
    for (i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (i = 1; i <= n; i++) {
        cin >> c[i];
        G[i].push_back (make_pair (n + i, c[i]));
        G[n + i].push_back (make_pair (i, c[i]));
    }
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        if (h[x] <= h[y])
            G[x].push_back (make_pair (y, 0));
        if (h[x] >= h[y])
            G[n + x].push_back (make_pair (n + y, 0));
        if (h[y] <= h[x])
            G[y].push_back (make_pair (x, 0));
        if (h[y] >= h[x])
            G[n + y].push_back (make_pair (n + x, 0));
    }
    G[0].push_back(make_pair (1, c[1]));
    G[0].push_back(make_pair (n + 1, c[1]));
    G[n].push_back(make_pair (2 * n + 1, 0));
    G[2 * n].push_back(make_pair (2 * n + 1, 0));
    cout << dijk(0, 2 * n + 1, G, 2 * n + 2)<<endl;
    return 0;
}
