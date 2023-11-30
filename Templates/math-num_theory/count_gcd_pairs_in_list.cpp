ll count_gcd_pairs(int num,vector<ll>&dp,int n,vector<ll>& cnt){
    //count number of pairs having gcd num in a list,all elements is list are <=n
    if(dp[num]!=-1)
        return(dp[num]);
    ll sum1=0;
    ll x=num,k=1;
    while(x<=n){
        sum1 += cnt[x];
        k+=1;
        x = num*k;
    }
    
    ll res = (sum1*(sum1-1))/2;
    x=num*2;
    k=2;
    
    while(x<=n){
        res = res - helper(x,dp,n,cnt);
        k+=1;
        x = num*k;
    }
    return(dp[num] = res);
    
}