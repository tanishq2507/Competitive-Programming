#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define MOD 998244353
//#define MOD 1000000007
#include <iostream>
int MOD = 1000000007;

void print_list(vector<int>&clist){
    for(int i=0;i<clist.size();i++)
        std::cout << clist[i] << " ";
    cout<<endl;
}

bool sortbysecdesc(const pair<pair<int,int>,int> &a,
                   const pair<pair<int,int>,int> &b)
{
       return (a.second>=b.second);
}

bool sortbysecdesc2(const pair<pair<int,int>,int> &a,
                   const pair<pair<int,int>,int> &b)
{
       return (a.first.second>=b.first.second);
}
int find_parent(int node,vector<int>& parent){
    if(parent[node]==node)
        return(node);
    return(parent[node]=find_parent(parent[node],parent));
}

//always find parent using find_parent function
void make_union(int u,int v,vector<int>& sze,vector<int>&parent){
    int up1,up2;
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
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
    
	freopen("mootube.in","r",stdin); 
	freopen("mootube.out","w",stdout);
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,q,i;
        cin>>n>>q;
        vector<pair<pair<int,int>,int>>edges;
        int u,v,r;
        for(i=0;i<n-1;i++){
            cin>>u>>v>>r;
            edges.push_back({{u,v},r});
        }
        vector<pair<pair<int,int>,int>>queries;
        for(i=0;i<q;i++){
            cin>>r>>u;
            queries.push_back({{u,r},i});
        }
        vector<int>parent(n+1);
        for(i=1;i<=n;i++)
            parent[i] = i;
        vector<int>sze(n+1,1);
        
        sort(edges.begin(), edges.end(), sortbysecdesc);
        sort(queries.begin(),queries.end(),sortbysecdesc2);
        
        vector<int>anslist(q);
        int xx=0;
        for(i=0;i<queries.size();i++){
            int ind = queries[i].second;
            int node = queries[i].first.first;
            int rmin = queries[i].first.second;
            while(xx<edges.size() && edges[xx].second>=rmin){
                make_union(edges[xx].first.first,edges[xx].first.second,sze,parent);
                xx++;
            }
            anslist[ind] = sze[find_parent(node,parent)]-1;
        }
        for(i=0;i<anslist.size();i++)
            cout<<anslist[i]<<endl;
            
        
}
   return 0;
}







