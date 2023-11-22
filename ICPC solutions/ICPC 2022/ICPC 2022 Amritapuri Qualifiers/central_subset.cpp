
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void print_list(vector<int>&clist){
    for(int i=0;i<clist.size();i++)
        std::cout << clist[i] << " ";
    cout<<endl;
}

int DFS(int u,vector<bool>&visited,vector<vector<int>>& adj,vector<int>&ans,int maxr){
        
        visited[u]=true;
        int h=0;
        for(int v: adj[u]){
        
            if(visited[v]==false)
            {
                 h = max(h,DFS(v,visited,adj,ans,maxr)+1);
            }
        }
        if(u==1 || h==maxr)
            ans.push_back(u);
        return(h%maxr);
        
       
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        int n,m,i,a,b;
        cin>>n>>m;
        vector<vector<int>>graph(n+1);
        for(i=0;i<m;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int>ans;
        int maxr = ceil(sqrt(n));
        vector<bool>visited(n+1,false);
        DFS(1,visited,graph,ans,maxr);
        cout<<ans.size()<<endl;
        print_list(ans);
        
    }

   return 0;
}

