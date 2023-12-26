#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

struct segtree {
    
    int size;
    vector<int> values ;
    
    void init(int n){
        size = 1;
        while(size < n )
            size = size*2;
        values.assign(2*size, 0LL);
    }
    
    void build(vector<int> &list1, int node_ind , int lx, int rx){
        if(rx - lx == 1){
            if(lx < list1.size()){
                values[node_ind] = list1[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(list1,2*node_ind +1,lx,m);
        build(list1,2*node_ind +2,m,rx);
        values[node_ind] = min(values[2*node_ind +1], values[2*node_ind +2]);
        
    }
    void build(vector<int>&list1){
        build(list1,0,0,size);
    }
    
    void set(int i, int val, int node_ind, int lx, int rx){
        
        //lx and rx are borders of current segment/node
        // i is index of element in input array
        
        if(rx - lx == 1){
            values[node_ind] = val;
            return;
        }
        
        int m  = (lx + rx)/2;
        
        if(i<m){
            set(i, val, 2*node_ind +1, lx, m);
        }
        else{
            set(i, val, 2*node_ind +2, m,rx);
        }
        values[node_ind] = min(values[2*node_ind + 1] , values[2*node_ind + 2]);
    }
    
    void set(int i , int val){
        set(i,val,0,0,size);
    }
    
    long long calc(int l,int r,int node_ind,int lx,int rx){
        if(lx>=r || l>=rx)
            return(INT_MAX);
        if(lx>=l && rx<=r)
            return(values[node_ind]);
        int m = (lx + rx)/2 ; 
        int val1 = calc(l,r,2*node_ind +1,lx,m);
        int val2 = calc(l,r,2*node_ind +2,m,rx);
        return(min(val1,val2));
            
    }
    
    long long calc(int l,int r){
        // finds min element in index l to r-1
        return calc(l,r,0,0,size);
    }
    
};
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int t=1;
    //cin>>t;
    
    
    while(t--){
        
        int n,m;
        cin>>n>>m;
        
        segtree st;
        st.init(n);
        
        vector<int>list1(n);
        for(int i = 0; i<n; i++){
            cin>>list1[i];
        }
        st.build(list1);
        while(m--){
            int op;
            cin>>op;
            
            if(op == 1){
                int i,v;
                cin>>i>>v;
                st.set(i,v);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout << st.calc(l,r) << endl;
            }
        }
        
    }

   return 0;
}