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

const string sel = "narek";
int f[2][5];

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), m = read();

		f[0][0] = 0;
		for(int i = 1; i < 5; ++i) f[0][i] = -1e9;

		for(int i = 1; i <= n; ++i) {
			string str;
			cin >> str;
			int now = i & 1, las = now ^ 1;
			memcpy(f[now], f[las], sizeof(f[now]));
			for(int j = 0; j < 5; ++j) {
				int p = j, foo = 0, bar = 0;
				for(int k = 0; k < m; ++k) {
					if(str[k] == sel[p]) foo += (++p >= 5) * 5, p %= 5;
					else if(sel.find(str[k]) < sel.length()) ++bar;
				}
				f[now][p] = max(f[now][p], f[las][j] + foo - bar);
			}
		}

		int ans = 0;
		for(int i = 0; i < 5; ++i) ans = max(ans, f[n&1][i] - i);
		printf("%d\n", ans);
	}
	return 0;
}

