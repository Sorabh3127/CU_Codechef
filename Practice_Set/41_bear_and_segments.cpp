#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;


pair<int, long long> bruteforce(vector<int> a, int mod) {
	vector<int> pref;
	pref.push_back(0);
	int sum = 0;
	for (int x: a) {
		sum = (sum + x) % mod;
		pref.push_back(sum);
	}
	int ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 0; j < i; j++) {
			int x = pref[i] - pref[j];
			if (x < 0) {
				x += mod;
			}
			ans = max(ans, x);
		}
	}
	long long res = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 0; j < i; j++) {
			int x = pref[i] - pref[j];
			if (x < 0) {
				x += mod;
			}
			if (x == ans) {
				res++;
			}
		}
	}
	return make_pair(ans, res);
}

pair<int, long long> smart(vector<int> a, int mod) {
	vector<int> pref;
	pref.push_back(0);
	int sum = 0;
	for (int x: a) {
		sum = (sum + x) % mod;
		pref.push_back(sum);
	}
	int ans = 0;
	set<int> st;
	st.insert(0);
	for (int i = 1; i <= a.size(); i++) {
		ans = max(ans, pref[i]);
		auto it = st.upper_bound(pref[i]);
		// Also mark the older error. 
		// Fail those solutions.
		if (it != st.end()) {
			ans = max(ans, pref[i] + mod - *it);	
		}
		st.insert(pref[i]);
	}
	long long res = 0;
	map<int, int> cnt;
	cnt[0]++;
	for (int i = 1; i <= a.size(); i++) {
		// pref[i] - pref[j] = ans
		if (pref[i] - ans >= 0) {
			res += cnt[pref[i] - ans];
		}
		// pref[i] - pref[j] + mod = ans
		// pref[j] = pref[i] + mod - ans
		res += cnt[pref[i] + mod - ans];
		cnt[pref[i]]++;
 	}
	return make_pair(ans, res);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, mod;
		scanf("%d %d", &n, &mod);
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		if (n <= 1000) {
			auto bans = bruteforce(a, mod);
			auto sans = smart(a, mod);
			cerr << bans.first << " " << bans.second << endl;
			cerr << sans.first << " " << sans.second << endl;
			assert(bans == sans);
		}
		auto sans = smart(a, mod);
		cout << sans.first << " " << sans.second << endl;
	}
	return 0;
}