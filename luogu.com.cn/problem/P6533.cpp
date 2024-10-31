#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
const int P = 1e4 + 7;
int a[N], b[N];

struct SegTree {
	int c;
	short coe[N][21];

	inline void pushup(const int &v) {
		for(int i = 0; i <= c; ++i) coe[v][i] = 0;
		for(int i = 0; i <= c; ++i)
			for(int j = 0; j <= c; ++j)
				(coe[v][min(i + j, c)] += 1l * coe[v << 1 | 0][i] * coe[v << 1 | 1][j] % P) %= P;
	}

	void build(int v, int l, int r) {
		if(l == r) return (void)(coe[v][1] = a[l] % P, coe[v][0] = b[l] % P);

		int m = (l + r) >> 1;
		build(v << 1 | 0, l, m + 0);
		build(v << 1 | 1, m + 1, r);
		pushup(v);
	}

	void update(int v, int l, int r, int p) {
		if(l == r) return (void)(coe[v][1] = a[l] % P, coe[v][0] = b[l] % P);

		int m = (l + r) >> 1;
		if(p <= m + 0) update(v << 1 | 0, l, m + 0, p);
		if(p >= m + 1) update(v << 1 | 1, m + 1, r, p);
		pushup(v);
	}
} seg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n >> seg.c;

	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];

	seg.build(1, 1, n);
	
	int q;
	cin >> q;
	while(q--) {
		int p, x, y;
		cin >> p >> x >> y;

		a[p] = x, b[p] = y, seg.update(1, 1, n, p);

		cout << seg.coe[1][seg.c] << "\n";
	}

	return 0;
}