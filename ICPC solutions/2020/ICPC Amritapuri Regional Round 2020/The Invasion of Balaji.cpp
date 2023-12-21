#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    
    while(t--){
        int n,q,i;
        cin>>n>>q;
        vector<ll>U(n);
        vector<ll>T(n);
        for(i=0;i<n;i++)
            cin>>U[i];
        for(i=0;i<n;i++){
            cin>>T[i];
            if(T[i]<0)
                T[i] = 0;
        }
        vector<ll>lasti(n);
        vector<ll>firsti(n);
        lasti[0] = U[0];
        for(i=1;i<n;i++)
            lasti[i] = max(lasti[i-1]+U[i],U[i]);
        firsti[n-1] = U[n-1];
        for(i=n-2;i>=0;i--){
            firsti[i] = max(U[i],U[i]+firsti[i+1]);
        }
        if(n==1){
            cout<<max(0ll,(U[0]) +(T[0]*q))<<endl;
        }
        else{
            ll max1 = max(0ll,U[0] + (T[0]*q) + (max(0ll,firsti[1])));
            for(i=1;i<=n-2;i++){
                ll val = U[i] +(T[i]*q) + max(0ll,firsti[i+1])+max(0ll,lasti[i-1]);
                max1 = max(max1,val);
            }
            ll val = (U[n-1]) +(T[n-1]*q)+max(lasti[n-2],0ll);
            max1 = max(max1,val);
            cout<<max1<<endl;
        }
        
    }

   return 0;
}