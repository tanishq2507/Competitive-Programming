#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#include <iostream>

void print_list(vector<int>&clist){
    for(int i=0;i<clist.size();i++)
        std::cout << clist[i] << " ";
    cout<<endl;
}

void dfs_matrix(int i,int j,vector<vector<int>>&ele_matrix,vector<vector<bool>>&visited,int &D,int n,int m){

    if(i<0 || j<0 || i>=n||j>=m){
        return;
    }
    
    if(visited[i][j]==true)
        return;
    visited[i][j] = true;
    if(i+1<n && abs(ele_matrix[i+1][j]-ele_matrix[i][j])<=D)
        dfs_matrix(i+1,j,ele_matrix,visited,D,n,m);
        
    if(i-1>=0 && abs(ele_matrix[i-1][j]-ele_matrix[i][j])<=D)
        dfs_matrix(i-1,j,ele_matrix,visited,D,n,m);
        
    if(j+1<m && abs(ele_matrix[i][j+1]-ele_matrix[i][j])<=D)
        dfs_matrix(i,j+1,ele_matrix,visited,D,n,m);
        
    if(j-1>=0 && abs(ele_matrix[i][j-1]-ele_matrix[i][j])<=D)
        dfs_matrix(i,j-1,ele_matrix,visited,D,n,m);
    
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
        
	freopen("ccski.in","r",stdin); 
	freopen("ccski.out","w",stdout);
	
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,m,val,i,j;
        cin>>n>>m;
        vector<vector<int>>ele_matrix(n,vector<int>(m));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>val;
                ele_matrix[i][j] = val;
            }
        }
        
        int stx=-1;
        int sty=-1;
        int x;
        vector<pair<int,int>>waypoints;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>x;
                if(x==1){
                    waypoints.push_back({i,j});
                    stx=i;
                    sty=j;
                }
            }
        }
        if(stx==-1)
            cout<<0<<endl;
        else{
            int low = 0;
            int high = 1e9;
            int ans = 1e9;
            while(low<=high){
                int mid = low +(high-low)/2;
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                dfs_matrix(stx,sty,ele_matrix,visited,mid,n,m);
                int flag=0;
                for(i=0;i<waypoints.size();i++){
                    int x = waypoints[i].first;
                    int y = waypoints[i].second;
                    if(visited[x][y]==false){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            cout<<ans<<endl;
        }
             
}
   return 0;
}







