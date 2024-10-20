#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

const int N = 1e5 + 5;
int u[N], v[N], c[N], d[N], deg[N];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) c[i] = read();

	int ans = n;
	for(int i = 2; i <= n; i++) {
		u[i] = read(), v[i] = read();
		ans ^= u[i] ^ v[i], deg[u[i]]++, deg[v[i]]++;
	}

	int x = 0, y = 0, z = 0;
	for(int i = 1; i <= n; i++)
		if(c[i] && (deg[i] & 1)) !x ? x = i : (!y ? y = i : z = i);

	if(x && y && z) {
		d[x] = ans ^ (1 << 21) ^ (1 << 20), d[y] = 1 << 21, d[z] = 1 << 20;
		assert((x ^ d[x]) != (y ^ d[y]) && (y ^ d[y]) != (z ^ d[z]) && (z ^ d[z]) != (x ^ d[x]));
	}
	else if(x) {
		if(y && (x ^ ans) != y) d[x] = ans ^ (1 << 20), d[y] = 1 << 20;
		else {
			d[x] = ans;
			if(d[x] && (x ^ d[x]) <= n) {
				if(c[x ^ d[x]]) d[x ^ d[x]] = 1 << 20;
				else puts("-1"), exit(0);
			}
		}
	}
	ans ^= d[x] ^ d[y] ^ d[z];

	if(ans) puts("-1");
	else {
		printf("%d\n", n);
		for(int i = 2; i <= n; i++) printf("%d %d\n", u[i] ^ d[u[i]], v[i] ^ d[v[i]]);
	}
	return 0;
}

