#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	string s;
	cin >> s;

	for(int i = 0; i + 1 < s.size(); ++i) {
		if(s[i] == s[i + 1]) {
			cout << s.substr(i, 2) << '\n';
			return;
		}
	}
	for(int i = 0; i + 2 < s.size(); ++i) {
		if(s[i] != s[i + 2]) {
			cout << s.substr(i, 3) << '\n';
			return;
		}
	}

	cout << "-1" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
