#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="/";
        string wd,cmd;
        for(int i=0;i<n;i++){
            cin>>wd;
            if(wd=="pwd"){
                if(s=="/")
                    cout<<s<<endl;
                else cout<<s<<"/"<<endl;
            }
            if(wd == "cd"){
                cin>>cmd;
                if(cmd[0]!='/'){
                    if(s=="/") s+=cmd;
                    else s=s+"/"+cmd;
                }
                else{
                    s=cmd;
                }
                while(true){
                        long long int k=s.find('.');
                        if(k==-1)
                            break;
                        string s1=s.substr(0,k-1);
                        string s2=s.substr(k+2,s.size()-k-2);
                        k=s1.rfind("/");
                        s1=s1.substr(0,k);
                        s=s1+s2;
                    }
            }
        }
    }
}