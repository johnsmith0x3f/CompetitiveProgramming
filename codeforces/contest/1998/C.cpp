#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k;

		vector<pair<int, int>> a(n + 1);
		for(int i = 1; i <= n; ++i) cin >> a[i].first;
		for(int i = 1; i <= n; ++i) cin >> a[i].second;
		sort(a.begin() + 1, a.end());

		vector<i64> s(n + 1, 0), t(n + 1, 0);
		for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i].first * a[i].second;
		for(int i = 1; i <= n; ++i) t[i] = t[i - 1] + a[i].second;

		auto check = [&](const int &x, const int &i) -> bool {
			int foo = lower_bound(a.begin() + 1, a.end(), make_pair(x, 0)) - a.begin() - 1;
			if(n - foo - (i > foo) >= n - n / 2) return 1;
			int bar = (n - n / 2) - (n - foo - (i > foo));
			if(t[foo] < bar) return 0;
			int baz = lower_bound(t.begin(), t.end(), t[foo] - bar) - t.begin();
			return 1ll * x * bar - (s[foo] - s[baz]) <= k;
		};

		i64 ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(a[i].second == 0) {
				int l = 1, r = 1e9, x = 0;
				while(l <= r) {
					int m = (l + r) / 2;
					if(check(m, i)) x = m, l = m + 1;
					else r = m - 1;
				}
				ans = max(ans, 0ll + a[i].first + x);
			}
			else ans = max(ans, 0ll + a[i].first + k + a[n / 2 + (i <= n / 2)].first);
		}
		cout << ans << "\n";
	}

	return 0;
}
