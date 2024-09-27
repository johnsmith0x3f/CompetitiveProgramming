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
	int cas = read();
	while(cas--) {
		int n = read(), q = read();
		vector<int> x(n);
		for(int i = 0; i < n; ++i) x[i] = read();

		map<i64, int> num;
		for(int i = 0; i < n; ++i) {
			num[1ll * (i + 1) * (n - i) - 1]++;
			if(i) num[1ll * i * (n - i)] += x[i] - x[i - 1] - 1;
		}

		while(q--) printf("%d%c", num[read<i64>()], " \n"[q == 0]);
	}
	return 0;
}

