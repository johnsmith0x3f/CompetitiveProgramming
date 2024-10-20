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

const int N = 2005;
const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
int c[N][N];

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++i, getchar())
		for(int j = 1; j <= m; ++j) c[i][j] = (getchar() == 'B');

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 4; ++k) c[i+dx[k]][j+dy[k]] ^= 1;

	puts("1");
	for(int i = 1; i <= n; ++i, putchar(10))
		for(int j = 1; j <= m; ++j) printf("%d", 2 + c[i][j]);
	return 0;
}

