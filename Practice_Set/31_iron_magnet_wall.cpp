#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    queue <int> qm, qi;
    int pos = 1, ans = 0;
    bool flag;
    for(auto c:s) {
        switch(c) {
            case 'X':
                while(!qm.empty())  qm.pop();
                while(!qi.empty())  qi.pop();
                break;

            case ':':
                pos ++;
                break;

            case 'I':
                flag = false;
                while(!qm.empty()) {
                    int a = qm.front();
                    qm.pop();
                    if(k+1-abs(pos-a) > 0) {
                        ans ++;
                        flag = true;
                        break;
                    }
                }
                if(!flag)   qi.push(pos);
                break;

            case 'M':
                flag = false;
                while(!qi.empty()) {
                    int a = qi.front();
                    qi.pop();
                    if(k+1-abs(pos-a) > 0) {
                        ans ++;
                        flag = true;
                        break;
                    }
                }
                if(!flag)   qm.push(pos);
                break;
        }
        pos ++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}