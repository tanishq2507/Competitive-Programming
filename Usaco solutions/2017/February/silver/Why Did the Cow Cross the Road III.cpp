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
void dfs_matrix(int i,int j,set<vector<int>>&set1,vector<vector<bool>>&visited, vector<vector<bool>>&is_cow,int &n,int &cnt){

    if(i<0 || j<0 || i>n-1 || j>n-1 ){
        return;
    }
    
    if(visited[i][j]==true)
        return;
    
    if(is_cow[i][j]==true)
        cnt+=1;
    visited[i][j] = true;
    
    if(i+1<n && set1.find({i,j,i+1,j}) == set1.end())
        dfs_matrix(i+1,j,set1,visited,is_cow,n,cnt);
    
    if(i-1>=0 && set1.find({i,j,i-1,j}) == set1.end())
        dfs_matrix(i-1,j,set1,visited,is_cow,n,cnt);

    if(j+1<n && set1.find({i,j,i,j+1}) == set1.end())
        dfs_matrix(i,j+1,set1,visited,is_cow,n,cnt);
    
    if(j-1<n && set1.find({i,j,i,j-1}) == set1.end())
        dfs_matrix(i,j-1,set1,visited,is_cow,n,cnt);
    
}





int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
        
	freopen("countcross.in","r",stdin); 
	freopen("countcross.out","w",stdout);
	
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,k,r,i,j;
        cin>>n>>k>>r;
        set<vector<int>>set1;
        for(i=0;i<r;i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            x1--;
            y1--;
            x2--;
            y2--;
            set1.insert({x1,y1,x2,y2});
            set1.insert({x2,y2,x1,y1});
    
        }
        vector<pair<int,int>>cows(k);
        vector<vector<bool>>is_cow(n,vector<bool>(n,false));
        for(i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            cows[i]={x,y};
            is_cow[x][y] = true;
        }
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<int>cows_count;
        for(i=0;i<k;i++){
            int x = cows[i].first;
            int y = cows[i].second;
            int c1=0;
            if(visited[x][y]==false){
                dfs_matrix(x,y,set1,visited,is_cow,n,c1);
                cows_count.push_back(c1);
            }
            
        }
        int ans=0;
        
        for(i=0;i<cows_count.size();i++){
            for(j=i+1;j<cows_count.size();j++){
                ans+=cows_count[i]*cows_count[j];
            }
        }
        cout<<ans<<endl;
}
   return 0;
}







