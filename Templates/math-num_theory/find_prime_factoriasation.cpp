void find_prime_factorisation(int n,map<int,int>&mp){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            mp[i]=0;
            
            while(n%i==0){
                mp[i]+=1;
                n = n/i;
            }
        }
    }
    if(n>1){
        
        mp[n]=1;
    }
    
    return;
}