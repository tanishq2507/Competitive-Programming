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

void dfs_matrix(int i,int j,vector<vector<char>>&matrix,vector<vector<bool>>&visited,int &peri,int &area){
    int n = matrix.size();
    int m = matrix[0].size();
    if(i<0 || j<0 || i>=n||j>=m){
        peri+=1;
        return;
    }
    
    if(matrix[i][j]=='.'){
        peri+=1;
        return;
    }
    
    if(visited[i][j]==true)
        return;
 
    visited[i][j] = true;
    area+=1;
    dfs_matrix(i+1,j,matrix,visited,peri,area);
    dfs_matrix(i-1,j,matrix,visited,peri,area);
    dfs_matrix(i,j+1,matrix,visited,peri,area);
    dfs_matrix(i,j-1,matrix,visited,peri,area);
    
}

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
        
	freopen("perimeter.in","r",stdin); 
	freopen("perimeter.out","w",stdout);
	
	
    int t=1;
    //cin>>t;
    int xxx=1;
    while(t--){
        int n,i,j;
        cin>>n;
        vector<vector<char>>matrix(n,vector<char>(n));
        string s;
        for(i=0;i<n;i++){
            cin>>s;
            for(j=0;j<n;j++){
                matrix[i][j] = s[j];
            }
        }
        int max_arr=0;
        int min_peri=4001;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                int area=0;
                int peri=0;
                if(visited[i][j]==false &&  matrix[i][j]=='#')
                    dfs_matrix(i,j,matrix,visited,peri,area);
                    if(area>max_arr){
                        max_arr=area;
                        min_peri=peri;
                    }
                    else if(area==max_arr){
                        if(peri<min_peri)
                            min_peri =peri;
                    }
            }
        }
        cout<<max_arr<<" "<<min_peri<<endl;
}
   return 0;
}







