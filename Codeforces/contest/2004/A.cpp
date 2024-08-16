#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
constexpr read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read(), foo = 0, bar = 0;
		for(int i = 0; i < n; ++i) foo ? (bar = read()) : (foo = read());
		puts((n == 2 && abs(foo - bar) > 1) ? "YES" : "NO");
	}
	return 0;
}