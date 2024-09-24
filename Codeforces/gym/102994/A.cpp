#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 64;
i64 a[N], b[N];

inline void insert(i64 x, i64 *base) {
	for(int i = 62; ~i; --i) {
		if((x >> i) & 1) {
			if(base[i]) x ^= base[i];
			else return void(base[i] = x);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cas;
	cin >> cas;
	while(cas--) {
		int n, m;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		i64 ans = 0;
		for(int i = 1; i <= n+m; ++i) {
			i64 x, y;
			cin >> x >> y;
			ans ^= x, insert(x ^ y, i <= n ? a : b);
		}
		for(int i = 60; ~i; --i) {
			if(a[i] && b[i]) ans ^= ((ans >> i) & 1) ? a[i] : 0, insert(a[i] ^ b[i], a);
			else ans ^= ((ans >> i) & 1) ? b[i] : a[i];
		}
		cout << ans << endl;
	}
	return 0;
}

