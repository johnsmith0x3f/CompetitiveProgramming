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

const int N = 1000006;
int fun[N];

inline int F(int x) {
	int res = 0;
	while(x) res += (x % 10) * (x % 10), x /= 10;
	return res;
}

int calc(int n) {
	if(fun[n]) return fun[n];
	return fun[n] = n, fun[n] = min(fun[n], calc(F(n)));
}

int main() {
	int A = read(), B = read(); i64 ans = 0;
	for(int i = A; i <= B; ++i) ans += calc(i);
	printf("%lld\n", ans);
	return 0;
}

