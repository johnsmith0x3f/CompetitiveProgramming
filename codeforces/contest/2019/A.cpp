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

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		vector<int> a(n);
		for(int i = 0; i < n; i++) a[i] = read();

		int ans = 0;
		for(int i = 0; i < n; i++) ans = max(ans, a[i] + i / 2 + 1 + (n - i - 1) / 2);
		printf("%d\n", ans);
	}
	return 0;
}

