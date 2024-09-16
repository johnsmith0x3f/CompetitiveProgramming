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
	i64 n = read<i64>(), p = 1, s = 0;

	while(s + p <= n / 2) s += p++;

	if(s + s == n) printf("%lld\n", p + p - 2);
	else if(s + p + s >= n) printf("%lld\n", p + p - 1);
	else printf("%lld\n", p + p);
	return 0;
}

