#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;

inline void solve() {
	int n;
	cin >> n;

	auto check = [&](i64 x) -> bool {
		while(x) {
			if(x % 10 == 7) return true;
			x /= 10;
		}
		return false;
	};

	int ans = 10;
	for(int i = 1; i <= 10; ++i)
		for(int j = 0; j <= 10; ++j)
			if(check(n + i64(pow(10, i) - 1) * j)) ans = min(ans, j);

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
