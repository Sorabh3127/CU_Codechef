#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, B, C;
ll X, x, y, p, q, r, cooks;
vector<pair<ll, ll> > dish;
vector<pair<ll, pair<ll, ll> > > town;

bool check(ll totalCooks) {
	int b = 0;
	int c = 0;

	B = dish.size();
	C = town.size();

	while(b<B && c<C) {
		if(dish[b].first == town[c].first) {
			if(totalCooks >= town[c].second.first) {
				totalCooks += town[c].second.second;
			}
			totalCooks -= dish[b].second;
			b++;
			c++;
		} else if(dish[b].first < town[c].first) {
			totalCooks -= dish[b].second;
			b++;
		} else {
			if(totalCooks >= town[c].second.first) {
				totalCooks += town[c].second.second;
			}
			c++;
		}
		if(totalCooks < 0) {
			return false;
		}
	}

	while(b<B) {
		totalCooks -= dish[b].second;
		b++;
		if(totalCooks < 0) {
			return false;
		}
	}


	return totalCooks > 0;
}

void solve() {
	ll group=-1, lo=1, mid, hi=cooks+1;

	while(lo<=hi) {
		mid = (lo+hi)/2;
		if(check(mid)) {
			group = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}

	printf("%lld\n", group);
}

int main() {

	scanf("%d", &T);

	while(T--) {
		scanf("%d", &X);
		scanf("%d", &B);

		cooks = 0;
		dish.clear();
		town.clear();

		while(B--) {
			scanf("%lld %lld", &x, &y);
			dish.push_back({x, y});
			cooks += y;
		}

		scanf("%d", &C);
		while(C--) {
			scanf("%d %lld %lld", &p, &q, &r);
			town.push_back({p, {q, r}});
		}

		solve();
	}

	return 0;
}