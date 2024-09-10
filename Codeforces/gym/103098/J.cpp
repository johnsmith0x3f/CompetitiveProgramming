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

const int K = 31624;
bool have[K];

int main() {
	int cas = read();
	while(cas--) {
		int k = read(), x = k, y = k + 1;
		for(int i = 1; i < K; ++i) have[i] = 0;

		for(int i = 2; i <= (k+1) / i; ++i) {
			if(x % i == 0) {
				have[i] = 1;
				while(x % i == 0) x /= i;
			}
			if(y % i == 0) {
				have[i] = 1;
				while(y % i == 0) y /= i;
			}
		}

		int ans = (x > 1) + (y > 1) - (x > 1 && y > 1 && x == y);
		for(int i = 1; i < K; ++i) ans += have[i];
		printf("%d\n", ans);
	}
	return 0;
}

