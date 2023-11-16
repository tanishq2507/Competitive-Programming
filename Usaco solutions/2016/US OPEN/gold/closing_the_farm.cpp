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

int find_parent(int node,vector<int>& parent){
    if(parent[node]==node)
        return(node);
    return(parent[node]=find_parent(parent[node],parent));
}

//always find parent using find_parent function
void make_union(int u,int v,vector<int>& sze,vector<int>&parent,int &curr_cnt){
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
        curr_cnt-=1;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
    
	freopen("closing.in","r",stdin); 
	freopen("closing.out","w",stdout);
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,m,i,u,v;
        cin>>n>>m;
        vector<vector<int>>graph(n+1);
        for(i=0;i<m;i++){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>vec(n);
        for(i=0;i<n;i++)
            cin>>vec[i];
        vector<bool>anslist(n,false);
        vector<bool>is_on(n+1,false);
        int curr_cnt=0;
        vector<int>parent(n+1);
        for(i=1;i<=n;i++)
            parent[i] = i;
        vector<int>sze(n+1,1);
        for(i=n-1;i>=0;i--){
            int node = vec[i];
            is_on[node] = true;
            curr_cnt+=1;
            for(int &u:graph[node]){
                if(is_on[u]==true){
                    make_union(node,u,sze,parent,curr_cnt);
                }
            }
            if(curr_cnt<=1)
                anslist[i] = true;
        }
        for(i=0;i<n;i++){
            if(anslist[i] == true)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

        
}
   return 0;
}







