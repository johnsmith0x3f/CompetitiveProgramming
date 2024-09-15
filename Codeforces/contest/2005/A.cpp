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

const char vow[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), m = n / 5;
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < m + (i < n % 5); ++j) putchar(vow[i]);
		putchar(10);
	}
	return 0;
}

