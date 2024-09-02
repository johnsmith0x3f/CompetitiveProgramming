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

const int N = 100005;
int sum[N], ans[N];


int main() {
	int cas = read();
	while(cas--) {
		int n = read(), q = read();
		vector<int> sum(n+1, 0);
		for(int i = 1; i <= n; ++i) ++sum[read()];
		for(int i = 1; i <= n; ++i) sum[i] += sum[i-1];

		for(int x = 1; x <= n; ++x) {
			int l = 0, r = x, y = 0;
			while(l <= r) {
				int m = (l + r) >> 1, num = 0;
				for(int i = 0; i <= n; i += x) num += sum[min(i+m, n)] - sum[i-(i>0)];

				if(num > n / 2) y = m, r = m - 1;
				else l = m + 1;
			}
			ans[x] = y;
		}

		while(q--) printf("%d%c", ans[read()], " \n"[q == 0]);
	}
	return 0;
}

