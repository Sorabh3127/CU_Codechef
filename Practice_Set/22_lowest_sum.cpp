#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--){
		long long n, k;
		cin >> n >> k;
		vector<long long> a;
		vector<long long> b;
		long long temp, i;
		
		for (i = 0; i < n; i++){
			cin >> temp;
			a.push_back(temp);
		}
		for (i = 0; i < n; i++){
			cin >> temp;
			b.push_back(temp);
		}	
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		priority_queue<ll> pq;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (pq.size() < 10000)
					pq.push(a[i] + b[j]);
			    else if(pq.top() > a[i] + b[j]){
				    pq.pop();
				    pq.push(a[i] + b[j]);
			    }
			    else
			    	break;
			}
		}
		vector<ll> res;
	    while(!pq.empty()){
		    res.push_back(pq.top());
		    pq.pop();
	    }
	    reverse(res.begin(), res.end());
    	while(k--){
    		ll q;
    		cin >> q;
    		cout << res[q - 1] << "\n";
	    }
	}
	return 0;
}