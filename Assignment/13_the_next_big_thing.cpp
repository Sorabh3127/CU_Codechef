#include<bits/stdc++.h>
using namespace std;
//    Om : A Peaceful Soul
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while ((!st.empty()) && (v[i] > v[st.top()]))
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }
    vector<int> nge = NGE(vect);
    for (i = 0; i < n; i++)
        cout << ((nge[i] == (-1)) ? -1 : vect[nge[i]]) << " ";
}