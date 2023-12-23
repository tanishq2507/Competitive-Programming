#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

void Dijkstra(vector<vector<pair<int,int>>>&adj_mat,int src,vector<ll>&dist_list,int n){
    multiset<pair<ll,int>>mset;
    mset.insert({0,src});
    vector<bool>selected(n,false);
    dist_list[src] = 0;
    while(!mset.empty()){
        pair<ll,int>p = *(mset.begin());
        mset.erase(mset.begin());
        if(selected[p.second])
            continue;
        selected[p.second] = true;
        for(auto &it:adj_mat[p.second]){
            int node = it.first;
            int w = it.second;
            if(w+p.first<dist_list[node]){
                dist_list[node] = w+p.first;
                mset.insert({dist_list[node],node});
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    //cin>>t;
    int xxx=1;
    
    while(t--){
        int n,m,i;
        cin>>n>>m;
        std::vector<ll>dist_list(n,LLONG_MAX);
        vector<vector<pair<int,int>>>adj_mat(n);
        for(i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            adj_mat[u].push_back({v,w});
        }
        Dijkstra(adj_mat,0,dist_list,n);
        for(i=0;i<n;i++)
            cout<<dist_list[i]<<" ";
        cout<<endl;
        
    }

   return 0;
}