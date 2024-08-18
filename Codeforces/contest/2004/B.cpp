#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

int main() {
	int cas = read();
	while(cas--) {
		int l = read(), r = read(), L = read(), R = read();
		printf("%d\n", max(min(r, R) - max(l, L), 0) + (l != L) + (r != R) - (L > r || l > R));
	}
	return 0;
}
