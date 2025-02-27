#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	vector<i64> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	if(n == 1) {
		cout << "0\n";
		return;
	}

	vector<i64> s(n * 3, 0);
	for(int i = 0; i < n * 3; ++i) s[i] = s[i - !!i] + (i & 1 ? a[i % n] : -a[i % n]);

	vector<i64> p(n * 2, 0);
	for(int i = 0; i + 2 < n * 2; i += 2) p[(i + 2) % n] = p[i + 2] = p[i] + s[i + n] - s[i + 1];

	for(int i = 0; i < n; ++i) {
		a[(i - 1 + n) % n] += p[i];
		a[i] += p[i], a[i] += p[i];
		a[(i + 1 + n) % n] += p[i];
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] != a[0]) {
			cout << "-1\n";
			return;
		}
	}

	i64 x = 0;
	for(int i = 0; i < n; ++i) x = min(x, p[i]);
	for(int i = 0; i < n; ++i) cout << p[i] - x << " \n"[i == n - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
