/*
    Om :- A Peaceful Soul
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--){
	    int tr,dr,t=0,d=0;
	    cin>>tr;
	    int Tr[tr];
	    for(int i=0;i<tr;i++)
	        cin>>Tr[i];
	    cin>>dr;
	    int Dr[dr];    
	    for(int i=0;i<dr;i++)
	        cin>>Dr[i];
	    int ts,ds;
	    cin>>ts;
	    int Ts[ts];
	    for(int i=0;i<ts;i++)
	    {
	        cin>>Ts[i];
	        for(int j=0;j<tr;j++)
	        {
	            if(Tr[j]==Ts[i])
	            {
	                t++;
	                break;
	            }
	        }     
	    }
	    cin>>ds;
	    
	    int Ds[ds];    
	    for(int i=0;i<ds;i++)
	    {
	        cin>>Ds[i];  
	        for(int j=0;j<dr;j++)
	        {
	            if(Dr[j]==Ds[i])
	            {
	                d++;
	                break;
	            }     
	        }
	    }
	    if(t==ts && d==ds)
	        cout<<"yes\n";
	    else
	        cout<<"no\n";
	}

	return 0;
}
