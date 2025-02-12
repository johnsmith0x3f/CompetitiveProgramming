#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

inline void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> num(n + 1);
	for(int i = 0; i < n; ++i) ++num[a[i]];

	bool flag = true;
	for(int i = 1; i <= n; ++i) {
		if(num[i] == 1) {
			flag = false;
			break;
		}
		num[i + 1] += max(num[i] - 2, 0);
	}

	cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
