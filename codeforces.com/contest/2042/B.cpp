#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> c(n + 1);
	for(int i = 0; i < n; ++i) ++c[a[i]];

	int foo = 0, bar = 0;
	for(int i = 1; i <= n; ++i) foo += c[i] > 1, bar += c[i] == 1;

	cout << foo + bar + (bar & 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
