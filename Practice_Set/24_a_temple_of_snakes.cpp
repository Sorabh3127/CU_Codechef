#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    
	int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        ll sum=0;

        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];sum+=arr[i];
        }

        vector<ll> left(n), right(n);

        left[0]=1;
        for(ll i=1;i<n;i++)
        {
            left[i]=min(left[i-1]+1, arr[i]);
        }

        right[n-1]=1;

        for(ll i=n-2;i>=0;i--)
        {
            right[i]= min(right[i+1]+1, arr[i]);
        }

        ll peak=-1;

        for(ll i=0;i<n;i++)
        {
            peak=max( peak, min(left[i], right[i]));
        }

        cout<<sum- peak*peak<<endl;
    }
}