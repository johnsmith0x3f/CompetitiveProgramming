#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;
	s = "~" + s;

	int foo = 0, bar = 0;
	for(int i = 1; i < n; ++i) foo |= (s[i] == 'p');
	for(int i = n; i > 1; --i) bar |= (s[i] == 's');

	cout << (foo && bar ? "NO" : "YES") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}