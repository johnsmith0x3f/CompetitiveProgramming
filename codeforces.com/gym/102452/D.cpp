#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

void write(int k, int X) {
	if(X >= k) write(k, X / k - 1);
	putchar(X % k + 10 - k + '0');
}

int main() {
	int cas = read();
	while(cas--) {
		int k = read(), X = read();
		write(k, X - 1), putchar('\n');
	}
	return 0;
}

