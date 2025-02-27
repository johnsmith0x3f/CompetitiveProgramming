#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pll = pair<i64, i64>;

inline void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<i64> x(m + 1), t(m + 1); x[0] = 1e18;
	for(int i = 1; i <= m; ++i) cin >> x[i] >> t[i];

	vector<int> head(n + 1, 0), next(m + 1, 0);
	for(int i = m; i >= 1; --i) next[i] = head[t[i]], head[t[i]] = i;

	priority_queue<pll, vector<pll>, greater<pll>> q;
	for(int i = 1; i <= n; ++i) q.push({ x[head[i]], a[i] });

	i64 ans = 0;
	for(int i = 1; i <= m; ++i) {
		while(q.size() && ans < x[i]) {
			auto [ p, a ] = q.top(); q.pop();
			if((ans += a) > x[i]) {
				if(p > x[i]) q.push({ p, ans - x[i] });
				ans = x[i];
			}
		}
		if(ans < x[i]) break;
		q.push({ x[next[i]], a[t[i]] });
	}
	while(q.size()) ans += q.top().second, q.pop();

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
