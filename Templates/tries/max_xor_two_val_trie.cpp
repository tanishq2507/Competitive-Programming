vector<vector<int>> findMaximumXOR_create_trie(vector<int>& nums) {
	//find maximum xor of two elements in an array nums
        int N=0;
        int n = nums.size();
        vector<vector<int>>nxt(1,vector<int>(2,0));
        //vector<bool>is_terminal(1,false);
        for(int num:nums){
            
            int node = 0;
            for(int i=31;i>=0;i--){
                char c;
                if(num & (1<<i))
                    c='1';
                else
                    c='0';
                if(nxt[node][c-'0'] == 0){
                    nxt.push_back(vector<int>(2,0));
                    nxt[node][c-'0'] = ++N;
                    
                }
                
                node = nxt[node][c-'0'];
                
            }
            //is_terminal[node] = true;
        }
        return(nxt);
}
int findMaximumXOR_for_val(int val,vector<vector<int>>&nxt){
    int x = val;
    int ans = 0;
    int y = 0;
    int node = 0;
    for(int j=31;j>=0;j--){
        if(x& (1<<j)){
            if(nxt[node][0] != 0 ){
                node = nxt[node][0];
            }
            else{
                node = nxt[node][1];
                y += 1<<j;
            }
        }
        else{
            if(nxt[node][1] != 0 ){
                node = nxt[node][1];
                y += 1<<j;
            }
            else{
                node = nxt[node][0];
            }
        }
    }
    ans = max(ans,x^y);
    return(ans);
    }
    
    findMaximumXOR(vector<int>&nums){
        vector<vector<int>>nxt = move(findMaximumXOR_create_trie(nums));
        int ans=0;
        for(int &num: nums){
            int maxx = findMaximumXOR_for_val(num,nxt);
            ans = max(ans,maxx);
        }
        return(ans);
    }