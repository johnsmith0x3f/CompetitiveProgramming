#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n, l, r;
	cin >> n >> l >> r;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	auto calc = [&](const int &x, const int &y) -> i64 {
		vector<int> vv;
		for(int i = x; i <= y; ++i) vv.emplace_back(a[i]);
		sort(begin(vv), end(vv));

		i64 ret = 0;
		for(int i = 0; i < r - l + 1; ++i) ret += vv[i];
		return ret;
	};

	cout << min(calc(1, r), calc(l, n)) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
