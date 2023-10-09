#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#include <iostream>


ll find_req_inc(ll num1,ll d){
    if(num1%d==0)
        return(0);
    ll val = d - num1%d;
    return(val);
}
//000 - do not have multiples of a,b,c
//001 - have only multiple of a
//010 - have only multiple of b
//100 - have only multiple of c
//011 - have multiples of a and b
//101 - have multiples of a and c
//110 - have multiples of b and c
//111 - have multiples of a and b and c
ll helper(int ind,int curr_state, ll lcm_ab,ll lcm_bc,ll lcm_ac,ll lcm_abc,vector<ll>& list1,ll &a,ll &b,ll &c,vector<vector<ll>>&dp){
    if(ind==list1.size()){
        if(curr_state==7)
            return(0);
        else
            return(1e18+1);
    }
    if(dp[ind][curr_state]!=-1)
        return(dp[ind][curr_state]);
    ll req_a = find_req_inc(list1[ind],a);
    ll req_b = find_req_inc(list1[ind],b);
    ll req_c = find_req_inc(list1[ind],c);
    ll req_ab = find_req_inc(list1[ind],lcm_ab);
    ll req_bc = find_req_inc(list1[ind],lcm_bc);
    ll req_ac = find_req_inc(list1[ind],lcm_ac);
    ll req_abc = find_req_inc(list1[ind],lcm_abc);
    
    ll res = 1e18+1;
    res = min(res,req_a+helper(ind+1,curr_state|1 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_b+helper(ind+1,curr_state|2 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_c+helper(ind+1,curr_state|4 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_ab+helper(ind+1,curr_state|1|2 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_ac+helper(ind+1,curr_state|1|4 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_bc+helper(ind+1,curr_state|2|4 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,req_abc+helper(ind+1,curr_state|1|2|4 ,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    res = min(res,helper(ind+1,curr_state,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp));
    if(res>1e18)
        res = 1e18+1;
    return(dp[ind][curr_state] = res);

}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
    
    int t=1;
    //cin>>t;
    //int xxx=1;
    while(t--){
    ll n,a,b,c,i;
    cin>>n>>a>>b>>c;
    
    vector<ll>list1(n);
    for(i=0;i<n;i++)
        cin>>list1[i];
    
    ll lcm_ab = (a*b)/__gcd(a,b);
    ll lcm_ac = (a*c)/__gcd(a,c);
    ll lcm_bc = (b*c)/__gcd(b,c);
    ll lcm_abc = (lcm_ab*c)/__gcd(lcm_ab,c);
    //cout<<lcm_ac<<endl;
    vector<vector<ll>>dp(n,vector<ll>(8,-1));
    ll ans = helper(0,0,lcm_ab,lcm_bc,lcm_ac,lcm_abc,list1,a,b,c,dp);
    cout<<ans<<endl;
    
    }
       

      

   return 0;
}







