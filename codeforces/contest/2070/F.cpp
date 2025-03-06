#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using vi64 = vector<i64>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> s(m);
	for(int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		for(char c : str) s[i] |= 1 << (c - 'A');
	}

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	int tot = accumulate(begin(a), end(a), 0);

	vector<int> num(1 << n); // number of odd pizzas
	vector<int> sum(1 << n); // sum of slices of odd pizzas
	for(int i = 0; i < (1 << n); ++i) {
		for(int j = 0; j < n; ++j) {
			if((i >> j) & a[j] & 1) ++num[i];
			if((i >> j) & 1) sum[i] += a[j];
		}
	}
	
	int N = 0, S = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] & 1) ++N, S |= 1 << i;

	vector<vi64> A(N + 1, vi64(1 << n));
	for(int i = 0; i < m; ++i) ++A[num[s[i]]][s[i]];

	for(int i = 0; i <= N; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < (1 << n); ++k)
				if((k >> j) & 1) A[i][k] += A[i][k ^ (1 << j)];

	vector<vi64> B(N + 1, vi64(1 << n));
	for(int i = 0; i <= N; ++i)
		for(int j = 0; i + j <= N; ++j)
			for(int k = 0; k < (1 << n); ++k) B[i + j][k] += A[i][k] * A[j][k];

	for(int i = 0; i <= N; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < (1 << n); ++k)
				if((k >> j) & 1) B[i][k] -= B[i][k ^ (1 << j)];

	vector<i64> ans(tot + 1);
	for(int i = 0; i < m; ++i)
		if(num[s[i]] == 0) --ans[tot - sum[s[i]]];
	for(int i = 0; i < (1 << n); ++i) ans[tot - sum[i]] += B[num[i]][i];
	for(int i = 0; i <= tot; ++i) cout << ans[i] / 2 << " \n"[i == tot];

	return 0;
}
