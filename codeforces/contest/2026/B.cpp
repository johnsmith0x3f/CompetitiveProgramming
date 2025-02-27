#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<i64> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	auto work = [&](vector<i64> a) -> i64 {
		i64 ret = 1;
		for(int i = 1; i < a.size(); i += 2) ret = max(ret, a[i] - a[i - 1]);
		return ret;
	};

	if(n % 2 == 0) {
		cout << work(a) << '\n';
		return;
	}

	i64 ans = 1e18;
	vector<i64> temp;
	for(int i = 0; i < n; ++i) {
		temp = a;
		temp.erase(temp.begin() + i);
		ans = min(ans, work(temp));
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
