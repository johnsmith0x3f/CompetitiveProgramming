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

const int N = 100005;
int st[N][21];

inline int query(const int &l, const int &r) {
	int k = __lg(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	int n = read(), w = read();
	for(int i = 1; i <= n; ++i) st[i][0] = read();
	for(int j = 0; j < 20; ++j)
		for(int i = 1; i <= n; ++i) st[i][j + 1] = max(st[i][j], i + (1 << j) <= n ? st[i + (1 << j)][j] : 0);

	for(int i = 1; i <= n; ++i) {
		i64 len = -1;
		for(int j = 1; j <= n; j += i) len += query(j, min(j + i - 1, n)) + 1;
		if(len <= w) printf("%d\n", i), exit(0);
	}
	return 0;
}

