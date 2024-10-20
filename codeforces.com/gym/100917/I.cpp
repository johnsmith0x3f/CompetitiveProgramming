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

const int V = 1 << 20;
int now;
bitset<300> bet, ans, b[V];

inline void ask(const int &x) {
	printf("%d\n", x), fflush(stdout);
	if((now = read()) == -1) exit(0);
}

int main() {
	int r = 120;
	for(int i = 0; i < V; ++i)
		for(i64 j = 0, x = i; j < r; ++j) b[i].set(j, __builtin_parity(x)), x = (487237 * x + 1011807) & (V - 1);

	int las = read();
	for(int i = 0; i < r; ++i) ask(1), bet.set(i, now > las), las = now;

	i64 x = 0;
	for(int i = 0; i < V; ++i)
		if(bet == b[i]) x = i;

	for(int i = 0; i < 200; ++i) ans.set(i, __builtin_parity(x)), x = (487237 * x + 1011807) & (V - 1);
	for(int i = r; i < 200; ++i) ask(ans[i] ? now : 1);
	return 0;
}

