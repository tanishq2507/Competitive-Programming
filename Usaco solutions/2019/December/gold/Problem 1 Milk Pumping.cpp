#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

void Dijkstra(vector<vector<pair<int,pair<int,int>>>>&adj_mat,int src,vector<ll>&dist_list,int n,int allowed_f){
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
            int w = it.second.first;
            int flowr = it.second.second;
            if(w+p.first<dist_list[node] && flowr>=allowed_f){
                dist_list[node] = w+p.first;
                mset.insert({dist_list[node],node});
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("pump.in","r",stdin); 
	freopen("pump.out","w",stdout);
    
    int t=1;
    //cin>>t;
    int xxx=1;
    
    while(t--){
        int n,m,i;
        cin>>n>>m;
        
        vector<ll>dist_list2(n,LLONG_MAX);
        vector<vector<pair<int,pair<int,int>>>>adj_mat(n);
        vector<vector<int>>edges;
        set<int>flow_rates;
        for(i=0;i<m;i++){
            int u,v,w,s;
            cin>>u>>v>>w>>s;
            u--;
            v--;
    
            flow_rates.insert(s);
            adj_mat[u].push_back({v,{w,s}});
            adj_mat[v].push_back({u,{w,s}});
        }
        double ans = 0;
        for(auto &val:flow_rates){
            vector<ll>dist_list1(n,LLONG_MAX);
            Dijkstra(adj_mat,0,dist_list1,n,val);
            if(dist_list1[n-1]!=LLONG_MAX){
                ans = max(ans,(val*1.0)/dist_list1[n-1]);
            }
        }
    
        cout<<floor(ans*1000000)<<endl;
        
    }

   return 0;
}