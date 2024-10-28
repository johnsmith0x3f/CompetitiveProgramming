#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

namespace SuffixArray {
	const int N = 2000005;
	int n, m, cnt[N];
	int sa[N], rk[N], id[N], newrk[N];
	string s;

	inline void build() {
		n = s.length(), m = 128, s = "~" + s;

		for(int i = 1; i <= n; ++i) cnt[rk[i] = s[i]]++;
		for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(int i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

		for(int w = 1; w < n; w <<= 1) {
			int x = 0;
			for(int i = n-w+1; i <= n; ++i) id[++x] = i;
			for(int i = 1; i <= n; ++i)
				if(sa[i] > w) id[++x] = sa[i] - w;

			fill(cnt, cnt+m+1, 0);
			for(int i = 1; i <= n; ++i) cnt[rk[i]]++;
			for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
			for(int i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];

			m = 0;
			for(int i = 1; i <= n; ++i) {
				if(rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+w] != rk[sa[i-1]+w]) m++;
				newrk[sa[i]] = m;
			}
			for(int i = 1; i <= n; ++i) rk[i] = newrk[i];

			if(m == n) break;
		}
	}
}

using namespace SuffixArray;

int main() {
	cin >> s;

	build();

	for(int i = 1; i <= n; ++i) printf("%d%c", sa[i], " \n"[i == n]);
	return 0;
}

