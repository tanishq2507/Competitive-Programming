#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

void floyd_warshall(vector<vector<ll>>&dist_matrix,int &n){
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){

                if(dist_matrix[i][k]!=-1 && dist_matrix[k][j]!=-1){
                    if(dist_matrix[i][j]!=-1)
                        dist_matrix[i][j] = min(dist_matrix[i][j],dist_matrix[i][k]+dist_matrix[k][j]);
                    else
                        dist_matrix[i][j] = dist_matrix[i][k]+dist_matrix[k][j];
                    dist_matrix[j][i] = dist_matrix[i][j];
                }
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
        int n,m,q,i;
        cin>>n>>m>>q;
        vector<vector<ll>>dist_matrix(n,vector<ll>(n,-1));
        for(i=0;i<n;i++){
            dist_matrix[i][i] = 0;
        }
        for(i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            a--;
            b--;
            if(dist_matrix[a][b]==-1){
                dist_matrix[a][b] = c;
                dist_matrix[b][a] = c;
            }
            else{
                int val = min(dist_matrix[a][b],c);
                dist_matrix[a][b] = val;
                dist_matrix[b][a] = val;
            }
        }
        floyd_warshall(dist_matrix,n);
        for(i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            cout<<dist_matrix[u][v]<<endl;
        }
        
    }

   return 0;
}