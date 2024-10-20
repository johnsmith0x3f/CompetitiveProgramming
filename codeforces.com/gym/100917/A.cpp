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

const int N = 3005;
char s[N][N];
int hasr[N], hasc[N], numr[N][128], numc[N][128];
tuple<char, int, char> ans[N + N];

int main() {
	int n = read();
	for(int i = 1; i <= n; i++, getchar())
		for(int j = 1; j <= n; j++) s[i][j] = getchar();

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(s[i][j] != '?') hasr[i] += !numr[i][s[i][j] - 'a']++, hasc[j] += !numc[j][s[i][j] - 'a']++;

	int cur = n + n, foo = 1, bar = 1;
	while(foo || bar) {
		foo = bar = 0;
		for(int i = 1; i <= n; i++) {
			if(hasr[i] != 1) continue;

			char c = 0;
			for(int j = 0; j < 26; j++)
				if(numr[i][j]) { c = 'a' + j; break; }

			for(int j = 1; j <= n; ++j)
				if(s[i][j] == c) hasc[j] -= !--numc[j][c - 'a'];

			foo = 1, hasr[i] = -1, ans[cur--] = { 'h', i, c };
		}
		for(int i = 1; i <= n; i++) {
			if(hasc[i] != 1) continue;

			char c = 0;
			for(int j = 0; j < 26; j++)
				if(numc[i][j]) { c = 'a' + j; break; }

			for(int j = 1; j <= n; ++j)
				if(s[j][i] == c) hasr[j] -= !--numr[j][c - 'a'];

			bar = 1, hasc[i] = -1, ans[cur--] = { 'v', i, c };
		}
	}

	for(int i = 1; i <= n; i++)
		if(!hasr[i]) ans[cur--] = { 'h', i, 'a' };
	for(int i = 1; i <= n; i++)
		if(!hasc[i]) ans[cur--] = { 'v', i, 'a' };

	for(int i = 1; i <= n + n; i++) printf("%c %d %c\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
	return 0;
}

