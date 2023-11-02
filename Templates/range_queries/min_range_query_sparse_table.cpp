//sparse table for min_range_query

const int MAX_N = 200005;
const int LOG = 21;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

void pre_process_sparse_table(int n){
    bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	//preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
}