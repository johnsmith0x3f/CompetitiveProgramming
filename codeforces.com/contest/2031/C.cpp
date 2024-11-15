#include <bits/stdc++.h>
using namespace std;

const string str = "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 13 12 12 1 13 ";

inline void solve() {
	int n;
	cin >> n;

	if(n & 1) {
		if(n < 27) {
			cout << "-1\n";
			return;
		}
		n -= 27;
		cout << str;
	}

	for(int i = 1; i <= n / 2; ++i) cout << i + 100 << ' ' << i + 100 << " \n"[i == n / 2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}

