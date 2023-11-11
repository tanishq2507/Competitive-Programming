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
int bfs(vector<vector<pair<int,int>>>&graph,int s,int k){
    queue<int>que;
    que.push(s);
    int n = graph.size();
    vector<bool>visited(n,false);
    visited[s]=true;
    int ans=0;
    while(que.empty()==0){
        int sze = que.size();
        for(int i=0;i<sze;i++){
            int curr = que.front();
            que.pop();
            
            for(int j=0;j<graph[curr].size();j++){
                int friend1 = graph[curr][j].first;
                if(visited[friend1]==true)
                    continue;
                else{
                    int val = graph[curr][j].second;
                   
                    if(val>=k){
                        ans+=1;
                        que.push(friend1);
                        visited[friend1]=true;
                    }
                }
            }
        }
    }
    return(ans);
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
        vector<vector<pair<int,int>>>graph(n+1);
        for(i=0;i<n-1;i++){
            int pi,qi,ri;
            cin>>pi>>qi>>ri;
            graph[pi].push_back({qi,ri});
            graph[qi].push_back({pi,ri});
        }
        
        int k,v;
        string s="";
        for(i=0;i<q;i++){
            cin>>k>>v;
           
            cout<<((bfs(graph,v,k)))<<endl;
        }
       
}
   return 0;
}







