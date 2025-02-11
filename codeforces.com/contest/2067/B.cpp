#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	map<int, int> num;
	for(int i = 0; i < n; ++i) ++num[a[i]];

	for(auto [ x, y ] : num) {
		if(y == 1) {
			cout << "NO" << '\n';
			return;
		}

		if(x == num.rbegin()->first) {
			if(y & 1) cout << "NO" << '\n';
			else cout << "YES" << '\n';

			return;
		}

		if(y > 2) num[x + 1] += y - 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
