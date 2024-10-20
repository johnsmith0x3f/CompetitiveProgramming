#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

namespace SuffixArray {
	const int N = 1000005;
	int n, m, sa[N], rk[N], id[N], cnt[N], newrk[N];
	int ht[N], st[N][21];
	string s;

	inline void build() {
		n = s.length(), m = 128, s = "~" + s;

		fill(cnt, cnt + m + 1, 0);
		for(int i = 1; i <= n; ++i) cnt[rk[i] = s[i]]++;
		for(int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

		for(int w = 1; w < n; w <<= 1) {
			int x = 0;
			for(int i = n - w + 1; i <= n; ++i) id[++x] = i;
			for(int i = 1; i <= n; ++i)
				if(sa[i] > w) id[++x] = sa[i] - w;

			fill(cnt, cnt + m + 1, 0);
			for(int i = 1; i <= n; ++i) cnt[rk[i]]++;
			for(int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
			for(int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];

			m = 0;
			for(int i = 1; i <= n; ++i) {
				if(rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + w] != rk[sa[i - 1] + w]) m++;
				newrk[sa[i]] = m;
			}
			for(int i = 1; i <= n; ++i) rk[i] = newrk[i];

			if(m == n) break;
		}

		int k = 0;
		for(int i = 1; i <= n; ++i) {
			if(rk[i] == 1) continue;
			if(k) k--;
			while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
			ht[rk[i]] = k;
		}

		for(int i = 1; i <= n; ++i) st[i][0] = ht[i];
		for(int j = 0; j < 20; ++j)
			for(int i = 1; i <= n; ++i) st[i][j + 1] = min(st[i][j], i + (1 << j) <= n ? st[i + (1 << j)][j] : INF);
	}

	inline int lcp(const int &i, const int &j) {
		int l = rk[i], r = rk[j];
		if(l > r) swap(l, r);

		assert(1 <= l && l < r && r <= n);

		int k = __lg(r - l);
		return min(st[l + 1][k], st[r - (1 << k) + 1][k]);
	}

	inline int lcs(const int &i, const int &j) {
		return lcp(n - i + 1, n - j + 1);
	}
}
using namespace SuffixArray;

inline void solve() {
	int k;
	cin >> k;
	string str;
	cin >> str;

	int len = str.length();
	if(k == 1) return void(printf("%lld\n", 1ll * len * (len + 1) / 2));

	s = str + "$" + string(str.rbegin(), str.rend());

	build();

	i64 ans = 0;
	for(int l = 1; l <= len / k; ++l) {
		int num = 1, las = 0;
		for(int i = 1; i <= len - l; i += l) {
			if(lcp(i, i + l) >= l) num++;
			else ans += max(las + lcp(i, i + l) + (num - k) * l + 1, 0), num = 1, las = i + l + l - 1 <= n ? lcs(i + l - 1, i + l + l - 1) : 0;
		}
		ans += max(las + (num - k) * l + 1, 0);
	}
	printf("%lld\n", ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cas;
	cin >> cas;
	while(cas--) solve();
	return 0;
}

