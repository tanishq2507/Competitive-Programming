const int MAXN = 1e6;
const int MOD = 1000000007;
long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** Computes x^n modulo m in O(log p) time. */
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

/** Precomputes n! from 0 to MAXN. */
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses() {
	inv[MAXN] = mod_expo(fac[MAXN], MOD - 2);
	for (int i = MAXN; i >= 1; i--) {
	    inv[i - 1] = inv[i] * i % MOD;
	    }
}

/** Computes nCr mod p */
long long choose(long long n, long long r) {
	return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}
 