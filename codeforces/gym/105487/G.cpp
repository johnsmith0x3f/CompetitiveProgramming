#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int N = 2e5 + 5;
i64 n, k, a[N], ok[64][2];

void DFS(int b, int l, int r) {
	if(b < 0 || l >= r) return;

	int foo = 1;
	for(int i = l + 1; i < r; ++i)
		if(((a[i - 1] >> b) & 1) && (((a[i] >> b) & 1) ^ 1)) foo = 0;
	ok[b][0] &= foo;

	int bar = 1;
	for(int i = l + 1; i < r; ++i)
		if((((a[i - 1] >> b) & 1) ^ 1) && ((a[i] >> b) & 1)) bar = 0;
	ok[b][1] &= bar;

	int m = r;
	for(int i = l + 1; i < r; ++i)
		if(((a[i - 1] >> b) & 1) != ((a[i] >> b) & 1)) m = i;

	DFS(b - 1, l, m), DFS(b - 1, m, r);
}

inline void solve() {
	cin >> n >> k;

	for(int i = 0; i < n; ++i) cin >> a[i];

	if(k == 0) {
		cout << is_sorted(a, a + n) << '\n';
		return;
	}

	for(int i = 60; ~i; --i) ok[i][0] = ok[i][1] = 1;
	DFS(60, 0, n);

	vector<i64> pre(61, 1);
	for(int i = 0; i < 60; ++i) pre[i + 1] = pre[i] * (ok[i][0] + ok[i][1]);

	i64 ans = 0, temp = 1;
	for(int i = 60; ~i; --i) {
		if((k >> i) & 1) ans += temp * ok[i][0] * pre[i];
		temp *= ok[i][(k >> i) & 1];
	}
	
	cout << ans + temp << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
