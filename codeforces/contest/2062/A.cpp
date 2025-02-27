#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	string s;
	cin >> s;

	int ans = 0;
	for(int i = 0; i < s.size(); ++i) ans += (s[i] == '1');

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
