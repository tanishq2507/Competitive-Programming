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
void dfs_matrix(int &x1,int &y1,int &x2,int &y2,vector<vector<char>>&matrix,vector<vector<bool>>&visited,int i,int j,char color){

    if(i<x1 || j<y1 || i>x2 || j>y2 ){
        return;
    }
    
    if(visited[i][j]==true)
        return;
    if(matrix[i][j]!=color)
        return;
    visited[i][j] = true;

    dfs_matrix(x1,y1,x2,y2,matrix,visited,i+1,j,color);
    
    dfs_matrix(x1,y1,x2,y2,matrix,visited,i-1,j,color);

    dfs_matrix(x1,y1,x2,y2,matrix,visited,i,j+1,color);
    
    dfs_matrix(x1,y1,x2,y2,matrix,visited,i,j-1,color);
    
}
void is_pcl(int &x1,int &y1,int &x2,int &y2,vector<vector<char>>&matrix,vector<vector<int>>&may_be_pcl_list,int &n){
    vector<int>cnt(26);
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    int i,j;
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(visited[i][j]==false){
                cnt[matrix[i][j]-'A'] += 1;
                dfs_matrix(x1,y1,x2,y2,matrix,visited,i,j,matrix[i][j]);
            }
        }
    }
    int c1=0;
    int c2=0;
    for(int i=0;i<26;i++){
        if(cnt[i]==1)
            c1+=1;
        else if(cnt[i]>=2)
            c2+=1;
    }
    if(c1==1 && c2==1){
     
        may_be_pcl_list.push_back({x1,y1,x2,y2});
    }
    
}



int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
        
	freopen("where.in","r",stdin); 
	freopen("where.out","w",stdout);
	
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,i,j,k,l;
        cin>>n;
        vector<vector<char>>matrix(n,vector<char>(n));
        string s;
        for(i=0;i<n;i++){
            cin>>s;
            for(j=0;j<n;j++)
                matrix[i][j]=s[j];
        }
        vector<vector<int>>may_be_pcl_list;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=i;k<n;k++){
                    for(l=j;l<n;l++){
                        is_pcl(i,j,k,l,matrix,may_be_pcl_list,n);
                    }
                }
            }
        }

        int ans=0;
        for(i=0;i<may_be_pcl_list.size();i++){
            int flag=0;
            int x1 = may_be_pcl_list[i][0];
            int y1 = may_be_pcl_list[i][1];
            int x2 = may_be_pcl_list[i][2];
            int y2 = may_be_pcl_list[i][3];
            for(j=0;j<may_be_pcl_list.size();j++){
                if(i!=j){
                    int a1 = may_be_pcl_list[j][0];
                    int b1 = may_be_pcl_list[j][1];
                    int a2 = may_be_pcl_list[j][2];
                    int b2 = may_be_pcl_list[j][3];
                    if(x1>=a1 && y1>=b1 && x2<=a2 && y2<=b2){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
           
                ans+=1;
            }
        }
        cout<<ans<<endl;
             
}
   return 0;
}







