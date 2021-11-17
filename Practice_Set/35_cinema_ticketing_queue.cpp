#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,ans[N];
deque<int> d[N];
set<int> s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.insert(x);
        d[x].push_back(i);
    }
    for(int i=1;i<=2*n;i++){
        auto it=s.upper_bound(i);
        if(it==s.begin())continue;
        it--;
        int p=d[*it].front();
        d[*it].pop_front();
        ans[p]=i;
        if(d[*it].empty())s.erase(it);
    }
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';
    cout<<'\n';

}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}