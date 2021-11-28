#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<long double,vector<long double>> maps;
        int n;
        cin>>n;
        while(n--)
        {
            long double x;
            long double y;
            long double z;
            cin>>x>>y>>z;
            if(y==0)
            {
                maps[pow(10,10)].push_back(z/x);
            }
            maps[x/y].push_back(z/y);
        }
        int p=INT_MIN;
        for(auto i=maps.begin();i!=maps.end();i++)
        {
            vector<long double> v=i->second;
            set<long double> s;
            for(int j=0;j<v.size();j++)
            {
                s.insert(v[j]);
            }
            p=max(p,(int)s.size());
        }
        cout<<p<<"\n";
    }
    
    
}