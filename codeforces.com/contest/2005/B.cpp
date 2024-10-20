#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

inline void solve() {
	int n = read(), m = read(), q = read();
	vector<int> b(m);
	for(int i = 0; i < m; ++i) b[i] = read();

	sort(b.begin(), b.end());
	while(q--) {
		int k = upper_bound(b.begin(), b.end(), read()) - b.begin();

		if(k == 0) printf("%d\n", b[0] - 1);
		else if(k == m) printf("%d\n", n - b[m-1]);
		else printf("%d\n", (b[k] - b[k-1]) / 2);
	}
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

