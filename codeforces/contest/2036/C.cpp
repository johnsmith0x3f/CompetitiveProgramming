#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	string s;
	cin >> s;
	s = "~~~~" + s + "~~~~";

	int num = 0;
	for(int i = 0; i < s.size(); ++i) num += (s.substr(i, 4) == "1100");

	int q;
	cin >> q;
	while(q--) {
		int i; char v;
		cin >> i >> v;

		for(int k = i; k < i + 4; ++k) num -= (s.substr(k, 4) == "1100");
		s[i + 3] = v;
		for(int k = i; k < i + 4; ++k) num += (s.substr(k, 4) == "1100");

		cout << (num ? "YES" : "NO") << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
