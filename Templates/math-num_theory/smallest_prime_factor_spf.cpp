vector<int> spf(10000001);

void calc_spf(int N) {
	for(int i=0;i<N;i++)
	    spf[i] =i;
	for (int p = 2; p < N; p++) {
		if (spf[p] != p)
			continue;
		if((long long)p*p<N){
		for (int d = p * p; d < N; d += p)
			spf[d] = min(spf[d], p);
		}
	}
}