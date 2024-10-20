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
const int P = 1000000007;
const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
char c[N][N];

template <typename T = int, const T p = P>
constexpr T binExp(const T &a, T b = p - 2) {
	T res = 1;
	for(T x = a; b; x = 1ll * x * x % p, b >>= 1)
		if(b & 1) res = 1ll * res * x % p;
	return res;
}

int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; ++i, getchar())
		for(int j = 1; j <= m; ++j) c[i][j] = getchar();

	int num = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int flag = 1;
			for(int k = 0; k < 4; ++k) {
				int x = i + dx[k], y = j + dy[k];
				flag &= (x < 1 || x > n || y < 1 || y > m || c[x][y] == c[i][j]);
			}
			num += flag;
		}
	}

	printf("%d\n", binExp(2, num));
	return 0;
}

