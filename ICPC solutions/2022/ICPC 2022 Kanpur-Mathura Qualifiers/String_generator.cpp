#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#include <iostream>

int helper(vector<vector<int>>&dp,string &s1,string &s2,int l,int r){
    if(l>r)
        return(1);
    if(dp[l][r]!=-1)
        return(dp[l][r]);
    else{
        int s1_ptr = r-l;
        int result=0;
        if(s2[l]==s1[s1_ptr])
            result = result|(helper(dp,s1,s2,l+1,r));
        if(result==0 && s2[r]==s1[s1_ptr])
            result = result|(helper(dp,s1,s2,l,r-1));
        return(dp[l][r] = result);
    }
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
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res = helper(dp,s1,s2,0,n-1);
        if(res==1)
            cout<<"Case "<<xxx++<<": YES"<<endl;
        else
            cout<<"Case "<<xxx++<<": NO"<<endl;
        
}
   return 0;
}







