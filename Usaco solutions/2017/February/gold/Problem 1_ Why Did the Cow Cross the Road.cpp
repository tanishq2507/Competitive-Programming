#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

void Dijkstra(vector<vector<int>>&mat,int n,int T,vector<vector<ll>>&dist_list){
    
    int dx[] = {0,0,1,-1,0,0,3,-3,2,2,-2,-2,1,-1,1,-1};
    int dy[] = {-1,1,0,0,3,-3,0,0,1,-1,1,-1,2,2,-2,-2};
    
   
    
    multiset<pair<ll,pair<int,int>>>mset;
    mset.insert({0,{0,0}});
    vector<vector<bool>>selected(n,vector<bool>(n,false));
    dist_list[0][0] = 0;
    while(!mset.empty()){
        pair<ll,pair<int,int>>p = *(mset.begin());
        mset.erase(mset.begin());
        int dis = p.first;
        int x = p.second.first;
        int y = p.second.second;
        if(selected[x][y])
            continue;
        selected[x][y] = true;
        for(int i=0;i<16;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<n){
            
                ll w = mat[newx][newy] + 3*T;
                if(w+dist_list[x][y]<dist_list[newx][newy]){
                    dist_list[newx][newy] = w+dist_list[x][y];
                    mset.insert({dist_list[newx][newy],{newx,newy}});
                }
            }
        }
        int manhat_dist = n-1-x +n-1-y;
        if(manhat_dist<3){
            if(dist_list[x][y]+manhat_dist*T<dist_list[n-1][n-1])
                dist_list[n-1][n-1] = dist_list[x][y]+manhat_dist*T;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("visitfj.in","r",stdin); 
    freopen("visitfj.out","w",stdout);
    
    int t=1;
    //cin>>t;
    int xxx=1;
    
    while(t--){
        int n,T,i,j;
        cin>>n>>T;
        
        vector<vector<ll>>dist_list(n,vector<ll>(n,1e18));
         
        vector<vector<int>>mat(n,vector<int>(n));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        Dijkstra(mat,n,T,dist_list);
        cout<<dist_list[n-1][n-1]<<endl;
        
    }

   return 0;
}