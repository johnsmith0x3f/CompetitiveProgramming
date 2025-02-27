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

const int N = 1000005;
i64 win[N];

inline void solve() {
	int n = read();
	for(int i = 0; i < n; ++i) win[i] = 0;
	for(int i = 0; i < n; ++i) win[i] -= read();
	for(int i = 0; i < n; ++i) win[i] += read();

	if(n == 2 && win[1]) return void(puts("NO"));

	sort(win+1, win+n, greater<i64>());
	for(int i = 1; i < n; ++i) {
		if(!win[0]--) return void(puts("NO"));
		win[0] += win[i];
	}
	puts("YES");
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

