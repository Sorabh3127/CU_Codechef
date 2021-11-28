#include <bits/stdc++.h>

using namespace std;

const long long N = 2e6 + 10, INF = 2e18 + 10;
long long T, n, m, b, y, w, par_dij[N], par_mst[N], sum_mst, sum_dij, dis[N], sz[N], lst[N];
vector<pair<long long, pair<long long, long long>>> edge;
vector<pair<long long, long long>> adj[N];
set<pair<long long, int>> st;
bool vis[N], ok;

bool cmp(pair<long long, pair<long long, long long>> a, pair<long long, pair<long long, long long>> b){//
	if(a.first < b.first){
		return 1;
	}
	return 0;
}

void Dijkstra(){//
	for(int i = 0; i < n; i++){//
		par_dij[i] = i;
		lst[i] = INF;
		dis[i] = INF;
	}
	st.insert({0, 0});
	par_dij[0] = dis[0] = lst[0] = 0;
	while(st.size()){//
		pair<long long, long long> z = *st.begin();
		st.erase(st.begin());
		long long u = z.second;
		long long mn_dis = z.first;
		vis[u] = 1;
		for(auto x : adj[u]){
			long long v = x.first;
			long long weight = x.second;
			if(mn_dis + weight < dis[v]){
				st.erase({dis[v], v});
				dis[v] = weight + mn_dis;
				lst[v] = weight;
				par_dij[v] = u;
				st.insert({dis[v], v});
			}else if(mn_dis + weight == dis[v] && lst[v] > weight){
				lst[v] = weight;
			}
		}
	}
	for(int i = 0; i < n; i++){//
		if(!vis[i] || lst[i] == INF){
			ok = 0;
		}
		sum_dij += lst[i];
	}
}

int get_par(long long u){//
	if(u == par_mst[u]){
		return u;
	}
	par_mst[u] = get_par(par_mst[u]);
	return par_mst[u];
}

void Union(long long u, long long v){//
	if(sz[u] > sz[v]){
		swap(u, v);
	}
	par_mst[u] = v;
	sz[v] += sz[u];
	sz[u] = 0;
}

void MST(){//
	for(int i = 0; i < n; i++){
		par_mst[i] = i;
		sz[i] = 1;
	}
	for(auto x : edge){
		long long U = get_par(x.second.first);
		long long V = get_par(x.second.second);
		long long W = x.first;
		if(U == V){
			continue;
		}
		Union(U, V);
		sum_mst += W;
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){//
		cin >> b >> y >> w;
		adj[b].push_back({y, w});
		adj[y].push_back({b, w});
		edge.push_back({w, {b, y}});
	}
	sort(edge.begin(), edge.end(), cmp);//
	ok = 1;
	Dijkstra();
	MST();
	if(sum_mst == sum_dij && ok){//
		cout << "YES\n";
	}else{
		cout <<  "NO\n";
	}
	for(int i = 0; i < n; i++){
		adj[i].clear();
		edge.clear();
		st.clear();
		dis[i] = INF;
		sz[i] = 1;
		par_dij[i] = par_mst[i] = i;
		sum_mst = sum_dij = vis[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--){
		solve();
	}
}