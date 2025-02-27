#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	auto check = [&](int x) -> bool {
		int num = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] > x && s[i] == 'B') {
				while(i + 1 < n && (a[i + 1] <= x || s[i + 1] == 'B')) ++i;
				++num;
			}
		}
		return num <= k;
	};

	int l = 0, r = 1e9;
	while(l < r) {
		int m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m + 1;
	}

	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
