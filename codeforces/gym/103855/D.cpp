#include <bits/stdc++.h>
using namespace std;

const int N = 600005;
const int V = 5000006;
int x[N], y[N], v[N], ri[N], ci[N];
int r[V], c[V];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	x[0] = y[0] = -1;
	for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> v[i];
	for(int i = 1; i <= n; ++i) r[x[i]] += v[i], c[y[i]] += v[i], ri[i] = ci[i] = i;

	int ans = 0;
	sort(ri+1, ri+n+1, [](const int &p, const int &q) {
		return x[p] < x[q] || (x[p] == x[q] && y[p] < y[q]);
	});
	sort(ci+1, ci+n+1, [](const int &p, const int &q) {
		return y[p] < y[q] || (y[p] == y[q] && x[p] < x[q]);
	});

	multiset<int, greater<int>> rss;
	for(int i = 1; i <= n; ++i)
		if(x[ri[i]] != x[ri[i-1]]) rss.insert(r[x[ri[i]]]);
	ans = max(ans, *rss.begin() + (rss.size() > 1 ? *next(rss.begin()) + (rss.size() > 2 ? *next(next(rss.begin())) : 0) : 0));

	multiset<int, greater<int>> css;
	for(int i = 1; i <= n; ++i)
		if(y[ci[i]] != y[ci[i-1]]) css.insert(c[y[ci[i]]]);
	ans = max(ans, *css.begin() + (css.size() > 1 ? *next(css.begin()) + (css.size() > 2 ? *next(next(css.begin())) : 0) : 0));

	for(int i = 1; i <= n; ++i) {
		if(x[ri[i]] == x[ri[i-1]]) continue;
		for(int j = i; j <= n && x[ri[j]] == x[ri[i]]; ++j) {
			css.erase(css.find(c[y[ri[j]]]));
			c[y[ri[j]]] -= v[ri[j]];
			css.insert(c[y[ri[j]]]);
		}
		ans = max(ans, r[x[ri[i]]] + *css.begin() + (css.size() > 1 ? *next(css.begin()) : 0));
		for(int j = i; j <= n && x[ri[j]] == x[ri[i]]; ++j) {
			css.erase(css.find(c[y[ri[j]]]));
			c[y[ri[j]]] += v[ri[j]];
			css.insert(c[y[ri[j]]]);
		}
	}

	for(int i = 1; i <= n; ++i) {
		if(y[ci[i]] == y[ci[i-1]]) continue;
		for(int j = i; j <= n && y[ci[j]] == y[ci[i]]; ++j) {
			rss.erase(rss.find(r[x[ci[j]]]));
			r[x[ci[j]]] -= v[ci[j]];
			rss.insert(r[x[ci[j]]]);
		}
		ans = max(ans, c[y[ci[i]]] + *rss.begin() + (rss.size() > 1 ? *next(rss.begin()) : 0));
		for(int j = i; j <= n && y[ci[j]] == y[ci[i]]; ++j) {
			rss.erase(rss.find(r[x[ci[j]]]));
			r[x[ci[j]]] += v[ci[j]];
			rss.insert(r[x[ci[j]]]);
		}
	}

	cout << ans << endl;
	return 0;
}

