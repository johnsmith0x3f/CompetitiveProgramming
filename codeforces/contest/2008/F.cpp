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

const int P = 1000000007;

template <typename T = int, const T p = P>
constexpr T binExp(const T &a, T b = p - 2) {
	T res = 1;
	for(T x = a; b; x = 1ll * x * x % p, b >>= 1)
		if(b & 1) res = 1ll * res * x % p;
	return res;
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		vector<int> a(n);
		for(int i = 0; i < n; ++i) a[i] = read();

		i64 sum = 0, prd = 0;
		for(int i = 0; i < n; ++i) prd += sum * a[i] % P, prd %= P, sum += a[i], sum %= P;
		printf("%lld\n", prd * 2 % P * binExp(n) % P * binExp(n-1) % P);
	}
	return 0;
}

