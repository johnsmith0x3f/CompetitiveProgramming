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

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		string str;
		cin >> str;

		vector<vector<int>> s(n+5, vector<int>(26, 0));
		for(int i = n-1; ~i; --i) {
			for(int j = 0; j < 26; ++j) s[i][j] = s[i+2][j];
			++s[i][str[i]-'a'];
		}

		int ans = n;
		if(n & 1) {
			for(int i = 0; i < n; ++i) {
				int foo = 0, bar = 0;
				for(int j = 0; j < 26; ++j) foo = max(foo, s[0][j] - s[i+(i&1)][j] + s[i+1+(i&1)][j]), bar = max(bar, s[1][j] - s[i+((i&1)^1)][j] + s[i+1+((i&1)^1)][j]);
				ans = min(ans, n - foo - bar);
			}
		}
		else {
			int foo = 0, bar = 0;
			for(int i = 0; i < 26; ++i) foo = max(foo, s[0][i]), bar = max(bar, s[1][i]);
			ans = min(ans, n - foo - bar);
		}
		printf("%d\n", ans);
	}
	return 0;
}

