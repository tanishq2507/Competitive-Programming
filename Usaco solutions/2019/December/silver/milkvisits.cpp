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
    
        
	freopen("milkvisits.in","r",stdin); 
	freopen("milkvisits.out","w",stdout);
	
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,m,i;
        cin>>n>>m;
        string s;
        cin>>s;
        int u,v;
        vector<int>sze(n);
        vector<int>parent(n);
        for(i=0;i<n;i++)
            parent[i] = i;
        for(i=0;i<n-1;i++){
            cin>>u>>v;
            u--;
            v--;
            if(s[u]==s[v])
                make_union(u,v,sze,parent);
        }
        string ans="";
        for(i=0;i<m;i++){
            char ch;
            cin>>u>>v>>ch;
            u--;
            v--;
            if(find_parent(u,parent)==find_parent(v,parent)){
                if(s[u]==ch)
                    ans+='1';
                else
                    ans+='0';
            }
            else
                ans+='1';
        }
        cout<<ans<<endl;
       
}
   return 0;
}







