#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define modulo 1000000007
int main() {

	ll n, k, i;
    cin>>n>>k;
    ll A[n];
    stack<ll>stk;
    for(i=0; i<n; i++){
        cin>>A[i];
    }
    ll fearfull_ness=1;
    for(i=0; i<n; i++){
        while( !stk.empty() && A[stk.top()] > A[i] ){
            fearfull_ness = (fearfull_ness % modulo) * (i-stk.top()+1) % modulo;
    
            stk.pop();
        }
        stk.push(i);
    }
    cout<<fearfull_ness;
	return 0;
}