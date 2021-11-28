#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
int cmp(pair<int,pair<int,int>> fr,pair<int,pair<int,int>> sc)
{
	if(fr.second.first>sc.second.first)
	return true;
	else if(fr.second.first==sc.second.first)
	{
		if(fr.second.second<sc.second.second)
		return true;
	}
	return false;
}

int main() {
	FASTIO;
	int n,h,x;
	cin>>n>>h;
	map<int,pair<int,int>> mp;
	set<int> s;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>x;
		mp[x].first+=1;
		if(s.find(x)==s.end()){
		mp[x].second=i;
		s.insert(x);
		}
	}
	vector<pair<int,pair<int,int>>> v;
	for(auto x : mp)
	v.push_back(x);
	sort(v.begin(),v.end(),cmp);
	for(auto x : v)
	{
		int res=x.second.first;
		while(res--){
			cout<<x.first<<" ";
		}
	}
	return 0;
}