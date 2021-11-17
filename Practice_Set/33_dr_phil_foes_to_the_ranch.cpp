#include <bits/stdc++.h>
using namespace std;

int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     long int t;
     cin>>t;
     while(t--)
     {
         stack <long int>st;
         long int j,p=-1,i,n;
         cin>>n;
         long int a[n];
         int b[n]={0};
         for(i=0;i<n;i++)
            {
                cin>>a[i];
                a[i]--;
            }
         for(i=0;i<n;i++)
         {
             if(b[a[i]])
             {
                 if(st.top()==a[i])
                 {
                     do
                     {
                         cout<<st.top()+1<<" ";
                         st.pop();
                         
                     }while(!st.empty() && b[st.top()]==2);
                 }
                 else 
                   b[a[i]]++;
             }
             if(!b[a[i]])
             {
                 for(j=p+1;j<a[i];j++)
                 {
                     b[j]=1;
                     st.push(j);
                 }
                 b[a[i]]=1;
                 cout<<a[i]+1<<" ";
                 p=a[i];
             }
             
         }
         
         if(!st.empty())
         {
             while(!st.empty())
               {
                   cout<<st.top()+1<<" ";
                   st.pop();
               }
         }
         cout<<"\n";
     }
     
     return 0;
 }