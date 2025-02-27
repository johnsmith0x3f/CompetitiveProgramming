#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;
	s = "~" + s;

	i64 ans = 0;
	for(int i = 1, j = n; i <= j; --j) {
		if(s[j] == '1') ans += (i++);
		else ans += j - (i > 1 ? --i : 0);
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
