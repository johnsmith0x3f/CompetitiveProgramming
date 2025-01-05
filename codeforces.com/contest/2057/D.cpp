#include <bits/stdc++.h>
using namespace std;

#define ls (v << 1)
#define rs (v << 1 | 1)

const int N = 1e6 + 5;

struct Data {
	int lmin, lmax, rmin, rmax, ans;
	
	Data(): lmin(0), lmax(0), rmin(0), rmax(0), ans(0) {}
	Data(int k, int x): lmin(k - x), lmax(k + x), rmin(k + x), rmax(k - x), ans(0) {}
};

Data operator + (const Data &a, const Data &b) {
	Data c;
	c.lmin = min(a.lmin, b.lmin);
	c.lmax = max(a.lmax, b.lmax);
	c.rmin = min(a.rmin, b.rmin);
	c.rmax = max(a.rmax, b.rmax);
	c.ans = max(max(a.ans, b.ans), max(b.rmax - a.lmin, a.lmax - b.rmin));
	return c;
}

struct SegmentTree {
	int n;
	vector<Data> val;

	SegmentTree(int n): n(n) {
		val = vector<Data>((n + 1) << 2);
	}

	void update(int v, int l, int r, int x, int k) {
		if(l == r) {
			val[v] = Data(k, x);
			return;
		}
		int m = (l + r) / 2;
		if(x <= m + 0) update(ls, l, m + 0, x, k);
		if(x >= m + 1) update(rs, m + 1, r, x, k);
		val[v] = val[ls] + val[rs];
	}
};

inline void solve() {
	int n, q;
	cin >> n >> q;

	SegmentTree st(n);
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		st.update(1, 1, n, i, x);
	}

	cout << st.val[1].ans << '\n';

	while(q--) {
		int p, x;
		cin >> p >> x;

		st.update(1, 1, n, p, x);

		cout << st.val[1].ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
