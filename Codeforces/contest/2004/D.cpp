#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
constexpr read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

const int N = 200005;
const int INF = 0x3f3f3f3f;
int a[N], las[16], pre[N][16], nxt[N][16];

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), q = read();
		for(int i = 1; i <= n; ++i) {
			char x = getchar(), y = getchar(); getchar();
			a[i] = ((x == 'R' || y == 'R') << 3) | ((x == 'G' || y == 'G') << 2) | ((x == 'B' || y == 'B') << 1) | (x == 'Y' || y == 'Y');
		}

		for(int i = 0; i < 16; ++i) las[i] = -1;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < 16; ++j) pre[i][j] = las[j];
			las[a[i]] = i;
		}
		for(int i = 0; i < 16; ++i) las[i] = -1;
		for(int i = n; i >= 1; --i) {
			for(int j = 0; j < 16; ++j) nxt[i][j] = las[j];
			las[a[i]] = i;
		}

		auto work = [=]() {
			int x = read(), y = read();
			if(x == y) return 0;

			int ans = INF;
			for(int i = 0; i < 16; ++i) {
				if(~pre[x][i] && (a[pre[x][i]] & a[x]) && (a[pre[x][i]] & a[y])) ans = min(ans, abs(x - pre[x][i]) + abs(y - pre[x][i]));
				if(~nxt[x][i] && (a[nxt[x][i]] & a[x]) && (a[nxt[x][i]] & a[y])) ans = min(ans, abs(x - nxt[x][i]) + abs(y - nxt[x][i]));
				if(~pre[y][i] && (a[pre[y][i]] & a[x]) && (a[pre[y][i]] & a[y])) ans = min(ans, abs(x - pre[y][i]) + abs(y - pre[y][i]));
				if(~nxt[y][i] && (a[nxt[y][i]] & a[x]) && (a[nxt[y][i]] & a[y])) ans = min(ans, abs(x - nxt[y][i]) + abs(y - nxt[y][i]));
			}
			return ans < INF ? ans : -1;
		};

		while(q--) printf("%d\n", work());
	}
	return 0;
}