
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl "\n"
void print_list(vector<int>&clist){
    for(int i=0;i<clist.size();i++)
        std::cout << clist[i] << " ";
    cout<<endl;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        string s;
        cin>>s;
        int i,n;
        n = s.size();
        int f1=0,f2=0,ind1=-1;
        for(i=0;i<n;i++){
            if(s[i]=='M'){
                f1=1;
                ind1 = i;
                break;
            }
        }
        if(f1){
            for(i=ind1+1;i<n;i++){
                if(s[i]=='U'){
                    f2=1;
                    break;
                }
                    
            }
        }
        if(f1 && f2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
            
    }

   return 0;
}

