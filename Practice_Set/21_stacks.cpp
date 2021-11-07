#include<bits/stdc++.h>
using namespace std;

int t, n, a[100005];

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		vector < long long > s;
		for(int i=0; i<n; i++){
			auto ite=upper_bound(s.begin(), s.end(), a[i]);
			if(ite!=s.end())	*ite=a[i];
			else	s.push_back(a[i]);
		}
		cout << s.size() << " ";
		for(int i=0; i<s.size(); i++){
			cout << s[i] << " ";
		}
		cout << endl;
	}
}