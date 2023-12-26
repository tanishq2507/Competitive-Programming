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
            c+=((ll)make_union(edges[i],sze,parent))*(-1);
        }
        return(c);
    }
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("superbull.in","r",stdin); 
	freopen("superbull.out","w",stdout);
	
    
    int t=1;
    //cin>>t;
    int xxx=1;
    
    while(t--){
        int n,m,i,a,j;
        cin>>n;
        vector<int>list1;
        for(i=0;i<n;i++){
            cin>>a;
            list1.push_back(a);
        }
        vector<vector<int>>edges;
        
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int u,v,w;
                u = i;
                v = j;
                w = list1[i]^list1[j];
                
                edges.push_back({-w,u,v});
            }
        }
        vector<int>parent(n);
        vector<int>sze(n,1);
        sort(edges.begin(),edges.end());
        for(i=0;i<n;i++)
            parent[i] = i;
        
        ll ans = mst_weight(edges,parent,sze);
        
        cout<<ans<<endl;
        
    }

   return 0;
}