#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
constexpr read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

const int N = 10000007;
int tot, pr[N], id[N], lp[N];

inline void init() {
	for(int i = 2; i < N; ++i) {
		if(lp[i] == 0) pr[++tot] = i, id[i] = tot, lp[i] = i;
		for(int j = 1; j <= tot && 1ll * i * pr[j] < N && pr[j] <= lp[i]; ++j) lp[i * pr[j]] = pr[j];
	}
	id[1] = lp[1] = 1, id[2] = 0;
}

int main() {
	init();

	int cas = read();
	while(cas--) {
		int n = read(), xsum = 0;
		for(int i = 0; i < n; ++i) xsum ^= id[lp[read()]];
		puts(xsum ? "Alice" : "Bob");
	}
	return 0;
}