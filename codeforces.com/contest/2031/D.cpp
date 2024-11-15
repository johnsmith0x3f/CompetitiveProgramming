#include <bits/stdc++.h>
using namespace std;

#define ls (v << 1 | 0)
#define rs (v << 1 | 1)

const int N = 2e6 + 5;
int a[N], key[N], tag[N];

inline void pushdown(const int &v) {
	key[ls] = max(key[ls], tag[v]);
	key[rs] = max(key[rs], tag[v]);
	tag[ls] = max(tag[ls], tag[v]);
	tag[rs] = max(tag[rs], tag[v]);
	tag[v] = 0;
}

void build(int v, int l, int r) {
	key[v] = tag[v] = 0;
	if(l >= r) {
		key[v] = a[l];
		return;
	}

	int m = (l + r) >> 1;
	build(ls, l, m + 0);
	build(rs, m + 1, r);
	key[v] = max(key[ls], key[rs]);
}

void update(int v, int l, int r, int x, int y, int k) {
	if(x <= l && r <= y) {
		key[v] = max(key[v], k), tag[v] = max(tag[v], k);
		return;
	}
	pushdown(v);

	int m = (l + r) >> 1;
	if(x <= m + 0) update(ls, l, m + 0, x, y, k);
	if(y >= m + 1) update(rs, m + 1, r, x, y, k);
	key[v] = max(key[ls], key[rs]);
}

int query(int v, int l, int r, int x) {
	if(l >= r) return key[v];
	pushdown(v);

	int m = (l + r) >> 1;
	return x <= m ? query(ls, l, m + 0, x) : query(rs, m + 1, r, x);
}

inline void solve() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);

	vector<int> id(n + 1);
	for(int i = 1; i <= n; ++i) id[i] = i;
	sort(begin(id) + 1, begin(id) + n + 1, [&](const int &i, const int &j) {
		if(a[i] != a[j]) return a[i] > a[j];
		return i > j;
	});

	set<int> ss;
	vector<int> xx(n + 1);
	for(int i = n, j = n; i >= 1; i = --j) {
		while(j >= 1 && a[id[j - 1]] == a[id[j]]) --j;
		if(ss.size()) for(int k = i; k >= j; --k) xx[id[k]] = *ss.rbegin();
		ss.insert(id[j]);
	}

	vector<int> ans(n + 1);
	for(int i = 1; i <= n; ++i) {
		ans[id[i]] = max(query(1, 1, n, id[i]), query(1, 1, n, xx[id[i]]));
		update(1, 1, n, id[i], n, ans[id[i]]);
	}

	for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
