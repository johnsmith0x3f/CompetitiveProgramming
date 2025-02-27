#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

const i64 INF = 1e18;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) cin >> a[i];

		vector<int> b(n + 1);
		for(int i = 1; i <= n; ++i) cin >> b[i];

		vector<vector<pii>> to(n + 1);
		for(int i = 2; i <= n; ++i) to[i].push_back({ i - 1, 0 });
		for(int i = 1; i <= n; ++i) to[i].push_back({ b[i], a[i] });

		priority_queue<pll, vector<pll>, greater<pll>> q;
		vector<i64> dst(n + 1, INF);
		vector<bool> vst(n + 1, 0);
		dst[1] = 0, q.push({ 0, 1 });
		while(q.size()) {
			auto [ d, u ] = q.top();
			q.pop();

			if(vst[u]) continue;
			vst[u] = 1;

			for(auto [ v, w ] : to[u]) {
				if(d + w < dst[v]) {
					q.push({ dst[v] = d + w, v });
				}
			}
		}

		i64 ans = 0, sum = 0;
		for(int i = 1; i <= n; ++i) {
			sum += a[i];
			ans = max(ans, sum - dst[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
