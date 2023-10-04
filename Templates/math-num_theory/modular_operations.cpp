ll mod_expo(ll a,ll b){
    if(a==0)
        return(0);
    if(b==0 or a==1)
        return(1);
    ll result = 1;
    if(b%2==1){
            result = (result%MOD *a%MOD)%MOD;
            b = b-1;
        }
        ll x = mod_expo(a,b/2)%MOD;
        return((  (result*x)%MOD  *x)%MOD);
    
    }
ll mod_mult(ll a,ll b){
    return((a%MOD *b%MOD)%MOD);
}
ll mod_factorial(ll num){
    ll pro=1;
    for(ll i=1;i<=num;i++){
        pro = mod_mult(pro,i);
    }
    return(pro);
}
ll mod_nCr(ll n ,ll r){
    ll a,b,c,d,e,f;
    a = mod_factorial(n);
    b = mod_factorial(r);
    c = mod_factorial(n-r);
    d = mod_mult(b,c);
    e = mod_expo(d,MOD-2);
    f = mod_mult(a,e);
    return(f);
}