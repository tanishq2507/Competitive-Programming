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
ll helper(int dp1[][61][11][101][2],int tot_rem,int vi_rem,int b,int w,int turn,int inv6,int vout,int dp2[][61][11]){
    if(tot_rem<=0 && vi_rem<=0)
        return(1);
    if(tot_rem<=0 && vi_rem>0)
        return(0);
    if(w>=10 || b<=0 || (vout==1 && vi_rem>0))
        return(0);
    if(vi_rem<0)
        vi_rem = 0;
    if(vout==0 && dp1[tot_rem][b][w][vi_rem][turn]!=-1)
        return(dp1[tot_rem][b][w][vi_rem][turn]);
    if(vout==1 && dp2[tot_rem][b][w]!=-1)
        return(dp2[tot_rem][b][w]);
    ll res=0;
    if(vout==0){
    if(turn==0){
        if((b-1)%6!=0){
            res = mod_add(res,helper(dp1,tot_rem-1,vi_rem-1,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-2,vi_rem-2,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-4,vi_rem-4,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-3,vi_rem-3,b-1,w,1,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem-6,vi_rem-6,b-1,w,0,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem,vi_rem,b-1,w+1,1,inv6,1,dp2));
        }
        else{
            res = mod_add(res,helper(dp1,tot_rem-1,vi_rem-1,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-2,vi_rem-2,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-4,vi_rem-4,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-3,vi_rem-3,b-1,w,0,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem-6,vi_rem-6,b-1,w,1,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem,vi_rem,b-1,w+1,1,inv6,1,dp2));
        }
            

    }
    else{
        if((b-1)%6!=0){
            res = mod_add(res,helper(dp1,tot_rem-1,vi_rem,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-2,vi_rem,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-4,vi_rem,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-3,vi_rem,b-1,w,0,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem-6,vi_rem,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem,vi_rem,b-1,w+1,1,inv6,0,dp2));
        }
        else{
            res = mod_add(res,helper(dp1,tot_rem-1,vi_rem,b-1,w,1,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-2,vi_rem,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-4,vi_rem,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem-3,vi_rem,b-1,w,1,inv6,0,dp2));
            res = mod_add(res, helper(dp1,tot_rem-6,vi_rem,b-1,w,0,inv6,0,dp2));
            res = mod_add(res,helper(dp1,tot_rem,vi_rem,b-1,w+1,0,inv6,0,dp2));
        }
       
    }
     res = mod_mult(res,inv6);
    return(dp1[tot_rem][b][w][vi_rem][turn] = res%MOD);
    }
    else{
        res = mod_add(res,helper(dp1,tot_rem-1,vi_rem,b-1,w,1,inv6,1,dp2));
        res = mod_add(res,helper(dp1,tot_rem-2,vi_rem,b-1,w,1,inv6,1,dp2));
        res = mod_add(res,helper(dp1,tot_rem-4,vi_rem,b-1,w,1,inv6,1,dp2));
        res = mod_add(res,helper(dp1,tot_rem-3,vi_rem,b-1,w,1,inv6,1,dp2));
        res = mod_add(res, helper(dp1,tot_rem-6,vi_rem,b-1,w,1,inv6,1,dp2));
        res = mod_add(res,helper(dp1,tot_rem,vi_rem,b-1,w+1,1,inv6,1,dp2));
        
        res = mod_mult(res,inv6);
     return(dp2[tot_rem][b][w] = res%MOD);
    }
            
        
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    int dp1[151][61][11][101][2];
    int dp2[151][61][11];
    for(int i=0;i<151;i++){
            for(int j=0;j<61;j++){
                for(int k=0;k<11;k++){
                    for(int l=0;l<101;l++){
                        for(int m=0;m<2;m++){
                                dp1[i][j][k][l][m] = -1;
                        }
                    }
                }
            }
        }
    for(int i=0;i<151;i++){
        for(int j=0;j<61;j++){
            for(int k=0;k<11;k++){
                dp2[i][j][k]=-1;
            }
        }
    }
    while(t--){
        int n,b,w,x;
        cin>>n>>b>>w>>x;
        int inv6 = mod_expo(6,MOD-2);
        int ans = helper(dp1,n,100-x,b,w,0,inv6,0,dp2);
        cout<<ans<<endl;
    }

   return 0;
}