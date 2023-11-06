int find_parent(int node,vector<int>& parent){
    if(parent[node]==node)
        return(node);
    return(parent[node]=find_parent(parent[node],parent));
}


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

int mst_weight(vector<vector<int>>&edges2,vector<int>& parent,vector<int>& sze){
//Krushkal's algo
        int i;
        int c=0;
        for(i=0;i<edges2.size();i++){
            c+=make_union(edges2[i],parent,sze);
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