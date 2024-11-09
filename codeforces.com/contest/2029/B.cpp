#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int foo = 0, bar = 0;
	for(int i = 0; i < n; ++i) foo += (s[i] == '0'), bar += (s[i] == '1');

	for(int i = 0; i < n - 1; ++i) {
		if(foo <= 0 || bar <= 0) {
			cout << "NO\n";
			return;
		}

		foo -= (t[i] != '0'), bar -= (t[i] != '1');
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
