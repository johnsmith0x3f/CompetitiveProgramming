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
const int P = 998244353;
int a[N];
i64 f[N][2];

int main() {
	int n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();

	for(int i = 2; i <= n; ++i) {
		f[i][0] = f[i-1][0] * i % P, f[i][1] = f[i-1][1] * i % P;
	}

	printf("%lld\n", f[n][1]);
	return 0;
}

