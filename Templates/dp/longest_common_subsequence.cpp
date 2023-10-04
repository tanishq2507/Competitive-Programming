int find_lcs(string &s,string &t,int from1,int from2,vector<vector<int>>&dp,vector<vector<int>>&dp2){
    if(from1>=s.size() || from2>=t.size()){
        return(0);
    }
    if(dp[from1][from2]!=-1)
        return(dp[from1][from2]);
    int result=0;
    if(s[from1]==t[from2]){
        result = 1+(find_lcs(s,t,from1+1,from2+1,dp,dp2));
        dp2[from1][from2]=2;
    }
    else{
        int x1 = find_lcs(s,t,from1+1,from2,dp,dp2);
        int x2 = find_lcs(s,t,from1,from2+1,dp,dp2);
        if(x1>=x2){
            result = x1;
            dp2[from1][from2]=0;
        }
            
        else{
            result = x2;
            dp2[from1][from2]=1;
        }
    }
    return(dp[from1][from2]=result);
}