#include <iostream>
#include<stack>
using namespace std;

int main() {
	// your code goes here
	int n,t,a;
	stack<int>stack;
	cin>>t;
	while(t--)
	{
	    cin>>a;
	    if(a==1)
	    {
	        cin>>n;
	        stack.push(n);
	        
	    }
	    else
	    {   if(!stack.empty()){
	        cout<<stack.top()<<endl;
	        stack.pop();}
	        else
	        cout<<"kuchbhi?"<<endl;
	    }
	}
	return 0;
}