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

const int N = 1003;
const string sc = "narek";
int f[N][5];

inline bool check(const char &c) {
	bool res = 0;
	for(int i = 0; i < 5; ++i) res |= (c == sc[i]);
	return res;
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), m = read();

		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < 5; ++j) f[i][j] = -1e9;
		f[0][0] = 0;

		for(int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			memcpy(f[i], f[i-1], sizeof(f[i]));
			for(int j = 0; j < 5; ++j) {
				int p = j, foo = 0, bar = 0;
				for(int k = 0; k < m; ++k) {
					if(s[k] == sc[p] && ++p >= 5) p = 0, foo += 5;
					else if(s[k] != sc[p] && check(s[k])) ++bar;
				}
				f[i][p] = max(f[i][p], f[i-1][j] + foo - bar);
			}
		}

		int ans = 0;
		for(int i = 0; i < 5; ++i) ans = max(ans, f[n][i] - i);
		printf("%d\n", ans);
	}
	return 0;
}

