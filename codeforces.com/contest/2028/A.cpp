#include <bits/stdc++.h>
using namespace std;

inline void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;

	int x = 0, y = 0;
	for(int i = 0; i < n * 100; ++i) {
		if(x == a && y == b) {
			cout << "YES\n";
			return;
		}

		if(s[i % n] == 'N') ++y;
		if(s[i % n] == 'E') ++x;
		if(s[i % n] == 'S') --y;
		if(s[i % n] == 'W') --x;
	}

	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
