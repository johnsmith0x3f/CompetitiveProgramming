#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
const int P = 1e4 + 7;
int a[N], b[N];

struct SegTree {
	int c, coe[N][20];

	// SegTree(int x = 0) { }

	// inline void pushup(const int &v) {
	// 	for(int k = 0; k < c; ++k) coe[v][k] = 0;

	// 	for(int i = 0; i < c; ++i)
	// 		for(int j = 0; j < c; ++j)
	// 			if(i + j < c) coe[v][i + j] = (coe[v][i + j] + coe[v << 1][i] * coe[v << 1 | 1][j]) % P;
	// }

	// void build(int v, int l, int r) {
	// 	if(l == r) return (void)(coe[v][1] = a[l] % P, coe[v][0] = b[l] % P);

	// 	int m = (l + r) >> 1;
	// 	build(v << 1, l, m);
	// 	build(v << 1 | 1, m + 1, r);
	// 	pushup(v);
	// }

	// void update(int v, int l, int r, int k, int x, int y) {
	// 	if(l == r) return (void)(coe[v][1] = x % P, coe[v][0] = y % P);

	// 	int m = (l + r) >> 1;
	// 	if(k <= m) update(v << 1, l, m, k, x, y);
	// 	else update(v << 1 | 1, m + 1, r, k, x, y);
	// 	pushup(v);
	// }

	// int sum() {
	// 	int ret = 0;
	// 	for(int k = 0; k < c; ++k) ret += coe[1][k];
	// 	return ret % P;
	// }
};

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	int n, c;
	cin >> n >> c;

	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];

	SegTree seg;
	// seg.build(1, 1, n);

	// int prod = 1, znum = 0;
	// for(int i = 1; i <= n; ++i) {
	// 	if((a[i] + b[i]) % P) prod = (prod * ((a[i] + b[i]) % P)) % P;
	// 	else ++znum;
	// }

	// int q;
	// cin >> q;
	// while(q--) {
	// 	int p, x, y;
	// 	cin >> p >> x >> y;

	// 	znum -= ((a[p] + b[p]) % P == 0);
	// 	seg.update(1, 1, n, p, a[p] = x, b[p] = y);
	// 	znum += ((a[p] + b[p]) % P == 0);

	// 	cout << (znum ? 0 : prod) - seg.sum() << "\n";
	// }

	return 0;
}
