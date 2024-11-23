#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	string s;
	cin >> s;

	for(int i = 1; i < s.size(); ++i) {
		if(s[i - 1] == s[i]) {
			cout << s[i - 1] << s[i] << '\n';
			return;
		}
		if(i > 1 && s[i - 2] != s[i]) {
			cout << s[i - 2] << s[i - 1] << s[i] << '\n';
			return;
		}
	}

	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
