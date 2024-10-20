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

const int M = 21000007;
int tot, pr[M], nxt[M];
bool isprime[M];

inline void init() {
	const int n = 2.1e7;
	for(int i = 2; i <= n; ++i) isprime[i] = 1;
	for(int i = 2; i <= n; ++i) {
		if(isprime[i]) pr[++tot] = i;
		for(int j = 1; j <= tot && i * pr[j] <= n; ++j) {
			isprime[i * pr[j]] = 0;
			if(i % pr[j] == 0) break;
		}
	}
	for(int i = 1e7, las = 1e9; i >= 0; --i) {
		if(isprime[i+1]) las = min(las, i * 2 + 2);
		if(isprime[i+1+i+2]) las = min(las, i * 2 + 3);
		nxt[i] = las;
	}
}

inline void solve(const int &x) {
	if(x > 0) (isprime[x] ? puts("1") : (isprime[x+x-1] || isprime[x+x+1] ? puts("2") : printf("%d\n", nxt[x])));
	else printf("%d\n", nxt[-x]);
}

int main() {
	init();

	int cas = read();
	while(cas--) solve(read());
	return 0;
}

