#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;

	vector<i64> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<i64>());

	vector<i64> s(n + 1);
	for(int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];

	for(int k = 1; k <= n; ++k) {
		i64 ans = 0;
		for(int i = 1; i <= n / k + 1; ++i) ans = max(ans, s[min(i * k, n)] - 1LL * i * d);

		cout << ans << '\n';
	}

	return 0;
}
