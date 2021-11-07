#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int Size = 1e5;
lli n, w, l, res, h[Size + 10], r[Size + 10];

void ReadData() {
	cin >> n >> w >> l;
	for (lli i = 1; i <= n; i++)
		cin >> h[i] >> r[i];
}

bool Check(lli Month) {
	lli tmp = 0;
	for (lli i = 1; i <= n; i++) {
		lli tmp1 = h[i] + r[i] * Month;
		if (tmp1 >= l)
			tmp += tmp1;
		
		if (tmp >= w)
			return true;
	}
	
	return tmp >= w;
}

void Solve() {
	res = 0;
	lli L = 0, R = 1e18;
	
	//bSearch
	while (L <= R) {
		lli mid = L + (R - L) / 2;
		if (Check(mid)) {
			res = mid;
			R = mid - 1;
		}
		else
			L = mid + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	ReadData();
	Solve();
	cout << res;
}