#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e6 + 5;
const int P = 1e9 + 7;
int f[N] = { 0, 1 };

inline void solve() {
	i64 n, k;
	cin >> n >> k;

	int i = 1;
	while(f[i] % k) f[i + 1] = (f[i] + f[i - 1]) % k, ++i;
	cout << n % P * i % P << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}
