vector<bool> is_prime(100001, true);
vector<int> prime_set;
void seive(int n){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        //cout<<i<<end
        if (is_prime[i]  ) {
            prime_set.push_back(i);
            if((long long)i * i <= (long long)n){
            for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }
}