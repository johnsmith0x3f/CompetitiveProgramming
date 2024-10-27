#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e7 + 5;
const int P = 1e9 + 7;

int main() {
	vector<i64> f(N, 0); f[1] = 1;

	int tt;
	cin >> tt;
	while(tt--) {
		i64 n, k;
		cin >> n >> k;

		int i = 1;
		while(f[i] % k) f[i + 1] = (f[i] + f[i - 1]) % k, ++i;
		cout << n % P * i % P << "\n";
	}

	return 0;
}
