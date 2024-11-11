#include <bits/stdc++.h>
using namespace std;

const int N = 8e5 + 5;
int c[N], d[N];

void update(int v, int l, int r, int x, int k) {
	if(l == r) {
		d[v] = k * x;
		return;
	}

	int m = (l + r) >> 1;
	if(x <= m) update(v << 1, l, m, x, k);
	else update(v << 1 | 1, m + 1, r, x, k);

	d[v] = gcd(d[v << 1], d[v << 1 | 1]);
}

inline void init() {
	for(int i = 1; i <= 2e5; ++i) {
		for(int j = 1; j * j <= i; ++j) {
			if(i % j == 0) c[i] += 1 + (j * j != i);
		}
	}
}

inline void solve() {
	int n, q;
	cin >> n >> q;

	c[0] = n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int i = 1; i < n; ++i) update(1, 1, n - 1, i, a[i] > a[i + 1]);

	cout << c[d[1]] << "\n";

	while(q--) {
		int p, v;
		cin >> p >> v;

		a[p] = v;
		if(p > 1) update(1, 1, n - 1, p - 1, a[p - 1] > a[p]);
		if(p < n) update(1, 1, n - 1, p, a[p] > a[p + 1]);

		cout << c[d[1]] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	init();

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
