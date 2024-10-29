#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 2e5 + 5;
const int V = 1e6 + 5;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<i64> s(n + 1, 0);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + (a[i] == a[i - 1]) * a[i];

	vector<i64> f(N, 0), p(V, 0);
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
		if(p[a[i]]) f[i] = max(f[i], f[p[a[i]] + 1] + s[i] - s[p[a[i]] + 1] + a[i]);
		p[a[i]] = i;
	}

	cout << f[n] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
