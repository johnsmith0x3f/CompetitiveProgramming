#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

inline void solve() {
	i64 n, x, k;
	cin >> n >> x >> k;

	string s;
	cin >> s;

	i64 sum = 0, foo = 0, bar = 0;
	for(int i = 0; i < n; ++i) {
		sum += (s[i] == 'R') - (s[i] == 'L');
		if(!foo && sum == -x) foo = i + 1;
		if(!bar && sum == +0) bar = i + 1;
	}

	if(foo == 0 || k < foo) cout << 0 << '\n';
	else if(bar == 0) cout << 1 << '\n';
	else cout << 1 + (k - foo) / bar << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
