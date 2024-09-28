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

i64 solve(const i64 &x) {
	if(x == 1) return 0;
	return x & 1 ? x + 1 + solve(x + (x + 1) / 2) : x + solve(x / 2);
}

int main() {
	return printf("%lld\n", solve(read())), 0;
}

