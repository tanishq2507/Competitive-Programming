#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

int find_parent(int node,vector<int>& parent){
    if(parent[node]==node)
        return(node);
    return(parent[node]=find_parent(parent[node],parent));
}

int make_union(vector<int>edgex,vector<int>& sze,vector<int>&parent){
    int up1,up2;
    int w = edgex[0];
    int u = edgex[1];
    int v = edgex[2];
    up1 = find_parent(u,parent);
    up2 = find_parent(v,parent);
    if(up1!=up2){
        if(sze[up1]>=sze[up2]){
            parent[up2]=up1;
            sze[up1]+=sze[up2];
        }
        else{
            parent[up1]=up2;
            sze[up2]+=sze[up1];
        }
        
        return(w);
    }
    else
        return(0);
    
}

ll mst_weight(vector<vector<int>>&edges,vector<int>& parent,vector<int>& sze){
//Krushkal's algo
//edges must be sorted in increasing order.
        int i;
        ll c=0;
        for(i=0;i<edges.size();i++){
            c+=(ll)make_union(edges[i],sze,parent);
        }
        return(c);
    }
    
bool is_mst(int n,vector<int>& parent){
        int i ;
        int par = find_parent(0,parent);
        for(i=1;i<n;i++){
            if(find_parent(i,parent)!=par)
                return(false);
        }
        return(true);
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
        
        vector<vector<int>>edges;
        
        for(i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            edges.push_back({w,u,v});
        }
        vector<int>parent(n);
        vector<int>sze(n,1);
        sort(edges.begin(),edges.end());
        for(i=0;i<n;i++)
            parent[i] = i;
        
        ll ans = mst_weight(edges,parent,sze);
        
        if(is_mst(n,parent))
            cout<<ans<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
        
    }

   return 0;
}
