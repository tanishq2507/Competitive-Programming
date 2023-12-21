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
ll mod_add(ll a,ll b){
    return((a%MOD +b%MOD)%MOD);
}
ll mod_expo(ll a,ll b){
    if(a==0)
        return(0);
    if(b==0 or a==1)
        return(1);
    ll result = 1;
    if(b%2==1){
            result = (result%MOD *a%MOD)%MOD;
            b = b-1;
        }
        ll x = mod_expo(a,b/2)%MOD;
        return((  (result*x)%MOD  *x)%MOD);
    
    }
   ll mod_mult(ll a,ll b){
    return((a%MOD *b%MOD)%MOD);
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    
    while(t--){
        int n,i;
        cin>>n;
        vector<int>list1(2*n);
        map<int,int>mp;
        map<int,int>temp;
        for(i=0;i<2*n;i++){
            cin>>list1[i];
            
        }
        sort(list1.begin(),list1.end());
        int val = list1[0]+list1[2*n-1];
        int f=0;
        for(i=0;i<n;i++){
            if(list1[i]+list1[2*n-1-i]!=val){
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"PERFECT"<<endl;
        }
        else{
            cout<<"IMBALANCED"<<endl;
        }
    }

   return 0;
}