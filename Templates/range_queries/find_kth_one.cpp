#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

struct segtree {
    
    int size;
    vector<long long> sums ;
    
    void init(int n){
        size = 1;
        while(size < n )
            size = size*2;
        sums.assign(2*size, 0LL);
    }
    
    void build(vector<int> &list1, int node_ind , int lx, int rx){
        if(rx - lx == 1){
            if(lx < list1.size()){
                sums[node_ind] = list1[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(list1,2*node_ind +1,lx,m);
        build(list1,2*node_ind +2,m,rx);
        sums[node_ind] = sums[2*node_ind +1] + sums[2*node_ind +2];
        
    }
    void build(vector<int>&list1){
        build(list1,0,0,size);
    }
    
    void set(int i, int node_ind, int lx, int rx){
        
        //lx and rx are borders of current segment/node
        // i is index of element in input array
        
        if(rx - lx == 1){
            sums[node_ind] = sums[node_ind]^1;
            return;
        }
        
        int m  = (lx + rx)/2;
        
        if(i<m){
            set(i, 2*node_ind +1, lx, m);
        }
        else{
            set(i, 2*node_ind +2, m,rx);
        }
        sums[node_ind] = sums[2*node_ind + 1] + sums[2*node_ind + 2];
    }
    
    void set(int i){
        set(i,0,0,size);
    }
    
    int find(int k, int node_ind, int lx, int rx){
        if(rx-lx==1){
            return(lx);
        }
        int m = (lx + rx)/2;
        int c1 = sums[2*node_ind +1];
        
        if(k<c1){
            return(find(k,2*node_ind+1,lx,m));
        }
        else{
            return(find(k-c1,2*node_ind+2,m,rx));
        }
    }
    int find(int k){
        return(find(k,0,0,size));
    }
    
};
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int t=1;
    //cin>>t;
    
    
    while(t--){
        
        int n,m,i;
        cin>>n>>m;
        
        segtree st;
        st.init(n);
        
        vector<int>list1(n);
        
        for(i=0;i<n;i++){
            cin>>list1[i];
        }
        st.build(list1);
        
        for(int i = 0; i<m; i++){
            int op;
            cin>>op;
            if(op==1){
                int ind;
                cin>>ind;
                st.set(ind);//invert element at index ind
            }
            else{
                int k;
                cin>>k;
                cout<<st.find(k)<<endl;
            }
        }
        cout<<endl;
        
    }

   return 0;
}