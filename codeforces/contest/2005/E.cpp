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

const int N = 302;
int a[N], b[N][N];
int s[2][N][N];

int main() {
	int cas = read();
	while(cas--) {
		int l = read(), n = read(), m = read();
		for(int i = 1; i <= l; ++i) a[i] = read();
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) b[i][j] = read();

		for(int i = 1; i <= n+1; ++i)
			for(int j = 1; j <= m+1; ++j) s[0][i][j] = s[1][i][j] = 0;
		for(int i = l; i >= 1; --i) {
			int now = i & 1, pre = (i & 1) ^ 1;
			for(int j = n; j >= 1; --j)
				for(int k = m; k >= 1; --k) s[pre][j][k] += s[pre][j][k+1] + s[pre][j+1][k] - s[pre][j+1][k+1];
			for(int j = n; j >= 1; --j)
				for(int k = m; k >= 1; --k) s[now][j][k] = (a[i] == b[j][k] && s[pre][j+1][k+1] == 0);
		}

		int flag = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) flag |= s[1][i][j];
		puts(flag ? "T" : "N");
	}
	return 0;
}

